/**
 *\file Reference.cpp
 * \brief Implantation de la classe Reference
 * \author Yacine Kahlis
 *\date 3 octobre 2021, 15:25
 */

#include "ContratException.h"
#include "Reference.h"
#include "validationFormat.h"
#include <sstream>
using namespace std;

static const int MIN_ANNEE = 0;

namespace biblio
{


  /**
   * \fn Reference::Reference (string p_auteurs, string p_titre, int p_annee, string p_identifiant)
   * \brief Constructeur avec parametres. Il initialise les attributs avec les paramètres donnés en entré.
   * \param[in] p_auteurs Le mom de l'auteur (ou du premier auteur s'ils sont plusieurs) de la référence
   * \param[in] p_titre Le titre de la référence
   * \param[in] p_annee L'année d'édtion de la référence
   * \pre p_auteurs valider par la fontion validerFormatNom
   * \pre p_titre non vide
   * \pre p_annee plus grand que 0
   * \pre p_identifiant valider par l'une des fonction suivante : validerCodeIssn, validerCodeIsbn
   * \post m_annee prend la valeur de p_annee
   * \post m_titre prend la valeur de p_titre
   * \post m_identifiant prend la valeur de p_identifiant
   * \post m_auteurs prend la valeur de p_auteurs
   */
  Reference::Reference (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant)
  : m_auteurs (p_auteurs), m_titre (p_titre), m_annee (p_annee), m_identifiant (p_identifiant)
  {
    PRECONDITION (util::validerFormatNom (p_auteurs));
    PRECONDITION (!(p_titre.empty ()));
    PRECONDITION (p_annee > MIN_ANNEE);
    PRECONDITION (util::validerCodeIsbn (p_identifiant) or util::validerCodeIssn (p_identifiant));

    POSTCONDITION (reqAnnee () == p_annee);
    POSTCONDITION (reqAuteurs () == p_auteurs);
    POSTCONDITION (reqIdentifiant () == p_identifiant);
    POSTCONDITION (reqTitre () == p_titre);

    INVARIANTS ();
  }


  /**
   * \fn Reference::~Reference ()
   * \brief Destructeur de la classe Reference.
   */
  Reference::~Reference () { };


  /**
   * \fn Reference::reqReference()
   * \brief Acceseur pour l'auteur
   * \return m_auteurs L'auteur de l'objet
   */
  const string
  Reference::reqAuteurs () const
  {
    return m_auteurs;
  }


  /**
   * \fn Reference::reqTitre ()
   * \brief Acceseur pour le titre
   * \return m_titre Le titre de l'objet
   */
  const string
  Reference::reqTitre () const
  {
    return m_titre;
  }


  /**
   * \fn Reference::reqAnnee ()
   * \brief Acceseur pour l'année
   * \return m_annee L'année de l'objet
   */
  int
  Reference::reqAnnee () const
  {
    return m_annee;
  }


  /**
   * \fn Reference::reqIdentifiant ()
   * \brief Acceseur pour l'identifiant
   * \return m_identifiant L'identifiant de l'objet
   */
  const string
  Reference::reqIdentifiant () const
  {
    return m_identifiant;
  }


  /**
   * \fn Reference::asgAnnee (int p_annee)
   * \brief Mutateur pour année, modifie l'année
   * \pre p_annee plus grand que 0
   * \post m_annee prend la nouvelle valeur de p_annee
   */
  void
  Reference::asgAnnee (int p_annee)
  {
    PRECONDITION (p_annee > MIN_ANNEE);
    m_annee = p_annee;
    POSTCONDITION (reqAnnee () == m_annee);
    INVARIANTS ();
  }


  /**
   * \fn Reference::reqReferenceFormate () const
   * \brief Retourne une chaine de caractere signifiant les valeurs de l'instance
   * \return un string qui contient l'information de la référence
   */
  string
  Reference::reqReferenceFormate () const
  {
    ostringstream os;
    os << reqAuteurs () << ". " << reqTitre () << ".";
    return os.str ();
  }


  /**
   * \fn Reference::operator== (const Reference& p_reference)
   * \brief Retourne la valeur booléenne de l'opération == entre deux objet références
   * \param[in] p_reference Un objet référence à comparer
   * \return un string qui contient l'information de la référence
   */
  bool Reference::operator== (const Reference& p_reference) const
  {
    bool valide = false;
    if (m_auteurs == p_reference.m_auteurs)
      {
        if (m_annee == p_reference.m_annee)
          {
            if (m_identifiant == p_reference.m_identifiant)
              {
                if (m_titre == p_reference.m_titre)
                  valide = true;
              }
          }
      }
    return valide;
  }


  /**
   * \brief Teste l'invariant de la classe Reference. L'invariant de cette classe s'assure que la reference est valide
   */
  void
  Reference::verifieInvariant () const
  {
    INVARIANT (util::validerFormatNom (reqAuteurs ()));
    INVARIANT (!(reqTitre ().empty ()));
    INVARIANT (reqAnnee () > MIN_ANNEE);
    INVARIANT (util::validerCodeIsbn (reqIdentifiant ()) or util::validerCodeIssn (reqIdentifiant ()));
  }
}