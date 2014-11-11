#include "GestionTable.h"

GestionTable::GestionTable(Section laSection, int nbPlaces) :laSection_(laSection), nbPlaces_(nbPlaces)
{
	pMeilleurMatch = nullptr;
}
GestionTable::~GestionTable()
{
}
ClientEnAttente * GestionTable::getMeilleurMatch()
{
	return pMeilleurMatch;
}

bool GestionTable::operator == (ClientEnAttente * client)
{
	if (client!=nullptr)
	if (client->GetClient().nbPersonnes <= nbPlaces_ && client->GetClient().sectionVoulu == laSection_)
	{
		if (pMeilleurMatch != nullptr)
		{
			if ((nbPlaces_ - client->GetClient().nbPersonnes) < nbPlaces_ - pMeilleurMatch->GetClient().nbPersonnes)
			{
				pMeilleurMatch = client;
				if (nbPlaces_ == client->GetClient().nbPersonnes)
					return true;
			}
		}
		else
			pMeilleurMatch = client;

	}
	return false;
		
}