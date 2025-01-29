#include<stdio.h>
int main()
{    
    int size,i;
    int a[100];
    printf("enter size:");
    scanf("%d",&size);
    printf("enter the elements of array:");
    for(i=0;i<size;i++){ 
        scanf("%d",&a[i]);
        printf("%d ",a[i]);   
    }
 
    printf("\n");

int n,j;
    printf("enter the inserting number n:\n");
    scanf("%d",&n);
    printf("enter the index of insertion j:");
    scanf("%d",&j);
    for(i=size-1;i>=j;i--){
        a[i+1]=a[i];
    }
    size++;
    a[j]=n;
    for(i=0;i<size;i++){
        printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}

