#include <iostream>
#include <vector>
#include <Windows.h>
#include "Matrix.h"

using namespace std;

void PrintMenu() {
	cout << "����:" << endl;
	cout << "0. ���� �������" << endl;
	cout << "1. ����� �������" << endl;
	cout << "2. �������� ������" << endl;
	cout << "3. ��������� ������" << endl;
	cout << "4. ��������� ������" << endl;
	cout << "5. ��������� ������� �� �����" << endl;
	cout << "6. ��������� ������� �� ������" << endl;
	cout << "7. ���������� ������������ �������" << endl;
	cout << "8. ���������������� �������" << endl;
	cout << "9. ���������� �������� �������" << endl;

	cout << "q. �����" << endl;
	cout << "�������� �����: ";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cols, rows;
	cout << "������� ���������� ����� � �������\n";
	cin >> cols;
	cout << "������� ���������� �������� � �������\n";
	cin >> rows;

	Matrix matrix1(rows, cols);
	Matrix matrix2(rows, cols);
	Matrix result(rows, cols);

	char option;
	do {
		PrintMenu();
		cin >> option;

		switch (option) {
		case '0': {
			cout << "������� ������� 1:\n";
			cin >> matrix1;
			cout << "������� ������� 2:\n";
			cin >> matrix2;
			break;
		}
		case '1': {
			cout << "������� 1:\n";
			cout << matrix1;
			cout << "������� 2:\n";
			cout << matrix2;
			break;
		}
		case '2': {
		
			Matrix sum = matrix1 + matrix2;
			cout << "����� ������:\n";
			cout << sum;
			break;
		}
		case '3': {
			
			Matrix diff = matrix1 - matrix2;
			cout << "�������� ������:\n";
			cout << diff;
			break;
		}
		case '4': {
			
			if (matrix1 == matrix2) {
				cout << "������� �����\n";
			}
			else {
				cout << "������� �� �����\n";
			}
			break;
		}
		case '5': {
			
			double number;
			cout << "������� �����: ";
			cin >> number;
			Matrix product = matrix1 * number;
			cout << "������������ ������� �� �����:\n";
			cout << product;
			break;
		}
		case '6': {
			
			vector<double> vec;
			cout << "������� ������ ����������� " << cols << ":\n";
			for (int i = 0; i < cols; ++i) {
				double value;
				cout << "������� " << i + 1 << ": ";
				cin >> value;
				vec.push_back(value);
			}
			Matrix result = matrix1 * vec;
			cout << "��������� ��������� ������� �� ������:\n";
			cout << result;
			cout << endl;
			break;
		}
		case '7': {
			
			double determinant = matrix1.Determinant();
			cout << "������������ ������� 1: " << determinant << endl;
			break;
		}
		case '8': {
			Matrix transpose = matrix1.Transpose();
			cout << "����������������� ������� 1:\n";
			cout << transpose;
			break;
		}
		case '9': {
			Matrix inverse = matrix1.Inversion();
			cout << "�������� ������� 1:\n";
			cout << inverse;
			break;
		}
		case 'q': {
			// �����
			break;
		}
		default: {
			cout << "������������ �����. ���������� �����.\n";
			break;
		}

			   cout << endl;
		}
		


	}
	while (option != 'q');
}
