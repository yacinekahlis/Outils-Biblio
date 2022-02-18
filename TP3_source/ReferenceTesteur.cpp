/**
 * \file SphereTesteur.cpp
 * \brief Testeur de la classe Reference
 *  A tester:
 *          Reference (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant);
 *          std::string reqAuteurs () const;
 *          std::string reqTitre () const;
 *          int reqAnnee () const;
 *          std::string reqIdentifiant () const;
 *          void asgAnnee (int p_annee);
 *          virtual std::string reqReferenceFormate () const = 0;
 *          bool operator== (const Reference& p_reference) const;
 *          virtual ~Reference ();
 *          virtual Reference* clone () const = 0;
 */

#include <gtest/gtest.h>
#include "Reference.h"
#include "ContratException.h"

using namespace std;
using namespace biblio;

/**
 * @class ReferenceDerivee
 *
 * Cette classe sert seulement à tester certaines méthodes de notre classe
 * abstraite Reference.
 *
 * On va donc "implémenter" les méthodes virtuelles pures de Reference
 * afin d'avoir une classe instantiable.
 *
 */
class ReferenceDerivee : public Reference
{

public:


  ReferenceDerivee (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant)
  : Reference (p_auteurs, p_titre, p_annee, p_identifiant) { }


  std::string
  reqReferenceFormate () const override
  {
    ostringstream os;
    os << reqAuteurs () << ". " << reqTitre () << ".";
    return os.str ();
  }


  Reference*
  clone () const override
  {
    return nullptr;
  }
} ;


/**
 * \brief Test du constructeur avec paramètre Reference (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant)
 *     Cas valide: 1- m_auteur doit être dans un format valide et vérifier grâce à la fonction validerFormatNom(const string& p_nom).
 *                 2- m_titre doit être non-vide.
 *                 3- m_annee > 0.
 *                 4- m_identifiant dans un format valide et vérifier grâce à validerCodeIsbn (const std::string& p_isbn) ou validerCodeIssn (const string& p_issn).
 *
 *     Cas invalide: Si l'un des quatres critères de validation n'est pas respecté
 */



TEST (ReferenceDerivee, ConstructeurAvecParametre)
{
  ReferenceDerivee uneReference ("Yacine Kahlis", "Dindons Sauvages", 2001, "ISSN 1467-8640");
  ASSERT_EQ ("Yacine Kahlis", uneReference.reqAuteurs ());
  ASSERT_EQ ("Dindons Sauvages", uneReference.reqTitre ());
  ASSERT_EQ (2001, uneReference.reqAnnee ());
  ASSERT_EQ ("ISSN 1467-8640", uneReference.reqIdentifiant ());
}

// cas invalide


TEST (ReferenceDerivee, ConstructeurAuteursInvalide)
{
  ASSERT_THROW (ReferenceDerivee uneReference ("", "Dindons Sauvages", 2001, "ISSN 1467-8640"), ContratException);
}


TEST (ReferenceDerivee, ConstructeurTitreInvalide)
{
  ASSERT_THROW (ReferenceDerivee uneReference ("Yacine Kahlis", "", 2001, "ISSN 1467-8640"), ContratException);
}


TEST (ReferenceDerivee, ConstructeurAnneeInvalide)
{
  ASSERT_THROW (ReferenceDerivee uneReference ("Yacine Kahlis", "Dindons Sauvages", 0, "ISSN 1467-8640"), ContratException);
}


TEST (ReferenceDerivee, ConstructeurIdentifiantInvalide)
{
  ASSERT_THROW (ReferenceDerivee uneReference ("Yacine Kahlis", "Dindons Sauvages", 2001, ""), ContratException);
}

/**
 * \brief Creation d’une fixture a utiliser pour les methodes public de la classe de test
 */
class uneReference : public ::testing::Test
{

public:


  uneReference () :
  t_reference ("Yacine Kahlis", "Dindons Sauvages", 2001, "ISSN 1467-8640") { }
  ReferenceDerivee t_reference;
} ;


/**
 * \test Test de la méthode reqAuteurs()
 *
 *     Cas valide: vérifier le retour de(s) auteur(es) de la reference
 *     Cas invalide: aucun
 */
TEST_F (uneReference, reqAuteurs)
{
  ASSERT_EQ ("Yacine Kahlis", t_reference.reqAuteurs ());
}


/**
 * \test Test de la méthode reqTitre()
 *
 *     Cas valide: vérifier le retour du titre de la reference
 *     Cas invalide: aucun
 */
TEST_F (uneReference, reqTitre)
{
  ASSERT_EQ ("Dindons Sauvages", t_reference.reqTitre ());
}


/**
 * \test Test de la méthode reqAnnee()
 *
 *     Cas valide: vérifier le retour de l'année d'édition de la reference
 *     Cas invalide: aucun
 */
TEST_F (uneReference, reqAnnee)
{
  ASSERT_EQ (2001, t_reference.reqAnnee ());
}


/**
 * \test Test de la méthode reqIdentifiant()
 *
 *     Cas valide: vérifier le retour de(s) auteur(es l'identifiant de la reference
 *     Cas invalide: aucun
 */
TEST_F (uneReference, reqIdentifiant)
{
  ASSERT_EQ ("ISSN 1467-8640", t_reference.reqIdentifiant ());
}


/**
 * \test Test de la méthode reqBibliographieFormate()
 *
 *     Cas valide: vérifier le retour d'un string formaté de la Reference dans le bon format
 *     Cas invalide: aucun
 */
TEST_F (uneReference, reqReferenceFormate)
{
  ASSERT_EQ ("Yacine Kahlis. Dindons Sauvages.", t_reference.reqReferenceFormate ());
}


/**
 * \test Test de la méthode asgAnnee (int p_annee)
 *
 *     Cas valide: annee plus grand que 0
 *     Cas invalide: assignation d'une annee plus petite ou egal a 0
 */
TEST_F (uneReference, asgAnneeValide)
{
  t_reference.asgAnnee (1995);
  ASSERT_EQ (1995, t_reference.reqAnnee ());
}

// cas invalide


TEST_F (uneReference, setAnneeInvalide)
{
  ASSERT_THROW (t_reference.asgAnnee (-1), ContratException) << "Une Référence ne doit pas accepter une année plus petite que 0";
}


/**
 * \test Test de la méthode operator== (const Reference& p_reference)
 *
 *     Cas valide: retour de true lorsque tout les attributs sont les mêmes
 *     Cas invalide: aucun
 */
TEST_F (uneReference, operatorEqualTrue)
{
  ReferenceDerivee rTestEqual ("Yacine Kahlis", "Dindons Sauvages", 2001, "ISSN 1467-8640");
  ASSERT_EQ (true, t_reference == rTestEqual);
}


/**
 * \test Test de la méthode operator== (const Reference& p_reference)
 *
 *     Cas valide: retour de true lorsque les attributs ne sont pas les mêmes
 *     Cas invalide: aucun
 */
TEST_F (uneReference, operatorEqualFalse)
{
  ReferenceDerivee rTestEqual ("Mouctar Balde", "Dindons Sauvages", 2001, "ISSN 1467-8640");
  ASSERT_EQ (false, t_reference == rTestEqual);
}