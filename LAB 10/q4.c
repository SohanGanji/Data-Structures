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

struct treenode *  insertnodeinBST(struct treenode * rootnode,int insertdata)
{
    if (rootnode==NULL)
    {
        struct treenode * newnode=(struct treenode * )malloc(sizeof(struct treenode));
        newnode->data=insertdata;
        newnode->leftchild=newnode->rightchild=NULL;
        return newnode;
    }
    
    if (rootnode->data>insertdata)
    {
        rootnode->leftchild = insertnodeinBST(rootnode->leftchild,insertdata);
    }
    else 
    {
       rootnode->rightchild = insertnodeinBST(rootnode->rightchild,insertdata);
    }
    
    return rootnode;
}

struct treenode * searchintree(struct treenode * rootnode,int element)
{
    if (rootnode==NULL || rootnode->data==element)
    {
        return rootnode;
    }
    if (rootnode->data > element)
    {
        return searchintree(rootnode->leftchild,element);
    }
    else
    {
        return searchintree(rootnode->rightchild,element);
    }
}
int main(int argc, char const *argv[])
{
    rootnode=createtree();
    printf("Tree INORDER Traversal :\n");
    inordertraversal(rootnode);

    insertnodeinBST(rootnode,12);
    inordertraversal(rootnode);

    if(searchintree(rootnode,13))
    {
        printf("\nElement is present in Tree\n");
    }
    else
    {
        printf("\nElement is not present in BST\n");
    }
    return 0;
}