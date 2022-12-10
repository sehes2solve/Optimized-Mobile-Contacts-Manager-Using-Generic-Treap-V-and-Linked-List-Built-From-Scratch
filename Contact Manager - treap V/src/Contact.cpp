#include "Contact.h"

bool comp_char (char c1, char c2)
{
    return tolower(c1) < tolower(c2);
}

Contact::Contact()
{
    phone_numbers.delimeter = " ";
}
Contact::Contact(string name)
{
    phone_numbers.delimeter = " ";
    this->name = name;
}
 Contact::Contact(const Contact& c):name(c.name),phone_numbers(c.phone_numbers)
{

}
Contact Contact::operator= (const Contact& c)/// used only in parameterized constructor
{
    name = c.name;
    phone_numbers = c.phone_numbers;
    return *this;
}
void Contact::addPhoneNumber(string number)
{
    phone_numbers.addSorted(number);
}
string Contact::getName()
{
    return name;
}
bool Contact::operator<(const Contact & c)
{
    return lexicographical_compare(name.begin(),name.end(),c.name.begin(),c.name.end(),comp_char);
}
bool Contact::operator==(const Contact & c)
{
    return name == c.name;
}
Contact::~Contact()
{

}

ostream& operator<<(ostream& o, Contact & c)
{
    o << c.name << ": " << c.phone_numbers ;
    return o;
}
