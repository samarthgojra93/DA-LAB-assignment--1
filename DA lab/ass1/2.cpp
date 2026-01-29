//Implement Merge sort for the given array int arr[] = {12, 11, 13, 5, 6, 7}. After implementing Merge Sort, apply the same implementation to sort another array: int arr2[] = {38, 27, 43,3, 9, 82, 10}.

#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r) {

    int n1= mid - l + 1;
    int n2= r - mid;

    int a[n1];
    int b[n2];

    for (int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }

    for (int j=0;j<n2;j++){
        b[j]=arr[mid + 1 + j];
    }

    int i=0;
    int j=0;
    int k=l;
    while (i<n1 && j<n2){
        if (a[i]<b[j]){
            arr[k]=a[i];
            i++;
            k++;
        }
        else{
            arr[k]=b[j];
            j++;
            k++;
        }
    }
    while (i<n1){
        arr[k]=a[i];
        i++;
        k++;
    }
    while (j<n2){
        arr[k]=b[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if (l<r){
        int mid = l + (r - l) / 2;

        mergeSort(arr, l , mid );
        mergeSort(arr, mid + 1 , r);

        merge(arr,l,mid,r);
    }
}

int main(){

    int arr[]={12, 11, 13, 5, 6, 7};
    mergeSort(arr,0,5);
    for (int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int arr2[]={38, 27, 43, 3, 9, 82, 10};
    mergeSort(arr2,0,6);
    for (int i=0;i<7;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;

    return 0;
}