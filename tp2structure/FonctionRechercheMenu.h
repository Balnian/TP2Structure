//////////////////////////////////////////////////////////////////////////////////////////////////
//fonctionrecherchemenu.h
//fait par frederic paquette et francis lemaire 
//le 10 novembre 2014
//but: Fonction Qui affiche le menu et qui gere le menu
//et qui demande les information a l'utilisateur
//////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <string>
#include "FileAttente.h"
using namespace std;


bool Menu(FileAttente &lafile);
bool GestionMenu(int choix, FileAttente & lafile);
void DemanderInfo(FileAttente &lafile);
void DemanderInfoClientQuitte(FileAttente& lafile);
void AfficherClient(FileAttente& lafile);
void InfoTable(FileAttente &lafile);
void GestionAttribution(FileAttente & lafile,int nbpersonnes, int choix);
void Wait();