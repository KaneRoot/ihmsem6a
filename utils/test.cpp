
#include "fileutils.h"

using namespace std;

void file_utils()
{
	FileUtils f("./films");
	f.init();
	cout << f.get(1,1) << endl;
	vector<string> vs;
	vs.push_back("bla");
	vs.push_back("truc");
	f.add(vs);
	//f.display();
	//f.del(3);
	f.display();
	f.write();
}

int main(int argc, char **argv)
{
	file_utils();
}
