/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SuppressionInterface.cpp
 * Author: etudiant
 *
 * Created on 1 décembre 2021, 21:31
 */

#include "SuppressionInterface.h"
#include "QMessageBox"
#include "validationFormat.h"


/**
 * \fn SuppressionInterface::SuppressionInterface ()
 * \brief Constructeur de la classe SuppressionInterface
 */
SuppressionInterface::SuppressionInterface ()
{
  widget.setupUi (this);
}


/**
 * \fn SuppressionInterface::~SuppressionInterface ()
 * \brief Destructeur de la classe SuppressionInterface
 */
SuppressionInterface::~SuppressionInterface () { }


/**
 * \fn SuppressionInterface::reqIdentifiant ()
 * \brief Acceseur pour l'identifant du widget Identifiant
 * \return L'identifiant à supprimer
 */
QString
SuppressionInterface::reqIdentifiant () const
{
  return widget.Identifiant->text ();
}


/**
 * \fn SuppressionInterface::valideEnregistrement ()
 * \brief Enregistre les données saisies par l'utilisateur et les vérifies
 */
void
SuppressionInterface::valideEnregistrement ()
{
  if (!util::validerCodeIssn (reqIdentifiant ().toStdString ()) and !util::validerCodeIsbn (reqIdentifiant ().toStdString ()))
    {
      QString message ("L'identifiant n'est pas valide, recommencez");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }

  accept ();
}