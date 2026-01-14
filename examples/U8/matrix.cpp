#include <iostream>

using std::cout;
using std::endl;

template<typename T, int N, int M>
class Matrix {
 private:
	T data[N][M];
 public:

  Matrix() {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				data[i][j] = T();
			}
		}
	}
 
	T& operator[](int i, int j) {
		return data[i][j];
	}

  T operator[](int i, int j) const {
		return data[i][j];
	}

	friend std::ostream& operator<<(std::ostream &os, Matrix const& mat) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				os << mat[i, j] << " ";
			}
			os << endl;
		}
		return os;
	}
};

int main() {
	Matrix<int, 2, 3> mat;
	mat[1, 1] = 5;
	cout << mat << endl;
	return 0;
}