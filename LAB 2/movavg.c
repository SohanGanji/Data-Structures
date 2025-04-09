#include <stdio.h>

void movingav(int n, int arr[], int k){
    float average[n];
    int index=0;
    for(int r=0;r<k-1;r++){
        int sum=0;
        for(int j=0;j<=r;j++){
            sum+=arr[j];
        }
        average[r]=(float)sum/(r+1);
        index++;
    }
    for(int y=0;y<n-k+1;y++){
        int sum=0;
        for(int j=y;j<y+k;j++){
            sum+=arr[j];
        }
        average[index]=(float)sum/k;
        index++;
    }
    printf("The moving average is: \n");
    for(int i=0;i<n;i++){
        printf("%.2f ",average[i]);
    }
}
    

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: \n");
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int k;
    printf("Enter the window size: ");
    scanf("%d", &k);
    movingav(n, arr, k);
    return 0;
}

