#pragma once
#include "ClientEnAttente.h"

class FileAttente
{
private:
   ClientEnAttente * pPremierClient_;
   ClientEnAttente* pDernnierClient_;
   int nbClient_;

   void SetDernierClient(ClientEnAttente* p);
   ClientEnAttente* GetDernier() const;

   void SetPremierClient(ClientEnAttente* p);
   ClientEnAttente* GetPremier() const;

   void SetNbClient(int nb);
   bool FileVide() const;

public:
   FileAttente();
   
   int GetNbClient() const;

   void AjouterClient(string nom,int nbPersonnes);
   ClientEnAttente RetirerClient();

   void AfficherFile(ostream& sortie) const;
   ~FileAttente();



};