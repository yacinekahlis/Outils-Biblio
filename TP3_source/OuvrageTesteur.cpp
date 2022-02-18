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
#include "Ouvrage.h"

using namespace std;
using namespace biblio;


/**
 * \test Test du constructeur
 *
 * 		  Cas valides: Création d'un objet Ouvrage et vérification de l'assignation de tous les attributs
 *		  Cas invalides:
 *		       ville de l'ouvrage vide validée par validerFormatNom
 *                     editeur de l'ouvrage non validé par validerFormatNom
 *                     identifiant non validé par validerFormatIsbn
 */
TEST (Ouvrage, ConstructeurAvecParametre)
{
  Ouvrage unOuvrage ("Yacine Kahlis", "Dindons Sauvages", 2001, "ISBN 978-0-387-77591-3", "Splinter", "Tombouctou");
  ASSERT_EQ ("Splinter", unOuvrage.reqEditeur ());
  ASSERT_EQ ("Tombouctou", unOuvrage.reqVille ());
  ASSERT_EQ ("Yacine Kahlis", unOuvrage.reqAuteurs ());
  ASSERT_EQ ("Dindons Sauvages", unOuvrage.reqTitre ());
  ASSERT_EQ (2001, unOuvrage.reqAnnee ());
  ASSERT_EQ ("ISBN 978-0-387-77591-3", unOuvrage.reqIdentifiant ());
}

// cas invalides


TEST (Ouvrage, ConstructeurVilleInvalide)
{
  ASSERT_THROW (Ouvrage unOuvrage ("Yacine Kahlis", "Dindons Sauvages", 2001, "ISBN 978-0-387-77591-3", "Splinter", ""), ContratException);
}


TEST (Ouvrage, ConstructeurEditeurInvalide)
{
  ASSERT_THROW (Ouvrage unOuvrage ("Yacine Kahlis", "Dindons Sauvages", 2001, "ISBN 978-0-387-77591-3", "", "Tombouctou"), ContratException);
}


TEST (Ouvrage, ConstructeurIdentifiantInvalide)
{
  ASSERT_THROW (Ouvrage unOuvrage ("Yacine Kahlis", "Dindons Sauvages", 2001, "", "Splinter", "Tombouctou"); , ContratException);
  ASSERT_THROW (Ouvrage unOuvrage ("Yacine Kahlis", "Dindons Sauvages", 2001, "ISSN 1467-8640", "Splinter", "Tombouctou"); , ContratException);
}

/**
 * \brief Creation d’une fixture a utiliser pour les methodes public de la classe de test
 */
class unOuvrage : public ::testing::Test
{

public:


  unOuvrage () :
  t_ouvrage ("Yacine Kahlis", "Dindons Sauvages", 2001, "ISBN 978-0-387-77591-3", "Splinter", "Tombouctou") { }
  Ouvrage t_ouvrage;
} ;


/**
 * \test Test de la méthode reqEditeur()
 *
 *     Cas valide: vérifier le retour de l'editeur de l'Ouvrage
 *     Cas invalide: aucun
 */
TEST_F (unOuvrage, reqEditeur)
{
  ASSERT_EQ ("Splinter", t_ouvrage.reqEditeur ());
}


/**
 * \test Test de la méthode reqreqVille()
 *
 *     Cas valide: vérifier le retour de la ville de l'Ouvrage
 *     Cas invalide: aucun
 */
TEST_F (unOuvrage, reqVille)
{
  ASSERT_EQ ("Tombouctou", t_ouvrage.reqVille ());
}


/**
 * \test Test de la méthode reqBibliographieFormate()
 *
 *     Cas valide: vérifier le retour d'un string formaté de l'Ouvrage dans le bon format
 *     Cas invalide: aucun
 */
TEST_F (unOuvrage, reqReferenceFormate)
{
  ASSERT_EQ ("Yacine Kahlis. Dindons Sauvages. Tombouctou : Splinter, 2001. ISBN 978-0-387-77591-3.", t_ouvrage.reqReferenceFormate ());
}


/**
 * \test Test de la méthode clone()
 *
 *     Cas valide: vérifier le retour d'un pointeur d'un objet référence alloué dynamiquement, tout en ayant les même attributs que celui cloné
 *     Cas invalide: aucun
 */
TEST_F (unOuvrage, clone)
{
  EXPECT_FALSE (&t_ouvrage == t_ouvrage.clone ()); //pas la même adresse, mais contient le meme contenu!
  ASSERT_EQ (t_ouvrage.reqAuteurs (), t_ouvrage.clone ()->reqAuteurs ());
  ASSERT_EQ (t_ouvrage.reqAnnee (), t_ouvrage.clone ()->reqAnnee ());
  ASSERT_EQ (t_ouvrage.reqIdentifiant (), t_ouvrage.clone ()->reqIdentifiant ());
  ASSERT_EQ (t_ouvrage.reqTitre (), t_ouvrage.clone ()->reqTitre ());
}



