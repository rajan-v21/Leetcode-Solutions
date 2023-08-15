#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long rev = 0;
        long long temp = x;
        while(temp != 0){
            int num = temp % 10;
            rev = (rev * 10) + num;
            temp /= 10;
        }
        return (rev == x);
    }
};

int main(){
    Solution s;
    s.isPalindrome(1234544321) ? cout<<"True" : cout<<"False";
}

/*---------------------------------------------------------------------------------------------------------------------------
TC: O(n) SC: O(1)

Intuition:
1. First simply store the original num in a temp variable.
2. Then divide temp by 10 and concatenating the remainder to a variable named reverse.
3. Update the temp as the quotient obtained from previous division.
4. Keep repeating the process until temp becomes 0.
5. Once temp is 0, return true if the reverse variable is equal to original num.
---------------------------------------------------------------------------------------------------------------------------*/
