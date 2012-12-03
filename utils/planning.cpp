#include "planning.h"

void Planning::init()
{
	if( Planning::fu == NULL)
	{
		string f(PLANNING_FILE_NAME);
		
		Planning::fu = new FileUtils(f);
		Planning::fu->init();
	}
}

int Planning::getId(int id_film, int id_salle, int id_horaire)
{
	Planning::init();
}

int Planning::getNbPlacesPrises(int id_film, int id_salle, int id_horaire)
{
	int id = getId(id_film, id_salle, id_horaire);
	return lexical_cast<int>(fu->get(id, PLANNING_PLACES_PRISES_ID));
}

void Planning::reserverPlace(int id_film, int id_salle, int horaire)
{
	fu->set(id_salle, PLANNING_PLACES_PRISES_ID, lexical_cast<string>(getNbPlacesPrises(id_film, id_salle, id_horaire)-1));
}

void Planning::save()
{
	fu->write();
}


