#include <iostream>
#include <fstream>
#include "ContactManager.h"

using namespace std;

int main()
{
    ///Linked List Example
    /*LinkedList<int> lis;
    lis.addSorted(20);
    lis.addSorted(12);
    lis.addSorted(8);
    lis.addSorted(5);
    lis.delimeter = " ";
    cout << lis << endl;
    cout << lis.get(5)->value << endl;*/
    /*LinkedList<string> lis;lis.delimeter = "\n";
    lis.addSorted("k");
    lis.addSorted("l");
    lis.addSorted("m");
    cout << lis << "K!";*/
    ///Contact Example
    /*Contact c1("Ali"),c2("Ahmed"),c3;
    cout << c1 << c2 << c3;
    c1.addPhoneNumber("01116891353");
    c2.addPhoneNumber("01110801353");
    c1.addPhoneNumber("01116891388");
    c1.addPhoneNumber("01116891399");
    cout << c1 << c2;
    cout << (c1 == c2) << endl << (c1 < c2) << endl << (c2 < c1) ;*/
    ///Construct Contacts List
    /*ContactManager manager;
    string file = "all-contacts.in",name = "Abanob Sedky",number = "0111";
    manager.loadFromFile(file);
    manager.add(name,number);
    name = "Abanoub Sedky",number = "0111";
    manager.add(name,number);
    manager.displayNumber(number);
    cout << manager ;*/
    ///Sample List
    ContactManager manager;
    string file = "Sample.txt";
    manager.loadFromFile(file);
    cout << manager ;
    cout << "Call Log : " << endl;
    string call_log[5] = {"002098765","002054321","002054321","012521212","002011111"};
    manager.displayNumber(call_log[0]);
    manager.displayNumber(call_log[1]);
    manager.displayNumber(call_log[2]);
    manager.displayNumber(call_log[3]);
    manager.displayNumber(call_log[4]);



    return 0;
}
