/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
vector<int> ans;
void func(Node *&root){
    if(root->left==NULL&&root->right==NULL){
        ans.push_back(root->data);
        return ;
    }
    if(root->left)
        func(root->left);
    if(root->right)
        func(root->right);
}
vector <int> printBoundary(Node *root)
{
    ans.clear();
   if(root)
        ans.push_back(root->data);
    vector<int> right;
    Node * curr=root->left;
    while(curr&&(curr->left||curr->right)){
         ans.push_back(curr->data);
         if(curr->left)
            curr=curr->left; 
         else
            curr=curr->right;
     }
     curr=root->right;
     while(curr&&(curr->left||curr->right)){
         right.push_back(curr->data);
         if(curr->right)
            curr=curr->right;
         else
            curr=curr->left;
     }
     if(root->left||root->right)
     	func(root);
     reverse(right.begin(),right.end());
     for(auto i:right)
         ans.push_back(i);
     return ans;
}