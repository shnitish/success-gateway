/*
https://leetcode.com/problems/find-median-from-data-stream/
*/
class MedianFinder
{
public:
    priority_queue<int> q1;                            // max heap for first half to keep track of max element or the last element in the sorted first half
    priority_queue<int, vector<int>, greater<int>> q2; // min heap to keep min element of 2nd half on the top
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (q1.empty() || num < q1.top())
            q1.push(num); // belongs to smaller half

        else
            q2.push(num); // belongs to greater half

        // difference of sizes of queue should not exceed more than 1
        if (q1.size() > q2.size() + 1)
        {
            q2.push(q1.top());
            q1.pop();
        }

        else if (q2.size() > q1.size() + 1)
        {
            q1.push(q2.top());
            q2.pop();
        }
    }

    // if size of PQ's are equal then there are even elements
    // If there is difference then return the max element from top
    double findMedian()
    {
        if (q1.size() == q2.size())
            return q1.empty() ? 0 : (q1.top() + q2.top()) / 2.0;

        else
            return q1.size() > q2.size() ? q1.top() : q2.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */