#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    int pass = 1;
    bool sorted = false;
    while(pass<size && !sorted) {
        sorted = true;
        for(int i=0; i<size-pass;i++) {
            if(arr[i] > arr[i+1])
                swap(arr[i], arr[i+1]);
                sorted = false;
        }
        pass++;
    }
    
}
void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
}
int main() {
    int arr[] = {5,4,3,2,1};
    bubbleSort(arr,5);
    printArray(arr,5);
    return 0;
}