#pragma once
#include <iostream>
#include "FileAttente.h"
using namespace std;
void Menu(FileAttente &lafile);
void GestionMenu(int choix, FileAttente & lafile);
void DemanderInfo(FileAttente &lafile);
void AssignerTable(FileAttente& lafile);