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
int l,temp;
for(i=0;i<size;i++){
    for(l=i+1;l<size;l++){
        if(a[l]<a[i]){
            temp=a[i];
            a[i]=a[l];
            a[l]=temp;
        }

    }
}
for(i=0;i<size;i++){
    printf("%d ",a[i]);
}
    return 0;
}