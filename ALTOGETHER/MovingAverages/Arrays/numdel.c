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
int k; 
    printf("enter the deleting element index k:");
    scanf("%d",&k);
    for(i=k+1;i<size;i++){
        a[i-1]=a[i];
    }
    size--;
    for(i=0;i<size;i++){
         printf("%d",a[i]);
    
    }
    printf("\n");
    return 0;
}
