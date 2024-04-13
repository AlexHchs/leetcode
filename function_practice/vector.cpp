#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

/*  
    Vector特色: 
    支援隨機存取,
    集合尾端增刪元素: O(1),
    集合中間增刪元素: O(N),
    可以儲存任意類型的變數,包括使用者自定義資料型態class,
    不保證stable iterator,
*/

int main(){
    /* ---- 1D vector ---- */
    vector<int> vec1, vec2;

    cout << "Function: push_back:" << endl;
    for(int i=0; i<7; i++){
        vec1.push_back(i);                  // Add a new element to the tail of vector
        cout << "vec1[" << i << "]=" << vec1[i] << " "; 
    }
    cout << endl;

    cout << "Function: pop_back:" << endl;
    cout << "vec1 size before pop: " << vec1.size() << endl;
    vec1.pop_back();                        // Delete the element from the tail of vector
    cout << "vec1 size after pop: " << vec1.size() << endl;

    cout << "Function: insert:" << endl;
    vec1.insert(vec1.begin(), 101);       // Insert a new element after the vec1[2]
    int i=1;
    for(const auto x : vec1){
        cout << "vec1[" << i++ << "]=" << x << endl;
    }

    cout << "Erase the element at vec1[3]:" << endl;
    vec1.erase(vec1.begin()+3);             // Erase the element from begin of the vector
    cout << vec1[3] << endl;

    cout << "Erase the element from vec1[1] to vec1[6]" << endl;
    cout << "vec1 size before erase: " << vec1.size() << endl;
    vec1.erase(vec1.begin()+1, vec1.end()); // Erase the element from begin to the end of the vector
    cout << "vec1 size after erase: " << vec1.size() << endl;

    cout << "Function: clear: ";
    cout << "vec1 size before clear: " << vec1.size() << endl;
    vec1.clear();                           // Clear whole element which in the vector
    cout << "vec1 size after clear: " << vec1.size() << endl;
    
    cout << "Judge the vector empty or not, Function: empty: " << endl;
    cout << "vec1 empty or not (with non-element): " << vec1.empty() << endl;
    vec1.push_back(100001);
    cout << "vec1 empty or not (with one-element): " << vec1.empty() << endl;

    /* ---- 2D vector ---- */
    vector<vector<int>> vec2d1(3, vector<int>(3, 0));

    cout << "2D vector: " << endl;
    for(const auto line : vec2d1){
        for(const auto x : line){
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Test
    vector<vector<int>> test = {{2, 5, 6, 9}, {10, 15, 16, 20}};
    int index = 0;
    for(int i=0; i<test.size(); i++){
        if(test[i][0] <= 9 && test[i][test[0].size()-1] >= 9){
            index = i;
            break;
        }
    }

    cout << "Index = " << index << endl;
}