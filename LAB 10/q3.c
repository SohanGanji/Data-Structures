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

int countTotalandLeafNodes(struct treenode * rootnode,int * leaves)
{
    if (rootnode==NULL)
    {
        return 0;
    }
    if(rootnode->leftchild==NULL && rootnode->rightchild==NULL)
    {
        *leaves+=1;
    }
    return 1 + countTotalandLeafNodes(rootnode->leftchild,leaves) + countTotalandLeafNodes(rootnode->rightchild,leaves);
}

int main(int argc, char const *argv[])
{
    rootnode=createtree();

    printf("\nTree PREORDER Traversal : \n");
    preordertraversal(rootnode);
    

    int leaves=0;
    int totalnodes=countTotalandLeafNodes(rootnode,&leaves);
    printf("Total nodes in tree : %d\n",totalnodes);
    printf("Leaf Nodes in tree : %d\n",leaves);
    printf("Internal Nodes in tree : %d\n",totalnodes-leaves);
    return 0;
}