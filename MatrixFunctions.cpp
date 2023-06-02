#include <iostream>
#include <vector>
#include "Matrix.h"

using namespace std;

Matrix::Matrix() {}

Matrix::Matrix(int rows, int cols) : _rows(rows), _cols(cols), _matrix(rows, vector<double>(cols)) {
}

void Matrix::FillRandom() {
    cout << "Заполнение матрицы случайными числами\n";
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            double randomValue = static_cast<double>(rand()) / (RAND_MAX / 10.0);
            _matrix[i][j] = randomValue;
        }
    }
}

vector<double>& Matrix::operator[](int index) {
    if (index >= 0 && index < _rows) {
        return _matrix[index];
    }
    else {
        cout << "Некорректный индекс";
    }
}

Matrix Matrix::operator=(Matrix& other) {
    if (_matrix.size() != other._matrix.size()) {
        cout << "Выполнить операцию - невозможно\n";
    }
    else {
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _cols; ++j) {
                if (_matrix[i][j] == other[i][j]) {
                    return *this;
                }
                else {
                    _matrix[i][j] = other[i][j];
                }
            }
        }
        return *this;
    }
}

Matrix Matrix::operator+(Matrix& other) {
    if (_matrix.size() != other._matrix.size()) {
        cout << "Выполнить операцию - невозможно\n";
    }
    else {
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _cols; ++j) {
                _matrix[i][j] = _matrix[i][j] + other[i][j];
            }
        }
        return *this;
    }
}

Matrix Matrix::operator*(const vector<double> vec) const {
    if (_cols != vec.size()) {
        cout << "Выполнить операцию - невозможно\n";
        return *this;
    }
    else {
        Matrix result(_rows, 1);
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _cols; ++j) {
                result[i][0] += _matrix[i][j] * vec[j];
            }
        }
        return result;
    }
}

Matrix Matrix::operator*(double number) {
    Matrix result(_rows, _cols);
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            result[i][j] = _matrix[i][j] * number;
        }
    }
    return result;
}

Matrix Matrix::operator-(Matrix& other) {
    if (_matrix.size() != other._matrix.size()) {
        cout << "Выполнить операцию - невозможно\n";
    }
    else {
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _cols; ++j) {
                _matrix[i][j] = _matrix[i][j] - other[i][j];
            }
        }
        return *this;
    }
}

bool Matrix::operator==(Matrix& other) {
    if (_matrix.size() != other._matrix.size()) {
        return false;
    }
    else {
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _cols; ++j) {
                if (_matrix[i][j] != other[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
}

bool Matrix::operator!=(Matrix& other) {
    if (_matrix.size() != other._matrix.size()) {
        return true;
    }
    else {
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _cols; ++j) {
                if (_matrix[i][j] != other[i][j]) {
                    return true;
                }
            }
        }
        return false;
    }
}

double Matrix::Determinant()  {
    if (_rows != _cols) {
        cout << "Вычислить определитель невозможно\n";
        return 0.0;
    }
    else if (_rows == 1) {
        return _matrix[0][0];
    }
    else if (_rows == 2) {
        return _matrix[0][0] * _matrix[1][1] - _matrix[0][1] * _matrix[1][0];
    }
    else {
        double det = 0.0;
        for (int i = 0; i < _rows; ++i) {
            Matrix submatrix = CreateSubmatrix(*this, 0, i);
            det += pow(-1, i) * _matrix[0][i] * submatrix.Determinant();
        }
        return det;
    }
}

Matrix Matrix::CreateSubmatrix(Matrix& matrix, int row, int col)  {
    Matrix submatrix(matrix._rows - 1, matrix._cols - 1);
    int sub_i = 0;
    for (int i = 0; i < matrix._rows; ++i) {
        if (i != row) {
            int sub_j = 0;
            for (int j = 0; j < matrix._cols; ++j) {
                if (j != col) {
                    submatrix[sub_i][sub_j] = matrix[i][j];
                    ++sub_j;
                }
            }
            ++sub_i;
        }
    }
    return submatrix;
}

Matrix Matrix::Transpose() const {
    Matrix result(_cols, _rows);
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            result[j][i] = _matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::Inversion()  {
    if (_rows != _cols) {
        cout << "Найти обратную матрицу невозможно\n";
        return Matrix();
    }
    else {
        double det = Determinant();
        if (det == 0.0) {
            cout << "Найти обратную матрицу невозможно (определитель равен нулю)\n";
            return Matrix();
        }
        else {
            Matrix result(_rows, _cols);
            for (int i = 0; i < _rows; ++i) {
                for (int j = 0; j < _cols; ++j) {
                    Matrix submatrix = CreateSubmatrix(*this, i, j);
                    double cofactor = pow(-1, i + j) * submatrix.Determinant();
                    result[j][i] = cofactor / det;
                }
            }
            return result;
        }
    }
}

istream& operator>>(istream& in, Matrix& matrix) {
	cout << "Заполнение матрицы с клавиатуры\n";
	for (int i = 0; i < matrix._rows; ++i) {
		for (int j = 0; j < matrix._cols; ++j) {
			cout << "Элемент матрицы [" << i + 1 << "][" << j + 1 << "]: ";
			in >> matrix[i][j];
		}

	}
	return in;
}

ostream& operator<<(ostream& out, Matrix& matrix) {
	cout << "Вывод матрицы\n";
	for (int i = 0; i < matrix._rows; ++i) {
		for (int j = 0; j < matrix._cols; ++j) {
			out << "|" << setw(8) << setprecision(4) << matrix[i][j] << "|";
		}
		cout << endl;
	}
	return out;
};

