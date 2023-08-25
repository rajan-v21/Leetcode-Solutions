class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 1;
        while(right < nums.size()){
            if(nums[right] != nums[left]){
                left++;
                nums[left] = nums[right];
            }
            right++;
        }
        return left+1;
    }
};
/*-----------------------------------------------------------------------------------------------------------------------------
TC: O(n) SC: O(1)

Intuition:

1. Use two pointer to bring the unique of array at front doesn't matter whatever elements remains after sorting unique element
at front.
2. So we first move the right pointer to an element where the element at left and right are not same.
3. Once a unique element is found increment the left and replace it with right element's val and keep repeating the upper step
until right touches end.
NOTE: We are returning left+1 bcz we never counted the unique element present at 0th index.
-----------------------------------------------------------------------------------------------------------------------------*/
