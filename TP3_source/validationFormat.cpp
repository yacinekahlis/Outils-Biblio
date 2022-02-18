/**
 * \file ValidationFormat.cpp
 * \brief Implementation des fonctions de validation
 * \author Yacine Kahlis
 * \date 3 octobre 2021, 15:25
 */
#include "validationFormat.h"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <array>
using namespace std;

namespace util
{


  bool
  validerFormatNom (const string& p_nom)
  {
    bool valide = true;
    if (p_nom.empty () or p_nom[0] == ' ' or p_nom[p_nom.size () - 1] == ' ')
      {
        valide = false;
      }

    else
      {
        for (int i = 0; i < p_nom.size (); i++)
          {

            if (!isalpha (p_nom[i]))
              {
                if (p_nom[i] == ' ' or p_nom[i] == '-') // l'élément est une lettre, un espace ou un tiret
                  {
                    if (i < p_nom.size () - 1) // dernier carac non atteint
                      {
                        if (p_nom[i + 1] == '-' or p_nom[i + 1] == ' ')   //
                          {
                            valide = false;
                            break;
                          }
                      }

                  }
                else
                  {
                    valide = false;
                    break;
                  }
              }
          }
      }
    return valide;
  }


  bool
  validerCodeIssn (const string& p_issn)
  {
    bool valide = false;
    string codeString;
    for (int i = 0; i < p_issn.length (); i++) //On prend slmt les nombres
      {
        if (isdigit (p_issn[i]))
          {
            codeString += p_issn[i];
          }
      }
    if (p_issn.substr (0, 5) == "ISSN " and p_issn[9] == '-' and codeString.length () == 8 and p_issn.length () == 14) //Le format est bon, on peut caluler la clef
      {
        int produit = 0;
        int clef = 0;
        for (int i = 0; i < codeString.length () - 1; i++)//On transforme les str en int
          {
            int j = codeString[i] - '0';
            produit += (j * (8 - i));
          }

        if (11 - (produit % 11) == 11) //Car qd le mod donne 0, la clef sera de 11, mais nous on
          {
            clef = 0;
          }

        else
          {
            clef = 11 - (produit % 11);
          }
        if (clef == p_issn[13] - '0')
          valide = true;
      }
    return valide;
  }


  bool
  validerCodeIsbn (const std::string& p_isbn)
  {
    bool valide = false;
    if (p_isbn.length () == 22)
      if (p_isbn.substr (0, 5) == "ISBN " and p_isbn[p_isbn.length () - 2] == '-' and isdigit (p_isbn[p_isbn.length () - 1]))
        {
          string codeString;
          for (int i = 0; i < p_isbn.length (); i++) //On prend slmt les nombres
            {
              if (isdigit (p_isbn[i]))
                {
                  codeString += p_isbn[i];
                }
            }
          if (codeString.length () == 13)
            {
              if (p_isbn.substr (5, 4) == "979-")
                {
                  string bT;
                  int j = 0;
                  while (p_isbn.substr (9, p_isbn.length () - 10)[j] != '-')
                    {
                      j++;
                      bT += p_isbn[j + 8];
                    }
                  if (bT == "0" or bT == "8" or bT == "10" or bT == "11" or bT == "12")
                    valide = calculCodeIsbn (p_isbn, codeString);
                }
              if (p_isbn.substr (5, 4) == "978-")
                {
                  string bT;
                  int j = 0;
                  while (p_isbn.substr (9, p_isbn.length () - 10)[j] != '-')
                    {
                      j++;
                      bT += p_isbn[j + 8];
                    }
                  if (bT.length () == 1)
                    {
                      if (bT == "0" or bT == "1" or bT == "2" or bT == "3" or bT == "4" or bT == "5" or bT == "7")
                        valide = calculCodeIsbn (p_isbn, codeString);
                    }
                  if (bT.length () == 2)
                    {
                      if (stoi (bT) >= 80 and stoi (bT) <= 94)
                        valide = calculCodeIsbn (p_isbn, codeString);
                    }
                  if (bT.length () == 3)
                    {
                      if (stoi (bT) >= 600 and stoi (bT) <= 649 or stoi (bT) >= 950 and stoi (bT) <= 989)
                        valide = calculCodeIsbn (p_isbn, codeString);
                    }
                  if (bT.length () == 4)
                    {
                      if (stoi (bT) >= 9900 and stoi (bT) <= 9989)
                        valide = calculCodeIsbn (p_isbn, codeString);
                    }
                  if (bT.length () == 5)
                    {
                      if (stoi (bT) >= 99900 and stoi (bT) <= 99999)
                        valide = calculCodeIsbn (p_isbn, codeString);
                    }
                }
            }
        }
    return valide;
  }


  bool
  calculCodeIsbn (const std::string p_isbn, const std::string& p_codeString)
  {
    int clef = 0;
    int produit = 0;
    bool validation = false;

    for (int i = 0; i < p_codeString.length () - 1; i++)
      {
        if (i % 2 == 0)
          produit += (p_codeString[i] - '0');
        else
          produit += 3 * (p_codeString[i] - '0');
      }
    if (10 - (produit % 10) == 10) //Car qd le mod donne 0, la clef sera de 11, mais nous on
      {
        clef = 0;
      }

    else
      {
        clef = 10 - (produit % 10);
      }
    if (clef == p_isbn[p_isbn.length () - 1] - '0')
      validation = true;

    return validation;
  }
}