#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct Company
{
	string name;
	string profit_tax;
	string address;
};

vector<Company> ReadListCompany(string file_name);
int HashString(string company_name);
