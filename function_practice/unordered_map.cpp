#include <iostream>
#include <unordered_map>

using namespace std;

/*
    Unordered map特色:
    存放資料為無序排列
    對應雜湊表(hash table)搜索效率高
    Time comlexity: O(1)
    Space comlexity: Higer than O(N)
*/

int main(){
    unordered_map<int, int> umap = {                      
        {0, 101},
        {1, 201},
        {2, 301}
    };

    cout << "Initial map element: " << endl;
    for(const auto& n:umap)
        cout << "Column number: " << n.first << ", Item: " << n.second << endl;

    cout << "After insert map elements: " << endl;
    for(int i=0; i<4; i++)
        umap.insert(pair<int, int>(i+3, i+4*100));                                  // Insert function
    umap[10] = 5001;                                                                // Direct insert a new element
    for(const auto& n:umap)
        cout << "Column number: " << n.first << ", Item: " << n.second << endl;
    
    cout << "After erase map element: " << endl;
    umap.erase(umap.begin());                                                       // Erase the first element of the unordered map
    umap.erase(2);                                                                  // Erase the specific element of the unordered map
    umap.erase(umap.find(3), umap.end());                                           // Erase the specific range of elements
    for(const auto& n:umap)
        cout << "Column number: " << n.first << ", Item: " << n.second << endl;

    cout << "After clear map element: " << endl;
    umap.clear();                                                                   // Clear the unordered map

    if(umap.empty())                                                                // Judge the unordered map is empty or not
        cout << "The map is empty!" << endl;
    else
        cout << "The map is non empty!" << endl;

    // Test
    umap = {                      
        {1, 101},
        {0, 201},
        {2, 301}
    };
    umap[3] = 401;
}
