/**
 *\file ReferenceException.cpp
 * \brief
 * \author Yacine Kahlis
 *\date 1 décembre 2021, 19:58
 */

#include "ReferenceException.h"


ReferenceException::ReferenceException (const std::string& p_raison) : std::runtime_error (p_raison) { }


ReferenceDejaPresenteException::ReferenceDejaPresenteException (const std::string& p_raison) : ReferenceException (p_raison) { }


ReferenceAbsenteException::ReferenceAbsenteException (const std::string& p_raison) : ReferenceException (p_raison) { }
