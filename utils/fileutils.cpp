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
		lines[lexical_cast<int>(fields.at(0))] = fields;
	}

	delete file_lines;
	/*
	for(int i(lines.size() -1) ; i >= 0 ; i--)
		print(lines[i]);
	*/
}

string FileUtils::get(int id, int column)
{
	return (lines[id].size() == 0) ? string("-1") : lines[id].at(column);
}

void FileUtils::display()
{
	for(int i(0) ; i < lines.size() ; i++)
		print(lines.at(i));
}

vector<string> FileUtils::add(vector<string> v)
{
	for(int i(0) ; ; i++)
		if(lines[i].size() == 0)
		{
			ostringstream convert;
			convert << i;
			v.insert(v.begin(), convert.str() );
			lines[i] = v;
			return v;
		}
}

void FileUtils::del(int id)
{
	lines[id].clear();
}

void FileUtils::set(int id, vector<string> v)
{
	del(id);
	lines[id] = v;
}

void FileUtils::write()
{
	ofstream ofs;
	ofs.open(filename.c_str());
	for(int i(0) ; i < lines.size() ; i++)
	{
		for(int j(0) ; j < lines.at(i).size() ; j++)
		{
			ofs << lines.at(i).at(j);
			if(j + 1 != lines.at(i).size())
				ofs << ";";
		}
		ofs << endl;
	}
	ofs.close();
}
