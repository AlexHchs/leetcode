#include <iostream>
#include <string>
using namespace std;

int main(){
    // Initialize string
    string str1;                                                // Empty string
    string str2("practice");                                    // Specific string initialize
    string str3 = "practice2";
    string str4 = str3;

    cout << "String length str1: " << str1.size() << endl;      // Function size() return string length 
    cout << "String length str2: " << str2.size() << endl;
    cout << "String length str3: " << str3.size() << endl;
    cout << "String length str4: " << str4.size() << endl;

    cout << "Judge the string length str1 and str2: " << (str1 == str2) << endl;    // Judge the string content is the same or not
    cout << "Judge the string length str3 and str4: " << (str3 == str4) << endl;

    string merged = str2 + str3;                                                    // Merge two string
    string appended = str4.append(str3);                                            // Append str3 back to str4
    cout << "String merged str2 and str3: " << merged << endl;
    cout << "String str3 append to str4: " << appended << endl;

    cout << "Judge the string str1 is empty or not: " << str1.empty() << endl;      // Judge the string is empty or not
    cout << "Judge the string str2 is empty or not: " << str2.empty() << endl;

    cout << "Function at() (at(3)): " << str2.at(3) << endl;                        // at() can do segment fault, like out of range

    string to_int = "-12345";
    string to_double = "53.5046";
    int a = stoi(to_int);                                                           // Convert string to int
    double b =stod(to_double);                                                      // Convert string to double
    cout << "Int: " << a << ", Double: " << b << endl;

    /*
        There are a lot of change function as below:
        stoi - to int
        stol - to long int
        stoll - to long long int
        stoul - to unsigned long int
        stoull - to unsigned long long int
        stof - to float
        stod - to double
        stold - to long double
    */

    // Test
    string test1 = "";
    string test2 = "00123";
    int test3 = -123;
    test1 += test2[0];
    cout << test3 % 10;
}
