/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   OuvrageInterface.cpp
 * Author: etudiant
 *
 * Created on 1 décembre 2021, 21:14
 */

#include "OuvrageInterface.h"
#include "QMessageBox"
#include "validationFormat.h"


/**
 * \fn OuvrageInterface::OuvrageInterface ()
 * \brief Constructeur de la classe OuvrageInterface
 */
OuvrageInterface::OuvrageInterface ()
{
  widget.setupUi (this);
}


/**
 * \fn OuvrageInterface::~OuvrageInterface ()
 * \brief Destructeur de la classe OuvrageInterface
 */
OuvrageInterface::~OuvrageInterface () { }


/**
 * \fn OuvrageInterface::reqAuteurs ()
 * \brief Acceseur pour le nom des auteurs de l'ouvrage du widget Auteurs
 * \return Les auteurs de l'objet
 */
QString
OuvrageInterface::reqAuteurs () const
{
  return widget.Auteurs->text ();
}


/**
 * \fn OuvrageInterface::reqTitre ()
 * \brief Acceseur pour le titre de l'ouvrage du widget Titre
 * \return Le titre de l'objet
 */
QString
OuvrageInterface::reqTitre () const
{
  return widget.Titre->text ();
}


/**
 * \fn OuvrageInterface::reqVille ()
 * \brief Acceseur pour la ville de l'ouvrage du widget Ville
 * \return La ville de l'objet
 */
QString
OuvrageInterface::reqVille () const
{
  return widget.Ville->text ();
}


/**
 * \fn OuvrageInterface::reqEditeur ()
 * \brief Acceseur pour l'editeur de l'ouvrage du widget Editeur
 * \return L'editeur de l'objet
 */
QString
OuvrageInterface::reqEditeur () const
{
  return widget.Editeur->text ();
}


/**
 * \fn OuvrageInterface::reqIsbn ()
 * \brief Acceseur pour l'isbn de l'ouvrage du widget Isbn
 * \return L'isbn de l'objet
 */
QString
OuvrageInterface::reqIsbn () const
{
  return widget.Isbn->text ();
}


/**
 * \fn OuvrageInterface::reqAnnee ()
 * \brief Acceseur pour l'annee de l'ouvrage du widget Annee
 * \return L'annee de l'objet
 */
int
OuvrageInterface::reqAnnee () const
{
  return widget.Annee->value ();
}


/**
 * \fn OuvrageInterface::valideEnregistrement ()
 * \brief Enregistre les données saisies par l'utilisateur et les vérifies
 */
void
OuvrageInterface::valideEnregistrement ()
{
  if (!util::validerFormatNom (reqAuteurs ().toStdString ()))
    {
      QString message ("Le nom de(s) auteur(s) n'est pas valide, recommencez");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }

  if (reqTitre ().isEmpty ())
    {
      QString message ("Le titre n'est pas valide, recommencez");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }

  if (!util::validerFormatNom (reqVille ().toStdString ()))
    {
      QString message ("La ville n'est pas valide, recommencez");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }

  if (!util::validerFormatNom (reqEditeur ().toStdString ()))
    {
      QString message ("L'éditeur n'est pas valide, recommencez");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }

  if (!util::validerCodeIsbn (reqIsbn ().toStdString ()))
    {
      QString message ("Le code Isbn n'est pas valide, recommencez");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }

  if (reqAnnee () <= 0)
    {
      QString message ("L'année n'est pas valide, recommencez");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }


  accept ();
}





