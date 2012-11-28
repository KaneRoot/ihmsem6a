#ifndef __FILM_H__
#define __FILM_H__

#include <vector>
#include <iostream>

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

};

#endif

