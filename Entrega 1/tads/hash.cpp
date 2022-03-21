#include "hash.h"

using namespace std;

Hash::Hash(string newA) : a(newA){
    a = newA;
};

int Hash::Obtain(string name){
    return 1;
}

/*ostream& operator<<(ostream& ostr,const Hash& hash){
    ostr << hash.a << "";
    return ostr;
}*/