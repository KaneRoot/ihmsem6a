#ifndef __HORAIRE_H__
#define __HORAIRE_H__

#include <vector>
#include <iostream>
#include "fileutils.h"

using namespace std;

class Horaire
{
	public :	
		static string getHoraire(int id);

	private :
		static vector<string> horaires;
};

#endif

