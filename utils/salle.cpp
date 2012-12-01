#include "salle.h"

FileUtils * Salle::salles = NULL;

void Salle::init()
{
	if( Salle::salles == NULL)
	{
		string f(SALLES_FILE_NAME);
		
		Salle::salles = new FileUtils(f);
		Salle::salles->init();
	}
}

int Salle::getNbPlaces(int id)
{
	return lexical_cast<int>(salles->get(id,1));
}

int Salle::getNbPlacesPrises(int id)
{
	return lexical_cast<int>(salles->get(id,2));
}

void Salle::reserverPlace(int id_salle)
{
	salles->set(id_salle, 2, lexical_cast<string>(getNbPlacesPrises(id_salle)-1));
}
