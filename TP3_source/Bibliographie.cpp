/**
 *\file Bibliographie.cpp
 * \brief Implantation de la classe Bibliographie
 * \author Yacine Kahlis
 *\date 15 novembre 2021, 16:16
 */

#include "ContratException.h"
#include "Bibliographie.h"
#include "validationFormat.h"
#include <sstream>
#include <cstring>

using namespace std;

namespace biblio
{


  /**
   * \fn  Bibliographie::Bibliographie (const std::string& p_nomBibliographie)
   * \brief Constructeur avec parametres. Il initialise les attributs avec les paramètres donnés en entré.
   * \param[in] p_nomBibliographie Le mom de la bibliographie
   * \pre p_nomBibliographie non vide
   * \post m_nomBibliographie prend la valeur de p_nomBibliographie
   * \post m_vReferences est un vecteur vide
   */
  Bibliographie::Bibliographie (const std::string& p_nomBibliographie) : m_nomBibliographie (p_nomBibliographie), m_vReferences ()
  {
    PRECONDITION (!p_nomBibliographie.empty ());
    POSTCONDITION (m_nomBibliographie == p_nomBibliographie);
    POSTCONDITION (m_vReferences.empty ());
    INVARIANTS ();
  }


  /**
   * \fn Bibliographie::reqNomBibliographie ()
   * \brief Acceseur pour le nom de la bibliographie
   * \return m_nomBibliographie Le nom de l'objet
   */
  const std::string
  Bibliographie::reqNomBibliographie () const
  {
    return m_nomBibliographie;
  }


  /**
   * \fn Bibliographie::referenceEstDejaPresente (const std::string& p_identifiant)
   * \param[in] p_reference Un objet reference
   * \brief Vérifie si un objet reference est deja present dans un objet bibliographie
   * \return present Un booléen
   */
  bool
  Bibliographie::referenceEstDejaPresente (const Reference& p_reference) const
  {
    bool present = false;
    for (vector<Reference*>::const_iterator it = m_vReferences.begin (); it != m_vReferences.end (); ++it)
      {
        if ((*(*it)) == p_reference)
          present = true;
      }
    return present;
  }


  /**
   * \fn Bibliographie::~Bibliographie ()
   * \brief Destructeur de la classe Bibliographie
   */
  Bibliographie::~Bibliographie ()
  {
    viderVecteur ();
  }


  /**
   * \fn Bibliographie::Bibliographie (const Bibliographie& p_bibliographie)
   * \param[in] p_bibliographie Un objet bibliographie
   * \brief Constructeur copie de la classe bibliographie
   */
  Bibliographie::Bibliographie (const Bibliographie& p_bibliographie) : m_nomBibliographie (p_bibliographie.m_nomBibliographie), m_vReferences (0)
  {
    this-> copierVecteur (p_bibliographie);
  }


  /**
   * \fn Bibliographie& Bibliographie::operator= (const Bibliographie& p_bibliographie)
   * \brief Retourne la valeur d'assignaation entre deux objet Biliographie
   * \param[in] p_bibliographie Un objet Bibliographie qui assigne sa valeur
   * \return L'objet bibliographie qui se fait assigner une nouvelle valeur
   */
  const Bibliographie& Bibliographie::operator= (const Bibliographie& p_bibliographie)
  {
    if (this != &p_bibliographie)
      {
        this->m_nomBibliographie.clear ();
        this->viderVecteur ();

        this->m_nomBibliographie = p_bibliographie.m_nomBibliographie;
        this->copierVecteur (p_bibliographie);

      }
    return *this;
  }


  /**
   * \fn Bibliographie::copierVecteur (const Bibliographie& p_source)
   * \brief Copie le vecteur source dans un vecteur destination de deux objets bibliographie
   * \param[in] p_source Un objet Bibliographie
   * \pre m_vReferences vide
   */
  void
  Bibliographie::copierVecteur (const Bibliographie& p_source)
  {
    PRECONDITION (m_vReferences.empty ());
    for (vector<Reference*>::const_iterator it = p_source.m_vReferences.begin (); it != p_source.m_vReferences.end (); ++it)
      {
        ajouterReference ((*(*it)));
      }
  }


  /**
   * \fn Bibliographie::viderVecteur ()
   * \brief Vide le vecteur d'un objet bibliographie
   */
  void
  Bibliographie::viderVecteur ()
  {
    for (vector<Reference*>::const_iterator it = m_vReferences.begin (); it != m_vReferences.end (); ++it)
      {
        delete (*it);
      }

    m_vReferences.clear ();
  }


  /**
   * \fn Bibliographie::ajouterReference (const Reference& p_nouvelleReference)
   * \brief Ajoute un pointeur d'une réfenrence dans le vecteur d'un objet Bibliographie s'il n'est pas déjà dedans
   * \param[in] p_nouvelleReference Un objet Réference
   */
  void
  Bibliographie::ajouterReference (const Reference& p_nouvelleReference)
  {
    if (!referenceEstDejaPresente (p_nouvelleReference))
      m_vReferences.push_back (p_nouvelleReference.clone ());
  }


  /**
   * \fn Bibliographie::reqBibliographieFormate ()
   * \brief Retourne une chaine de caractere signifiant les valeurs de l'instance
   * \return un string qui contient l'information de la Bibliographie
   */
  std::string
  Bibliographie::reqBibliographieFormate () const
  {
    int i = 1;
    std::ostringstream os;
    os << reqNomBibliographie () << endl << "===============================" << endl;
    for (vector<Reference*>::const_iterator it = m_vReferences.begin (); it != m_vReferences.end (); ++it)
      {
        os << "[" << i << "] " << (*it)->reqReferenceFormate () << endl;
        i++;
      }
    return os.str ();
  }


  /**
   * \fn Bibliographie::supprimerReference (const std::string& p_identifiant)
   * param[in] p_identifiant L'identifant de la reference à supprimer
   * \brief Supprime la référence liée a l'identifant donné
   */
  void
  Bibliographie::supprimerReference (const std::string& p_identifiant)
  {
    bool continuer = true;
    for (auto it  = m_vReferences.begin (); it != m_vReferences.end () and continuer == true; it++)
      {
        if ((*(*it)).reqIdentifiant () == p_identifiant)
          {
            delete (*it);
            m_vReferences.erase (it);
            continuer = false;
          }
      }
  }


  /**
   * \brief Teste l'invariant de la classe Bibliographie. L'invariant de cette classe s'assure que le Bibliographie est valide
   */
  void
  Bibliographie::verifieInvariant () const
  {
    INVARIANT (!m_nomBibliographie.empty ());
  }
}