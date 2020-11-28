#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node * root) {
        map<int,int> m;
        queue<pair<Node *,int>> q;
        if(root)
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            while(size){
                auto a=q.front();
                if(m.find({a.second})==m.end()){
                    m[a.second]=a.first->data;
                }
                q.pop();
                if(a.first->left){
                    q.push({a.first->left,a.second-1});
                }
                if(a.first->right){
                    q.push({a.first->right,a.second+1});
                }
                size--;
            }
        }
        for(auto i:m){
            cout<<i.second<<" ";
        }
    }

}; //End of Solution