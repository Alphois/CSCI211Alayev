#ifndef SAFE_MATRIX_HPP
#define SAFE_MATRIX_HPP
#include "SafeArray.h"
#include <iosfwd>

using namespace std;

template <class T>

class SafeMatrix {
public:
	SafeMatrix (int rows, int cols);
	
	//Used to test various components in the SafeMatrix class.
	void rider ( );
	
	//Returns the number of rows in the matrix.
	int length ( ) const;
	
	//Returns a SafeArray located at the index specified. Boundaries are checked.
	SafeArray<T>& operator[](int index);
	
	friend ostream& operator<<(ostream& output, const SafeMatrix& aSafeMatrix) {
		for (int i = 0; i < aSafeMatrix.rowSize; ++i) {
			output << aSafeMatrix.myRows[i] <<endl;
		}
		return output;
	}
private:
	int rowSize;
	
	//SafeArray of SafeArrays.
	SafeArray<SafeArray<T>> myRows;


};
	template <typename T>
SafeMatrix<T>::SafeMatrix(int rows, int cols): myRows(SafeArray<SafeArray<T>>(rows)) {
	rowSize=rows;
	myRows=SafeArray<SafeArray<T>>(rowSize);
	
	for (int i = 0; i < rowSize; ++i) {
		myRows[i] = SafeArray<T>(cols);
	}
}

//Used to test various operator overloads
template <typename T>
void SafeMatrix<T>::rider ( ) {
	cout << "Testing >> op."<<endl;
	for (int i = 0; i < rowSize; ++i) {
		for (int j = 0; j < myRows[0].length ( ); ++j) {
			cin >> (*this)[i][j];
		}
	}

	cout << "Testing << op."<<endl;
		cout << *this;

	cout << "Testing [] op."<<endl;
	cout << "SafeMatrix[0]: " << (*this)[0] << "\n";
}

template <typename T>
int SafeMatrix<T>::length( ) const {
	return rowSize;
}

template <typename T>
SafeArray<T>& SafeMatrix<T>:: operator[](int index)
{
	return myRows[index];
}


#endif //SAFE_MATRIX_H