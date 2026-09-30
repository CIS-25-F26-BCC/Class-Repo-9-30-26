#include <iostream>

using namespace std;

// int myFunction(int x, int arr[])

int * allocateArray(int size) {
    int * arr = new int[size];

    for(int i = 0; i < size; i++) {
        arr[i] = 0;
    }

    return arr;
    // the memory is never deleted...
}

// if we call this function from main as-is...
// we get a memory leak.
void doSomeStuff() {
    int * x = allocateArray(5);
    // do some stuff
    // now we're done...
    return;
}

int main() {
    // int myInteger = 5;
    // cout << "\n\nThe value of myInteger is: " << myInteger << "\n\n";
    // cout << "\n\nThe address of myInteger is: " << &myInteger << "\n\n";
    // int * myPointer;
    // myPointer = &myInteger;
    // cout << "\n\nThe value of myPointer is: " << myPointer << "\n\n";
    // cout << "\n\nThe address of myPointer is: " << &myPointer << "\n\n";

    int size = 50;

    cout << "\n\nPlease put in the size of the class: ";

    cin >> size;

    // manually creating the array in main...
    
    // int studentIDs[size]; // this is wrong, not C++, and will not necessarily.

    // double * studentIDs = new double[size];

    // for(int i = 0; i < size; i++) {
    //     cout << "\n\nPlease put in the studentID for the " << i << " index: ";
    //     cin >> studentIDs[i];
    //     cout << "\n\nThe memory address where that student ID will be stored is: " << &studentIDs[i];
    // }

    // or instead, we can use the function above 

    int * studentIDs = allocateArray(size);

    for(int i = 0; i < size; i++) {
        cout << "\n\n" << studentIDs[i];
    }

    cout << "\n\nUsing dereferencing syntax...\n\n";

    for(int i = 0; i < size; i++) {
        cout << "\n\nAddress: " << (studentIDs + i);
        cout << "\nValue: " << *(studentIDs + i);
    }

    cout << "\n\n";

    delete studentIDs; // deleting the thing at this memory address.
    // DANGER "DANGLING POINTER"
    studentIDs = nullptr; // retiring the memory address value (which now points to nothing, or to garbage, or something else)

    cout << "\n\nThe pointer points to: " << studentIDs;
    cout << "\nThe value at that location is: " << studentIDs[0];

    return 0;
}