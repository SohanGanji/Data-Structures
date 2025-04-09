#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

int main(){
    struct node* head = NULL,*nnode,*temp;
    int i=1,count=0;
    while(i){
        nnode=(struct node*)malloc(sizeof(struct node));
        count++;
        printf("Enter the data: ");
        scanf("%d",&nnode->data);
        nnode->next=NULL;
        if(head==NULL){
            head=temp=nnode;
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

    printf("The linked list is:-\n");
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");

    int q=1;
    while(q){
        int loc;
        nnode=(struct node*)malloc(sizeof(struct node));
        count++;
        nnode->next=nnode->prev=NULL;
        printf("Enter the data for the node to be inserted: ");
        scanf("%d",&nnode->data);
        printf("Enter the position of the node to be inserted in the linked list: ");
        scanf("%d",&loc);

        if(loc>count+1){
            printf("This position is not possible!\n");
        }
        else if(loc==1){
            temp=head;
            temp->prev=nnode;
            nnode->next=temp;
            head=nnode;
        }
        else if(loc==count){
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=nnode;
            nnode->prev=temp;
        }
        else{
            temp=head;
            int i;
            for(i=1;i<loc-1;i++){
                temp=temp->next;
            }
            nnode->next=temp->next;
            temp->next->prev=nnode;
            temp->next=nnode;
            nnode->prev=temp;
        }

        printf("The linked list after node insertion is:-\n");
        temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
        printf("Do you want to insert another node? press 1 for yes and 0 for no: ");
        scanf("%d",&q);
    }
}