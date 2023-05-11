#include "Menu.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>
#include <fstream>
using namespace std;
Menu:: Menu(){

}
void Menu::gui(){
   cout << ";[;';;['[;'[]'];[;']['];"<<endl
        << "       Main Menu"<<endl
        << ";[;[;[;[;['[;[;['[;[;'[;"<<endl
        << "1) Read from file"<<endl
	     << "2) Create Image file"<<endl
	     << "3) Create Text file"<<endl
	     << "4) Print All files"<<endl
	     << "5) Print Image files only"<<endl
	     << "6) Print Text files only"<<endl
	     << "7) Delete file"<<endl
	     << "8) Terminate program"<<endl;
        int userInput;
        cout<<"enter in the number of the command you would like to use"<<endl;
	cin>>userInput;
   cin.ignore();
	switch(userInput) {
		case 1:
			readFile();
			break;
		case 2:
			createImage ( );
			break;
		case 3:
			createText ( );
			break;
		case 4:
			printAll ( );
			break;
		case 5:
			printCertainFiles ("gif");
			break;
		case 6:
			printCertainFiles ("txt");
			break;
		case 7: 
		{
			string fileName, fileType;
			cout << "Enter the file's name: ";
			getline(cin, fileName);
			cout << "Enter the file's extension: ";
			getline (cin, fileType);
			deleteFile (fileName, fileType);

		}	break;
		case 8:	
			cout << "Program will now quit.\n";
			writeFile ( );
			return;
		default:
			cout << "Invalid option please try again!"<<endl;
	}
   cout << "Press enter to continue . . ."<<endl;
	cin.get ( );
	gui( );
}
void Menu::createImage(){
   cout<< "============"<<endl
       << "CREATE IMAGE BOI"<<endl
       <<"============="<<endl;
   int dH, dW, cDepth;
   string fn;
	cout << "Please enter file's name: ";
	getline (cin, fn);
   cout << "Please enter the height of the image: ";
   cin>>dH;
   cin.ignore();
   cout << "Please enter the width of the image: ";
   cin>>dW;
   cin.ignore();	
   cout<<"please enter color depth of image: ";
   cin>>cDepth;
   fileArr.push_back(new ImageFile(fn,dH, dW, cDepth));
}
void Menu::createText( ) {
	cout << "+ ===================== +"<<endl;
	cout << "    Create Text File"<<endl;
	cout << "+ ===================== + "<<endl;
	string fn;
	cout << "Please enter the file's name: ";
	getline (cin, fn);
	fileArr.push_back (new TextFile (fn));
}
void Menu::deleteFile(string fn,string type) {
	int location = findFile (fn, type);
	if(location == -1) {
		cout << "Could not find file."<<endl;
		return;//terminate this function
	}
	delete fileArr[location];
	fileArr.erase (fileArr.begin() + location);
	cout << "====================="<<endl;
	cout << " File Slaughtered"<<endl;
	cout << "====================="<<endl;
}
int Menu:: findFile(string fn, string type)const{
   fn=lowerConvert(fn);
   type=lowerConvert(type);
   for (int i=0;i<fileArr.size();i++){
      if (fn==lowerConvert(fileArr[i]->getName())
         && 
         type == lowerConvert(fileArr[i]->getExtension()))
      {
            return i;
      }//if
   }
   return -1;//return -1 if not found
}
string Menu:: lowerConvert(string thing)const{
   for (int i=0; i< thing.length();i++){
      thing[i]=static_cast<char>(tolower (thing[i]));
   }
   return thing;
}
void Menu:: printAll()const{
   cout << "=====================";
	cout << " File Array: "<<endl;
	cout << "=====================";
   seeMoon(fileArr);
}
void Menu:: printCertainFiles(string type) const{
   cout << "=====================";
	cout << "   "<<type<< " File Arr"<<endl;
	cout << "=====================";
   seeMoon(seeSunOnly(fileArr, type));
}


