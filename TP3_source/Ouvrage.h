/**
 *\file Ouvrage.h
 * \brief Interface de la classe Ouvrage
 * \author Yacine Kahlis
 *\date 10 novembre 2021, 20:13
 */


#ifndef OUVRAGE_H
#define OUVRAGE_H

#include "Reference.h"

namespace biblio
{

  /**
   * \class Ouvrage
   * \brief Cette classe permet de gérer des ouvrages. Elle hérite de Reference
   */
  class Ouvrage : public Reference
  {
  public:
    Ouvrage (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant, const std::string& p_editeur, const std::string& p_ville); //
    const std::string reqEditeur () const; //
    const std::string reqVille () const; //
    virtual std::string reqReferenceFormate () const; //
    virtual Reference* clone () const;

  private:
    std::string m_editeur;
    std::string m_ville;
    void verifieInvariant () const;
  };
} // namespace biblio

#endif /* OUVRAGE_H */

