#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    struct node{
        int data;
        struct node *next;
    };

    struct node *head=NULL,*temp,*nnode,*temp1;           
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
        printf("Do you want to continue? press 1 for yes and 0 for no: ");
        scanf("%d",&option);
    }

    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");

    bool del=true;
    while(del){
        int option=0;
        printf("Enter the position of the elements to be deleted,press 1 for beginning, 2 for specific position(except beginning and end), 3 for end: ");
        scanf("%d",&option);

        if(option==1){
            bool r=true;
            while(r){
                temp=head;
                head=temp->next;
                free(temp);
                temp=head;
                while(temp!=NULL){
                    printf("%d ",temp->data);
                    temp=temp->next;
                }
                printf("\n");
                printf("Do you want to delete more elements from beginning? press 1 for yes and 0 for no: ");
                scanf("%d",&r);
            }
        }   

        else if(option==2){
            bool r=true;
            while(r){
                int pos;
                printf("Enter the position of element to be deleted: ");
                scanf("%d",&pos);
                temp=head;
                for(int f=0;f<pos-2;f++){
                    temp=temp->next;
                }
                temp1=temp->next;
                temp->next=temp1->next;
                free(temp1);
                temp=head;
                while(temp!=NULL){
                    printf("%d ",temp->data);
                    temp=temp->next;
                }
                printf("\n");
                printf("Do you want to delete more elements at specific position(except beginning and end)? press 1 for yes and 0 for no: ");
                scanf("%d",&r);
            }

        }  
        else if(option==3){
            bool r=true;
            while(r){
                temp=head;
                while(temp->next->next!=0){
                    temp=temp->next;
                }   
                free(temp->next);
                temp->next=NULL;
                temp=head;
                while(temp!=NULL){
                    printf("%d ",temp->data);
                    temp=temp->next;
                }
                printf("\n");
                printf("Do you want to delete more elements from end? press 1 for yes and 0 for no: ");
                scanf("%d",&r);
            }

        }
        else{
            printf("Invalid option\n");
        }
        printf("Do you want to delete more data? press 1 for yes and 0 for no: ");
        scanf("%d",&del);
    }
    
    printf("The list after deletion of elements is :-\n");
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}
