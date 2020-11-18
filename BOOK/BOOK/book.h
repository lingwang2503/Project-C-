#include <iostream>
#include <string>
using namespace std;



class book
{
private:
	string name, id;
	string author;
	string publisher;
	float price;
public:
	book();
	~book();
	book(string name, string id, string author,
		string publisher, float price);
	string getName();
	string getAuthor();
	string getPublisher();
	string getID();
	float getPrice();
	void setId(string id);
	void setName(string name);
	void setAuthor(string author);
	void setPublisher(string publisher);
	void setPrice(float price);
	void inputBookUser();
	void outputBook();
	
};

