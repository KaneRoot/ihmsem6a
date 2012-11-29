#include "horaire.h"

FileUtils * Horaire::horaires = NULL;

void Horaire::init()
{
	if( Horaire::horaires == NULL)
	{
		string f(HORAIRES_FILE_NAME);
		
		Horaire::horaires = new FileUtils(f);
		Horaire::horaires->init();
	}
}

string Horaire::getHoraire(int id)
{
	return Horaire::horaires->get(id, 1);
}
