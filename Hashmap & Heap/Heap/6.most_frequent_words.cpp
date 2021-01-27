/*
https://leetcode.com/problems/top-k-frequent-words/

Min-heap: return int p1 > int p2 (keep larger one)
low-alphabetical order : string p1 < string p2 (keep lower one)
*/
typedef pair<int, string> pi;

class comp{
public:
    bool operator()(pi p1, pi p2)
    {
        if(p1.first != p2.first)
            return p1.first < p2.first;
        
        else
            return p1.second > p2.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> m;
        vector<string> ans;
        
        for(auto x: words)
            m[x]++;
        
        priority_queue<pi,vector<pi>,comp> pq;
        
        for(auto x: m)
            pq.push({x.second,x.first});
        
        while(k--)
        {
            auto x = pq.top();
            pq.pop();
            ans.push_back(x.second);
        }
        
        return ans;
    }
};