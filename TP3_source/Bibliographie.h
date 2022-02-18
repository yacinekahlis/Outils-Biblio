/**
 *\file Bibliographie.h
 * \brief Interface de la classe Bibliographie
 * \author Yacine Kahlis
 *\date 15 novembre 2021, 15:31
 */

#ifndef BIBLIOGRAPHIE_H
#define BIBLIOGRAPHIE_H

#include "ContratException.h"
#include "Reference.h"
#include <vector>
#include "Ouvrage.h"
#include "Journal.h"


namespace biblio
{

  /**
   * \class Bibliographie
   * \brief Cette classe permet de construire un objet bibliographie.
   */
  class Bibliographie
  {
  public:
    Bibliographie (const std::string& p_nomBibliographie); //
    ~Bibliographie (); //
    Bibliographie (const Bibliographie& p_bibliographie); //
    const Bibliographie& operator= (const Bibliographie& p_bibliographie); //
    const std::string reqNomBibliographie () const; //
    void ajouterReference (const Reference& p_nouvelleReference); //
    void supprimerReference (const std::string& p_identifiant);
    std::string reqBibliographieFormate () const; //
    bool referenceEstDejaPresente (const Reference& p_reference) const;

  private:
    std::string m_nomBibliographie;
    std::vector<Reference*> m_vReferences;
    //fait
    void copierVecteur (const Bibliographie& p_source);
    void viderVecteur ();
    void verifieInvariant () const;
  };
} // namespace biblio
#endif /* BIBLIOGRAPHIE_H */

