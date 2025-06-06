#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    struct node{
        int data;
        struct node *next;
    };

    struct node *temp1,*nnode1,*head1=NULL,*temp2,*nnode2,*head2=NULL,*temp3,*nnode3,*head3=NULL;
    int option=1;
    while(option){
        nnode1=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&nnode1->data);
        nnode1->next=NULL;
        if(head1==NULL){
            head1=temp1=nnode1;
        }
        else{
            temp1->next=nnode1;
            temp1=nnode1;
        }
        printf("Do you want to add more elements? press 1 for yes and 0 for no: ");
        scanf("%d",&option);
    }

    printf("The first list is :-\n");
    temp1=head1;
    while(temp1!=NULL){
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
    printf("\n");

    int var=1;
    while(var){
        nnode2=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&nnode2->data);
        nnode2->next=NULL;
        if(head2==NULL){
            head2=temp2=nnode2;
        }
        else{
            temp2->next=nnode2;
            temp2=nnode2;
        }
        printf("Do you want to add more elements? press 1 for yes and 0 for no: ");
        scanf("%d",&var);
    }

    printf("The second list is :-\n");
    temp2=head2;
    while(temp2!=NULL){
        printf("%d ",temp2->data);
        temp2=temp2->next;
    }
    printf("\n");

    temp1=head1;
    temp2=head2;
    while(temp1!=NULL && temp2!=NULL){
        nnode3=(struct node*)malloc(sizeof(struct node));
        nnode3->data=(temp1->data)+(temp2->data);
        nnode3->next=NULL;
        if(head3==NULL){
            head3=temp3=nnode3;
        }
        else{
            temp3->next=nnode3;
            temp3=nnode3;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }

    if(temp1==NULL && temp2==NULL){
        printf("The list after addition of the two lists is :-\n");
        temp3=head3;
        while(temp3!=NULL){
            printf("%d ",temp3->data);
            temp3=temp3->next;
        }
    }
    else{
        if(temp1==NULL){
            while(temp2!=NULL){
                nnode3=(struct node*)malloc(sizeof(struct node));
                nnode3->data=temp2->data;
                nnode3->next=NULL;
                if(head3==NULL){
                    head3=temp3=nnode3;
                }
                else{
                    temp3->next=nnode3;
                    temp3=nnode3;
                }
                temp2=temp2->next;
            }
        }
        else{
            while(temp1!=NULL){
                nnode3=(struct node*)malloc(sizeof(struct node));
                nnode3->data=temp1->data;
                nnode3->next=NULL;
                if(head3==NULL){
                    head3=temp3=nnode3;
                }
                else{
                    temp3->next=nnode3;
                    temp3=nnode3;
                }
                temp1=temp1->next;
            }
        }

        printf("The list after addition of the two lists is :-\n");
        temp3=head3;
        while(temp3!=NULL){
            printf("%d ",temp3->data);
            temp3=temp3->next;
        }
    }

    return 0;
}
