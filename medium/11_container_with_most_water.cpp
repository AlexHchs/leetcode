#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height){
    int left = 0, right = height.size() - 1;
    int lower = 0, area = 0;
    int result = INT_MIN;
    
    while(left != right){
        lower = min(height[left], height[right]);
        area = (right - left) * lower;
        result = max(result, area);

        if(height[left] > height[right])
            right--;
        else
            left++;
    }

    return result;
}

int main(){
    vector<int> input = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result;

    cout << "Input: ";
    for(const auto x : input){
        cout << x << " ";
    }
    cout << endl;

    result = maxArea(input);

    cout << "Output: " << result << endl;
}