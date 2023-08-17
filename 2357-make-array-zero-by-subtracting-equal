#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        return us.size() - us.count(0);
    }
};

int main(){
    Solution s;
    vector<int> v = {1,5,0,3,5};
    cout<<s.minimumOperations(v);
}

/*----------------------------------------------------------------------------------------------------------------------------
TC: O(n) SC: O(n)

Intuition:

1. Intuition is that same elements of array will remain same even when we subtract x from them because we are subtracting 
same value(x) from the same elements and for different elements remain different.
2. And hence the same elements become 0 in same no. of operations but the different elements take different no. of operations.
3. Therefore we need to count the number of different positive elements in the array.
4. In code above we are subtracting 0's count because in set, there are n different elements implying that many operations 
are required but if there is 0 present in set means we are not performing any operation to make it 0 again.
----------------------------------------------------------------------------------------------------------------------------*/
