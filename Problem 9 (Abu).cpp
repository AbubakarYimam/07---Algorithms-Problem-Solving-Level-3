#include <iostream>
#include <iomanip>
using namespace std;

int randnum(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void fillmat(int arr[3][3]) {
    for (int i = 0;i < 3;i++) {
        for (int j = 0; j < 3;j++) {
            arr[i][j] = randnum(1, 10);
        }
    }
}

void printmat(int arr[3][3]) {
    for (int i = 0;i < 3;i++) {
        for (int j = 0; j < 3;j++) {
            cout<<setw(5)<<arr[i][j];
        }
        cout << "\n";
    }
}

void printmidcol(int arr[3][3],int j) {
    for (int i = 0; i < 3;i++) {
        cout <<setw(5)<< arr[i][j];
    }
}
void printmidrow(int arr[3][3], int j) {
    for (int i = 0; i < 3;i++) {
        cout <<setw(5)<< arr[j][i];
    }
}
int main()
{
    int arr[3][3];
    fillmat(arr);
    printmat(arr);
    cout << "\n\n\n";
    printmidcol(arr,1);
    cout << "\n\n";
    printmidrow(arr, 1);

}
