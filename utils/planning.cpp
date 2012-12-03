#include "planning.h"

FileUtils * Planning::fu = NULL;

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
	vector<int> ids = Planning::fu->getIDs();
	for(size_t i(0) ; i < ids.size() ; i++)
	{
		int x = ids.at(i);
		int id_f = lexical_cast<int>(fu->get(x, PLANNING_FILM_ID)); if(id_f != id_film) continue;
		int id_s = lexical_cast<int>(fu->get(x, PLANNING_SALLE_ID)); if(id_s != id_salle) continue;
		int id_h = lexical_cast<int>(fu->get(x, PLANNING_HORAIRE_ID)); if(id_h != id_horaire) continue;
		return x;
	}
	return -1;
}

int Planning::getNbPlacesPrises(int id_planning)
{
	return lexical_cast<int>(fu->get(id_planning, PLANNING_PLACES_PRISES_ID));
}

vector<int> Planning::getHorairesLibresFilm(int id_film)
{
	vector<int> horaires;
	vector<int> ids = Planning::fu->getIDs();
	int x;			// l'id du planning en cours
	int idf;		// id du film en cours
	int salle;	// id de la salle
	int horaire;	// horaire trouvée
	bool trouve(false);
	for(size_t i(0) ; i < ids.size() ; i++)
	{
		x = ids.at(i);
		idf = lexical_cast<int>(fu->get(x, PLANNING_FILM_ID)); if(idf != id_film) continue;
		horaire = lexical_cast<int>(fu->get(x, PLANNING_HORAIRE_ID));
		salle = lexical_cast<int>(fu->get(x, PLANNING_SALLE_ID));
		if(Planning::getNbPlacesRestantes(id_film, salle, horaire) <= 0)
			continue;
		
		for(size_t j(0) ; j < horaires.size() && ! trouve; j++)
		{
			if(horaires.at(j) == horaire)
				trouve = true;
		}
		if(! trouve)
			horaires.push_back(horaire);
		trouve = false;
	}
	return horaires;
}

vector<int> Planning::getHorairesFilm(int id_film)
{
	vector<int> horaires;
	vector<int> ids = Planning::fu->getIDs();
	int x;			// l'id du planning en cours
	int idf;		// id du film en cours
	int horaire;	// horaire trouvée
	bool trouve(false);
	for(size_t i(0) ; i < ids.size() ; i++)
	{
		x = ids.at(i);
		idf = lexical_cast<int>(fu->get(x, PLANNING_FILM_ID)); if(idf != id_film) continue;
		horaire = lexical_cast<int>(fu->get(x, PLANNING_HORAIRE_ID));
		for(size_t j(0) ; j < horaires.size() && ! trouve; j++)
		{
			if(horaires.at(j) == horaire)
				trouve = true;
		}
		if(! trouve)
			horaires.push_back(horaire);
		trouve = false;
	}
	return horaires;
}

int Planning::getNbPlacesRestantes(int id_film, int id_salle, int id_horaire)
{
	int prises = getNbPlacesPrises(id_film, id_salle, id_horaire);
	return Salle::getNbPlaces(id_salle) - prises;
}
int Planning::getNbPlacesPrises(int id_film, int id_salle, int id_horaire)
{
	int id = getId(id_film, id_salle, id_horaire);
	return Planning::getNbPlacesPrises(id);
}

bool Planning::reserverPlace(int id_film, int id_salle, int id_horaire)
{
	int id = Planning::getId(id_film, id_salle, id_horaire);
	int nb_places = getNbPlacesPrises(id_film, id_salle, id_horaire);
	if(nb_places <= 0)
		return false;
	nb_places--;
	fu->set(id, PLANNING_PLACES_PRISES_ID, lexical_cast<string>(nb_places));
	return true;
}

void Planning::save()
{
	fu->write();
}
