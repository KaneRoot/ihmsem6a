#include "horaire.h"

FileUtils * Horaire::fu = NULL;

void Horaire::init()
{
	if( Horaire::fu == NULL)
	{
		string f(HORAIRES_FILE_NAME);
		
		Horaire::fu = new FileUtils(f);
		Horaire::fu->init();
	}
}

vector<int> Horaire::getHorairesId()
{
	Horaire::init();
	return Horaire::fu->getIDs();
}

string Horaire::getHoraire(int id)
{
	Horaire::init();
	return Horaire::fu->get(id, 1);
}

vector<string> Horaire::getHorairesString()
{
	vector<int> ids = Horaire::getHorairesId();
	vector<string> les_horaires;
	for(size_t i(0) ; i < ids.size() ; i++)
	{
		les_horaires.push_back(Horaire::getHoraire(ids.at(i)));
	}
	return les_horaires;
}

bool Horaire::isHoraireExists(int id)
{
	Horaire::init();
	return Horaire::fu->isIdExists(id);
}
