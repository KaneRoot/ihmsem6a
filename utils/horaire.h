#ifndef __HORAIRE_H__
#define __HORAIRE_H__

#define HORAIRES_FILE_NAME "./data/creneaux"

#include <vector>
#include <iostream>
#include "fileutils.h"

using namespace std;

class Horaire
{
	public :	
		static void init();
		static string getHoraire(int id);
		static vector<int> getHorairesId();
		static vector<string> getHorairesString();
		static bool isHoraireExists(int id);

	private :
		static FileUtils * fu;
};

#endif
