#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    int i,key; // sorted, unsorted;
    for(key=1; key<size; key++) {
        i = key - 1;
        while(i>=0 && arr[i] > arr[key]) {
            swap(arr[key], arr[i]);
            i--;
            key--;
        }
    }
}

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {5,4,3,2,1};
    insertionSort(arr,5);

    printArray(arr,5);
    return 0;
}