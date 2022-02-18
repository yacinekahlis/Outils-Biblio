/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newsimpletest1.cpp
 * Author: etudiant
 *
 * Created on 19 novembre 2021, 12:31
 */

#include <gtest/gtest.h>
#include "Reference.h"
#include "ContratException.h"
#include "Bibliographie.h"

using namespace std;
using namespace biblio;


/**
 * \test Test du constructeur
 *
 * 		  Cas valides: Création d'un objet Bibliographie et vérification de l'assignation de tous les attributs
 *		  Cas invalides:
 *		       nom vide
 */
TEST (Bibliographie, constructeurAvecParametre)
{
  Bibliographie maBiblio ("BiblioTest");
  ASSERT_EQ ("BiblioTest", maBiblio.reqNomBibliographie ());
}



// cas invalide


TEST (Bibliographie, constructeurNomInvalide)
{
  ASSERT_THROW (Bibliographie maBiblio (""), ContratException);
}

/**
 * \brief Creation d’une fixture a utiliser pour les methodes public de la classe de test
 */
class uneBiblio : public ::testing::Test
{

public:


  uneBiblio () :
  t_biblio ("maBiblioTest"),
  t_ouvrage ("Yacine Kahlis", "Dindons Sauvages", 2001, "ISBN 978-0-387-77591-3", "Splinter", "Tombouctou"),
  t_journal ("Yacine Kahlis", "Dindons Sauvages", 2001, "ISSN 1937-4771", "Journal Ulaval", 1, 2, 3) { }
  Bibliographie t_biblio;
  Ouvrage t_ouvrage;
  Journal t_journal;
} ;


/**
 * \test Test de la méthode Bibliographie (const Bibliographie& p_bibliographie)
 *
 *     Cas valide: vérifier l'emploie d'un constructeur copie de bibliographie
 *     Cas invalide: aucun
 */
TEST_F (uneBiblio, constructeurCopie)
{
  Bibliographie uneBiblioCopie (t_biblio);
  ASSERT_EQ (t_biblio.reqNomBibliographie (), uneBiblioCopie.reqNomBibliographie ());
}


/**
 * \test Test de la méthode operator= (const Bibliographie& p_bibliographie)
 *
 *     Cas valide: vérifier le retour de l'operateurAssignation de la bibliographie
 *     Cas invalide: aucun
 */
TEST_F (uneBiblio, operateurAssignation)
{
  Bibliographie uneBiblio ("TOZZ");
  uneBiblio = t_biblio;
  ASSERT_EQ (t_biblio.reqNomBibliographie (), uneBiblio.reqNomBibliographie ());
}


/**
 * \test Test de la méthode reqNomBibliographie()
 *
 *     Cas valide: vérifier le retour du nom de la bibliographie
 *     Cas invalide: aucun
 */
TEST_F (uneBiblio, reqNomBibliographie)
{
  ASSERT_EQ ("maBiblioTest", t_biblio.reqNomBibliographie ());
}


/**
 * \test Test de la méthode reqBibliographieFormate()
 *
 *     Cas valide: vérifier le retour d'un string formaté de la bibliographie dans le bon format
 *     Cas invalide: aucun
 */
TEST_F (uneBiblio, reqBibliographieFormate)
{
  t_biblio.ajouterReference (t_ouvrage);
  ASSERT_EQ ("maBiblioTest\n===============================\n[1] Yacine Kahlis. Dindons Sauvages. Tombouctou : Splinter, 2001. ISBN 978-0-387-77591-3.\n", t_biblio.reqBibliographieFormate ());
}


/**
 * \test Test de la méthode ajouterReference (const Reference& p_nouvelleReference)
 *
 *     Cas valide: vérifier l'ajout d'une réference
 *     Cas invalide: aucun
 */
TEST_F (uneBiblio, ajouterReference)
{
  ASSERT_EQ ("maBiblioTest\n===============================\n", t_biblio.reqBibliographieFormate ());
  t_biblio.ajouterReference (t_ouvrage);
  ASSERT_EQ ("maBiblioTest\n===============================\n[1] Yacine Kahlis. Dindons Sauvages. Tombouctou : Splinter, 2001. ISBN 978-0-387-77591-3.\n", t_biblio.reqBibliographieFormate ());
}


/**
 * \test Test de la méthode supprimerReference (const std::string& p_identifiant)
 *
 *     Cas valide: vérifier la suppression d'une réference
 *     Cas invalide: aucun
 */
TEST_F (uneBiblio, supprimerReference)
{
  ASSERT_EQ ("maBiblioTest\n===============================\n", t_biblio.reqBibliographieFormate ());
  t_biblio.ajouterReference (t_ouvrage);
  ASSERT_EQ ("maBiblioTest\n===============================\n[1] Yacine Kahlis. Dindons Sauvages. Tombouctou : Splinter, 2001. ISBN 978-0-387-77591-3.\n", t_biblio.reqBibliographieFormate ());
  t_biblio.supprimerReference (t_ouvrage.reqIdentifiant ());
  ASSERT_EQ ("maBiblioTest\n===============================\n", t_biblio.reqBibliographieFormate ());
}


/**
 * \test Test de la méthode referenceEstDejaPresente (const Reference& p_reference) const
 *
 *     Cas valide: vérifier si une reférence existe déjà
 *     Cas invalide: aucun
 */
TEST_F (uneBiblio, referenceEstDejaPresente)
{
  t_biblio.ajouterReference (t_ouvrage);
  t_biblio.ajouterReference (t_journal);
  ASSERT_EQ (true, t_biblio.referenceEstDejaPresente (t_ouvrage));
  ASSERT_EQ (true, t_biblio.referenceEstDejaPresente (t_journal));
  t_biblio.supprimerReference (t_journal.reqIdentifiant ());
  t_biblio.supprimerReference (t_ouvrage.reqIdentifiant ());
  ASSERT_EQ (false, t_biblio.referenceEstDejaPresente (t_journal));
  ASSERT_EQ (false, t_biblio.referenceEstDejaPresente (t_ouvrage));
}