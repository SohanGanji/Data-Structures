#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *tail = NULL, *nnode, *temp=NULL;
    int i=1;
    while (i) {
        nnode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data for node: ");
        scanf("%d", &nnode->data);
        nnode->next = NULL;
        if (head == NULL) {
            head = tail = nnode;
            nnode->next = head;
        } else {
            tail->next = nnode;
            tail = nnode;
            tail->next = head;
        }
        printf("Do you want to continue? Press 1 for yes and 0 for no: ");
        scanf("%d", &i);
    }
    temp=head;
    while(temp!=tail){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ",tail->data);
    return 0;
}