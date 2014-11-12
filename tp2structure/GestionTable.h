/////////////////////////////////////////////////////////////////////////////////////////////////////
//Gestiontable.h
//fait par Frederic paquette et francis lemaire
//le 10 novembre 2014
//but: classe qui prend en paramettre le nombre de place et la section pour une table
// et qui retourne le meilleur client pour la table
////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Section.h"
#include "ClientEnAttente.h"

class GestionTable
{
   int nbPlaces_;
   Section laSection_;
   ClientEnAttente * pMeilleurMatch; //pointeur qui pointe sur le meilleur client actuelle
public:
	GestionTable(Section laSection, int nbPlaces);
   ClientEnAttente * getMeilleurMatch();
   bool operator == (ClientEnAttente * client);

};
