/*
Priority Queue implementation using min heap
*/

#include <bits/stdc++.h>
using namespace std;

void init()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout);
	#endif
}

vector<string> split(string s)
{
	stringstream ss(s);
	string word;

	vector<string> result;
	while(ss >> word)
	{
		result.push_back(word);
	}

	return result;
}

class PriorityQueue
{
private:
	vector<int> data;

public:

	void upheapify(int i)
	{
		if(i == 0)
			return;

		int pi = (i - 1) / 2;

		if(data[i] < data[pi])
		{
			swap(data[i], data[pi]);
			upheapify(pi);
		}
	}

	void add(int val)
	{
		data.push_back(val);
		upheapify(data.size() - 1);
	}

	void downheapify(int root)
	{
		int min = root;

		int leftChildIdx = 2 * root + 1;
		if(leftChildIdx < data.size() && data[leftChildIdx] < data[min])
			min = leftChildIdx;

		int rightChildIdx = 2 * root + 2;
		if(rightChildIdx < data.size() && data[rightChildIdx] < data[min])
			min = rightChildIdx;

		if(min != root)
		{
			swap(data[min], data[root]);
			downheapify(min);
		}
	}

	int remove()
	{
		if(data.size() == 0)
		{
			cout << "Underflow\n";
			return -1;
		}

		swap(data[0], data[data.size() - 1]);
		int val = data[data.size() - 1];
		data.pop_back();
		downheapify(0);

		return val;
	}

	int peek()
	{
		if(data.size() == 0)
		{
			cout << "Underflow\n";
			return -1;
		}
		
		return data[0];

	}

	int size()
	{
		return data.size();
	}

};

int main()
{
	init();

	PriorityQueue *pq = new PriorityQueue();
	string s; 

	do
	{
		getline(cin, s);
		vector<string> result = split(s);
		string instruction = result[0];

		if(instruction == "add")
		{
			int val;
			stringstream obj(result[1]);
			obj >> val;
			pq->add(val);
		}

		else if(instruction == "remove")
		{
			int val = pq->remove();
			if(val != -1)
				cout << val << "\n";
		}

		else if(instruction == "peek")
		{
			int val = pq->peek();
			if(val != -1)
				cout << val << "\n";
		}

		else if(instruction == "size")
		{
			int val = pq->size();
			cout << val <<"\n";
		}

	}while(s != "quit");

	return 0;
}

/*

Input

add 10
add 20
add 30
add 40
peek
add 50
peek
remove
peek
remove
peek
remove
peek
remove
peek
quit
*/

/*
Output

10
10
10
20
20
30
30
40
40
50

*/