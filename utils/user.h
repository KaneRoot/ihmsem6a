#ifndef __USER_H__
#define __USER_H__

#define USERS_FILE_NAME "data/users"

#include <vector>
#include <iostream>
#include "fileutils.h"

using namespace std;

class User
{
	public :	
		static void init();
		static bool isRealUser(string user, string passwd);

	private :
		static vector<int> getUserIDS();
		static string getUser(int id);
		static string getUserPass(int id);
		static FileUtils * users;
};

#endif
