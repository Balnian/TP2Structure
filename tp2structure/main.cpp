
#include "FonctionRechercheMenu.h"


int main()
{
   FileAttente file;
  
   while (true)
   {
	   try
	   {
       Menu(file);
	   Wait();
	   }
	   catch (exception e)
	   {
		   e.what();
	   }
	   
   }
     
   
    
   
 
   
   
   







}