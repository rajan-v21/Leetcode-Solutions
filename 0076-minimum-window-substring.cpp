#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int> ump;
        for(auto ch:t) ump[ch]++;

        int left = 0, right = 0, start = 0;
        int count = ump.size();
        int minLen = INT_MAX;
        while(right < s.size()){
            if(ump.find(s[right]) != ump.end()){
                ump[s[right]]--;
                if(ump[s[right]] == 0) count--;
            }
            while(count == 0){
                if(ump.find(s[left]) != ump.end()){
                    ump[s[left]]++;
                    if(ump[s[left]] == 1){
                        count++;
                        if( minLen > right - left + 1 ){
                            minLen = right - left + 1;
                            start = left;
                        }
                    }
                }
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

int main(){
	Solution s;
    string s1 = "ADOBECODEBANC";
    string s2 = "ABC";
	cout<<s.minWindow(s1, s2);
}

/*---------------------------------------------------------------------------------------------------------------------------
TC: O(n) SC: O(n)

Intuition:

Lets take an example:
s = _ A _ _ C _ _ A A A _ C
t = "AAC"

1. Intution is we have to first find a range which contains all the required chars along with the duplicates until reaching
last desired char of string t.
2. Once we have the range we start poping char from left one by one & check do we still have the required chars in the range.
3. And we check this by using an unordered_map which stores no. of times a certain char is present in string t.
(for above eg; A->2, C->1)
4. So we first of all insert all the char of string t and its occurence times in map.
(Snippet ump[ch]++; in code increments the value present at iterator ch by 1)
4. Now we traverse the string s and if we find the char, we decrement that char's value in map by 1.
5. If that char's value reaches 0, means we found total no. of times that char was required. 
6. Then we also decrement count variable of map by 1 which was original intialized equal to the size of the map.
(we are using count variable to know how many unique char is required.)
7. We do this until count is 0 (i.e no more unique char is required), if count reaches 0 means we have got our range.
NOTE: If a char has occured more than the times it was present in string t, its char value in map will be less than 0.
8. Now we start discarding char from left side of range. 
9. If we find a char of string t, while discarding we increment the value of that char by 1 in map.
10. And if any char's value in map reaches 1 means we are again in need of that char that many times.
11. The moment we encounter this, means we have found a possible candidate for minimum window substring.
12. Calculate the length and search for new range by repeating above steps.
---------------------------------------------------------------------------------------------------------------------------*/
