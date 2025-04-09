#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    printf("The list of elements is :-\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");

    bool add=true;
    while(add){
        int option=0;
        printf("Enter the position at which the data is to be added, press 1 for beginning, 2 for any specific position(except beginning and end), 3 for end: ");
        scanf("%d",&option);
        if(option==1){
            temp=head;
            int var=1;
            while(var){
                nnode=(struct node*)malloc(sizeof(struct node));
                printf("Enter the data: ");
                scanf("%d",&nnode->data);
                nnode->next=head;
                head=temp=nnode;
                temp=head;
                while(temp!=NULL){
                    printf("%d ",temp->data);
                    temp=temp->next;
                }
                printf("\n");
                printf("Do you want to add more nodes in the beginning? press 1 for yes and 0 for no: ");
                scanf("%d",&var);
            }
        }
        else if(option==2){
            int var=1;
            while(var){
                nnode=(struct node*)malloc(sizeof(struct node));
                temp=head;
                int pos;
                printf("Enter the position of the data to be inserted: ");
                scanf("%d",&pos);
                printf("Enter the data: ");
                scanf("%d",&nnode->data);
                nnode->next=NULL;
                for(int r=0;r<pos-2;r++){
                    temp=temp->next;
                }
                nnode->next=temp->next;
                temp->next=nnode;
                temp=head;
                while(temp!=NULL){
                    printf("%d ",temp->data);
                    temp=temp->next;
                }
                printf("\n");
                printf("Do you want to add more elements at specific position(except beginning and end)? press 1 for yes and 0 for no: ");
                scanf("%d",&var);
            }
        }
        else if(option==3){
            temp=head;
            int var=1;
            while(var){
                temp=head;
                while(temp->next!=0){
                    temp=temp->next;
                }
                nnode=(struct node*)malloc(sizeof(struct node));
                printf("Enter the data: ");
                scanf("%d",&nnode->data);
                temp->next=nnode;
                nnode->next=NULL;
                temp=nnode;
                temp=head;
                while(temp!=NULL){
                    printf("%d ",temp->data);
                    temp=temp->next;
                }
                printf("\n");
                printf("Do you want to add more elements at the end? press 1 for yes and 0 for no: ");
                scanf("%d",&var);
            }
        }
        else{
            printf("Invalid option\n");
        }
        printf("Do you want to add more data? Press 1 for yes and 0 for no: ");
        scanf("%d",&add);
    }

    temp=head;
    printf("The list after adding the elements is :-\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}
