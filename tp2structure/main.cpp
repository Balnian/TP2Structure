#include "FileAttente.h"
#include <iostream>
using namespace std;


int main()
{

   
    
   for (size_t i = 0; i <100000; i++)
   {
      FileAttente* file=new FileAttente();
      for (size_t y = 0; y < 40; y++)
      {
         try
         {




            file->AjouterClient("bob", 2);
            file->AjouterClient("bill", 2);
            file->AjouterClient("bertrand", 2);
            file->AjouterClient("ginette", 2);



            file->RetirerClient();
            file->RetirerClient();



           
        }
         catch (exception e)
         {
            e.what();
         }
      
       }
	  delete file;
      cout << i << " ";
   }
   








}