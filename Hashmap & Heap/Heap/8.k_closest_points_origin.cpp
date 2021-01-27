/*
https://leetcode.com/problems/k-closest-points-to-origin/
*/
class Solution
{
public:
    struct comp
    {
        bool operator()(vector<int> v1, vector<int> v2)
        {
            // calc distance
            return v1[0] * v1[0] + v1[1] * v1[1] < v2[0] * v2[0] + v2[1] * v2[1];
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        if (points.size() == 1)
            return {points[0]};

        vector<vector<int>> result;
        priority_queue<vector<int>, vector<vector<int>>, comp> heap;

        for (auto point : points)
        {
            heap.push(point);
            if (heap.size() > K)
                heap.pop();
        }

        while (heap.size() > 0)
        {
            auto x = heap.top();
            result.push_back(x);
            heap.pop();
        }

        return result;
    }
};