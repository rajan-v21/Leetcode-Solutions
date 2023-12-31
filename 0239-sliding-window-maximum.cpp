#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0, right = 0;
        deque<int> q;
        vector<int> res;
        while(right < nums.size()){
            while(!q.empty() && q.back() < nums[right]) q.pop_back();
            q.push_back(nums[right]);
            if(right - left + 1 == k){
                res.push_back(q.front());
                if(nums[left] == q.front()) q.pop_front();
                left++;
            }
            if(right - left + 1 < k) right++;
        }
        return res;
    }
};

int main(){
	Solution s;
    vector<int> v = {-1,3,1,2,0,5};
    int k = 3;
    for(int i=0; i < s.maxSlidingWindow(v, k).size(); i++)
	cout<<s.maxSlidingWindow(v, k)[i]<<" ";
}

/*---------------------------------------------------------------------------------------------------------------------------
TC: O(n) SC: O(n)

Intuition:

Intuition is to keep track of first element in deque, which will always be the maximum element found up till the traverse
and checking every new element at right pointer with the last element of deque and removing all the elements from back untill
current element is less than last element in deque to maintain the monotonicity of queue i.e to keep element in deque in
non-decreasing order.
For eg: if deque contains elements 4 3 0 -2 and if the element at right pointer of vector nums turns to be 2 then we remove
all the elements up till 0 and insert 2 at last. Then elements in deque will be 4 3 2.

1. Traverse towards right and keep inserting the element in the deque if the element on right pointer is smaller than last
element in deque.
2. But if we encounter any element bigger than the last element of deque, we start popping all the elements from behind to
maintain the monotonicity of deque.
3. And do this untill we hit the window.
3. This way the first element of the deque which will always be max in window.
5. If we have got our window, simply return the first element of deque.
6. Now before sliding our window check whether window's start (nums's left) is going past the max element in deque 
(i.e first element of deque)
7. If yes that means our max element in deque wont be max for new window, so discard it by poping from deque.
8. Now set start of new window by incrementing left pointer and repeat the process for new obtained window.
---------------------------------------------------------------------------------------------------------------------------*/
