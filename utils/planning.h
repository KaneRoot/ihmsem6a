#ifndef __PLANNING_H__
#define __PLANNING_H__

#define PLANNING_FILE_NAME "../data/planning"

#define PLANNING_ID_ID				0
#define PLANNING_SALLE_ID			1
#define PLANNING_FILM_ID			2
#define PLANNING_HORAIRE_ID			3
#define PLANNING_PLACES_PRISES_ID	4

#include <vector>
#include <iostream>
#include "fileutils.h"

using namespace std;

class Planning
{
	public :	
		static void init();
		static int getId(int id_film, int id_salle);
		static int reserverPlace(int id_film, int id_salle, int horaire);
		static int getNbPlacesPrises(int id_film, int id_salle, int id_horaire);
		static void save();

	private :
		static FileUtils * fu;
};

#endif

#endif

