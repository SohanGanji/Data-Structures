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
int m;
printf("enter the element to search m:");
scanf("%d",&m); 
for(i=0;i<size;i++){
    if(a[i]==m){
        printf("the element is present in index %d",i);
    }
} 
printf("\n");
    return 0;
}