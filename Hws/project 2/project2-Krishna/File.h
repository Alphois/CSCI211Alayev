#ifndef FILE_H
#define FILE_H
#include <string>
using namespace std;
class File {
private:
	string name;
	string extension;
public:
	File ();
	File (string extension);
	File (string name, string extension);
	virtual ~File ();
	string getName ( ) const;
	string getExtension ( ) const;
	virtual int getSize ( ) const = 0;//pure function, makes this class an abstract 
	virtual int getBits ( ) const = 0;

};

#endif //FILE_HPP
