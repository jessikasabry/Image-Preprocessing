#include <iostream> 
#include "CS213-2026-2027-Assignemnt1-LibraryAndExample/CS213-2026-2027-Assignemnt1-LibraryAndExample/Image_Class.h"
using namespace std;



void applyframe(Image& image, int frameSize){
    cout<< "Choose frame style:\n"<<"1.simple frame"<<endl<<"2.Fancy frame"<<endl;
    int choice;
    cin>>choice;
    if(choice==1){
 for(int i=0;i<image.width;i++){
    for(int j=0;j<image.height;j++){
        for(int k=0;k<3;k++){
            if(i<frameSize || i>=image.width-frameSize || j<frameSize || j>=image.height-frameSize){
                image(i,j,0)=0;
                image(i,j,1)=0;
                image(i,j,2)=0;
            }
        }
    }
 }
    }
    else if(choice==2){
        for(int i=0;i<image.width;i++){
            for(int j=0;j<image.height;j++){
                for(int k=0;k<3;k++){
                    if(i<frameSize+5 || i>=image.width-(frameSize+5) || j<frameSize+5 || j>=image.height-(frameSize+5)){
                        image(i,j,k)=255;
                        
                    }
                 if(i<frameSize || i>=image.width-frameSize || j<frameSize || j>=image.height-frameSize){
                image(i,j,0)=0;
                image(i,j,1)=0;
                image(i,j,2)=0;
            }
                 if(i<5 || i>=image.width-(5) || j<5 || j>=image.height-(5)){
                        image(i,j,k)=255;
                        
                    }
                }
            }
        }
    }

}

int main() {
   string filename;
   cout<<"Enter the filename of the image to laod:\n";
    cin>> filename;

    Image image(filename); // Load an image from a file
    
    int framesize=min(image.width,image.height)*0.04;
    applyframe(image,framesize);

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";

    cin >> filename;
    image.saveImage(filename);
    return 0;
}