#ifndef __FILEUTILS_H__
#define __FILEUTILS_H__

#include <vector>
#include <map>
#include <iostream>
#include <fstream>
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

	private :
		vector<string> * getLines();
		string filename;
		map<int, string> lines;
		
};

#endif

