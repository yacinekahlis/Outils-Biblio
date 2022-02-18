/*
 * \File JournalInterface.h
 * \Author Yacine Kahlis
 * \brief Interface de la classe JournalInterface
 * \date 1 décembre 2021, 21:27
 */

#ifndef _JOURNALINTERFACE_H
#define _JOURNALINTERFACE_H

#include "ui_JournalInterface.h"

/**
 * \class JournalInterface
 * \brief Cette classe permet de gérer l'interface graphique de la fenetre JournalInterface. Elle hérite de QDialog
 */
class JournalInterface : public QDialog
{
  Q_OBJECT
public:
  JournalInterface ();
  virtual ~JournalInterface ();
  QString reqAuteurs () const;
  QString reqTitre () const;
  int reqAnnee () const;
  QString reqIssn () const;
  QString reqNom () const;
  int reqVolume () const;
  int reqNumero () const;
  int reqPage () const;


private slots:
  void valideEnregistrement ();


private:
  Ui::JournalInterface widget;
};

#endif /* _JOURNALINTERFACE_H */
