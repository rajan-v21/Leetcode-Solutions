#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int max = 0, t_weight = 0;
        for(int i = 0; i<weights.size(); i++){
            t_weight += weights[i];
            if(weights[i]>max) max = weights[i];
        }
        if(days == weights.size()) return max;
        int minCap = max, maxCap = t_weight;
        while(minCap <= maxCap){
            int reqCap = (minCap + maxCap)/2, load = 0, t_days = 0;
            for(int i = 0; i < weights.size() && t_days <= days; i++){
                load += weights[i];
                if(load > reqCap){
                    t_days++;
                    load = weights[i];
                }
            }
            t_days++;
            if(t_days > days) minCap = reqCap + 1;
            else maxCap = reqCap - 1;
        }
        return minCap;
    }
};

int main(){
	Solution s;
	vector<int> v = {3,2,2,4,1,4};
    	int D = 3;
	cout<<s.shipWithinDays(v, D);
}

/*---------------------------------------------------------------------------------------------------------------------------
TC: O(n*log(w)) SC: O(1)
w -> sum of all weights

Intuition:

1. For this, first thing we need to understand if the no. of weights given is equal to D days, the minimum load capacity we
need is the max weight among the weights.
2. And if the D-days is reduced to 1 day, we will need to increase our load capacity all the weights given.
3. So basically we have to find load capacity between max weight among the given weights (minimum capacity) and sum of 
total weights given (maximum capacity). And that will be our range. (For which we will use binary search.)
4. Now we traverse through the given weights until the addition of weights hit the load capacity. And increase the counter.
5. Now do the same untill we have traversed through all the weights. And compare the counter with the D day.
6. If the counter is more than D day means we still have some spare loads and we need to increase the load capacity. 
So we will set our minimum capacity at mid of load range.
7. If the counter is less than D day means we still have some spare days and we need to decrease the load capacity. 
So we will set our maximum capacity at mid of load range.
---------------------------------------------------------------------------------------------------------------------------*/
