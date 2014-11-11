
#include "FonctionRechercheMenu.h"


int main()
{


   FileAttente file;
   bool finProgramme = false;
  

      while (!finProgramme)
      {
         try
         {
        
          finProgramme =  Menu(file);
            
          }
         catch (exception e)
         {
            cout << e.what() << endl;
            Wait();
         }

     }
   
  
}

   
    
   
 
   
   
   







