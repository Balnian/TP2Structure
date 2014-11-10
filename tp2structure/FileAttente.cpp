#include "FileAttente.h"
#include <sstream>
#include <iostream>
using namespace std;

FileAttente::FileAttente()
{
   SetDernierClient(nullptr);
   SetPremierClient(nullptr);
   SetNbClient(0);

}
/////////////////////////////////////////////////////////////////////////////////////
void FileAttente::SetDernierClient(ClientEnAttente* p)
{
	
   pDernnierClient_ = p;
}
////////////////////////////////////////////////////////////////////////////////////
ClientEnAttente* FileAttente::GetDernier() const
{

   return pDernnierClient_;

}
////////////////////////////////////////////////////////////////////////////////////////
void FileAttente::SetPremierClient(ClientEnAttente* p)
{
   pPremierClient_ = p;;
}
/////////////////////////////////////////////////////////////////////////////////////////////
ClientEnAttente* FileAttente::GetPremier() const
{
   return  pPremierClient_;

}
/////////////////////////////////////////////////////////////////////////////////////////////////
void FileAttente::SetNbClient(int nb)
{
   nbClient_ = nb;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
bool FileAttente::FileVide() const
{
   return GetPremier() == nullptr;
}
  
/////////////////////////////////////////////////////////////////////////////////////////////////////
int  FileAttente::GetNbClient() const
{

   return nbClient_;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void  FileAttente::AjouterClient(string nom,int nbPersonnes)
{
   ClientEnAttente* pclientTampo = new ClientEnAttente(nom, nbPersonnes);
   if (FileVide())
   {
      SetPremierClient(pclientTampo);
      SetDernierClient(pclientTampo);
   }
   else
   {
      pclientTampo->Setprecedent(GetDernier());
      GetDernier()->SetSuivant(pclientTampo);
      SetDernierClient(pclientTampo);
   }

   SetNbClient(GetNbClient() + 1);

}
/////////////////////////////////////////////////////////////////////////////////////////////////////
ClientEnAttente  FileAttente::RetirerClient(int nbpersonne , Section laSection)
{
   ClientEnAttente* clientAretirer = GetPremier();
   ClientEnAttente clientRetirer;

   if (clientAretirer == nullptr)
      throw exception("Liste Vide.....!!!!...");

   while (clientAretirer != nullptr)
   {
      if (clientAretirer->GetClient().nbPersonnes == nbpersonne
         && clientAretirer->GetClient().sectionVoulu == laSection)
      {
      }
      else
      {
        
      }

   }
  
   

   return clientRetirer;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void FileAttente::AfficherFile(ostream& sortie) const
{

   ClientEnAttente* lecture = GetPremier();
   if (lecture == nullptr)

	   throw exception("liste vide...");

   while (lecture != nullptr)
   {
      sortie << lecture->GetClient().nom << endl;
      lecture = lecture->GetSuivant();
   }
   
   sortie << GetNbClient() << endl;

}
////////////////////////////////////////////////////////////////////

string FileAttente::GetClient(int indice)
{
   ClientEnAttente * client;
   string leClient;
   string temp;
   stringstream ss;
   int i = 1;

   client = GetPremier();

   if (client == nullptr)
	   throw exception("liste vide...");


   while (i < indice)
   {
      client = client->GetSuivant();
	    i++; 
   }

   leClient = client->GetClient().nom + " ";

   /*ss << client->GetClient().nbPersonnes;w
   leClient = ss.str();

  leClient = leClient + temp;*/

  return leClient;



}
////////////////////////////////////////////////////////////////////////////////////////////////////
bool FileAttente::RetirerClient(string nom, int nbpersonnes)
{

	ClientEnAttente* clientAretirer = GetPremier();
	ClientEnAttente* temp;

	bool trouver = false;

	if (clientAretirer == nullptr)
		throw exception("Liste Vide.....!!!!...");


	
	while (clientAretirer!=nullptr && !trouver )
	{
		if (MettreEnMajuscules(clientAretirer->GetClient().nom) == MettreEnMajuscules(nom) 
                                                              && clientAretirer->GetClient().nbPersonnes == nbpersonnes)
		{
		
			
			trouver = true;
         if (clientAretirer->GetPrecedent() != nullptr)
            clientAretirer->GetPrecedent()->SetSuivant(clientAretirer->GetSuivant());
         else if (clientAretirer->GetSuivant() != nullptr)
         {
            clientAretirer->GetSuivant()->Setprecedent(nullptr);
            SetPremierClient(clientAretirer->GetSuivant());
         }
         else
         {
            SetPremierClient(nullptr);
            SetDernierClient(nullptr);
         }
        
         if (clientAretirer->GetSuivant()!=nullptr)        
			clientAretirer->GetSuivant()->Setprecedent(clientAretirer->GetPrecedent());
         else if (clientAretirer->GetPrecedent() != nullptr)
         {
            clientAretirer->GetPrecedent()->SetSuivant(nullptr);
            SetDernierClient(clientAretirer->GetPrecedent());
         }

			delete clientAretirer;



			SetNbClient(GetNbClient() - 1);		
			
		}
		else
		{
			clientAretirer = clientAretirer->GetSuivant();
			
		}
	}


	return trouver;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
string FileAttente::MettreEnMajuscules(string nom) const
{
	for (int i = 0; i < nom.size(); ++i)
	{
		nom[i] = toupper(nom[i]);
	}
	return nom;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
FileAttente::~FileAttente()
{
   
   if (GetPremier()!=nullptr)
   {
     ClientEnAttente* delitation = GetPremier();
     ClientEnAttente* prochainAmourir;

      while (delitation != nullptr)
      {
         prochainAmourir = delitation->GetSuivant();
         delete delitation;
         delitation = nullptr;
         delitation = prochainAmourir;
       }

   }

}