#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left,*right;
};

struct node *newnode(int item)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->key=item;
    temp->left=temp->right=NULL;
    return temp;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\n",root->key);
        inorder(root->right);
    }
}

struct node* insert(struct node *node,int key)
{
    if(node==NULL) return newnode(key);

    if(key<node->key)
        node->left=insert(node->left,key);
    else
        node->right=insert(node->right,key);

    return node;
};

struct node *minvalue(struct node* node)
{
    struct node* current=node;

    while(current->left!=NULL)
        current=current->left;

    return current;
};


struct node* deletenode(struct node* root,int key)
{
    if(root==NULL) return root;

    if(key<root->key)
        root->left=deletenode(root->left,key);

    else if(key>root->key)
        root->right=deletenode(root->right,key);

    else
    {
        if(root->left==NULL)
        {
            struct node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }

        struct node *temp=minvalue(root->right);

        root->key=temp->key;
        root->right=deletenode(root->right,temp->key);

    }
    return root;
}

int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    printf("\nDelete 20\n");
    root = deletenode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 30\n");
    root = deletenode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 50\n");
    root = deletenode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    return 0;
}
