#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxArea(vector<int>& height) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int i = 0, j = height.size()-1;
        int maxArea = 0;
        while(i<=j){
            int area = 0;
            if(height[i]==0) i++;
            else if(height[j]==0) j--;
            else{
                if(height[i]<height[j]){
                    area = height[i]*(j-i);
                    i++;
                }
                else{
                    area = height[j]*(j-i);
                    j--;
                }
            }
            if(area>maxArea) maxArea = area;
        }
        return maxArea;
    }
};

int main(){
    Solution s;
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    cout<<s.maxArea(v);
}

/*---------------------------------------------------------------------------------------------------------------------------
TC: O(n) SC: O(1)

NOTE: Snippet "ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);" disables synchronization and provide a speed boost.
    "ios::sync_with_stdio(false);" disables the synchronization between C++ standard I/O streams and C standard I/O streams.
    "cin.tie(0); cout.tie(0);" unties cin stream from the cout stream and vice versa.

Intuition:

1. Simple intuition is using two pointers one at left end and other at right end.
2. If either of pointers value is traverse toward mid.
3. Once reaching to point where both sides contains some value, calculate the distance between them and multiply it by the
height of lower value to get area.
4. Increase the left pointer if height at left pointer is smaller than height at right pointer or decrease right pointer.
5. Repeat the process until left & right both passes by each other.
---------------------------------------------------------------------------------------------------------------------------*/
