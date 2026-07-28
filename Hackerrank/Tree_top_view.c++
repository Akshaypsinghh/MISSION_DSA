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
    
    if(root == NULL)
        return;

    map<int,int> mp;
    queue<pair<Node*,int>> q;

    q.push({root,0});
     while(!q.empty()){
        
        int size = q.size();
        
            Node* node  = q.front().first;
            int cnt = q.front().second;
            q.pop();
            
            if(mp.find(cnt) == mp.end()){
                
                mp[cnt] = node->data;
            }
            if(node->left){
                q.push({node->left,cnt-1});
            }
            if(node->right){
                q.push({node->right,cnt+1});
            }
            
        }
        for(auto it : mp){
            cout<<it.second<<" ";
        }
     

    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.topView(root);
    return 0;
}
