/**
 *\file Utilisation.cpp
 * \brief Programme principale d'utilisation de ma gestion de référence bibliographique
 * \author Yacine Kahlis
 *\date 15 novembre 2021, 16:05
 */

#include <cstdlib>
#include "Journal.h"
#include "Reference.h"
#include "Ouvrage.h"
#include "Bibliographie.h"
#include <iostream>
#include "validationFormat.h"

using namespace std;


int
main ()
{
  cout << "Bienvenue dans l'outil de gestion de references bibliographiques" << endl;
  cout << "================================================================" << endl;
  cout << "-------------------------------------------------------" << endl;
  cout << "Ajoutez un ouvrage" << endl;
  cout << "-------------------------------------------------------" << endl;

  biblio::Bibliographie uneBiblio ("La merveilleuse bibliographie!");

  bool auteurOuvrageValide = false;
  string auteurOuvrage;

  while (!auteurOuvrageValide)
    {
      char buffer[256];

      cout << "Entrez le nom du ou des auteurs :" << endl;
      cin.getline (buffer, 256);
      auteurOuvrage = buffer;

      if (util::validerFormatNom (auteurOuvrage))
        auteurOuvrageValide = true;
      else
        cout << "Le nom des auteurs ne doit pas être vide, recommencez" << endl;
    }


  bool titreOuvrageValide = false;
  string titreOuvrage;

  while (!titreOuvrageValide)
    {
      char buffer[256];

      cout << "Entrez le titre :" << endl;
      cin.getline (buffer, 256);
      titreOuvrage = buffer;

      if (!titreOuvrage.empty ())
        titreOuvrageValide = true;
      else
        cout << "Le titre n’est pas valide, recommencez" << endl;
    }

  bool villeValide = false;
  string ville;

  while (!villeValide)
    {
      char buffer[256];

      cout << "Entrez la ville d’édition:" << endl;
      cin.getline (buffer, 256);
      ville = buffer;

      if (util::validerFormatNom (ville))
        villeValide = true;
      else
        cout << "La ville n’est pas valide, recommencez" << endl;
    }

  bool editeurValide = false;
  string editeur;

  while (!editeurValide)
    {
      char buffer[256];

      cout << "Entrez l'éditeur :" << endl;
      cin.getline (buffer, 256);
      editeur = buffer;

      if (util::validerFormatNom (editeur))
        editeurValide = true;
      else
        cout << "L'éditeur n’est pas valide, recommencez" << endl;
    }

  bool anneeOuvrageValide = false;
  int anneeOuvrage;

  while (!anneeOuvrageValide)
    {
      char buffer[256];
      string anneeStr;

      cout << "Entrez l'année :" << endl;
      cin>> anneeStr;
      string codeStr;
      for (int i = 0; i < anneeStr.length (); i++)
        {
          if (!isdigit (anneeStr[i]))
            codeStr += anneeStr[i];
        }

      if (stoi (anneeStr) > 0)
        {
          anneeOuvrage = stoi (anneeStr);
          anneeOuvrageValide = true;
        }
      else
        cout << "L'année n’est pas valide, recommencez" << endl;
    }

  bool isbnValide = false;
  string isbn;

  while (!isbnValide)
    {
      char buffer[256];

      cout << "Entrez le code ISBN :" << endl;
      cin.ignore ();
      cin.getline (buffer, 256);
      isbn = buffer;

      if (util::validerCodeIsbn (isbn))
        isbnValide = true;
      else
        cout << "L'identifiant n’est pas valide, recommencez" << endl;
    }

  biblio::Ouvrage unOuvrage (auteurOuvrage, titreOuvrage, anneeOuvrage, isbn, editeur, ville);
  uneBiblio.ajouterReference (unOuvrage);

  cout << endl << "-------------------------------------------------------" << endl;
  cout << "Ajoutez un journal" << endl;
  cout << "-------------------------------------------------------" << endl;

  bool auteurJournalValide = false;
  string auteurJournal;

  while (!auteurJournalValide)
    {
      char buffer[256];

      cout << "Entrez le nom du ou des auteurs :" << endl;
      cin.getline (buffer, 256);
      auteurJournal = buffer;

      if (util::validerFormatNom (auteurJournal))
        auteurJournalValide = true;
      else
        cout << "Le nom des auteurs ne doit pas être vide, recommencez" << endl;
    }

  bool titreJournalValide = false;
  string titreJournal;

  while (!titreJournalValide)
    {
      char buffer[256];

      cout << "Entrez le titre :" << endl;
      cin.getline (buffer, 256);
      titreJournal = buffer;

      if (!titreJournal.empty ())
        titreJournalValide = true;
      else
        cout << "Le titre n’est pas valide, recommencez" << endl;
    }

  bool nomValide = false;
  string nom;

  while (!nomValide)
    {
      char buffer[256];

      cout << "Entrez le nom :" << endl;
      cin.getline (buffer, 256);
      nom = buffer;

      if (!nom.empty ())
        nomValide = true;
      else
        cout << "Le nom n’est pas valide, recommencez" << endl;
    }

  bool volumeValide = false;
  int volume;

  while (!volumeValide)
    {
      char buffer[256];
      string volumeStr;

      cout << "Entrez le volume :" << endl;
      cin>> volumeStr;
      string codeStr;


      for (int i = 0; i < volumeStr.length (); i++)
        {
          if (!isdigit (volumeStr[i]))
            codeStr += volumeStr[i];
        }

      if (stoi (volumeStr) > 0)
        {
          volume = stoi (volumeStr);
          volumeValide = true;
        }
      else
        cout << "Le volume n’est pas valide, recommencez" << endl;
    }

  bool numeroValide = false;
  int numero;

  while (!numeroValide)
    {
      char buffer[256];
      string numeroStr;

      cout << "Entrez le numero :" << endl;
      cin>> numeroStr;
      string codeStr;
      for (int i = 0; i < numeroStr.length (); i++)
        {
          if (!isdigit (numeroStr[i]))
            codeStr += numeroStr[i];
        }

      if (stoi (numeroStr) > 0)
        {
          numero = stoi (numeroStr);
          numeroValide = true;
        }
      else
        cout << "Le numéro n’est pas valide, recommencez" << endl;
    }

  bool pageValide = false;
  int page;

  while (!pageValide)
    {
      char buffer[256];
      string pageStr;

      cout << "Entrez la page où commence la référence :" << endl;
      cin>> pageStr;
      string codeStr;
      for (int i = 0; i < pageStr.length (); i++)
        {
          if (!isdigit (pageStr[i]))
            codeStr += pageStr[i];
        }

      if (stoi (pageStr) > 0)
        {
          page = stoi (pageStr);
          pageValide = true;
        }
      else
        cout << "La page n’est pas valide, recommencez" << endl;
    }

  bool anneeJournalValide = false;
  int anneeJournal;

  while (!anneeJournalValide)
    {
      char buffer[256];
      string anneeStr;

      cout << "Entrez une année valide" << endl;
      cin>> anneeStr;
      string codeStr;
      for (int i = 0; i < anneeStr.length (); i++)
        {
          if (!isdigit (anneeStr[i]))
            codeStr += anneeStr[i];
        }

      if (stoi (anneeStr) > 0)
        {
          anneeJournal = stoi (anneeStr);
          anneeJournalValide = true;
        }
      else
        cout << "L'année n’est pas valide, recommencez" << endl;
    }

  bool issnValide = false;
  string issn;

  while (!issnValide)
    {
      char buffer[256];

      cout << "Entrez le code ISSN :" << endl;
      cin.ignore ();
      cin.getline (buffer, 256);
      issn = buffer;

      if (util::validerCodeIssn (issn))
        issnValide = true;
      else
        cout << "L'identifiant n’est pas valide, recommencez" << endl;
    }

  biblio::Journal unJournal (auteurJournal, titreJournal, anneeJournal, issn, nom, volume, numero, page);
  uneBiblio.ajouterReference (unJournal);


  cout << endl << "Références bibliographiques enregistrées :" << endl;
  cout << uneBiblio.reqBibliographieFormate ();

  return 0;
}

