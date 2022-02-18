/*
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 1 décembre 2021, 20:50
 */

#include <QApplication>
#include <qt5/QtWidgets/qwidget.h>
#include "ReferenceInterface.h"


int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  // create and show your widgets here
  ReferenceInterface fenetrePrincipal;
  fenetrePrincipal.show ();

  return app.exec ();
}
