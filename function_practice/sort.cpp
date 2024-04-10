#include <bits/stdc++.h>
using namespace std;

/*
    Sort¯S¦â:
    Time complexity:O(nlogn),
*/

/* ---- Struct Define ---- */
struct student {
    std::string name;
    int score;	
};
bool mycompare(student s1, student s2){
   return s1.score > s2.score;
}
/* ----------------------- */

/* ---- Object Define ---- */
struct myclass {
    bool operator() (int a, int b) { return a > b; }  // Decreasing sort
} myobject;
/* ----------------------- */

bool myCompare(int x, int y){
    return x > y;
}

int main(){
    vector<int> array_int = {4, 5, 8, 3, 7, 1, 2, 6, 10, 9};

    /* Increasing method */
    cout << "Vector(array_int): " << endl;
    for(auto x : array_int){
        cout << x << " ";
    }
    cout << endl;

    sort(array_int.begin(), array_int.begin()+5);

    cout << "Vector with the first five elements sorted.(Increaing): " << endl;
    for(auto x : array_int){
        cout << x << " ";
    }
    cout << endl;

    sort(array_int.begin(), array_int.end());

    cout << "Vector after sorted all.(Increaing): " << endl;
    for(auto x : array_int){
        cout << x << " ";
    }
    cout << endl;

    /* ----------------------------------------------------------------------------------------------------------- */
    /* Decreasing method */
    array_int = {4, 5, 8, 3, 7, 1, 2, 6, 10, 9};

    sort(array_int.begin(), array_int.end(), myCompare);
    cout << "Vector with the specific rule define by myself.(Decreaing): " << endl;
    for(auto x : array_int){
        cout << x << " ";
    }
    cout << endl;

    array_int = {4, 5, 8, 3, 7, 1, 2, 6, 10, 9};
    sort(array_int.rbegin(), array_int.rend());
    cout << "Vector with reverse begin(rbegin()) and end(rend()).(Decreaing): " << endl;
    for(auto x : array_int){
        cout << x << " ";
    }
    cout << endl;

    array_int = {4, 5, 8, 3, 7, 1, 2, 6, 10, 9};
    sort(array_int.rbegin(), array_int.rend(), [](int x, int y){
        return y > x;
    });
    cout << "Vector with lambda function.(Decreaing): " << endl;
    for(auto x : array_int){
        cout << x << " ";
    }
    cout << endl;

    array_int = {4, 5, 8, 3, 7, 1, 2, 6, 10, 9};
    sort(array_int.begin(), array_int.end(), myobject);
    cout << "Vector with define class/myobject.(Decreaing): " << endl;
    for(auto x : array_int){
        cout << x << " ";
    }
    cout << endl;

    /* ----------------------------------------------------------------------------------------------------------- */
    /* Increasing sort string */
    vector<string> array_string = {"bean", "apple", "zoo", "sky", "practice", "sort", "function", "vector"};

    cout << "Vector(array_string): " << endl;
    for(auto s : array_string){
        cout << s << " ";
    }
    cout << endl;

    sort(array_string.begin(), array_string.begin()+5);
    cout << "Vector with the first three elements sorted.(Increaing): " << endl;
    for(auto s : array_string){
        cout << s << " ";
    }
    cout << endl;

    sort(array_string.begin(), array_string.end());
    cout << "Vector after sort all.(Increaing): " << endl;
    for(auto s : array_string){
        cout << s << " ";
    }
    cout << endl;

    /* ----------------------------------------------------------------------------------------------------------- */
    /* Increasing sort struct */
    student st[4];
    st[0].name = "bob";
    st[0].score = 70;
    st[1].name = "cindy";
    st[1].score = 66;
    st[2].name = "alice";
    st[2].score = 77;
    st[3].name = "alice";
    st[3].score = 76;

    cout << "Struct: " << endl;
    for (student s : st) {
        cout << s.name << " " << s.score << endl;
    }
    cout << endl;

    sort(st, st+4, mycompare);
    cout << "Sort struct (Decreasing): " << endl;
    for (student s : st) {
        cout << s.name << " " << s.score << endl;
    }
    cout << endl;

    return 0;
}