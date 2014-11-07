#include <string>
using namespace std;

#pragma once

class ClientEnAttente
{

private:
   struct Client
   {
      struct Section
      {
         bool teraceF;
         bool teraceNf;
         bool interieur;


      };

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
   void SetClient(Client c);
   void SetSuivant(ClientEnAttente* p);
   void Setprecedent(ClientEnAttente* p);
   ClientEnAttente* GetSuivant();
   ClientEnAttente* GetPrecedent();
   Client GetClient();
  
};