#include "File.h"
#include "ImageFile.h"
#include "SafeMatrix.h"
#include "TextFile.h"
#include <iostream>
#include <vector>
#include "Menu.h"
using namespace std;




int main(){
   /*===================================================
   ImageFile jesus("jesus",5,5,0);
   cout<<"file object jesus properties:"<<endl
      << jesus.getName()<<"<-Name"<<endl
      << jesus.getExtension()<<"<-Extension"<<endl
      <<jesus.getSize()<<"<-#bytes"<<endl
      <<jesus.getDHeight()<<"<-D-height"<<endl
      <<jesus.getDWidth()<<"<-D-width"<<endl
      <<jesus.getColorDepth()<<"<-Get color depth"<<endl;
   TextFile god("mixSwirl");
   cout<<"file object god properties:"<<endl
      << god.getName()<<"<-Name"<<endl
      << god.getExtension()<<"<-Extension"<<endl//inherited from parent class File
      <<god.getSize()<<"<-- # bytes"<<endl
      <<god.getCharCount()<<"<-D-width"<<endl;
    ====================================================  */
   //hw 8 test
   /*===================================================
   vector<File*> gamshara;//pass a vector by const ref for efficiency 
   gamshara.push_back(new ImageFile("jesus",5,5,0));
   gamshara.push_back(new TextFile("mixSwirl"));
   gamshara.push_back(new TextFile("jajanken"));
   seeMoon (gamshara);
   seeMoon(seeSunOnly(gamshara, "txt"));
    ====================================================  */
    //hw 9 test
   Menu Zeus;
   Zeus.gui();
   return 0;
}


