#include "ClientEnAttente.h"

//constructeur par defaut de la struct client
ClientEnAttente::Client::Client()
{
   nom = "";
   nbPersonnes = 0;

   sectionVoulu.interieur = false;
   sectionVoulu.teraceF = false;
   sectionVoulu.teraceNf = false;

}
//////////////////////////////////////////////////////////////////////////////////////////////////////

ClientEnAttente::ClientEnAttente()
{
   SetSuivant(0);
   Setprecedent(0);
   
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
void ClientEnAttente::SetClient(Client c)
{
    client_.nom = c.nom;
    client_.nbPersonnes = c.nbPersonnes;
   
}

