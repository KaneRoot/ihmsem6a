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

string Horaire::getHoraire(int id)
{
	return Horaire::fu->get(id, 1);
}
