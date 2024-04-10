#include <iostream>
#include <string>
using namespace std;

/*
    nullpointer practice it would not confused with integer 0 (NULL problem)
*/

void myprint(string* p){
    cout << "Pointer type!" << endl;
}

void myprint(int n){
    cout << "Integer type!" << endl;
}

int main(){
    myprint(0);
    myprint(NULL);          // C++ call it as integer
    myprint(nullptr);       // C++ define it as all types of pointer (It could string, char, double, and int ...etc)
    return 0;
}