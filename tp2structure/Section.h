#pragma once

struct Section
{
   bool teraceF = false;
   bool teraceNf = false;
   bool interieur = false;

   bool operator == (Section sect)
   {
	   bool estEgale=false;
	   estEgale |= this->teraceF == sect.teraceF;
	   estEgale |= this->teraceNf == sect.teraceNf;
	   estEgale |= this->interieur == sect.interieur;
	   return estEgale;

   }
   
};