#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    /* ------------------------------ 
        Time complexity: O((M+N)^2)
        Space comlexity: O(M+n)
        Method:
        1. Merge two array.
        2. Sort them.
        3. Find median.
    ------------------------------ */

    // int n1_len = nums1.size(), n2_len = nums2.size();
    // int result;
    // vector<int> merged;

    // for(const auto& n:nums1)
    //     merged.push_back(n);
    // for(const auto& n:nums2)
    //     merged.push_back(n);
    
    // sort(merged.begin(), merged.end());

    // int mid = merged.size() / 2;
    // if(merged.size()%2 == 0)
    //     result = merged[mid-1] + merged[mid];
    // else
    //     result = merged[mid] * 2;

    // return result / 2.0;

    /* ----------------------------
        Time complexity: O(M+N)
        Space complexity: O(M+N)
        Method:
        Using two pointer with extra space.
    ---------------------------- */
    int n1 = nums1.size(), n2 = nums2.size();
    int i = 0, j = 0;
    int terminate = -1;
    vector<int> merged(n1+n2, 0);

    while(i<n1 && j<n2){
        if(nums1[i] < nums2[j])
            merged[++terminate] = nums1[i++];
        else
            merged[++terminate] = nums2[j++];
    }

    while(i<n1)
        merged[++terminate] = nums1[i++];
    while(j<n2)
        merged[++terminate] = nums2[j++];
    
    int mid = merged.size() / 2;
    if(merged.size()%2 == 0)
        return  (merged[mid] + merged[mid-1]) / 2.0;
    else
        return  merged[mid];
}

int main(){
    // vector<int> nums1 = {1, 2}, nums2 = {3, 4};
    vector<int> nums1 = {1, 3}, nums2 = {2};

    cout << "Input: nums1 = ";
    for(const auto& n:nums1)
        cout << n << " ";
    cout << ", nums2 = ";
    for(const auto& n:nums2)
        cout << n << " ";
    cout << endl;

    cout << "Output: " << findMedianSortedArrays(nums1, nums2);

    return 0;
}