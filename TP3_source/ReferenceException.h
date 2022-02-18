/**
 *\file ReferenceException.h
 * \brief Fichier contenant la déclaration de la classe ReferenceException et de ses héritiers
 * \author Yacine Kahlis
 *\date 1 décembre 2021, 19:58
 */

#ifndef REFERENCEEXCEPTION_H
#define REFERENCEEXCEPTION_H
#include <stdexcept>
#include <string>

/**
 * \class ReferenceException
 * \brief Classe de base des exceptions de Reference.
 */
class ReferenceException : public std::runtime_error
{
public:
  ReferenceException (const std::string& p_raison);
};

/**
 * \class ReferenceDejaPresenteException
 * \brief Classe dérivé des exceptions de Reference.
 */
class ReferenceDejaPresenteException : public ReferenceException
{
public:
  ReferenceDejaPresenteException (const std::string& p_raison);
};

/**
 * \class ReferenceAbsenteException
 * \brief Classe dérivé des exceptions de Reference.
 */
class ReferenceAbsenteException : public ReferenceException
{
public:
  ReferenceAbsenteException (const std::string& p_raison);
};


#endif /* REFERENCEEXCEPTION_H */

