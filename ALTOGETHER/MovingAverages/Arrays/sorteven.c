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
for(int i = 0;i<n;i++)
{
   for(int j=i+1;j<n;j++){
    if((A[i]%2 == 0) && (A[j]%2 == 0))
        {
            if(A[i]>A[i+1])
            {
                int temp= A[i+1];
                A[i+1] = A[i];
                A[i] = temp;
            }
        }

   }
}

for(i=0;i<size;i++){
    printf("%d ",a[i]);
}
    return 0;
}