void Menu::readFile(){
   cout << "====================="<<endl;
	cout << " Reading File: "<<endl;
	cout << "====================="<<endl;
   int filesRead = 0;
	ifstream tengokuIko ("file.txt");
	if(tengokuIko.is_open()) {
		string userInput;
		while(getline(tengokuIko, userInput)) {
			if(userInput == "txt") {
				string fileName;
				int fileSize;
				tengokuIko >> fileName >> fileSize;
				tengokuIko.ignore ( );
				fileArr.push_back (new TextFile (fileName, SafeArray<int> (fileSize)));
				filesRead++;
			} else if (userInput == "gif") {
				string fileName;
				int height, width, colorDepth;
				tengokuIko >> fileName >> height;
				tengokuIko.get ( );
				tengokuIko.get ( );
				tengokuIko.get ( );
				tengokuIko >> width >> colorDepth;
				fileArr.push_back (new ImageFile (fileName, height, width, colorDepth));
				tengokuIko.ignore ( );
				filesRead++;
			}
		}
	} else {
		cout << "Could not find file.txt"<<endl;
	}
   string plural;
   if (filesRead!=1){
      plural="s";
   }else{
      plural="";
   }
	cout << filesRead << " file" <<plural;
	cout << " read"<<endl;
}
void Menu::writeFile()const{
   ofstream outputFile ("file.txt");
	int numOfFiles = fileArr.size ( );
	for (int i = 0; i < numOfFiles; ++i) {
		File* currentFile = fileArr[i];
		outputFile << currentFile->getExtension ( ) <<endl 
			<< currentFile->getName() <<endl;
		
		if(currentFile->getExtension() == "gif") {//if the file extension is gif theres extra stuff to do
			ImageFile* anImageFile = dynamic_cast<ImageFile*>(currentFile);
			outputFile << anImageFile->getDHeight ( ) << " x "
				<< anImageFile->getDWidth ( ) <<endl
				<< anImageFile->getColorDepth() << endl;
		} else {
			outputFile << currentFile->getBits ( ) <<endl;
		}

		if(i != numOfFiles - 1) {
			outputFile <<endl;
		}
	}
	outputFile.close ( );
}









void Menu:: seeMoon(vector<File*> gunshara)const{//will recursively output properties of every file
   vector<File*> tmp(gunshara);
   if (tmp.size()!=0){
      File* last= tmp.back();
      //fileoutput
      tmp.pop_back();
      seeMoon(tmp);//this way, the vector array will print in order from the first pointor to last. 
      cout<<"Type: "<<last->getExtension()<<endl
          <<"Name: "<<last->getName()<<endl;
      if (last->getExtension()=="gif"){
         ImageFile* hermitPurple=dynamic_cast<ImageFile*>(last);
         cout<<"Dimensions: " <<hermitPurple->getDHeight()<<" by "
             <<hermitPurple->getDWidth()<<endl;
      }else if(last->getExtension()=="txt"){      //if it is a textFile:
         TextFile* emporiosPrinter=dynamic_cast<TextFile*>(last);
         cout<<"charCount: "<<emporiosPrinter->getCharCount()<<endl;
      }
      cout<< "File size: "<<last->getSize()<<" bytes"<<endl<<endl;
  }
}




void Menu:: DiverDown(vector<File*>& gunshara, vector<File*>& madeInHeaven, string type)const{
    if (gunshara.size()==0){
      return;//terminate
   }
   File* last= gunshara.back();
   //fileoutput
   gunshara.pop_back();
   DiverDown(gunshara, madeInHeaven,type); 
   if (last->getExtension()==type){
      madeInHeaven.push_back(last);
   }
}
vector<File*> Menu:: seeSunOnly(const vector<File*>& gunshara, string type)const{//will recursively output properties of every file
  
   vector<File*> tmp(gunshara);
   vector<File*> recourse;


   DiverDown(tmp, recourse, type);
   
  
   return recourse;
}