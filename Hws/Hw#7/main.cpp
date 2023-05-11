#include "SafeMatrix.h"
#include <string>

void getRC (int& rowSize, int& colSize);

int main() {
	int rowSize, colSize;
	
	cout << "Test #1 using <int>:"<<endl;
	getRC(rowSize, colSize);
	SafeMatrix<int> mySafeMatrix (rowSize, colSize);
	cout<<"tested int successfully"<<endl;
	cout<<"couting safeMatrix.length():" <<mySafeMatrix.length()<< " and safeMatrix[0].length(): "<<mySafeMatrix[0].length()<<endl;
	mySafeMatrix.rider ( );//this is for testing various overloads -  bracket, <<
	
	cout << "Test #2 using <string>"<<endl;
	getRC (rowSize, colSize);
	SafeMatrix<string> mySafeMatrix2 (rowSize, colSize);
	mySafeMatrix2.rider ( );//this is for testing various overloads -  bracket, <<

	return 0;
}

void getRC(int& rowSize, int& colSize) {
	cout << "Enter the row size: ";
	while(!(cin >> rowSize)) {
		cout << "Invalid, Try again: ";
		cin.clear ( );
		cin.ignore (100,'\n');
	}
	cout << "Enter the col size: ";
	while (!(cin >> colSize)) {
		cout << "Invalid, Try again: ";
		cin.clear ( );
		cin.ignore (100, '\n');
	}
}
