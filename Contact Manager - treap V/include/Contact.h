#ifndef CONTACT_H_
#define CONTACT_H_
#include "LinkedList.h"
#include "algorithm"
#include "..\src\LinkedList.cpp"

class Contact {
private:
	string name;
	LinkedList<string> phone_numbers;
public:
	Contact();
	Contact(string name);
	Contact(const Contact&);
	~Contact();
	void addPhoneNumber(string number);
	string getName();
	Contact operator=(const Contact& c);
	bool operator<(const Contact & c);
	bool operator==(const Contact & c);
	friend ostream& operator<<(ostream& o, Contact & c);
};

#endif  /* CONTACT_H_ */
