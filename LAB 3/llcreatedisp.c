#include <stdio.h>
#include <stdlib.h>

int main(){
    struct node{
        int data;
        struct node *next;
    };

    struct node *head=NULL,*temp,*nnode;
    int option=1;
    
    while(option){
        nnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&nnode->data);
        nnode->next=NULL;
        if(head==NULL){
            head=nnode;
            temp=nnode;
        }
        else{
            temp->next=nnode;
            temp=nnode;
        }
        printf("Do you want to continue? Press 1 for yes and 0 for no: ");
        scanf("%d",&option);
    }

    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}
