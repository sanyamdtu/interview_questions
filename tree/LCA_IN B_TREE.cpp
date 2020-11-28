/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

/* If n1 and n2 are present, return pointer
   to LCA. If both are not present, return 
   NULL. Else if left subtree contains any 
   of them return pointer to left.*/

Node* lca(Node* root ,int n1 ,int n2 )
{
    if(!root->left&&!root->right)
        return (root->data==n1||root->data==n2)?root:NULL;
    Node *l=NULL,*r=NULL;
    if(root->left)
        l=lca(root->left,n1,n2);
    if(root->right)    
        r=lca(root->right,n1,n2);
    if(l&&r)
        return root;
    else if(l){
        if(root->data==n1||root->data==n2)
            return root;
        return l;
    }
    else if(r){
        if(root->data==n1||root->data==n2)
            return root;
        return r;
    }
    else{
        if(root->data==n1||root->data==n2)
            return root;
        return NULL;
    }
}