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
#include "Journal.h"

using namespace std;
using namespace biblio;


/**
 * \test Test du constructeur
 *
 * 		  Cas valides: Création d'un objet Journal et vérification de l'assignation de tous les attributs
 *		  Cas invalides:
 *		       nom du journal vide
 *                     identifiant non validé par validerFormatIssn
 */
TEST (Journal, ConstructeurAvecParametre)
{
  Journal unJournal ("Yacine Kahlis", "Dindons Sauvages", 2001, "ISSN 1937-4771", "Journal Ulaval", 1, 2, 3);
  ASSERT_EQ ("Journal Ulaval", unJournal.reqNom ());
  ASSERT_EQ (1, unJournal.reqVolume ());
  ASSERT_EQ (2, unJournal.reqNumero ());
  ASSERT_EQ (3, unJournal.reqPage ());
  ASSERT_EQ ("Yacine Kahlis", unJournal.reqAuteurs ());
  ASSERT_EQ ("Dindons Sauvages", unJournal.reqTitre ());
  ASSERT_EQ (2001, unJournal.reqAnnee ());
  ASSERT_EQ ("ISSN 1937-4771", unJournal.reqIdentifiant ());
}

// cas invalides


TEST (Journal, ConstructeurNomInvalide)
{
  ASSERT_THROW (Journal unJournal ("Yacine Kahlis", "Dindons Sauvages", 2001, "ISSN 1937-4771", "", 1, 2, 3), ContratException);
}


TEST (Journal, ConstructeurIdentifiantInvalide)
{
  ASSERT_THROW (Journal unJournal ("Yacine Kahlis", "Dindons Sauvages", 2001, "", "Journal Ulaval", 1, 2, 3), ContratException);
  ASSERT_THROW (Journal unJournal ("Yacine Kahlis", "Dindons Sauvages", 2001, "ISBN 978-0-387-77591-3", "Journal Ulaval", 1, 2, 3), ContratException);
}

/**
 * \brief Creation d’une fixture a utiliser pour les methodes public de la classe de test
 */
class unJournal : public ::testing::Test
{

public:


  unJournal () :
  t_journal ("Yacine Kahlis", "Dindons Sauvages", 2001, "ISSN 1937-4771", "Journal Ulaval", 1, 2, 3) { }
  Journal t_journal;
} ;


/**
 * \test Test de la méthode reqNom()
 *
 *     Cas valide: vérifier le retour du nom du Journal
 *     Cas invalide: aucun
 */
TEST_F (unJournal, reqNom)
{
  ASSERT_EQ ("Journal Ulaval", t_journal.reqNom ());
}


/**
 * \test Test de la méthode reqVolume()
 *
 *     Cas valide: vérifier le retour du volume du Journal
 *     Cas invalide: aucun
 */
TEST_F (unJournal, reqVolume)
{
  ASSERT_EQ (1, t_journal.reqVolume ());
}


/**
 * \test Test de la méthode reqNumero()
 *
 *     Cas valide: vérifier le retour du numero du Journal
 *     Cas invalide: aucun
 */
TEST_F (unJournal, reqNumero)
{
  ASSERT_EQ (2, t_journal.reqNumero ());
}


/**
 * \test Test de la méthode reqPage()
 *
 *     Cas valide: vérifier le retour de la page du Journal
 *     Cas invalide: aucun
 */
TEST_F (unJournal, reqPage)
{
  ASSERT_EQ (3, t_journal.reqPage ());
}


/**
 * \test Test de la méthode reqBibliographieFormate()
 *
 *     Cas valide: vérifier le retour d'un string formaté du Journal dans le bon format
 *     Cas invalide: aucun
 */
TEST_F (unJournal, reqReferenceFormate)
{
  ASSERT_EQ ("Yacine Kahlis. Dindons Sauvages. Journal Ulaval, vol. 1, no. 2, pp. 3, 2001. ISSN 1937-4771.", t_journal.reqReferenceFormate ());
}


/**
 * \test Test de la méthode clone()
 *
 *     Cas valide: vérifier le retour d'un pointeur d'un objet référence alloué dynamiquement, tout en ayant les même attributs que celui cloné
 *     Cas invalide: aucun
 */
TEST_F (unJournal, clone)
{
  EXPECT_FALSE (&t_journal == t_journal.clone ()); //pas la même adresse, mais contient le meme contenu!
  ASSERT_EQ (t_journal.reqAuteurs (), t_journal.clone ()->reqAuteurs ());
  ASSERT_EQ (t_journal.reqAnnee (), t_journal.clone ()->reqAnnee ());
  ASSERT_EQ (t_journal.reqIdentifiant (), t_journal.clone ()->reqIdentifiant ());
  ASSERT_EQ (t_journal.reqTitre (), t_journal.clone ()->reqTitre ());
}