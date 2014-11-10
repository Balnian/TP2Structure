#include "GestionTable.h"


GestionTable::~GestionTable()
{
}
ClientEnAttente * GestionTable::getMeilleurMatch()
{
	return pMeilleurMatch;
}

bool GestionTable::operator == (ClientEnAttente * client)
{
	if (client->GetClient().nbPersonnes <= nbPlaces_ && client->GetClient().sectionVoulu == laSection_)
	{
		if (this->nbPlaces_ - client->GetClient().nbPersonnes < this->nbPlaces_ - this->pMeilleurMatch->GetClient().nbPersonnes)
		{
			this->pMeilleurMatch = client;
			if (this->nbPlaces_ == client->GetClient().nbPersonnes)
				return true;
		}
	}
	return false;
		
}