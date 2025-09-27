#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

int randnum(int from, int to) {
	return rand() % (to - from + 1) + from;
}

void Fillmatrix(int arr[3][3], int row, int col) {
	for (int i = 0;i < row;i++) {
		for (int j = 0; j < col;j++) {
			arr[i][j] = randnum(1, 100);
		}
	}
}

void printmatrix(int arr[3][3], int row, int col) {
	cout << "\nThe Matrix  \n";
	for (int i = 0; i < row;i++) {
		for (int j = 0; j < col;j++) {
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}
	
}

int fillsum(int arr[3][3], int a[3], int col, int row) {
	a[col] = 0;
	for (int i = 0;i < row;i++) {
		a[col] += arr[i][col];
	}
	return a[col];
}

void printsum(int arr [3][3],int a[3], int col, int row) {
	for (int i = 0;i < col;i++) {
		cout << "SUM " << i + 1 << " " << fillsum(arr, a, i, row) << endl;;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3], a[3];
	Fillmatrix(arr, 3, 3);
	printmatrix(arr, 3, 3);
	fillsum(arr, a, 3, 3);
	printsum(arr, a, 3, 3);
   
}
