#include "film.h"

using namespace std;
using namespace boost;

FileUtils * Film::fu = NULL;

Film::Film() : id(-1)
{
	Film::init();
}

Film::Film(int ident) : id(ident)
{
	Film::init();
}

int Film::getId()
{
	return id;
}

vector<Film> Film::getFilms()
{
	Film::init();
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

string Film::getTypeName()
{
	int type_id = getTypeId();
	Type::init();
	return Type::getType(type_id);
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
	Film::init();
	vector<string> actors_tmp;
	vector<string> actors;
	string tmp(Film::fu->get(id, MOVIE_ACTORS_ID));
	split( actors_tmp, tmp, is_any_of( "::" ) );
	for(size_t i(0) ; i < actors_tmp.size() ; i++)
		if(actors_tmp.at(i).size() > 0)
			actors.push_back(actors_tmp.at(i));
	return actors;
}

string Film::getActorsString()
{
	Film::init();
	ostringstream stream;
	vector<string> actors = getActors();
	for(unsigned int i(0) ; i < actors.size() ; i++)
		stream << actors.at(i) << " " ;
	return stream.str();
}

string Film::getRealisator()
{
	Film::init();
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
		if(actors.at(i).size() > 0)
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

void Film::save()
{
	Film::fu->write();
}

vector<Film> Film::getFilms_search_name(string expression)
{
	Film::init();
	vector<int> movies_ids = Film::getFilmsIds_search_name(expression);
	vector<Film> movies;
	for(size_t i(0) ; i < movies_ids.size() ; i++)
	{
		movies.push_back(Film(movies_ids.at(i)));
	}
	return movies;
}

vector<int> Film::getFilmsIds_search_name(string expression)
{
	Film::init();
	vector<int> movies_concerned;
	vector<int> films_ids = Film::fu->getIDs();
	for(size_t i(0) ; i < films_ids.size() ; i++)
	{
		string movie_name = Film::fu->get(films_ids.at(i), MOVIE_NAME_ID) ;
		if(string::npos != movie_name.find(expression))
		{
			movies_concerned.push_back(films_ids.at(i));
		}
	}

	return movies_concerned;
}

void Film::init()
{
	if(fu == NULL)
	{
		string f(MOVIE_FILE_NAME);
		Film::fu = new FileUtils(f) ;
		Film::fu->init();
	}
}

vector<int> Film::getHoraires()
{
	Planning::init();
	return Planning::getHorairesFilm(id);
}

vector<int> Film::getHorairesLibres()
{
	Planning::init();
	return Planning::getHorairesLibresFilm(id);
}

string Film::getHorairesString()
{
	vector<int> horaires = getHoraires();
	ostringstream stream;
	for(size_t i(0) ; i < horaires.size() ; i++)
	{
		stream << Horaire::getHoraire(horaires.at(i)) << " ";
	}
	return stream.str();
}

void Film::addFilm(
				string name, 
				int id_type, 
				bool is3d, 
				string duree, 
				string synopsis,  
				vector<string> actors, 
				string realisator, 
				int base_price)
{
	Film::init();
	ostringstream actors_string;
	for(size_t i(0) ; i < actors.size() ; i++)
		actors_string << actors.at(i) << "::";

	vector<string> movie_to_add;
	movie_to_add.push_back(name);
	movie_to_add.push_back(lexical_cast<string>(id_type));
	movie_to_add.push_back(lexical_cast<string>(is3d));
	movie_to_add.push_back(duree);
	movie_to_add.push_back(synopsis);
	movie_to_add.push_back(actors_string.str());
	movie_to_add.push_back(realisator);
	movie_to_add.push_back(lexical_cast<string>(base_price));

	Film::fu->add(movie_to_add);
}

void Film::addActor(string actor)
{
	if(id != -1)
	{
		vector<string> actors = getActors();
		actors.push_back(actor);
		setActors(actors);
	}
}

bool Film::isFilmExists(int id)
{
	Film::init();
	return Film::fu->isIdExists(id);
}

vector<Film> Film::getFilmsEnProjection()
{
	Film::init();
	vector<Film> films_en_projection;
	
	vector<Film> tous_les_films = getFilms();
	for(size_t i(0) ; i < tous_les_films.size() ; i++)
	{
		if(tous_les_films.at(i).getHoraires().size() != 0)
			films_en_projection.push_back(tous_les_films.at(i));
	}

	return films_en_projection;
}

void Film::delFilm(int id)
{
	Film::init();
	Film::fu->del(id);
}

void Film::afficher_tous_les_films()
{
	vector<Film> tous_les_films = getFilms();
	Film tmp;
	for(size_t i(0) ; i < tous_les_films.size() ; i++)
	{
		tmp = tous_les_films.at(i);
		cout << "id : " << tmp.getId() << " ";
		cout << "Nom : " << tmp.getName() << endl;
	}
}
