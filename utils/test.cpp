#include "fileutils.h"
#include "film.h"

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
	Film film(2);
	cout << "Film name : " << film.getName() << endl;
	if(film.is3d())
		cout << "Film en 3D" << endl;
	else
		cout << "Film non en 3D" << endl;

	cout << "Film synopsis : " << film.getSynopsis() << endl;
	cout << "Horaires : ";
	vector<int> horaires(film.getHoraires());
	for(int i(0) ; i < horaires.size() ; i++)
		cout << horaires.at(i) << " ";
	cout << endl;

	vector<string> actors(film.getActors());
	for(int i(0) ; i < actors.size() ; i++)
		cout << actors.at(i) << " ";
	cout << endl;

	cout << " En une seule ligne : " << film.getActorsString() << endl;
}

int main(int argc, char **argv)
{
	//file_utils();
	film_test();
}
