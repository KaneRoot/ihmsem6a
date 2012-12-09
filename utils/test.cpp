#include "fileutils.h"
#include "film.h"
#include "horaire.h"
#include "user.h"

using namespace std;

void file_utils()
{
	FileUtils f("./films");
	f.init();
	cout << f.get(1,1) << endl;
	vector<string> vs;
	vs.push_back("bla");
	vs.push_back("truc");
	f.add(vs);
	//f.display();
	//f.del(3);
	f.display();
	f.write();
}

void film_test()
{
	Film film(1);
	cout << "Film name : " << film.getName() << endl;
	if(film.is3d())
		cout << "Film en 3D" << endl;
	else
		cout << "Film non en 3D" << endl;

	cout << "Film synopsis : " << film.getSynopsis() << endl;
	cout << "Horaires : ";

	vector<string> actors(film.getActors());
	for(unsigned int i(0) ; i < actors.size() ; i++)
		cout << actors.at(i) << " ";
	cout << endl;

	cout << " En une seule ligne : " << film.getActorsString() << endl;
	film.setName(string("Coucou"));
	cout << "Film name : " << film.getName() << endl;
	film.save();
}

void get_films()
{
	vector<Film> films = Film::getFilms();
	vector<Film>::iterator it;
	for( it=films.begin() ; it != films.end(); it++ )
	{
		cout << "Nom : " << (*it).getName() << endl;
		cout << "Type : " << (*it).getTypeName() << " :: " << it->getTypeId() << endl;
	}
}

void utilisateurs()
{
	User::init();
	if(User::isRealUser(string("moi"), string("toi")))
		cout << "Ça mARCHe" << endl;
	else
		cout << "Ça mARCHe PAS" << endl;
}

void search_films()
{
	Film::init();
	string expression("pas copain");
	vector<Film> films = Film::getFilms_search_name(expression);
	for(size_t i(0) ; i < films.size() ; i++)
	{
		cout << "Nom film : " << films.at(i).getName() << endl;
		cout << "Acteurs : " << films.at(i).getActorsString() << endl;
	}
}

void ajout_acteur()
{
	vector<Film> films = Film::getFilms_search_name("pas copain");
	for(size_t i(0) ; i < films.size(); i++)
	{
		cout << "ON a trouvé un film !!!!!!" << endl;
		films.at(i).addActor("Jean Paul");
	}
	Film::save();
	search_films();
}

void del_film()
{
	Film::init();
	string expression("pas copain");
	vector<Film> films = Film::getFilms_search_name(expression);
	for(size_t i(0) ; i < films.size() ; i++)
	{
		cout << "Nom film : " << films.at(i).getName() << endl;
		cout << "Acteurs : " << films.at(i).getActorsString() << endl;
		cout << "On delete " << endl;
		Film::delFilm(films.at(i).getId());
	}
	Film::save();
}

void add_film()
{
	del_film();
	vector<string> acteurs;
	acteurs.push_back("Chon Coe"); acteurs.push_back("The destroyer"); acteurs.push_back("Mimie Matthie");
	Film::addFilm( "pas copain", 1, false, "5h","the synopsis",  
					acteurs, "Le réalisateur" , 50);
	Film::save();
	search_films();
}

void get_horaires_ids()
{
	vector<int> hids = Horaire::getHorairesId();
	cout << "Horaire ID : " ;
	for(size_t i(0) ; i < hids.size() ; i++)
	{
		cout << " " << hids.at(i);
	}
	cout << endl;
}

void add_horaire_film(int argc, char **argv)
{
	Planning::init();
	if(argc != 4)
	{
		cout << "./main id_film id_salle id_horaire" << endl;
		return;
	}
	int id_film = lexical_cast<int>(argv[1]);
	int id_salle = lexical_cast<int>(argv[2]);
	int id_horaire = lexical_cast<int>(argv[3]);
	//cout << "Salle " << id_salle << " horaire : " << id_horaire << " : " << Planning::isSalleFree(id_salle, id_horaire) << endl;

	Planning::addHoraireFilm(id_film, id_salle, id_horaire);
}

int main(int argc, char **argv)
{
	//file_utils();
	//film_test();
	//get_films();
	//utilisateurs();
	//search_films();
	//test_planning();
	//ajout_acteur();
	//del_film();
	//add_film();
	//get_horaires_ids();
	add_horaire_film(argc, argv);
}
