#include"Section.h"
#include <string>
using namespace std;

#pragma once

class ClientEnAttente
{

private:
   struct Client
   {
      
      string nom;
      int nbPersonnes;
      Section sectionVoulu;

      Client();
   };

   Client client_;
   ClientEnAttente* pPrecedent_;
   ClientEnAttente* pSuivant_;
public:
   ClientEnAttente();
   ClientEnAttente(string nom,int nbPersonnes);
   void SetSuivant(ClientEnAttente* p);
   void Setprecedent(ClientEnAttente* p);
   ClientEnAttente* GetSuivant();
   ClientEnAttente* GetPrecedent();
   Client GetClient();
   void SetNom(string nom);
   void SetNbPersonnes(int nbPersonnes);
   void SetSection(Section sectionVoulu);
  
};