////////////////////////////////////////////////////////////////////////////////////////////////
//section.h
//fait par frederic et francis lemaire
//le 10 novembre 2014
//but : structure de bool pour savoir quelle section a ete choisi par le client
/////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once

struct Section
{
   bool teraceF = false;
   bool teraceNf = false;
   bool interieur = false;

   bool operator == (Section sect)
   {
      //Vérifie si la section de la table est = a une des sections choisis
	   bool estEgale=false;
	   estEgale |= this->teraceF == sect.teraceF;
	   estEgale |= this->teraceNf == sect.teraceNf;
	   estEgale |= this->interieur == sect.interieur;
	   return estEgale;

   }
   
};