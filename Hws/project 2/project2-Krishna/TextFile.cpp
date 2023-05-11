// TextFile.cpp
#include "TextFile.h"
using namespace std;
const string TextFile::extension = "txt";//global constant

TextFile::TextFile( ) : File(extension), charArray(SafeArray<int>(0)), charCount(0) { 
	//initialize File extension property to txt using predefined global constant;
}

TextFile::TextFile(string fname) : File(fname, extension), charArray(SafeArray<int>(0)), charCount(0) { }

TextFile::TextFile(string fname, SafeArray<int> charList) : File(fname, extension), charArray(charList), charCount(charList.length()) {

	 }

int TextFile::getSize( ) const {
	return charCount / 8;
}
int TextFile::getBits() const{
	return charCount;
}

int TextFile::getCharCount( ) const {
	return charCount;
}
