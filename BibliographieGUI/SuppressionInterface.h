/*
 * \File SuppressionInterface.h
 * \Author Yacine Kahlis
 * \brief Interface de la classe SuppressionInterface
 * \date 1 décembre 2021, 21:31
 */


#ifndef _SUPPRESSIONINTERFACE_H
#define _SUPPRESSIONINTERFACE_H

#include "ui_SuppressionInterface.h"

/**
 * \class SuppressionInterface
 * \brief Cette classe permet de gérer l'interface graphique de la fenetre SuppressionInterface. Elle hérite de QDialog
 */
class SuppressionInterface : public QDialog
{
  Q_OBJECT
public:
  SuppressionInterface ();
  virtual ~SuppressionInterface ();
  QString reqIdentifiant () const;

private slots:
  void valideEnregistrement ();


private:
  Ui::SuppressionInterface widget;
};

#endif /* _SUPPRESSIONINTERFACE_H */
