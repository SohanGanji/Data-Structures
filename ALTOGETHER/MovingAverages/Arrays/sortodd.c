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

int c,temp2;  
for(i=1;i<size;i++){
    for(c=i;c<size;c++){
        if(a[c]<a[i]){
            temp2=a[i];
            a[i]=a[c];
            a[c]=temp2;

        }
    }

} 
    return 0;
}