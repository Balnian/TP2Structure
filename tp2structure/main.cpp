
#include "FonctionRechercheMenu.h"


int main()
{
   FileAttente file;
  
    while (true)
     {
		Wait();

	   try
	   {
		   Menu(file);
		 
	   }
	   catch (exception e)
	   {
		   cout << e.what();
	   }

     }
   }
     
   
    
   
 
   
   
   







