#ifndef TEXTFILE_H
#define TEXTFILE_H

#include "File.h"
#include "SafeArray.h"
#include <string>
using namespace std;
class TextFile : public File{
public:
	TextFile ();

	TextFile (string fname);
	
	TextFile (string fname, SafeArray<int> charList);

	int getSize () const override;//overrides File::getSize() function
	int getBits () const override;

	int getCharCount () const;
private:
	SafeArray<int> charArray;
	int charCount;
	static const string extension;
};

#endif //TEXTFILE_HPP

