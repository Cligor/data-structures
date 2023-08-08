#include <iostream>
using namespace std;

int* insertionSort(int array[], int n) {
    if (n >= 2) {
        for(int i = 0; i < n; i++) {
            int minPosition = i;
        
            for (int j = i+1; j < n; j++) {
                minPosition = array[j] < array[minPosition]
                    ? j
                    : minPosition;
            }
            
            if (minPosition != i) {
                int aux = array[i];
                array[i] = array[minPosition];
                array[minPosition] = aux;
            }
        }
    }
}

int main() {
    int n = 5;
    int array[n] = {5,9,2,7,1};
    int* orderedArray = insertionSort(array, n);
    
    cout << "|";
    for(int i = 0; i < 5; i++) {
        cout << array[i] << "|";
    }

    cout << endl;
    return 0;
}
