#include "admin.h"



admin::admin()
{

}


admin::~admin()
{
}

bool admin::isLogin(bool check, int type)
{
	if ((check) && (type == 0))
		return true;
	else return false;
}

