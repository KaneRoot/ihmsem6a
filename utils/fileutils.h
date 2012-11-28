#ifndef __FILEUTILS_H__
#define __FILEUTILS_H__

#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <string>

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

class FileUtils
{
	public :
		FileUtils(string f);
		virtual ~FileUtils();
		
		string get(int id, int column);
		void init();
		vector<string> add(vector<string>); // retourne le vecteur avec l'ID en première position
		void del(int id);
		void display();
		void set(int id, vector<string> v);
		void write(); // écrire tout ça dans le fichier

	private :
		vector<string> * getLines();
		string filename;
		map<int, vector<string> > lines;
		
};

#endif

