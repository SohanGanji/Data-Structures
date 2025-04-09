#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){
    struct node* head = NULL,*temp,*nnode,*var,*temp1,*prev;
    int q=1;
    while(q){
        nnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&nnode->data);
        nnode->next=NULL;
        if(head==NULL){
            head=temp=nnode;
        }
        else{
            temp->next=nnode;
            temp=nnode;
        }
        printf("Do you want to continue? press 1 for yes and 0 for no: ");
        scanf("%d",&q);
    }
    printf("The original list is:-\n");
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    temp=var=head;
    while(temp!=NULL){
        if(temp->data<var->data){
            var=temp;
        }
        temp=temp->next;
    }
    prev=head;
    while(prev->next!=var){
        prev=prev->next;
    }

    temp1=var->next;
    var->next=head->next;
    prev->next=head;
    head->next=temp1;
    head=var;
    temp=head;

    temp=var=head;    
    while(temp!=NULL){
        if(temp->data>var->data){
            var=temp;
        }
        temp=temp->next;
    }

    temp=prev=head;
    temp1=var->next;
    while(temp->next!=NULL){
        temp=temp1->next;
    }

    while (prev->next!=var){
        prev=prev->next;
    }
    
    var->next=0;
    prev->next=temp1->next;
    temp1->next=var;
    temp->next=temp1;

    temp=head;
    printf("The modified list is:-\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}
