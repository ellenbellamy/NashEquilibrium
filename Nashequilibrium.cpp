#include <iostream>
#include <vector>
#include <fstream>
#include"Header.h"

using namespace std;

int main() {
	vector<MM> A;
	vector<MM> B;
	int m, n, x;
	int max;

	ifstream file("Text.txt");

	cout << "Enter size of matrix A and B" << endl;
	cin >> m >> n;

	int** a = new int* [m];		//строки					// создаем 
	for (int i = 0; i < m; i++) {          // двумерный
		a[i] = new int[n];				 // массив 
	}
	int** b = new int* [m];					// создаем 
	for (int i = 0; i < m; i++) {          // двумерный
		b[i] = new int[n];				// массив 
	}

	cout << "Consol(0) or (file)" << endl;
	cin >> x;
	while (x!=0 && x!=1) {
		cin >> x;
	}
	if (x == 0) {
		cout << "Matrix A: " << endl;

		read(a, m, n);

		cout << "Matrix B: " << endl;

		read(b, m, n);
	}
	else {
		readf(a, b, m, n);
	}

	maxColumn(a, m, n, A);

	maxRow(b, m, n, B);
	
	vector<MM> Z = result(A, B);

	for (auto c : Z) {
		cout << "(" << c.y + 1 << "," << c.x + 1 << ")";
	}
}
