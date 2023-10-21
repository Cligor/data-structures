#include <iostream>
using namespace std;

bool hasBrother(int position) {
    return (position+1)%2 > 0;
}

void heapify(int* array, int numberOfMissingPositions) {
    // heapify
    for (int i = (numberOfMissingPositions - 1); i > 0; i--) {
        int fatherPosition = ((i + 1)/2) - 1;
        int father = array[fatherPosition];
        int greaterChildPosition = -1;

        if (hasBrother(i)) {
            int rightChild = array[i];
            int leftChild = array[--i];


            greaterChildPosition = rightChild > leftChild
                ? i+1
                : i;

        } else {
            greaterChildPosition = i;
        }

        cout <<  father << " é o pai de " << array[greaterChildPosition] << endl;
        
        if (father < array[greaterChildPosition]) {
            array[fatherPosition] = array[greaterChildPosition];
            array[greaterChildPosition] = father;
        }

        cout << "Novo pai é " << array[fatherPosition] << endl;
    }
}

int main() {
    int arraySize = 7;
    int array[arraySize] = {40,20,30,10,70,90,80};

    for (int i = arraySize; i > 0; i--) {
        heapify(array, i);
        int aux = array[i - 1];
        array[i - 1] = array[0];
        array[0] = aux;
    }

    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << "|";
    }

    cout << endl;

    return 0;
}