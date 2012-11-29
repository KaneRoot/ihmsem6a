#include "film.h"

using namespace std;
using namespace boost;

Film::Film(int id)
{
	string f(MOVIE_FILE_NAME);
	fu = new FileUtils(f) ;
	fu->init();
}

Film::~Film() { }


/*
string Film::getName()
{
}
bool Film::is3d()
{
}
int Film::getTypeId()
{
}
string Film::getTypeName()
{
}
int Film::getBasePrice()
{
}
string Film::getSynopsis()
{
}
vector<string> Film::getActors()
{
}
string Film::getActorsString()
{
}
vector<int> Film::getHoraires()
{
}
*/
void Film::setName(string name)
{
}
void Film::set3d(bool is3d)
{
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
