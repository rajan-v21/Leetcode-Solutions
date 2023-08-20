#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int clumsy(int n) {
        if(n<=2) return n;
        if(n<=4) return n+3;
        if(n%4 == 0) return n+1;
        else if(n%4 <= 2) return n+2;
        return n-1;
    }
};

int main(){
	Solution s;
	cout<<s.clumsy(10);
}

/*------------------------------------------------------------------------------------------------------------------------------
TC: O(1) SC: O(1)

Intuition:
1. If we closely look into the problem and solve few testcases, we will find a pattern between them.
2. The pattern follows same as done in above code.
------------------------------------------------------------------------------------------------------------------------------*/
