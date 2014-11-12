/////////////////////////////////////////////////////////////////////////////////////////////////
//main.cpp
//fait par frederic paquette et francis lemaire
//le 10 novembre 2014
//but: boucle le menu jusqua la fin du programme qui est choisi par l'utilisateur dans le menu
///////////////////////////////////////////////////////////////////////////////////////////////

#include "FonctionRechercheMenu.h"

int main()
{

   FileAttente file;
   bool finProgramme = false;
 
      while (!finProgramme)
      {
         try
         {      
           finProgramme = Menu(file); //menu revoie une booleene qui vérifie la fin          
          }
         catch (exception e)
         {
            cout << e.what() << endl;
            Wait();
         }
     }  
  
}

   
    
   
 
   
   
   







