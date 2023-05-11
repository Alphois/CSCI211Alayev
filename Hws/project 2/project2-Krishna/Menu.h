#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>
using namespace std;
#include "File.h"
class Menu{
   public:
      Menu();
      void gui();
   private:
      void createImage();
      void createText();
      void deleteFile(string fn, string type);
      int findFile(string fn, string type) const;
      void printAll() const;
      void printCertainFiles(string type) const;
      void readFile();
      void writeFile()const;

      void seeMoon(vector<File*> gunshara) const;//will recursively output properties of every file
      void DiverDown(vector<File*>& gunshara, vector<File*>& madeInHeaven, string type)const;
      vector<File*> seeSunOnly(const vector<File*>& gunshara, string type) const;//will recursively output properties of every file

      string lowerConvert(string thing) const;

      vector<File*> fileArr;
      
};


#endif