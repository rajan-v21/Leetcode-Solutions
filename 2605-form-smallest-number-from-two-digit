#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 1; i <= 9; i++){
            if(count(nums1.begin(), nums1.end(), i) && 
                    count(nums2.begin(), nums2.end(), i))
                return i;
        }
        
        int minNums1 = *min_element(nums1.begin(), nums1.end());
        int minNums2 = *min_element(nums2.begin(), nums2.end());

        return min(minNums1, minNums2)*10 + max(minNums2, minNums1);
    }
};

int main(){
	Solution s;
	vector<int> v1 = {3,5,2,6,9}, v2 = {3,1,7,6};
	cout<<s.minNumber(v1, v2);
}

/*---------------------------------------------------------------------------------------------------------------------------
TC: O(n) SC: O(1)

Intuition:

1. Intuition is to first find the common value in both arrays and return it. 
(And as per given constraints in problem max common value will not be more than 9 which will always be less than two digit no.)
2. If there is no common value we find the min element from both the arrays.
3. And as we want minimum no., digit at tenth place should be less than once place.
4. Therefore, we will return min between nums1 and nums2 at tenth place & max between both at once place.
---------------------------------------------------------------------------------------------------------------------------*/
