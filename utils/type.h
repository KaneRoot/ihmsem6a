#ifndef __TYPE_H__
#define __TYPE_H__

#define TYPES_FILE_NAME "../data/types"

#include <vector>
#include <iostream>
#include "fileutils.h"

using namespace std;

class Type
{
	public :	
		static string getType(int id);
		static void init();

	private :
		static FileUtils * types;
};

#endif

