#include <stdio.h>

void expomovingav(int n,int arr[],int k){
    float average[n],alpha=2.0/(k+1);
    for(int r=0;r<n;r++){
        if(r==0){
            average[r]=arr[r];
        }
        else{
            average[r]=(arr[r]*alpha) + (average[r-1]*(1-alpha));
        }
    }
    printf("The exponential moving average is: \n");
    for(int i=0;i<n;i++){
        printf("%.2f ",average[i]);
    }
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int k;
    printf("Enter the window size: ");
    scanf("%d", &k);
    expomovingav(n, arr, k);
    return 0;
}
