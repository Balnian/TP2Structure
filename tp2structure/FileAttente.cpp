/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FileAttendte.cpp
//fait par frederic paquette et francis lemaire
//le 10 novembre 2014
//but: File doublement chainer qui gere des client en attente dans un restaurent
// ajoute les client a la file carge un pointeur sur le premeir et le derniere client 
// retire un client avec les conditions voulue ou un client qui quitte
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "FileAttente.h"
#include <sstream>
#include <iostream>
using namespace std;

FileAttente::FileAttente()
{
	SetDernierClient(nullptr);
	SetPremierClient(nullptr);
	SetNbClient(0);
	SetNbGroupe(0);
	SetNbgroupeServie(0);
}
/////////////////////////////////////////////////////////////////////////////////////////
void FileAttente::SetNbGroupe(int nb)
{
	nbGroup_ = nb;
}
////////////////////////////////////////////////////////////////////////////////////////
void FileAttente::SetNbgroupeServie(int nb)
{
	nbGroupServie_ = nb;
}
////////////////////////////////////////////////////////////////////////////////////////
int FileAttente::GetNbGroupe() const
{
	return nbGroup_;
}
/////////////////////////////////////////////////////////////////////////////////////////
int FileAttente::GetNbGroupeServie() const
{
	return nbGroupServie_;
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
////////////////////////////////////////////////////////////////////////////////////////
ClientEnAttente* FileAttente::GetPremier() const
{
	return  pPremierClient_;
}
////////////////////////////////////////////////////////////////////////////////////////
void FileAttente::SetNbClient(int nb)
{
	nbClient_ = nb;
}
///////////////////////////////////////////////////////////////////////////////////////
bool FileAttente::FileVide() const
{
	return GetPremier() == nullptr;
}
///////////////////////////////////////////////////////////////////////////////////////
int  FileAttente::GetNbClient() const
{
	return nbClient_;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void  FileAttente::AjouterClient(ClientEnAttente client)
{
	//cree le client avec les information demander a l'utilisateur
	ClientEnAttente* pclientTampo = new ClientEnAttente();
	*pclientTampo = client;

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

	SetNbGroupe(GetNbGroupe() + 1);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
ClientEnAttente  FileAttente::RetirerClient(int nbpersonne, Section laSection)
{
	ClientEnAttente* clientAretirer = GetPremier();
	ClientEnAttente clientRetirer;

	GestionTable latable(laSection, nbpersonne);
	if (FileVide())
		throw exception("Liste Vide.....!!!!...");

	//temp quil n'y a pas un match parfait on continue et si le pointeur n'est pas = a la fin de la file
	while (clientAretirer != nullptr && !(latable == clientAretirer)) //
	{
		clientAretirer = clientAretirer->GetSuivant();
	}
	if (latable.getMeilleurMatch() != nullptr)
	{
		//attribue le nom et le nombre de personne au client retirer
		clientRetirer = *latable.getMeilleurMatch();
		RetirerClient(latable.getMeilleurMatch()->GetClient().nom, latable.getMeilleurMatch()->GetClient().nbPersonnes);

		SetNbgroupeServie(GetNbGroupeServie() + 1);
		SetNbClient(GetNbClient() + clientRetirer.GetClient().nbPersonnes);
	}
	else
		throw exception("Personne ne veux/peux etre sur cette table....Bruler la!!!!!");

	return clientRetirer;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void FileAttente::AfficherFile(ostream& sortie) const
{

	int i = 1;

	if (FileVide())
		throw exception("liste vide...");

	while (i <= GetNbGroupe())
	{
		sortie << GetClient(i) << endl;
		i++;
	}

	
}
////////////////////////////////////////////////////////////////////

string FileAttente::GetClient(int indice) const
{
	ClientEnAttente * client;
	string leClient;
	stringstream ss;
	int i = 1;

	client = GetPremier();

	if (FileVide())
		throw exception("liste vide...");

	if (GetNbGroupe() < indice)
		throw exception("indice trop grand...");

	while (i < indice)
	{
		client = client->GetSuivant();
		i++;
	}

	leClient = client->GetClient().nom + " ";

	ss << client->GetClient().nbPersonnes;
	leClient += "pour " + ss.str() + ((client->GetClient().nbPersonnes > 1) ? " personnes" : " personne");
	leClient += " dans la section ";
	leClient += ((client->GetClient().sectionVoulu.interieur) ? "salle a manger" : "");
	leClient += ((client->GetClient().sectionVoulu.interieur && client->GetClient().sectionVoulu.teraceF) ? ", " : "");
	leClient += ((client->GetClient().sectionVoulu.teraceF) ? "terrasse fumeur" : "");
	leClient += ((client->GetClient().sectionVoulu.teraceF && client->GetClient().sectionVoulu.teraceNf) ? ", " : "");
	leClient += ((client->GetClient().sectionVoulu.teraceNf) ? "terrasse non fumeur" : "");
	leClient += ".";
	return leClient;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
bool FileAttente::RetirerClient(string nom, int nbpersonnes)
{
	ClientEnAttente* clientAretirer = GetPremier();
	bool trouver = false;

	if (FileVide())
		throw exception("Liste Vide.....!!!!...");

	while (clientAretirer != nullptr && !trouver)
	{
		if (MettreEnMajuscules(clientAretirer->GetClient().nom) == MettreEnMajuscules(nom)
					&& clientAretirer->GetClient().nbPersonnes == nbpersonnes)
		{
			trouver = true;
			SupprimerClient(clientAretirer);
		}
		else
			clientAretirer = clientAretirer->GetSuivant();
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
void FileAttente::SupprimerClient(ClientEnAttente* clientAretirer)
{
	if (clientAretirer == GetPremier())
	{
		SetPremierClient(clientAretirer->GetSuivant());
		(GetPremier() != nullptr) ? clientAretirer->GetSuivant()->Setprecedent(nullptr) : SetDernierClient(nullptr);
	}
	else if (clientAretirer == GetDernier())
	{
		clientAretirer->GetPrecedent()->SetSuivant(nullptr);
		SetDernierClient(clientAretirer->GetPrecedent());
	}
	else
	{
		clientAretirer->GetPrecedent()->SetSuivant(clientAretirer->GetSuivant());
		clientAretirer->GetSuivant()->Setprecedent(clientAretirer->GetPrecedent());
	}
	
	SetNbGroupe(GetNbGroupe() - 1);
	delete clientAretirer;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
FileAttente::~FileAttente()
{

	if (GetPremier() != nullptr)
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