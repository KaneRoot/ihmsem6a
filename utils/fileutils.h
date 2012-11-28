#ifndef __FILEUTILS_H__
#define __FILEUTILS_H__

#include <vector>
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>

using namespace std;

class FileUtils
{
	public :
		FileUtils(string f);
		virtual ~FileUtils();
		
		string get(int id, int column);
	private :
		vector<string> * getLines();
		string filename;
		map<int, string> lines;
		
};

FileUtils::FileUtils(string f) : filename(f)
{
}

FileUtils::~FileUtils() { }

vector<string> * FileUtils::getLines()
{
	vector<string> * tab = new vector<string>;
	ifstream file(filename.c_str());
	string line;
	while(getline(file, line))
		tab->push_back(line);

	return tab;
}

void FileUtils::init()
{
	vector<string> * lines = getLines();
	string tmp;
	while(! lines.empty())
	{
		tmp = lines.pop();

	}
}

#endif

