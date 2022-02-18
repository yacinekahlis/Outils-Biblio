/**
 *\file Journal.cpp
 * \brief Implantation de la classe Journal
 * \author Yacine Kahlis
 *\date 12 novembre 2021, 21:57
 */

#include "Journal.h"
#include "validationFormat.h"
#include "ContratException.h"
#include <sstream>

namespace biblio
{


  /**
   * \fn Journal::Journal (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant, const std::string& p_nom, int p_volume, int p_numero, int              p_page)
   * \brief Constructeur avec parametres. Il initialise les attributs avec les paramètres donnés en entré.
   * \param[in] p_auteurs Le mom de l'auteur (ou du premier auteur s'ils sont plusieurs) l'ouvrage
   * \param[in] p_titre Le titre de l'ouvrage
   * \param[in] p_identifiant Le code Isbn de l'ouvrage
   * \param[in] p_annee L'année d'édtion de l'ouvrage
   * \param[in] p_nom Le nom du journal
   * \param[in] p_volume Le volume du journal
   * \param[in] p_numero Le numero du journal
   * \param[in] p_page La page du journal
   * \pre p_nom non vide
   * \pre p_identifiant valider par validerCodeIssn
   * \post m_nom prend la valeur de p_nom
   * \post m_numero prend la valeur de p_numero
   * \post m_page prend la valeur de p_page
   * \post m_volume prend la valeur de p_volume
   */

  Journal::Journal (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant, const std::string& p_nom, int p_volume, int p_numero, int p_page) :
  biblio::Reference (p_auteurs, p_titre, p_annee, p_identifiant), m_nom (p_nom), m_volume (p_volume), m_numero (p_numero), m_page (p_page)
  {
    PRECONDITION (!p_nom.empty ());
    PRECONDITION (util::validerCodeIssn (p_identifiant));
    POSTCONDITION (m_nom == p_nom);
    POSTCONDITION (m_numero == p_numero);
    POSTCONDITION (m_page == p_page);
    POSTCONDITION (m_volume == p_volume);
    INVARIANTS ();
  }


  /**
   * \fn Journal::reqNom ()
   * \brief Acceseur pour le nom
   * \return m_nom Le nom de l'objet
   */
  const std::string
  Journal::reqNom () const
  {
    return m_nom;
  }


  /**
   * \fn Journal::reqVolume ()
   * \brief Acceseur pour le volume
   * \return m_volume Le volume de l'objet
   */
  int
  Journal::reqVolume () const
  {
    return m_volume;
  }


  /**
   * \fn Journal::reqNumero ()
   * \brief Acceseur pour le numero
   * \return m_numero Le numero de l'objet
   */
  int
  Journal::reqNumero () const
  {
    return m_numero;
  }


  /**
   * \fn Journal::reqPage ()
   * \brief Acceseur pour la page
   * \return m_page La page de l'objet
   */
  int
  Journal::reqPage () const
  {
    return m_page;
  }


  /**
   * \fn Journal::reqReferenceFormate ()
   * \brief Retourne une chaine de caractere signifiant les valeurs de l'instance
   * \return un string qui contient l'information de l'ouvrage
   */
  std::string
  Journal::reqReferenceFormate () const
  {
    std::ostringstream os;
    os << Reference::reqAuteurs () << ". " << Reference::reqTitre () << ". " << reqNom () <<
            ", vol. " << reqVolume () << ", no. " << reqNumero () << ", pp. " <<
            reqPage () << ", " << Reference::reqAnnee () << ". " << Reference::reqIdentifiant () << ".";
    return os.str ();
  }


  /**
   * \fn Journal::clone ()
   * \brief Retroune un pointeur allouée dynamiquement d'un objet Journal
   * \return un pointeur allouée dynamiquement d'un objet Journal
   */
  Reference*
  Journal::clone () const
  {
    return new Journal (*this);
  }


  /**
   * \brief Teste l'invariant de la classe Journal. L'invariant de cette classe s'assure que le Journal est valide
   */
  void
  Journal::verifieInvariant () const
  {
    INVARIANT (!m_nom.empty ());
    INVARIANT (util::validerCodeIssn (Reference::reqIdentifiant ()));
  }
}