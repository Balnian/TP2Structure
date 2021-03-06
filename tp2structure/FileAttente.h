/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FileAttendte.h
//fait par frederic paquette et francis lemaire
//le 10 novembre 2014
//but: File doublement chainer qui gere des client en attente dans un restaurent
// ajoute les client a la file carge un pointeur sur le premeir et le derniere client 
// retire un client avec les conditions voulue ou un client qui quitte
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#pragma warning (disable:4018)
#pragma warning (disable:4715)
#include "ClientEnAttente.h"
#include "GestionTable.h"

class FileAttente
{
private:
   ClientEnAttente * pPremierClient_;
   ClientEnAttente* pDernnierClient_;
   int nbClient_;
   int nbGroup_;
   int nbGroupServie_;

   void SetDernierClient(ClientEnAttente* p);
   ClientEnAttente* GetDernier() const;

   void SetPremierClient(ClientEnAttente* p);
   ClientEnAttente* GetPremier() const;
   string MettreEnMajuscules(string nom) const;
   void SupprimerClient(ClientEnAttente* clientAretirer);
 
  
   void SetNbClient(int nb);
   void SetNbGroupe(int nb);
   void SetNbgroupeServie(int nb);
   bool FileVide() const;

public:
   FileAttente();
   
     int GetNbClient() const;
	 int GetNbGroupe() const;
	 int GetNbGroupeServie() const;
   string GetClient(int indice) const;
   void AjouterClient(ClientEnAttente client);
   ClientEnAttente RetirerClient(int nbpersonnes,Section laSection);
   bool RetirerClient(string nom, int nbpersonnes);

   void AfficherFile(ostream& sortie) const;
   ~FileAttente();



};