#include "ContactManager.h"

ContactManager::ContactManager()
{
    contacts.delimeter = "\n";
}
bool ContactManager::loadFromFile(string fileName)
{
    ifstream all_contacts(fileName.c_str(),ios::in);
    string number,name;
    while(true)
    {
        getline(all_contacts,number,' ');
        if(all_contacts.fail())
            return true;
        getline(all_contacts,name);
        if(all_contacts.fail())
            return false;
        add(name,number);
    }
    all_contacts.close();
    return true;
}
void ContactManager::add(string name, string phone_number)
{
    Contact c(name);
    LinkedList<Contact>::Node *contact_pos = contacts.get(c);
    if(contact_pos == nullptr)
    {
        c.addPhoneNumber(phone_number);
        contacts.addSorted(c);
        contact_pos = contacts.get(c);
        Add(phone_number,&(contact_pos->value));
        //tree.insert(phone_number,&(contact_pos->value));
    }
    else
    {
        contact_pos->value.addPhoneNumber(phone_number);
        Add(phone_number,&(contact_pos->value));
        //tree.insert(phone_number,&(contact_pos->value));
    }
}
void ContactManager::Add(string phone_number,Contact* c)
{
    tree.insert(phone_number,c);
}
Contact* ContactManager::find(string phone_number)
{
    return tree.find(phone_number);
}
void ContactManager::displayNumber(string phone_number)
{
    Contact* c = find(phone_number);
    if(c != nullptr)
        cout << c->getName() << endl;
    else
        cout << phone_number << endl;
}

ostream& operator<<(ostream& o, ContactManager & c)
{
    o << c.contacts;
    return o;
}
