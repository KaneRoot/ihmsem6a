#include "type.h"

FileUtils * Type::types = NULL;

void Type::init()
{
	if( Type::types == NULL)
	{
		string f(TYPES_FILE_NAME);
		
		Type::types = new FileUtils(f);
		Type::types->init();
	}
}

string Type::getType(int id)
{
	return Type::types->get(id, 1);
}
