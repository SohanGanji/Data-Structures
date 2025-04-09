#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    int st[size];
    int top = -1,choice=1,temp;
    while(choice){
        int opt;
        printf("Press 1 for push function, 2 for pop function and 3 for print function: ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
            if(top==size-1) printf("Stack is full!\n");
            else{
                top++;
                printf("Enter the element to be pushed: ");
                scanf("%d",&st[top]);
            }
            break;
            case 2:
            if(top==-1) printf("Stack is empty!\n");
            else{
                printf("Popped element is: %d\n",st[top]);
                top--;
            }
            break;
            case 3:
            temp=top;
            while(temp!=-1){
                printf("%d ",st[temp]);
                temp--;
            }
            printf("\n");
            break;
            default:
            printf("Invalid choice!");
            break;
        }
        printf("Do you want to continue? press 1 for yes and 0 for no: ");
        scanf("%d",&choice);
    }
    return 0;
}