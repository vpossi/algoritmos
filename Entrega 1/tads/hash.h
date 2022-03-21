#ifndef HASH_H
#define HASH_H

#include <string>
#include <iostream>

using namespace std;

struct Asociation
{
    string key;
    int value;
    Asociation(string aKey, int aValue) : key(aKey), value(aValue){};
};

class Hash {
    //private
    string a;
    double b;

public:
    Hash(string a);

    bool Insert(string name, int points);
    int Obtain(string name);
    //friend ostream& operator<<(ostream& ostr,const Hash& hash);
    
};

//ostream& operator<<(ostream& ostr,const Hash& hash);



#endif //HASH_H