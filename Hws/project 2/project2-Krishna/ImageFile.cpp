// ImageFile.cpp
// Created by Evan Almonte
//
#include "ImageFile.h"

const std::string ImageFile::extension = "gif";

ImageFile::ImageFile( ) : File(extension), pMatrix(SafeMatrix<int>(0, 0)), colDepth(0) { }

ImageFile::ImageFile(string fname, int height, int width, int cD) :
	File(fname, extension), pMatrix(SafeMatrix<int>(height, width)), colDepth(cD) { 
}

ImageFile::ImageFile(string fname, SafeMatrix<int> pixelMatrix, int colorDepth) :
	File(fname, extension), pMatrix(pixelMatrix), colDepth(colorDepth) {//initialization list

}
//getter methods
int ImageFile::getColorDepth( ) const {
	return colDepth;
}

int ImageFile::getDHeight( ) const {
	return pMatrix.length();
}

int ImageFile::getDWidth( ) const {
	return pMatrix.width();
}

int ImageFile::getSize( ) const {
	return static_cast<double>(pMatrix.length() * pMatrix.width() * colDepth) / 8;
}

int ImageFile::getBits( ) const {
	return pMatrix.length ( ) * pMatrix.width ( );
}
