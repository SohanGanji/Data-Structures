#include <stdio.h>

int main() {
	int n;
    printf("enter array size : ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("entered input is :\n");
    for(int i=0;i<n;i++){
    
    printf("%d\n",a[i]);
    }

    int t;
    printf("no of elements : ");
    scanf("%d",&t);

    for(int i=0;i<t;i++){
        int  j;
        printf("enter element : ");
        scanf("%d",&j);
        printf("%d\n",a[j]);
    }
 
    return 0;
}