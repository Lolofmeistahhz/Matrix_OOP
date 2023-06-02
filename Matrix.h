#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Matrix {
protected:
	int _rows{}, _cols{};
	std::vector<std::vector<double>> _matrix;
public:
	Matrix();
	Matrix(int rows, int cols);

	void FillRandom();

	std::vector<double>& operator[](int index);

	Matrix operator=(Matrix& other);
	Matrix operator+(Matrix& other);
	Matrix operator*(const vector<double> vec) const;
	Matrix operator*(double number);
	Matrix operator-(Matrix& other);

	bool operator==(Matrix& other);
	bool operator!=(Matrix& other);

	double Determinant();
	Matrix CreateSubmatrix(Matrix& matrix, int row, int col) ;
	Matrix Transpose() const;
	Matrix Inversion();

	friend std::istream& operator>>(istream& in, Matrix& matrix);
	friend std::ostream& operator<<(ostream& out, Matrix& matrix);
};

#endif
