/**
 *\file ValidationFormat.h
 * \brief Interface des fonctions de validation générale
 * \author Yacine Kahlis
 *\date 3 octobre 2021, 14:45
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H

#include <string>

namespace util
{
  bool validerFormatNom (const std::string& p_nom);
  bool validerCodeIssn (const std::string& p_issn);
  bool validerCodeIsbn (const std::string& p_isbn);
  bool calculCodeIsbn (const std::string p_isbn, const std::string& p_codeString);
} // namespace util

#endif /* VALIDATIONFORMAT_H */

