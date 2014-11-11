#pragma once
#include <iostream>
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