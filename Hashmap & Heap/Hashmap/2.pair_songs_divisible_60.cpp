/*
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

Similar to 2 sum problem

for i = 100 
first = 100 % 60 = 40
second = (60 - 40) % 60 = 20

so element having value = 20 will be potential pair for i.
*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        vector<int> temp(60, 0);
        int ans = 0;
        
        for(int i = 0; i < time.size(); i++)
        {
            int first = time[i]%60;
            int second = (60 - first)%60;
            ans += temp[second];
            temp[first]++;
        }
        
        return ans;
    }
};