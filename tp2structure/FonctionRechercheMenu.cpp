#include "FonctionRechercheMenu.h"
#include <iostream>
#include <string>
using namespace std;

bool Menu(FileAttente& lafile)
{
	int choix;


   do
   {

   system("cls");
   cout << "1. Ajouter un Client"<<endl;
   cout << "2. Assigner une table" << endl;
   cout << "3. Retirer un Client" << endl;
   cout << "4. Afficher un client de la file" << endl;
   cout << "5. Afficher la file" << endl;
   cout << "6. Quitter le programme" << endl <<endl;
   cout << "Faite un choix: ";
   cin >> choix;
 
   } while (choix < 1 || choix > 6);
  
 
  return GestionMenu(choix,lafile);

}

bool GestionMenu(int choix,FileAttente& lafile)
{
	
   switch (choix)
   {
   case 1: 
  
      DemanderInfo(lafile);

      break;
   case 2:
    
	   InfoTable(lafile);
      break;
   case 3:  
    
      DemanderInfoClientQuitte(lafile);
      break;
   case 4: 
    
      AfficherClient(lafile);
      break;
   case 5:
     
      lafile.AfficherFile(cout);
      break;
  
   default:
      cout << "Bonne Journee" << endl;
      return true;
      break;
   }

   Wait();
   return false;
}

void DemanderInfo(FileAttente &lafile)
{
   string nom;
   int nbPersonnes;
   Section section;
   ClientEnAttente clientTempo;

   cout << "Nom du client: ";
   cin >> nom;
   cout << "Pour combien de personnes: ";
   cin >> nbPersonnes;

 
  
   system("cls");
   cout << "Dans quelles sections? (1=Oui, 0=Non)" << endl;
   cout << "Terrasse Fumeur: ";
   cin >> section.teraceF;
   cout <<endl<< "Terrasse Non Fumeur: ";
   cin >> section.teraceNf;
   cout << endl << "Interieur: ";
   cin >> section.interieur;

   clientTempo.SetNom(nom);
   clientTempo.SetNbPersonnes(nbPersonnes);
   clientTempo.SetSection(section);

   lafile.AjouterClient(clientTempo);

}

void AfficherClient(FileAttente& lafile)
{

	int indice;

	cout << "Quelle clients voulez vous connaitre l'identiter? : ";
	cin >> indice;
	cout << "le client" << " " << indice << " " << "est " << lafile.GetClient(indice);
	

}
void DemanderInfoClientQuitte(FileAttente& lafile)
{

	string nom;
	int nbPersonnes;

	cout << "Nom du client qui quitte ? : ";
	cin >> nom;
	cout << "Combien de personne ?: ";
	cin >> nbPersonnes;


   if (lafile.RetirerClient(nom, nbPersonnes))
   {
      cout << nom << " " << "a ete retirer avec succes de la file" << endl;
   }
   else
      throw exception("Client introuvable impossible de retirer");
}
void InfoTable(FileAttente &lafile)
{
   int nbPersonne;
   int section;
   
   do
   {

   system("cls");
   cout << "La table disponible est pour combien de personnes?: ";
   cin >> nbPersonne;

   cout << "La table ce trouve dans quelle section? : "<<endl;
   cout << "1.Terrace non Fumeur" << endl;
   cout << "2.Terrace fumeur" << endl;
   cout << "3. Salle a Manger" << endl;
   cout << ": ";
   cin >> section;

   } while (section < 1 || section > 3);

   GestionAttribution(lafile,nbPersonne, section);

}
void GestionAttribution(FileAttente & lafile,int nbpersonne, int choix)
{

   Section laSection;
   ClientEnAttente leclient;
   switch (choix)
   {
   case 1:
      laSection.teraceNf = true;
      break;
   case 2:
      laSection.teraceF = true;
      break;
   default:
      laSection.interieur = true;
      break;
   }

  leclient = lafile.RetirerClient(nbpersonne,laSection);

  cout << "la table a ete attribuer a " << leclient.GetClient().nom << " pour "<<leclient.GetClient().nbPersonnes;

}
void Wait()
{
	cout << endl << "Any key to continue..." << endl;
	cin.ignore(cin.rdbuf()->in_avail() + 1);
	system("cls");
}