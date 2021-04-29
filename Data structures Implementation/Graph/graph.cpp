#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<pair<int, int>> graph[], int v1, int v2, int wt)
{
    graph[v1].push_back({v2, wt});
    graph[v2].push_back({v1, wt});
}

void display(vector<pair<int, int>> graph[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << i << "-> ";
        vector<pair<int, int>> temp = graph[i];
        for(int j = 0; j < temp.size(); j++)
        {
            pair<int, int> p = temp[j];
            cout << p.first << "@" << p.second << " ";
        }
        cout << "\n";
    }
}


int main()
{
    // Enter number of node/vertices and edges in the graph
    int n, m; cin >> n >> m;
    vector<pair<int, int>> graph[n];

    for(int i = 0; i < m; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        addEdge(graph, v1, v2, wt);
    }

    display(graph, n);
    return 0;
}

/*
Input:
7
8
0 1 10
1 2 10
2 3 10
0 3 10
3 4 10
4 5 10
5 6 10
4 6 10
*/