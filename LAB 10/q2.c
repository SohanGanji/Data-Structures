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

int heightoftree(struct treenode * rootnode)
{
    if(rootnode==NULL)
    {
        return -1;
    }
    int lheight=heightoftree(rootnode->leftchild);
    int rheight=heightoftree(rootnode->rightchild);
    return ((lheight>rheight)?lheight:rheight)+1;
}
int depthoftree(struct treenode * rootnode)
{
    if(rootnode==NULL)
    {
        return -1;
    }
    int ldepth=depthoftree(rootnode->leftchild);
    int rdepth=depthoftree(rootnode->rightchild);
    return ((ldepth>rdepth)?ldepth:rdepth)+1;
    
}

int main(int argc, char const *argv[])
{
    rootnode=createtree();

    printf("\nTree PREORDER Traversal : \n");
    preordertraversal(rootnode);

    printf("\nHeight of tree is : %d\n",heightoftree(rootnode));
    printf("Depth of Tree : %d\n",depthoftree(rootnode));

    return 0;
}