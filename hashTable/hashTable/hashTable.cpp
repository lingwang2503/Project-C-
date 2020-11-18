#include "hashTable.h"

//Câu 1
vector<Company> ReadListCompany(string file_name)
{

}
//Câu 2
int HashString(string company_name) 
{
	if (company_name.length() > 20) {
		company_name = company_name.substr(0, 20);
	}
	int sum = 0;
	for (int i = 0; i < company_name.length(); i++) {
		cout << sum << "\n";
		sum = sum + int(int(company_name[i]) * pow(double(31), double(i))) % int(pow(10, 9) + 9);
	}
	return sum;
}
