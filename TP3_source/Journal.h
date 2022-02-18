/**
 *\file Journal.h
 * \brief Interface de la classe Journal
 * \author Yacine Kahlis
 *\date 12 novembre 2021, 21:42
 */

#ifndef JOURNAL_H
#define JOURNAL_H

#include "Reference.h"
#include <string>

namespace biblio
{

  /**
   * \class journal
   * \brief Cette classe permet de construire un objet réference. Elle est dérivé de Reference.
   */
  class Journal : public Reference
  {
  public:
    Journal (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant, const std::string& p_nom, int p_volume, int p_numero, int p_page); //
    const std::string reqNom () const; //
    int reqVolume () const; //
    int reqNumero () const; //
    int reqPage () const; //
    virtual std::string reqReferenceFormate () const; //
    virtual Reference* clone () const; //

  private:
    std::string m_nom;
    int m_volume;
    int m_numero;
    int m_page;
    void verifieInvariant () const;
  };
} // namespace biblio



#endif /* JOURNAL_H */

