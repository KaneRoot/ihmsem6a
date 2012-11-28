
#include "fileutils.h"

using namespace std;

void file_utils()
{
	FileUtils f("../data/films");
	f.init();
	cout << f.get(1,1) << endl;
	vector<string> vs;
	vs.push_back("bla");
	vs.push_back("truc");
	f.add(vs);
	f.display();
	f.del(3);
	f.display();
}

int main(int argc, char **argv)
{
}
