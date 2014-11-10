#pragma once
#include "Section.h"
#include "ClientEnAttente.h"

class GestionTable
{
   int nbPlaces_;
   Section laSection_;
   ClientEnAttente * pMeilleurMatch;
public:
   GestionTable(Section laSection, int nbPlaces):laSection_(laSection),nbPlaces_(nbPlaces);
   ~GestionTable();
   bool operator == (ClientEnAttente * client);

};
