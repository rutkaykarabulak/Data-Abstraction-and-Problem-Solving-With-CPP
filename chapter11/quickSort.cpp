#include <iostream>
using namespace std;

// Assumes array has at least 3 element.
void sortFirstMiddleLast(int arr[], int first, int mid, int last) {
    if (arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
    if (arr[mid] > arr[last])
        swap(arr[mid], arr[last]);
    if (arr[first] > arr[last])
        swap(arr[first], arr[last]);
}

void displayArray(const int arr[], const int last) {
    for(int i=0; i<=last;i++) {
        cout << arr[i] << " ";
    }
}

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

// automatically selects last item as a pivot
int partitioning(int arr[], int first, int last) {
    int mid = first + last / 2;
    sortFirstMiddleLast(arr, first, mid, last);
    swap(arr[mid], arr[last-1]);
    int pivotIndex = last-1;
    int pivot = arr[last-1];

    int indexFromLeft = first + 1;
    int indexFromRight = last - 2;

    bool done = false; // indicates whether partioning is done or not

    while(!done) {
        while(arr[indexFromLeft] < arr[pivotIndex])
            indexFromLeft++;
        while(arr[indexFromRight] > arr[pivotIndex])
            indexFromRight--;
        
        if(indexFromLeft < indexFromRight) {
            swap(arr[indexFromLeft], arr[indexFromRight]);
            indexFromLeft++;
            indexFromRight--;
        } else {
            done = true;
        }
    }
    swap(arr[indexFromLeft], arr[pivotIndex]);
    pivotIndex = indexFromLeft;

    return pivotIndex;

}

/**
 * Sorts the arr[first..last]
*/
void quickSort(int arr[], int first, int last) {
    if(last - first + 1 < 4) {
        insertionSort(arr, last-first+1);
    } else {
        int pivotIndex = partitioning(arr, first, last);

        quickSort(arr, first, pivotIndex-1);
        quickSort(arr, pivotIndex+1, last);
    } 
}



int main() {
    int arr[] = {1,2,1,12,3,4,13};
    quickSort(arr, 0, 6);
    displayArray(arr, 6);
    return 0;
}