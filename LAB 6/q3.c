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
        struct node* var=head;
        printf("Enter the position of the node to be deleted in the linked list: ");
        scanf("%d",&loc);

        if(loc>count || count==0){
            printf("Node deletion not possible!\n");
        }
        else if(loc==1){
            temp=var=head;
            temp->next->prev=NULL;
            head=temp->next;
            free(var);
        }
        else if(loc==count){
            var=head;
            while(var->next!=NULL){
                var=var->next;
            }
            var->prev->next=0;
            free(var);
        }
        else{
            var=head;
            int i;
            for(i=1;i<loc;i++){
                var=var->next;
            }
            var->prev->next=var->next;
            var->next->prev=var->prev;
            free(var);
        }

        printf("The linked list after node deletion is:-\n");
        temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
        count--;
        printf("Do you want to delete another node? press 1 for yes and 0 for no: ");
        scanf("%d",&q);
    }
}