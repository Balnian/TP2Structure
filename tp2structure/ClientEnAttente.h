/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//clientenattente.h
//fait par frederic paquette et francis lemaire
//le 10 novembre 2014
//but: classe contenant le noeuds  de la liste doublement chainer
//contient le nom du client le nombre de personnes dans le groupe
//les pointeurs sur le client precedent et suivant
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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