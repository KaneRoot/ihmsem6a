#include "film.h"

using namespace std;
using namespace boost;

FileUtils * Film::fu = NULL;

Film::Film(int ident) : id(ident)
{
	string f(MOVIE_FILE_NAME);
	if(fu == NULL)
	{
		Film::fu = new FileUtils(f) ;
		Film::fu->init();
	}
}

Film::~Film() { }


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
	for(int i(0) ; i < actors.size() ; i++)
		stream << actors.at(i) << " " ;
	return stream.str();
}

vector<int> Film::getHoraires()
{
	vector<int> horaires;
	vector<string> fields;

	string tmp(Film::fu->get(id, MOVIE_HORAIRES_ID));
	split( fields, tmp, is_any_of( "-" ) );
	for(int i(0) ; i < fields.size() ; i++)
		horaires.push_back(lexical_cast<int>(fields.at(i)));

	return horaires;
}

void Film::setName(string name)
{
	film_construct[lexical_cast<int>(MOVIE_NAME_ID)].insert(0, name);
}

void Film::set3d(bool is3d)
{
	film_construct[MOVIE_3D_ID] = lexical_cast<string>(is3d);
}
void Film::setTypeId()
{
}
void Film::setBasePrice(int base_price)
{
}
void Film::setSynopsis(string s)
{
}
void Film::setActors(vector<string> actors)
{
}
void Film::setActors(string actors)
{
}
void Film::setHoraires(vector<int> h)
{
}
