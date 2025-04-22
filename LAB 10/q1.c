#include<stdio.h>
#include<stdlib.h>

struct treenode 
{
    int data;
    struct treenode * leftchild;
    struct treenode * rightchild;
}*rootnode;

struct treenode * createtree()
{
    int data;
    printf("Enter data for tree node : ");
    scanf("%d",&data);
    if (data==-1)
    {
        return NULL;
    }
    else
    {
        struct treenode * newnode =(struct treenode *)malloc(sizeof(struct treenode));
        newnode->data=data;
        printf("For leftchild of %d :\n",data);
        newnode->leftchild=createtree();
        printf("For rightchild of %d :\n",data);
        newnode->rightchild=createtree();
        return newnode;
    }
}
void inordertraversal(struct treenode * rootnode)
{
    if (rootnode==NULL)
    {
        return;
    }
    inordertraversal(rootnode->leftchild);
    printf("%d ",rootnode->data);
    inordertraversal(rootnode->rightchild);
}
void preordertraversal(struct treenode * rootnode)
{
    if (rootnode==NULL)
    {
        return;
    }
    printf("%d ",rootnode->data);
    preordertraversal(rootnode->leftchild);
    preordertraversal(rootnode->rightchild);
}

void postordertraversal(struct treenode * rootnode)
{
    if (rootnode==NULL)
    {
        return;
    }
    postordertraversal(rootnode->leftchild);
    postordertraversal(rootnode->rightchild);
    printf("%d ",rootnode->data);
}
int main(int argc, char const *argv[])
{
    rootnode=createtree();
    printf("Tree INORDER Traversal :\n");
    inordertraversal(rootnode);
    printf("\nTree PREORDER Traversal : \n");
    preordertraversal(rootnode);
    printf("\nTree POSTORDER Traversal :\n");
    postordertraversal(rootnode);
    return 0;
}