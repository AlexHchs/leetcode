#include <bits/stdc++.h>
using namespace std;

/*
    Set特色:
    set是有序的關聯式容器,
    容器內元素為唯一性不重複值不可修改,
    通常實作以紅黑樹(red-black tree)可以保證搜尋,插入,刪除在O(log N)內完成
*/

int main(){
    int arr[] = {1,2,3,4,5};
    vector<int> vec1 = {5,6,7,8,9};
    set<int> set1 = {15,6};

    /* Initial set with c-style array */
    set<int> set2(arr, arr+5);
    set<int> set3(vec1.begin(), vec1.end());


    cout << "---------------------- Initial set ----------------------" << endl;

    cout << "set1 = ";
    for(const auto x : set1){
        cout << x << " ";
    }
    cout << endl;

    cout << "set2 = ";
    for(const auto x : set2){
        cout << x << " ";
    }
    cout << endl;

    cout << "set3 = ";
    for(const auto x : set3){
        cout << x << " ";
    }
    cout << endl;

    cout << "---------------------------------------------------------" << endl << endl;


    cout << "---------------------- Insert set1 ----------------------" << endl;

    set1.insert(11);
    cout << "(Insert: 11) set1 = " << endl;
    for(const auto x : set1){
        cout << x << " ";
    }
    cout << endl;
    
    set1.insert(arr, arr+3);
    cout << "(Insert array with first 3 elements: 1, 2, 3) set1 = " << endl;
    for(const auto x : set1){
        cout << x << " ";
    }
    cout << endl;

    set1.insert(vec1.begin(), vec1.end());
    cout << "(Insert vec1 with whole elements: 5, 6, 7, 8, 9) set1 = " << endl;
    for(const auto x : set1){
        cout << x << " ";
    }
    cout << endl;

    cout << "---------------------------------------------------------" << endl << endl;

    cout << "---------------------- Erase set1 ----------------------" << endl;
    bool era;

    era = set1.erase(15);
    cout << "(Erase: element = 15) set1 = " << endl;
    for(const auto x : set1){
        cout << x << " ";
    }
    cout << endl << "Erase success: " << ((era == true) ? "true" : "false") << endl;

    for(int i=1; i<6; i++){
        era = set1.erase(i);
    }
    cout << "(Erase: element = 1 to 5) set1 = " << endl;
    for(const auto x : set1){
        cout << x << " ";
    }
    cout << endl << "Erase success: " << ((era == true) ? "true" : "false") << endl;

    era = set1.erase(50);
    cout << "Erase elment 50 which not exist in set1 = " << endl;
    for(const auto x : set1){
        cout << x << " ";
    }
    cout << endl << "Erase success: " << ((era == true) ? "true" : "false") << endl;

    cout << "---------------------------------------------------------" << endl << endl;


    cout << "---------------------- Clear set2 ----------------------" << endl;

    set2.clear();
    cout << "set2 = ";
    for(const auto x : set2){
        cout << x << " ";
    }
    cout << endl;

    cout << "---------------------------------------------------------" << endl << endl;


    cout << "---------------------- Count and find set1 ----------------------" << endl;

    cout << "set1 = ";
    for(const auto x : set1){
        cout << x << " ";
    }
    cout << endl ;

    /*
        Function: find(),
        回傳布林值
    */
    cout << "Function: count(): " << endl;
    cout << "Element: 6 exist of not: " << ((set1.count(6) == 1) ? "true" : "false") << endl;
    cout << "Element: 1 exist of not: " << ((set1.count(1) == 1) ? "true" : "false") << endl;

    /*
        Function: find(),
        回傳指標
    */
    cout << "Function: find(): " << endl;
    cout << "Element: 6 exist of not: " << ((set1.find(6) != set1.end()) ? "true" : "false") << endl;
    cout << "Element: 1 exist of not: " << ((set1.find(1) != set1.end()) ? "true" : "false") << endl;

    cout << "-----------------------------------------------------------------" << endl << endl;
    

    cout << "---------------------- Empty set1 or not ----------------------" << endl;

    cout << "set1 is empty: " << ((set1.empty() == 1) ? "true" : "false") << endl; 
    cout << "set2 is empty: " << ((set2.empty() == 1) ? "true" : "false") << endl;

    cout << "---------------------------------------------------------------" << endl << endl;

    return 0;
}