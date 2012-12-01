#include "film.h"

using namespace std;
using namespace boost;

FileUtils * Film::fu = NULL;

Film::Film() : id(-1)
{
	if(fu == NULL)
	{
		string f(MOVIE_FILE_NAME);
		Film::fu = new FileUtils(f) ;
		Film::fu->init();
	}
}

Film::Film(int ident) : id(ident)
{
	if(fu == NULL)
	{
		string f(MOVIE_FILE_NAME);
		Film::fu = new FileUtils(f) ;
		Film::fu->init();
	}
}

vector<Film> Film::getFilms()
{
	if(fu == NULL)
	{
		string f(MOVIE_FILE_NAME);
		Film::fu = new FileUtils(f) ;
		Film::fu->init();
	}
	vector<Film> films;
	vector<int> identifiants = Film::fu->getIDs();
	for(unsigned int i(0) ; i < identifiants.size() ; i++)
		films.push_back(Film(identifiants[i]));

	return films;
}

Film::~Film() { }

/**	GETTERS **/
string Film::getName()
{
	return Film::fu->get(id, MOVIE_NAME_ID);
}

bool Film::is3d()
{
	return lexical_cast<bool>(Film::fu->get(id, MOVIE_3D_ID));
}

int Film::getTypeId()
{
	return lexical_cast<int>(Film::fu->get(id, MOVIE_TYPE_ID));
}

string Film::getTypeName() // TODO
{
	return Film::fu->get(id, MOVIE_TYPE_ID);
}

int Film::getBasePrice()
{
	return lexical_cast<int>(Film::fu->get(id, MOVIE_BASE_PRICE_ID));
}

string Film::getSynopsis()
{
	return fu->get(id, MOVIE_SYNOPSIS_ID);
}

vector<string> Film::getActors()
{
	vector<string> actors;
	string tmp(Film::fu->get(id, MOVIE_ACTORS_ID));
	split( actors, tmp, is_any_of( "::" ) );
	return actors;
}

string Film::getActorsString()
{
	ostringstream stream;
	vector<string> actors = getActors();
	for(unsigned int i(0) ; i < actors.size() ; i++)
		stream << actors.at(i) << " " ;
	return stream.str();
}

vector<int> Film::getHoraires()
{
	vector<int> horaires;
	vector<string> fields;

	string tmp(Film::fu->get(id, MOVIE_HORAIRES_ID));
	split( fields, tmp, is_any_of( "-" ) );
	for(unsigned int i(0) ; i < fields.size() ; i++)
		horaires.push_back(lexical_cast<int>(fields.at(i)));

	return horaires;
}

string Film::getRealisator()
{
	return Film::fu->get(id, MOVIE_REAL_ID);
}

/**	SETTERS **/
void Film::setName(string name)
{
	if(id == -1)
		film_construct[lexical_cast<int>(MOVIE_NAME_ID)].insert(0, name);
	else
		Film::fu->set(id, MOVIE_NAME_ID, name);
}

void Film::set3d(bool is3d)
{
	if(id == -1)
		film_construct[lexical_cast<int>(MOVIE_3D_ID)] = lexical_cast<string>(is3d);
	else
		Film::fu->set(id, MOVIE_3D_ID, lexical_cast<string>(is3d));
}

void Film::setTypeId(int idType)
{
	if(id == -1)
		film_construct[lexical_cast<int>(MOVIE_TYPE_ID)] = lexical_cast<string>(idType);
	else
		Film::fu->set(id, MOVIE_TYPE_ID, lexical_cast<string>(idType));
}

void Film::setBasePrice(int base_price)
{
	if(id == -1)
		film_construct[lexical_cast<int>(MOVIE_BASE_PRICE_ID)] = lexical_cast<string>(base_price);
	else
		Film::fu->set(id, MOVIE_BASE_PRICE_ID, lexical_cast<string>(base_price));
}

void Film::setSynopsis(string s)
{
	if(id == -1)
		film_construct[lexical_cast<int>(MOVIE_SYNOPSIS_ID)].insert(0, s);
	else
		Film::fu->set(id, MOVIE_SYNOPSIS_ID, s);
}

void Film::setActors(vector<string> actors)
{
	ostringstream stream;
	for(unsigned int i(0) ; i < actors.size() ; i++)
	{
		stream << actors.at(i) << "::";
	}
	setActors(stream.str());
}

void Film::setActors(string actors)
{
	if(id == -1)
		film_construct[lexical_cast<int>(MOVIE_ACTORS_ID)].insert(0, actors);
	else
		Film::fu->set(id, MOVIE_ACTORS_ID, actors);
}

void Film::setRealisator(string realisator)
{
	if(id == -1)
		film_construct[lexical_cast<int>(MOVIE_REAL_ID)].insert(0, realisator);
	else
		Film::fu->set(id, MOVIE_REAL_ID, realisator);
}

void Film::setHoraires(vector<int> h)
{
	ostringstream stream;
	for(unsigned int i(0) ; i < h.size() ; i++)
	{
		stream << h.at(i) << "-";
	}
	setHoraires(stream.str());
}

void Film::setHoraires(string h)
{
	if(id == -1)
		film_construct[lexical_cast<int>(MOVIE_HORAIRES_ID)].insert(0, h);
	else
		Film::fu->set(id, MOVIE_HORAIRES_ID, h);
}

void Film::save()
{
	Film::fu->write();
}
