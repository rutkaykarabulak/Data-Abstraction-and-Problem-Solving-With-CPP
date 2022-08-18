#include <iostream>
using namespace std;

int findLargestIndexOfArray(const int arr[], int last) {
    int largestIndexSoFar = 0;

    for(int i=1; i<last; i++) {
        if(arr[i] > arr[largestIndexSoFar])
            largestIndexSoFar = i;
    }

    return largestIndexSoFar;
}

void bubbleSort(int arr[], int size) {
    for(int i = size-1; i>0; i--) {
        int largestIndex = findLargestIndexOfArray(arr, i+1);

        swap(arr[largestIndex], arr[i]);
    }
};

int main() {
    int arr[] = {5,4,3,2,1};

    bubbleSort(arr,5);

    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}