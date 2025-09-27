#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time
using namespace std;
int randnum(int from, int to) {
	return rand() % (to - from + 1) + from;
}
void read(int m[3][3], int n[3]) {
	for (int i = 0; i <3; i++) {
		n[i] = 0;
		for (int j = 0; j < 3;j++) {
			m[i][j] = randnum(1, 100);
			n [i] += m[i][j];
		}
	}
}
void write(int m[3][3], int n[3]) {
	for (int i = 0; i <3; i++) {
		for (int j = 0; j < 3;j++) {
			cout << m[i][j] << "  ";
		}
		cout << endl;
	}
	for (int i = 0; i < 3; i++) {
		cout << "SUM "<<i+1<< " " << n[i] << endl;

	}
}
int main()
{
	srand(time(0));
	int m[3][3], n[3];
	read(m, n);
	write(m, n);

}