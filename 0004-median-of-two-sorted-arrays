#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        
        while (left <= right) {
            int partitionA = (left + right) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;

            int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
            int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];

            int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
            int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 0) return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                else return max(maxLeftA, maxLeftB);
            } 
            else if (maxLeftA > minRightB) right = partitionA - 1;
            else left = partitionA + 1;
        }
        return 0.0;
    }
};

int main(){
   Solution s;
   vector<int> v1 = {1,5,8}, v2 = {2,3,6,9};
   cout<<s.findMedianSortedArrays(v1, v2);
}

/*---------------------------------------------------------------------------------------------------------------------------
TC: O(log(m+n)) SC: O(1)

Intuition:
1. First we need to make sure size of array A should always be less than array B.
2. Now using binary search we have to partition array A. (array of 6 will partition in two halves A_left(3) & A_right(3))
3. And partition of array B will be complement of A_right i.e A_left
(array of 9 will partition in two halves B_left(6) & B_right(length of A_left) i.e 3).
4. After partition, consider A_left + B_left partition as LEFT partition & A_right + B_right partition as RIGHT partition.
5. For edge cases:
  - if partitionA is 0 means theres nothing on the A_left side. Use -INFINITY i.e INT_MIN
  - if partitionA is length of nums1 means theres nothing on the A_right side. Use +INFINITY i.e INT_MAX
  - do same for partitionB.
6. We basically have to reach a partition where max of A_left partition is less than min of B_right partition 
  & max of B_left partition is less than min of A_right partition.
7. For that, if max of A_left partition is greater than min of B_right, shift the partition A towards left.
  similarly, if  max of B_left partition is greater than min of A_right, shift the partition A towards right.
8. Once we have reached at desired partition, 
  EVEN length:  Get max element of LEFT partition and min element of RIGHT partition.
  ODD length: get max element of LEFT partition for odd length as length of LEFT partition will always be 1 more than RIGHT partition.
---------------------------------------------------------------------------------------------------------------------------*/
