#include <stdio.h>

void merge(int arr[],int l, int mid, int h){
    int i=l;
    int j=mid+1;
    int k=l;
    int b[h+1];

    while(i<=mid && j<=h){
        if(arr[i]>arr[j]){
            b[k]=arr[j];
            k++;j++;
        }
        else{
            b[k]=arr[i];
            k++;i++;
        }
    }

    while(i<=mid){
        b[k]=arr[i];
        k++;i++;
    }

    while(j<h){
        b[k]=arr[j];
        k++;j++;
    }

    for(int d=l;d<=h;d++){
        arr[d]=b[d];
    }
}

void divide(int arr[],int l,int h){
    int mid=(l+h)/2;
    if(l<h){
        divide(arr,l,mid);
        divide(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}

int bin(int arr[],int l,int key,int n){
    l=0;
    int h=n-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

int main(){
    int len;
    printf("Enter the number of elements:- ");
    scanf("%d",&len);
    int arr[len];
    printf("Enter the elements:- \n");
    for(int g=0;g<len;g++){
        scanf("%d",&arr[g]);
    }
    int ele;
    printf("Enter the element which you want to search: ");
    scanf("%d",&ele);
    divide(arr,0,len-1);
    int c=bin(arr,0,ele,len-1);
    printf("%d",c);
    return 0;
}
