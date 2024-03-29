#include "salle.h"

FileUtils * Salle::fu = NULL;

void Salle::init()
{
	if( Salle::fu == NULL)
	{
		string f(SALLES_FILE_NAME);
		
		Salle::fu = new FileUtils(f);
		Salle::fu->init();
	}
}

bool Salle::isSalleExists(int id)
{
	Salle::init();
	return Salle::fu->isIdExists(id);
}

int Salle::getNbPlaces(int id)
{
	Salle::init();
	return lexical_cast<int>(fu->get(id,1));
}
