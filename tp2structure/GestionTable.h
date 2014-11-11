#pragma once
#include "Section.h"
#include "ClientEnAttente.h"

class GestionTable
{
   int nbPlaces_;
   Section laSection_;
   ClientEnAttente * pMeilleurMatch;
public:
	GestionTable(Section laSection, int nbPlaces);
   ~GestionTable();
   ClientEnAttente * getMeilleurMatch();
   bool operator == (ClientEnAttente * client);


};
