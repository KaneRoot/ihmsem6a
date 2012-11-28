#include "fileutils.h"

//using namespace std;

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
	vector<string> * lines = getLines();
	string tmp;
	vector<string> fields;
	for(int i(0) ; i < lines->size() ; i++)
	{
		tmp = lines->at(i);

		split( fields, tmp, is_any_of( ";" ) );
		print(fields);
	}
}
