#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0] , fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);  

        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main(){
	Solution s;
	vector<int> v = {3, 2, 4, 1, 5, 2};
	cout<<s.findDuplicate(v);
}

/*---------------------------------------------------------------------------------------------------------------------------
TC: O(n) SC: O(1)

Intuition:

1. Intuition is to travel through the vector starting from first index of nums and then going to the second num which has 
previous num as index somewhat like a linked list pointing to next value, which will eventually create a loop the moment it 
encounters any dupicate. 
For e.g: 
    Index:  0 1 2 3 4 5
    Nums:   3 2 4 1 5 2
2. Like we start from first index of nums which has val 3 after that we jump to index 3 (val 1) then jump to index 1 (val 2) 
then to index 2 (val 4) and so on. Lets call it VLL(Value Linked List): 3->1->2->4->5->2 
3. So here the arrow is pointing to 2 again means we have a loop and there exists a duplicate.
4. And for this we use Tortoise and Hare technique which is a two pointer method uses slow pointer (jumps 1 index forward) 
and fast pointer (jumps 2 index forward).
(In above code, we are using do while bcz both slow and fast pointer is at starting index else it will collide on first
occurence itself)
5. Now jump our slow pointer to current val's index i.e  move forward by 1 and fast to current val's index's val's index i.e 
move forward by 2, until both collide.
6. Once they collide we intialize one of the pointer at the start of our VLL and then move forward both pointer by 1 until 
they collide again.
7. And this collision point will be our duplicate num.
---------------------------------------------------------------------------------------------------------------------------*/
