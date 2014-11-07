#include "FonctionRechercheMenu.h"
#include <iostream>
#include <string>
using namespace std;

void Menu(FileAttente& lafile)
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
  

   GestionMenu(choix,lafile);

}
void GestionMenu(int choix,FileAttente& lafile)
{
   switch (choix)
   {
   case 1: DemanderInfo(lafile);
      break;
   case 2: 
      break;
   case 3:
      break;
   case 4:
      break;
   case 5: lafile.AfficherFile(cout);
      break;
   case 6:
      break;

   default:
      break;
   }

}

void DemanderInfo(FileAttente &lafile)
{
   string nom;
   int nbPersonnes;

   cout << "Nom du client: ";
   cin >> nom;
   cout << endl;
   cout << "Pour combien de personnes: ";
   cin >> nbPersonnes;
  
   lafile.AjouterClient(nom, nbPersonnes);

}
void AssignerTable(FileAttente& lafile)
{

   bool Trouver = false;

   while (lafile.)







}