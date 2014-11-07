#include "FileAttente.h"
#include <sstream>
FileAttente::FileAttente()
{
   SetDernierClient(nullptr);
   SetPremierClient(nullptr);
   SetNbClient(0);

}
void FileAttente::SetDernierClient(ClientEnAttente* p)
{

  
   pDernnierClient_ = p;
}
ClientEnAttente* FileAttente::GetDernier() const
{

   return pDernnierClient_;

}

void FileAttente::SetPremierClient(ClientEnAttente* p)
{
   pPremierClient_ = p;;
}
ClientEnAttente* FileAttente::GetPremier() const
{
   return  pPremierClient_;

}

void FileAttente::SetNbClient(int nb)
{
   nbClient_ = nb;


}
bool FileAttente::FileVide() const
{
   
   return GetPremier() == nullptr;

}
  

int  FileAttente::GetNbClient() const
{

   return nbClient_;

}

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
ClientEnAttente  FileAttente::RetirerClient()
{
   ClientEnAttente* clientAretirer = GetPremier();
   ClientEnAttente clientRetirer;

   if (clientAretirer == nullptr)
      throw exception("Liste Vide.....!!!!...");

   clientRetirer.SetClient(clientAretirer->GetClient());
   SetPremierClient(GetPremier()->GetSuivant());

   if (GetPremier() != nullptr)
   {
      GetPremier()->Setprecedent(nullptr);
   }
   else
   {
      SetDernierClient(nullptr);
   }

   delete clientAretirer;
   SetNbClient(GetNbClient() - 1);
   

   return clientRetirer;
}

void FileAttente::AfficherFile(ostream& sortie) const
{

   ClientEnAttente* lecture = GetPremier();


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
   int i = 0;

   if (GetPremier()!= nullptr)
   client = GetPremier();

   while (i < indice)
   {
      client = client->GetSuivant();
   }

   leClient = client->GetClient().nom + " ";

   ss << client->GetClient().nbPersonnes;
   leClient = ss.str();

  leClient = leClient + temp;

  return leClient;



}
/////////////////////////////////////////////////////////////////////////
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