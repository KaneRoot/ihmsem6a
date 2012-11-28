#include "fileutils.h"

using namespace std;
using namespace boost;

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

void print( vector <string> & v )
{
	for (size_t n = 0; n < v.size(); n++)
		cout << "\"" << v[ n ] << "\"\n";
	cout << endl;
}

void FileUtils::init()
{
	vector<string> * file_lines = getLines();
	string tmp;
	vector<string> fields;

	for(int i(0) ; i < file_lines->size() ; i++)
	{
		tmp = file_lines->at(i);
		split( fields, tmp, is_any_of( ";" ) );
		lines[i] = fields;
	}

	delete file_lines;
	/*
	for(int i(lines.size() -1) ; i >= 0 ; i--)
		print(lines[i]);
	*/
}

string FileUtils::get(int id, int column)
{
	for( int i(0) ; i < lines.size() ; i++)
		if( id == lexical_cast<int>( lines[i].at(0) ) )
			return lines[i].at(column);

	return NULL;
}
