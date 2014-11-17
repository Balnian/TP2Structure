//////////////////////////////////////////////////////////////////////////////////////////////////
//fonctionrecherchemenu.h
//fait par frederic paquette et francis lemaire 
//le 10 novembre 2014
//but: Fonction Qui affiche le menu et qui gere le menu
//et qui demande les information a l'utilisateur
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "FonctionRechercheMenu.h"


bool Menu(FileAttente& lafile)
{
	int choix;
   //Menu des choix
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	   return  DemandeFin(lafile);
      break;
   }

   Wait();
   return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DemanderInfo(FileAttente &lafile)
{
   //Demande toutes les info Pour un client
   //et le passe a la file

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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AfficherClient(FileAttente& lafile)
{
   //demande quelle numero de client que l'utilisateur veux
	int indice;

	cout << "Quelle clients voulez vous connaitre l'identiter? : ";
	cin >> indice;
	cout << "le client" << " " << indice << " " << "est " << lafile.GetClient(indice);
	

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DemanderInfoClientQuitte(FileAttente& lafile)
{

	string nom;
	int nbPersonnes;

	cout << "Nom du client qui quitte ? : ";
	cin >> nom;
	cout << "Combien de personne ?: ";
	cin >> nbPersonnes;

   //affiche le message en fonction si le retirer a marcher ou non
   if (lafile.RetirerClient(nom, nbPersonnes))
   {
      cout << nom << " " << "a ete retirer avec succes de la file" << endl;
   }
   else
      throw exception("Client introuvable impossible de retirer");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

  //seulement si la table a ete attribuer corectement
  cout << "la table a ete attribuer a " << leclient.GetClient().nom << " pour "<<leclient.GetClient().nbPersonnes;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Wait()
{
	cout << endl << "Any key to continue..." << endl;
	cin.ignore(cin.rdbuf()->in_avail() + 1);
	system("cls");
}

bool DemandeFin(FileAttente & lafile)
{
	string fin;
	if (lafile.GetNbGroupe() >= 1)
	{
		cout << "Ete vous sure de vouloir Quitter la file n'est pas vide o/n :";
		cin >> fin;
		if (fin == "o")
		{
			cout << endl;
			cout << "Nombre groupe servie " << lafile.GetNbGroupeServie() << endl;
			cout << "pour un total de " << lafile.GetNbClient() << " personnes" << endl;
			cout << "il reste " << lafile.GetNbGroupe() << " groupe dans la file " << endl;
			Wait();
			return true;
		}
		else
			return false;


	}

}
