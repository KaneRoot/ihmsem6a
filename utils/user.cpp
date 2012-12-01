#include "user.h"

FileUtils * User::users = NULL;

void User::init()
{
	if( User::users == NULL)
	{
		string f(USERS_FILE_NAME);
		
		User::users = new FileUtils(f);
		User::users->init();
	}
}

bool User::isRealUser(string user, string passwd)
{
	vector<int> ids = User::getUserIDS();
	string u_name; string u_passwd;

	for(size_t i(0) ; i < ids.size() ; i++)
	{
		u_name.clear(); u_passwd.clear();
		u_name.insert(0, User::getUser(ids.at(i)));
		u_passwd.insert(0, User::getUserPass(ids.at(i)));

		std::cout << "Comparaison : " << u_name << " pass : " << u_passwd << std::endl;

		if(u_name.compare(user) == 0 && u_passwd.compare(passwd) == 0)
			return true;

	}	
	return false;
}

vector<int> User::getUserIDS()
{
	return User::users->getIDs();
}

string User::getUserPass(int id)
{
	return User::users->get(id, 2);
}

string User::getUser(int id)
{
	return User::users->get(id, 1);
}
