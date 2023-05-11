#ifndef SAFE_ARRAY_H
#define SAFE_ARRAY_H
#include <iostream>
#include <cstdlib>

using namespace std;
template <class T>
class SafeArray {
	T* array;
	int size;

public:
	SafeArray ( );
	SafeArray (int s);
	T& operator [] (int index);
	const T& operator [] (int index) const;
	int length ( ) const;
	//big three
	~SafeArray ( );
	SafeArray (const SafeArray<T>& other);
	SafeArray<T>& operator = (const SafeArray<T>& other);
	
	friend ostream& operator<<(ostream& output, const SafeArray& aSafeArray){
		for (int i = 0; i < aSafeArray.size; i++) {
			output << aSafeArray.array[i]<<" ";
		}
	return output;
	}

};//safeArrayClass
	template <typename T>
SafeArray<T>::SafeArray( ) {
	array=nullptr;
	size=0; 
}

template <typename T>
SafeArray<T>::SafeArray (int s){
	
	if (size < 0) {
		cout << "Array size cannnot be negative." << endl;
		exit (1);
	}
	size=s;
	array = new T[size];
}

template <typename T>
T& SafeArray<T>::operator [] (int index) {
	if (index < 0 || index >= size) {
		cout << "Array index: " << index << "out of bounds."
			<< endl;
		exit (1);
	}
	return array[index];
}

template <typename T>
const T& SafeArray<T>::operator[](int index) const
{
	if (index < 0 || index >= size) {
		cout << "Array index: " << index << " is out of bounds."
			<< endl;
		exit (1);
	}
	return array[index];
}

template <class T>
int SafeArray<T>::length ( ) const {
	return size;
}

template <class T>
SafeArray<T>::~SafeArray ( ) {
	if (array != nullptr) {
		delete[] array;
		array = nullptr;
	}
}

template <class T>
SafeArray<T>::SafeArray (const SafeArray<T>& other)  {
	size=other.size;
	array = new T[size];
	for (int i = 0; i < size; i++) {
		array[i] = other.array[i];
	}
}

template <class T>
SafeArray<T>& SafeArray<T>::operator = (const SafeArray<T>& other) {
	if (this == &other) {
		return *this;
	}
	if (array !=nullptr) {
		delete[] array;
		array = nullptr;
	}
	size = other.size;
	array = new T[size];
	for (int i = 0; i < size; i++) {
		array[i] = other.array[i];
	}
	
	return *this;
}
#endif //SAFE_ARRAY_H
