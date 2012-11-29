#ifndef __FILM_H__
#define __FILM_H__

#include <vector>
#include <map>
#include <iostream>

#include "fileutils.h"

#define MOVIE_FILE_NAME		"./films"
#define MOVIE_NAME_ID		1
#define MOVIE_TYPE_ID		2
#define MOVIE_3D_ID			3
#define MOVIE_DUREE_ID		4
#define MOVIE_SYNOPSIS_ID	5
#define MOVIE_ACTORS_ID		6
#define MOVIE_REAL_ID		7
#define MOVIE_HORAIRES_ID	8
#define MOVIE_BASE_PRICE_ID	9

using namespace std;

class Film
{
	public :
		Film();
		Film(int id);
		virtual ~Film();

		string getName();
		bool is3d();
		int getTypeId();
		string getTypeName();
		int getBasePrice();
		string getSynopsis();
		vector<string> getActors();
		string getActorsString();
		vector<int> getHoraires();
		
		void setName(string name);
		void set3d(bool is3d);
		void setTypeId();
		void setBasePrice(int base_price);
		void setSynopsis(string s);
		void setActors(vector<string> actors);
		void setActors(string actors);
		void setHoraires(vector<int> h);

	private :
		static FileUtils * fu;
		int id;
		map<int,string> film_construct;
};

#endif

