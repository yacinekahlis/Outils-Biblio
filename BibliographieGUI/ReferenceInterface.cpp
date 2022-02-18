/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ReferenceInterface.cpp
 * Author: etudiant
 *
 * Created on 1 décembre 2021, 20:51
 */

#include "ReferenceInterface.h"
#include "OuvrageInterface.h"
#include "JournalInterface.h"
#include "SuppressionInterface.h"
#include "Ouvrage.h"
#include "Reference.h"
#include "Journal.h"
#include "ReferenceException.h"
#include "QMessageBox"

using namespace biblio;


/**
 * \fn ReferenceInterface::ReferenceInterface ()
 * \brief Constructeur de la classe ReferenceInterface
 */
ReferenceInterface::ReferenceInterface () : m_bibliographie ("La merveilleuse bibliographie"), m_vIdentifiant ()
{
  widget.setupUi (this);
}


/**
 * \fn ReferenceInterface::~ReferenceInterface ()
 * \brief Destructeur de la classe ReferenceInterface
 */
ReferenceInterface::~ReferenceInterface () { }


/**
 * \fn ReferenceInterface::dialogOuvrage ()
 * \brief Fenetre de dialog de l'ajout d'un ouvrage
 */
void
ReferenceInterface::dialogOuvrage ()
{
  OuvrageInterface OuvrageInt;
  if (OuvrageInt.exec ())
    {
      try
        {
          biblio::Ouvrage unOuvrage (OuvrageInt.reqAuteurs ().toStdString (),
                                     OuvrageInt.reqTitre ().toStdString (),
                                     OuvrageInt.reqAnnee (),
                                     OuvrageInt.reqIsbn ().toStdString (),
                                     OuvrageInt.reqEditeur ().toStdString (),
                                     OuvrageInt.reqVille ().toStdString ());
          if (m_bibliographie.referenceEstDejaPresente (unOuvrage))
            {
              throw ReferenceDejaPresenteException (unOuvrage.reqReferenceFormate ());
            }
          m_bibliographie.ajouterReference (unOuvrage);
          m_vIdentifiant.push_back (OuvrageInt.reqIsbn ().toStdString ());
        }
      catch (ReferenceDejaPresenteException& e)
        {


          QString message = e.what ();
          QMessageBox::information (this, "AJOUT D'UN DOUBLON", message);
        }
    }
  widget.Affichage->setText (m_bibliographie.reqBibliographieFormate ().c_str ());
}


/**
 * \fn ReferenceInterface::dialogJournal ()
 * \brief Fenetre de dialog de l'ajout d'un Journal
 */
void
ReferenceInterface::dialogJournal ()
{
  JournalInterface JournalInt;
  if (JournalInt.exec ())
    {
      try
        {
          biblio::Journal unJournal (JournalInt.reqAuteurs ().toStdString (),
                                     JournalInt.reqTitre ().toStdString (),
                                     JournalInt.reqAnnee (),
                                     JournalInt.reqIssn ().toStdString (),
                                     JournalInt.reqNom ().toStdString (),
                                     JournalInt.reqVolume (),
                                     JournalInt.reqNumero (),
                                     JournalInt.reqPage ());
          if (m_bibliographie.referenceEstDejaPresente (unJournal))
            {
              throw ReferenceDejaPresenteException (unJournal.reqReferenceFormate ());
            }
          m_bibliographie.ajouterReference (unJournal);
          m_vIdentifiant.push_back (JournalInt.reqIssn ().toStdString ());
        }
      catch (ReferenceDejaPresenteException& e)
        {


          QString message = e.what ();
          QMessageBox::information (this, "AJOUT D'UN DOUBLON", message);
        }

    }
  widget.Affichage->setText (m_bibliographie.reqBibliographieFormate ().c_str ());
}


/**
 * \fn ReferenceInterface::dialogSuppression ()
 * \brief Fenetre de dialog de la suppression d'une reference
 */
void
ReferenceInterface::dialogSuppression ()
{
  SuppressionInterface SuppressionInt;
  if (SuppressionInt.exec ())
    {
      try
        {
          bool present = false;
          bool continuer = true;
          for (std::vector<std::string>::const_iterator it = m_vIdentifiant.begin (); it != m_vIdentifiant.end (); ++it)
            {
              if ((*it) == SuppressionInt.reqIdentifiant ().toStdString ())
                present = true;
            }
          if (!present)
            {
              throw ReferenceAbsenteException (SuppressionInt.reqIdentifiant ().toStdString ());
            }
          m_bibliographie.supprimerReference (SuppressionInt.reqIdentifiant ().toStdString ());
          for (auto it  = m_vIdentifiant.begin (); it != m_vIdentifiant.end () and continuer == true; it++)
            {
              if ((*it) == SuppressionInt.reqIdentifiant ().toStdString ())
                {
                  m_vIdentifiant.erase (it);
                  continuer = false;
                }
            }
        }
      catch (ReferenceAbsenteException& e)
        {
          QString message = e.what ();
          QMessageBox::information (this, "ERREUR", message);
        }
    }
  widget.Affichage->setText (m_bibliographie.reqBibliographieFormate ().c_str ());
}
