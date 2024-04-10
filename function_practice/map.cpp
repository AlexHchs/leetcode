#include <bits/stdc++.h>
#include <map>
using namespace std;

/*
    Map特色:
    存放資料為關聯式有序排列
    利用紅黑樹(red-black tree)可以保證搜尋,插入,刪除在O(log N)內完成
    Time comlexity: O(log N)
    Space comlexity: Higer than O(N)
*/

int main(){
    map<int, string> mp = {
        {3, "John"},
        {4, "Rose"},
        {5, "William"}
    };
    
    mp.insert(pair<int, string>(1, "Tom"));                                 // Insert a new element to map
    mp[2] = "Jack";                                                         // Insert a new element as array

    for(const auto& n:mp)
        cout << "Column number: " << n.first << ", Item: " << n.second << endl;

    mp[1] = "Max";                                                          // Change the key:1 value to Max
    cout << "Change the value of mp[1] to Max: mp[1] = " << mp[1] << endl;  
    mp.insert(pair<int, string>(1, "John"));                                // If use insert function to change the value it will fail
    cout << "Change the value of mp[1] to John: mp[1] = " << mp[1] << endl;

    cout << "After erase map element: " << endl;
    mp.erase(mp.begin());                                                   // Erase the first element of the map
    mp.erase(2);                                                            // Erase the specific element of the map
    mp.erase(mp.find(3), mp.end());                                         // Erase the specific range of elements
    mp[5] = "William";
    for(const auto& n:mp)
        cout << "Column number: " << n.first << ", Item: " << n.second << endl;

    cout << "After clear map element: " << endl;
    mp.clear();                                                             // Clear the map

    if(mp.empty())                                                          // Judge the map is empty or not
        cout << "The map is empty!" << endl;
    else
        cout << "The map is non empty!" << endl;
}
