/*
 * \File OuvrageInterface.h
 * \Author Yacine Kahlis
 * \brief Interface de la classe OuvrageInterface
 * \date 1 décembre 2021, 21:14
 */

#ifndef _OUVRAGEINTERFACE_H
#define _OUVRAGEINTERFACE_H

#include "ui_OuvrageInterface.h"

/**
 * \class OuvrageInterface
 * \brief Cette classe permet de gérer l'interface graphique de la fenetre OuvrageInterface. Elle hérite de QDialog
 */
class OuvrageInterface : public QDialog
{
  Q_OBJECT
public:
  OuvrageInterface ();
  virtual ~OuvrageInterface ();

  QString reqAuteurs () const;
  QString reqTitre () const;
  QString reqVille () const;
  QString reqEditeur () const;
  QString reqIsbn () const;
  int reqAnnee () const;

private slots:
  void valideEnregistrement ();

private:
  Ui::OuvrageInterface widget;
};

#endif /* _OUVRAGEINTERFACE_H */
