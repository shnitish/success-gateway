#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    vector<Node*> children;
};

class GTree
{
    public:
    Node *contruct(vector<int> arr)
    {
        stack<Node*> s;
        Node *root = NULL;
        
        for(int i = 0; i < arr.size(); i++)
        {
            int val = arr[i];
            
            if(val == -1)
                s.pop();
            
            else
            {
                Node *n = new Node();
                n->data = val;
                
                if(s.size() > 0)
                    s.top()->children.push_back(n);
                
                else
                    root = n;
                
                s.push(n);
            }
        }
        return root;
    }

    void display(Node *root)
    {
        cout << root->data << "->";
        for(int i = 0; i < root->children.size(); i++)
        {
            Node *child = root->children[i];
            cout << child->data << ",";
        }
        cout << "." << endl;

        // recur for root's children
        for(int i = 0; i < root->children.size(); i++)
        {
            Node *child = root->children[i];
            display(child);
        }
    }
};

int main()
{
    GTree obj;
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    Node *root = obj.contruct(arr);

    obj.display(root);
    return 0;
}