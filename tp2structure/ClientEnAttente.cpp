#include "ClientEnAttente.h"

//constructeur par defaut de la struct client
ClientEnAttente::Client::Client()
{
   nom = "";
   nbPersonnes = 0;

  

}
//////////////////////////////////////////////////////////////////////////////////////////////////////

ClientEnAttente::ClientEnAttente()
{
   SetSuivant(nullptr);
   Setprecedent(nullptr);
   
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

ClientEnAttente::ClientEnAttente(string nom, int nbPersonnes)
{
   SetSuivant(nullptr);
   Setprecedent(nullptr);
   client_.nom = nom;
   client_.nbPersonnes = nbPersonnes;

}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void ClientEnAttente::SetSuivant(ClientEnAttente* p)
{
    
      pSuivant_ = p;

}
void ClientEnAttente::Setprecedent(ClientEnAttente* p)
{
      pPrecedent_ = p;
}
ClientEnAttente* ClientEnAttente::GetSuivant()
{
     return pSuivant_;
}
ClientEnAttente* ClientEnAttente::GetPrecedent()
{
   
      return pPrecedent_;

}
ClientEnAttente::Client ClientEnAttente::GetClient()
{
   return client_;
}


void ClientEnAttente::SetNom(string nom)
{
	client_.nom = nom;
}
void ClientEnAttente::SetNbPersonnes(int nbPersonnes)
{
	client_.nbPersonnes = nbPersonnes;
}
void ClientEnAttente::SetSection(Section sectionVoulu)
{
	client_.sectionVoulu = sectionVoulu;
}

