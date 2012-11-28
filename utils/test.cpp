
#include "fileutils.h"

using namespace std;

int main(int argc, char **argv)
{
	FileUtils f("../data/films");
	f.init();
	cout << f.get(1,1) << endl;
}	
