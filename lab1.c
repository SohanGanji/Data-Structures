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

//deleting element
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

//searching element
int m;
printf("enter the element to search m:");
scanf("%d",&m); 
for(i=0;i<size;i++){
    if(a[i]==m){
        printf("the element is present in index %d",i);
    }
} 
printf("\n");
//bubble sort
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
//sorting even index elements
int b,temp1;  
for(i=0;i<size;i=i+2){
    for(b=i;b<size;b=b+2){
        if(a[b]<a[i]){
            temp1=a[i];
            a[i]=a[b];
            a[b]=temp1;

        }
    }

} 
for(i=0;i<size;i++){
    printf("%d ",a[i]);
}
//sorting odd index elements
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
//sorting even elements
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
