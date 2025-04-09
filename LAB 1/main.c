#include <stdio.h>
#include <stdbool.h>

int main(){
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n+5];
    printf("Enter the elements of array : \n");
    for(int y=0;y<n;y++){
        scanf("%d",&arr[y]);
    } 
    printf ("---------------------------\n");
    int var;
    printf("For displaying the array, press 1.\n");
    printf("For inserting an element in the array, press 2.\n");
    printf("For deleting an element from the array, press 3.\n");
    printf("For searching an element, press 4.\n");
    printf("For sorting the array, press 5.\n");
    printf("For sorting the elements at even index, press 6.\n");
    printf("For sorting the elements at odd index, press 7.\n");
    printf("For sorting the even elements, press 8.\n");
    printf("For sorting the odd elements, press 9.\n");
    printf("Enter your choice : ");
    scanf("%d",&var);
    if(var==1){
        for(int g=0;g<n;g++){
            printf("%d ",arr[g]);
        }
    }
    else if(var==2){
        int ele,ind;
        printf("Enter the index at which element is to be inserted: ");
        scanf("%d",&ind);
        printf("Enter the element: ");
        scanf("%d",&ele);
        for(int y=n;y>ind;y--){
            arr[y]=arr[y-1];
        }
        arr[ind]=ele;
        printf("The new array is: \n");
        for(int g=0;g<n+1;g++){
            printf("%d ",arr[g]);
        }
    }
    else if(var==3){
        int delind;
        printf("Enter the index of the element to be deleted: ");
        scanf("%d",&delind);
        for(int t=delind;t<n-1;t++){
            arr[t]=arr[t+1];
        }
        printf("The new array is : \n");
        for(int f=0;f<n-1;f++){
            printf("%d ",arr[f]);
        }
    }
    else if(var==4){
        int search;
        printf("Enter the element to be searched: ");
        scanf("%d",&search);
        bool found=false;
        for(int z=0;z<n;z++){
            if(arr[z]==search){
                printf ("Element found and the index of the element is %d.",z);
                found=true;
                break;
            }
        }
        if(!found){
            printf("Element not found.");
        }
    }
    else if(var==5){
        for(int x=0;x<n-1;x++){
            int min_idx=x;
            
            for(int j=x+1;j<n;j++){
                if(arr[j]<arr[min_idx]){
                    min_idx=j;
                }
            }

            int temp=arr[x];
            arr[x]=arr[min_idx];
            arr[min_idx]=temp;
        }
        printf("The sorted array is: \n");
        for(int f=0;f<n;f++){
            printf("%d ",arr[f]);
        }
    }
    else if(var==6){
        for(int g=0;g<n;g+=2){
            for(int y=g+2;y<n;y+=2){
                if(arr[g]>arr[y]){
                    int temp=arr[y];
                    arr[y]=arr[g];
                    arr[g]=temp;
                }
            }
        }
        printf("The sorted array is: \n");
        for(int u=0;u<n;u++){
            printf("%d ",arr[u]);
        }
    }
    else if(var==7){
        for(int g=1;g<n;g+=2){
            for(int y=g+2;y<n;y+=2){
                if(arr[g]>arr[y]){
                    int temp=arr[y];
                    arr[y]=arr[g];
                    arr[g]=temp;
                }
            }
        }
        printf("The sorted array is: \n");
        for(int u=0;u<n;u++){
            printf("%d ",arr[u]);
        }
    }
    else if(var==8){
        for(int f=0;f<n-1;f++){
            for(int g=f+1;g<n;g++){
                if(arr[f]%2==0 && arr[g]%2==0 && arr[f]>arr[g]){
                    int temp=arr[f];
                    arr[f]=arr[g];
                    arr[g]=temp;
                }
            }
        }
        
        for(int r=0;r<n;r++){
            printf("%d ",arr[r]);
        }
    }
    else if(var==9){
        for(int f=0;f<n-1;f++){
            for(int g=f+1;g<n;g++){
                if(arr[f]%2!=0 && arr[g]%2!=0 && arr[f]>arr[g]){
                    int temp=arr[f];
                    arr[f]=arr[g];
                    arr[g]=temp;
                }
            }
        }
        
        for(int r=0;r<n;r++){
            printf("%d ",arr[r]);
        }
    }
    else{
        printf("Wrong choice entered!");
    }
    return 0;
}

