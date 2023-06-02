#include <iostream>
#include <vector>
#include <Windows.h>
#include "Matrix.h"

using namespace std;

void PrintMenu() {
	cout << "Меню:" << endl;
	cout << "0. Ввод матрицы" << endl;
	cout << "1. Вывод матрицы" << endl;
	cout << "2. Сложение матриц" << endl;
	cout << "3. Вычитание матриц" << endl;
	cout << "4. Сравнение матриц" << endl;
	cout << "5. Умножение матрицы на число" << endl;
	cout << "6. Умножение матрицы на вектор" << endl;
	cout << "7. Нахождение определителя матрицы" << endl;
	cout << "8. Транспонирование матрицы" << endl;
	cout << "9. Нахождение обратной матрицы" << endl;

	cout << "q. Выход" << endl;
	cout << "Выберите опцию: ";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cols, rows;
	cout << "Введите количество строк в матрице\n";
	cin >> cols;
	cout << "Введите количество столбцов в матрице\n";
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
			cout << "Введите матрицу 1:\n";
			cin >> matrix1;
			cout << "Введите матрицу 2:\n";
			cin >> matrix2;
			break;
		}
		case '1': {
			cout << "Матрица 1:\n";
			cout << matrix1;
			cout << "Матрица 2:\n";
			cout << matrix2;
			break;
		}
		case '2': {
		
			Matrix sum = matrix1 + matrix2;
			cout << "Сумма матриц:\n";
			cout << sum;
			break;
		}
		case '3': {
			
			Matrix diff = matrix1 - matrix2;
			cout << "Разность матриц:\n";
			cout << diff;
			break;
		}
		case '4': {
			
			if (matrix1 == matrix2) {
				cout << "Матрицы равны\n";
			}
			else {
				cout << "Матрицы не равны\n";
			}
			break;
		}
		case '5': {
			
			double number;
			cout << "Введите число: ";
			cin >> number;
			Matrix product = matrix1 * number;
			cout << "Произведение матрицы на число:\n";
			cout << product;
			break;
		}
		case '6': {
			
			vector<double> vec;
			cout << "Введите вектор размерности " << cols << ":\n";
			for (int i = 0; i < cols; ++i) {
				double value;
				cout << "Элемент " << i + 1 << ": ";
				cin >> value;
				vec.push_back(value);
			}
			Matrix result = matrix1 * vec;
			cout << "Результат умножения матрицы на вектор:\n";
			cout << result;
			cout << endl;
			break;
		}
		case '7': {
			
			double determinant = matrix1.Determinant();
			cout << "Определитель матрицы 1: " << determinant << endl;
			break;
		}
		case '8': {
			Matrix transpose = matrix1.Transpose();
			cout << "Транспонированная матрица 1:\n";
			cout << transpose;
			break;
		}
		case '9': {
			Matrix inverse = matrix1.Inversion();
			cout << "Обратная матрица 1:\n";
			cout << inverse;
			break;
		}
		case 'q': {
			// Выход
			break;
		}
		default: {
			cout << "Некорректная опция. Попробуйте снова.\n";
			break;
		}

			   cout << endl;
		}
		


	}
	while (option != 'q');
}
