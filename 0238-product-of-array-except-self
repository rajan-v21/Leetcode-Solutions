#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int current_product = 1;
        vector<int> res(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++){
            res[i] = current_product;
            current_product *= nums[i];
        }
        current_product = 1;
        for(int j = nums.size()-1 ; j >= 0; j--){
            res[j] *= current_product;
            current_product *= nums[j];
        }
        return res;
    }
};

int main(){
	Solution s;
	vector<int> v = {-1,1,0,-3,3};
	for(int &x : s.productExceptSelf(v))
        cout << x << " ";
}

/*---------------------------------------------------------------------------------------------------------------------------
TC: O(n) SC: O(n)

Intuition:

1. Intuition is to calculate all the products once traversing towards right starting from left and once towards left starting
from right.
2. First set initial product to 1 and then travelling from left to right; multiplying current product and previous element 
and then storing the current product in result vec and updating the current product.
3. Now doing the same thing again from right to left but instead of directly storing current product in result vec which will 
overwrite the prevoius elements in result vec, we multiply the current product to the element present at right pointer in 
the result vec.
---------------------------------------------------------------------------------------------------------------------------*/
