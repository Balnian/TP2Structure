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
   string MettreEnMajuscules(string nom) const;
   
  
   void SetNbClient(int nb);
   bool FileVide() const;

public:
   FileAttente();
   
   int GetNbClient() const;
   string GetClient(int indice);
   void AjouterClient(string nom,int nbPersonnes);
   ClientEnAttente RetirerClient(int nbpersonnes);
   bool RetirerClient(string nom, int nbpersonnes);

   void AfficherFile(ostream& sortie) const;
   ~FileAttente();



};