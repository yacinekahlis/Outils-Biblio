/*
 * \File ReferenceInterface.h
 * \Author Yacine Kahlis
 * \brief Interface de la classe ReferenceInterface
 * \date 1 décembre 2021, 20:51
 */

#ifndef _REFERENCEINTERFACE_H
#define _REFERENCEINTERFACE_H

#include "ui_ReferenceInterface.h"
#include <string>
#include "Bibliographie.h"
#include <vector>

/**
 * \class ReferenceInterface
 * \brief Cette classe permet de gérer l'interface graphique de la fenetre ReferenceInterface. Elle hérite de QMainWindow
 */
class ReferenceInterface : public QMainWindow
{
  Q_OBJECT
public:
  ReferenceInterface ();
  virtual ~ReferenceInterface ();

private slots:
  void dialogOuvrage ();
  void dialogJournal ();
  void dialogSuppression ();

private:
  Ui::ReferenceInterface widget;
  biblio::Bibliographie m_bibliographie;
  std::vector<std::string> m_vIdentifiant;
};

#endif /* _REFERENCEINTERFACE_H */
