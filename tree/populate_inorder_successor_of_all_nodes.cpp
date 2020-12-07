

/* Set next of p and all descendents of p by traversing them in reverse Inorder */

/*
Node Structure

struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *next;
	
	node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    next = NULL;
	}
};
*/

void populateNext(struct node *p)
{
    if (!p)
        return;
    node *prev = NULL;
    node *curr = p;
    while (curr)
    {
        if (!curr->left)
        {
            if (prev)
                prev->next = curr;
            prev = curr;
            curr = curr->right;
        }
        else
        {
            node *temp = curr->left;
            while (temp->right && temp->right != curr)
                temp = temp->right;
            if (temp->right == NULL)
            {
                temp->right = curr;
                curr = curr->left;
            }
            else
            {
                if (prev)
                    prev->next = curr;
                prev = curr;
                temp->right = NULL;
                curr = curr->right;
            }
        }
    }
}