/**
 *\file Reference.h
 * \brief Interface de la classe Reference
 * \author Yacine Kahlis
 *\date 15 novembre 2021, 16:15
 */

#ifndef REFERENCE_H
#define REFERENCE_H

#include <string>

namespace biblio
{

  /**
   * \class Reference
   * \brief Cette classe permet de construire un objet réference.
   */
  class Reference
  {
  public:
    Reference (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant);
    const std::string reqAuteurs () const;
    const std::string reqTitre () const;
    int reqAnnee () const;
    const std::string reqIdentifiant () const;
    void asgAnnee (int p_annee);
    virtual std::string reqReferenceFormate () const = 0;
    bool operator== (const Reference& p_reference) const;
    virtual ~Reference ();
    virtual Reference* clone () const = 0;


  private:
    std::string m_auteurs;
    std::string m_titre;
    int m_annee;
    std::string m_identifiant;
    void verifieInvariant () const;
  };
} // namespace biblio

#endif /* REFERENCE_H */

