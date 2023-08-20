#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + 2 * t;
    }
};

int main(){
    Solution s;
    int num = 3, t = 2;
    cout<<s.theMaximumAchievableX(num, t);
}
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TC: O(1), SC: O(1)

Intuition:

1. Here we have to find maximum x possible in such a way that x and num should be able to reach to common integer after performing specific operation.
2. There are two ways to find x:  First is to increase num and decrease x and other is decrease num and increase x.
3. And if we are decreasing x towards num means it will always be greater than the x which we are increasing towards num.
4. So we will opt for first operation which is to increase num by 1 and decrease x by 1; t times.
5. Which is basically increasing num by 2; t times to reach the x. 
 -> num + 1 * t = x - 1 * t 
 -> num + t =  x - t
 -> num + 2t = x)
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
