#ifndef __SALLE_H__
#define __SALLE_H__

#define SALLES_FILE_NAME "data/salles"

#include <vector>
#include <iostream>

#include "fileutils.h"

class Salle
{
	public :
		static void init();
		static int getNbPlaces(int id);
		static int getNbPlacesPrises(int id);
		static void reserverPlace(int id);
		static void save();

	private :
		static FileUtils * fu;
};

#endif

