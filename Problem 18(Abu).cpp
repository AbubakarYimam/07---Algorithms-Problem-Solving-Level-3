#include <iostream>
#include <iomanip>
using namespace std;
int randnum(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void fillmat(int arr[3][3]) {
    for (int i = 0;i < 3;i++) {
        for (int j = 0; j < 3;j++) {
            arr[i][j] = randnum(0, 10);
        }
    }
}

void printmat(int arr[3][3]) {
    for (int i = 0;i < 3;i++) {
        for (int j = 0; j < 3;j++) {
            printf(" %03d ",arr[i][j]);
        }
        cout << "\n\n";
    }
    
}

void listInter(int arr1[3][3], int arr2[3][3]) {
    for (int i = 0;i < 3;i++) {
        for (int j = 0; j < 3;j++) {
            int a = arr1[i][j];
            for (int l = 0;l < 3;l++) {
                for (int k = 0;k < 3;k++) {
                    if (a == arr2[l][k]) {
                        cout << a << "   ";
                    }
                }
            }
        }
    }
}
int main()
{
    int arr1[3][3], arr2[3][3];
    fillmat(arr1);
    cout << "\nMatrix 1 :\n";
    printmat(arr1);
    fillmat(arr2);
    cout << "\nMtrix 2  :\n";
    printmat(arr2);
    cout << "\n\nThe Intersecton Numbers is \n\n";
    listInter(arr1, arr2);

}
