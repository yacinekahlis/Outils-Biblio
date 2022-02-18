/*
 * File:   JournalInterface.cpp
 * Author: etudiant
 *
 * Created on 1 décembre 2021, 21:27
 */

#include "JournalInterface.h"
#include "QMessageBox"
#include "validationFormat.h"


/**
 * \fn JournalInterface::JournalInterface ()
 * \brief Constructeur de la classe JournalInterface
 */
JournalInterface::JournalInterface ()
{
  widget.setupUi (this);
}


/**
 * \fn JournalInterface::~JournalInterface ()
 * \brief Destructeur de la classe JournalInterface
 */
JournalInterface::~JournalInterface () { }


/**
 * \fn JournalInterface::reqNom ()
 * \brief Acceseur pour le nom du Journal du widget Nom
 * \return nom Le nom de l'objet
 */
QString
JournalInterface::reqNom () const
{
  return widget.Nom->text ();
}


/**
 * \fn JournalInterface::reqAuteurs ()
 * \brief Acceseur pour le nom des auteurs du Journal du widget Auteurs
 * \return Les auteurs de l'objet
 */
QString
JournalInterface::reqAuteurs () const
{
  return widget.Auteurs->text ();
}


/**
 * \fn JournalInterface::reqTitre ()
 * \brief Acceseur pour le Titre du Journal du widget Titre
 * \return Le titre de l'objet
 */
QString
JournalInterface::reqTitre () const
{
  return widget.Titre->text ();
}


/**
 * \fn JournalInterface::reqIssn ()
 * \brief Acceseur pour l'issn du Journal du widget Issn
 * \return L'issn nom de l'objet
 */
QString
JournalInterface::reqIssn () const
{
  return widget.Issn->text ();
}


/**
 * \fn JournalInterface::reqAnnee ()
 * \brief Acceseur pour l'année du Journal du widget Annee
 * \return L'annee de l'objet
 */
int
JournalInterface::reqAnnee () const
{
  return widget.Annee->value ();
}


/**
 * \fn JournalInterface::reqVolume ()
 * \brief Acceseur pour le volume du Journal du widget Volume
 * \return Le volume de l'objet
 */
int
JournalInterface::reqVolume () const
{
  return widget.Volume->value ();
}


/**
 * \fn JournalInterface::reqNumero ()
 * \brief Acceseur pour le numero du Journal du widget Numero
 * \return Le numero de l'objet
 */
int
JournalInterface::reqNumero () const
{
  return widget.Numero->value ();
}


/**
 * \fn JournalInterface::reqPage ()
 * \brief Acceseur pour la page du Journal du widget Page
 * \return La page de l'objet
 */
int
JournalInterface::reqPage () const
{
  return widget.Page->value ();
}


/**
 * \fn JournalInterface::valideEnregistrement ()
 * \brief Enregistre les données saisies par l'utilisateur et les vérifies
 */
void
JournalInterface::valideEnregistrement ()
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

  if (reqNom ().isEmpty ())
    {
      QString message ("Le nom n'est pas valide, recommencez");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }

  if (!util::validerCodeIssn (reqIssn ().toStdString ()))
    {
      QString message ("Le code Issn n'est pas valide, recommencez");
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