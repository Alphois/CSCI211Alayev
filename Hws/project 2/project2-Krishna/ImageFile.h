#ifndef IMAGEFILE_H
#define IMAGEFILE_H

#include "File.h"
#include "SafeMatrix.h"
#include <string>
using namespace std;
class ImageFile : public File {//extends 
public:
	//constructors
	ImageFile( );

	ImageFile(string fname, int height, int width, int colorDepth);

	ImageFile (string fname, SafeMatrix<int> pixelMatrix, int colorDepth);
	
	//getters

	int getColorDepth( ) const;

	int getDHeight( ) const;

	int getDWidth( ) const;

	int getSize( ) const override;
	int getBits() const override;
private:
	SafeMatrix<int> pMatrix;
	int colDepth;
	static const string extension;
};

#endif //IMAGEFILE_H
