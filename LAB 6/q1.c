#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

int main(){
    struct node* head = NULL,*nnode,*temp;
    int i = 1;
    while(i){
        nnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&nnode->data);
        nnode->next=NULL;
        if (head==NULL){
            temp=head=nnode;
            temp->prev=NULL;
        }
        else{
            temp->next=nnode;
            nnode->prev=temp;
            temp=nnode;
        }
        printf("Do you want to continue? press 1 for yes and 0 for no: ");
        scanf("%d",&i);
    }

    printf("The linked list in forward direction:-\n");
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    printf("\n");

    printf("The linked list in backward direction is:-\n");
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
}
