/**
 *\file Ouvrage.cpp
 * \brief Implantation de la classe Ouvrage
 * \author Yacine Kahlis
 *\date 10 novembre 2021, 20:33
 */

#include "Ouvrage.h"
#include "validationFormat.h"
#include "ContratException.h"
#include <sstream>
#include "Reference.h"

using namespace std;

namespace biblio
{


  /**
   * \fn Ouvrage::Ouvrage (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant, const std::string& p_editeur, const std::string& p_ville)
   * \brief Constructeur avec parametres. Il initialise les attributs avec les paramètres donnés en entré.
   * \param[in] p_auteurs Le mom de l'auteur (ou du premier auteur s'ils sont plusieurs) l'ouvrage
   * \param[in] p_titre Le titre de l'ouvrage
   * \param[in] p_identifiant Le code Isbn de l'ouvrage
   * \param[in] p_annee L'année d'édtion de l'ouvrage
   * \param[in] p_editeur L'édteur de l'ouvrage
   * \param[in] p_ville La ville d'édtion de l'ouvrage
   * \pre p_ville valider par la fontion validerFormatNom
   * \pre p_editeur valider par la fontion validerFormatNom
   * \pre p_identifiant valider par validerCodeIsbn
   * \post m_editeur prend la valeur de p_editeur
   * \post m_ville prend la valeur de p_ville
   */
  Ouvrage::Ouvrage (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant, const std::string& p_editeur, const std::string& p_ville) :
  Reference (p_auteurs, p_titre, p_annee, p_identifiant),
  m_editeur (p_editeur), m_ville (p_ville)
  {
    PRECONDITION (util::validerFormatNom (p_editeur));
    PRECONDITION (util::validerFormatNom (p_ville));
    PRECONDITION (util::validerCodeIsbn (p_identifiant));

    POSTCONDITION (m_editeur == p_editeur);
    POSTCONDITION (m_ville == p_ville);

    INVARIANTS ();
  }


  /**
   * \fn Ouvrage::reqEditeur ()
   * \brief Acceseur pour l'editeur
   * \return m_editeur L'editeur de l'objet
   */
  const std::string
  Ouvrage::reqEditeur () const
  {
    return m_editeur;
  }


  /**
   * \fn Ouvrage::reqVille ()
   * \brief Acceseur pour la ville
   * \return m_ville La ville d'edition de l'objet
   */
  const std::string
  Ouvrage::reqVille () const
  {
    return m_ville;
  }


  /**
   * \fn Ouvrage::reqReferenceFormate ()
   * \brief Retourne une chaine de caractere signifiant les valeurs de l'instance
   * \return un string qui contient l'information de l'ouvrage
   */
  std::string
  Ouvrage::reqReferenceFormate () const
  {
    std::ostringstream os;
    os << Reference::reqAuteurs () << ". " << Reference::reqTitre () << ". " << reqVille () << " : " << reqEditeur () << ", " << Reference::reqAnnee () << ". " << Reference::reqIdentifiant ()
            << ".";
    return os.str ();
  }


  /**
   * \fn Ouvrage::clone ()
   * \brief Retroune un pointeur allouée dynamiquement d'un objet Ouvrage
   * \return un pointeur allouée dynamiquement d'un objet Ouvrage
   */
  Reference*
  Ouvrage::clone () const
  {
    return new Ouvrage (*this);
  }


  /**
   * \brief Teste l'invariant de la classe Ouvrage. L'invariant de cette classe s'assure que l'Ouvrage est valide
   */
  void
  Ouvrage::verifieInvariant () const
  {
    INVARIANT (util::validerFormatNom (m_editeur));
    INVARIANT (util::validerFormatNom (m_ville));
    INVARIANT (util::validerCodeIsbn (Reference::reqIdentifiant ()));
  }
}
