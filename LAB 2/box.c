#include <stdio.h>

int arrmedian(int arr[]){
    for(int i=0; i<9;i++){
        for(int j=0; j<9-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr[4];
}

int main(){
    int n;
    printf("Enter the order of matrix: ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter the elements of matrix: \n");

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    int median[(n-2)*(n-2)],ind=0;

    for(int i=0;i<n-2;i++){
        int k=0;
        while(k<n-2){
            int array[9],index=0;
            for(int j=i;j<=i+2;j++){
                for(int r=k;r<=k+2;r++){
                    array[index] = a[j][r];
                    index++;
                }
            }
            k++;
            median[ind] = arrmedian(array);
            ind++;
        }
    }

    int indmedian=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0 || i==n-1 || j==n-1){
                a[i][j] = 0;
            }
            else{
                a[i][j] = median[indmedian];
                indmedian++;
            }
        }
    }

    printf("The final matrix is : \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
