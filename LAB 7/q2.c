#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){
    struct node *top=NULL,*nnode,*temp;
    int choice=1;
    while(choice){
        int opt;
        printf("Press 1 for push function, 2 for pop function and 3 for print function: ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
            nnode=(struct node*)malloc(sizeof(struct node));
            printf("Enter the data to be pushed: ");
            scanf("%d",&nnode->data);
            nnode->next=top;
            top=nnode;
            break;
            case 2:
            if(top==NULL){
                printf("stack is empty!\n");
            }
            else{
                printf("The data getting popped is: %d.\n",top->data);
                temp=top;
                top=top->next;
                free(temp);
            }
            break;
            case 3:
            temp=top;
            while(temp!=NULL){
                printf("%d ",temp->data);
                temp=temp->next;
            }
            printf("\n");
            break;
            default:
            printf("Invalid choice!\n");
        }
        printf("Do you want to continue? press 1 for yes and 0 for no: ");
        scanf("%d",&choice);
    }
    return 0;
}