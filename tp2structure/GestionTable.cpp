//////////////////////////////////////////////////////////////////////////////////////////////////////////
//GestionTable.cpp
//fait par: frederic paquette et francis lemaire
//le 10 novembre 2014
//but: classe qui garde en memoire le meilleur client pour une table donee
//et le retourne
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "GestionTable.h"

GestionTable::GestionTable(Section laSection, int nbPlaces) :laSection_(laSection), nbPlaces_(nbPlaces)
{
	pMeilleurMatch = nullptr;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ClientEnAttente * GestionTable::getMeilleurMatch()
{
	return pMeilleurMatch;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool GestionTable::operator == (ClientEnAttente * client)
{
   if (client != nullptr)
   {
      //condition qui verifie si le client peu etre assis minimalement a la table
      if (client->GetClient().nbPersonnes <= nbPlaces_ && client->GetClient().sectionVoulu == laSection_)
      {
         if (pMeilleurMatch != nullptr)
         {
            if ((nbPlaces_ - client->GetClient().nbPersonnes) < nbPlaces_ - pMeilleurMatch->GetClient().nbPersonnes)
            {
               pMeilleurMatch = client; //Garde en mémoire le meilleur match
               if (nbPlaces_ == client->GetClient().nbPersonnes)
                  return true; //dit au programmes que le client est un match parfait
            }
         }
         else
            pMeilleurMatch = client;
      }
   }

	return false;		
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////