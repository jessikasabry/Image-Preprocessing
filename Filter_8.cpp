#include <iostream> 
#include "Image_Class.h"
using namespace std;




void resize(Image& image, int h,int w){
    int nh,nw;
    cout<<"ENter the new width and the new height of the image;\n";
    cin>>nw>>nh;
    float scaleH=(float)h/nh;
    float scaleW=(float)w/nw;

    Image newImage(nw,nh);

    for(int i=0;i<nw;i++){
        for(int j=0;j<nh;j++){
            for(int k=0;k<3;k++){
                int oldX=(int)(i*scaleW);
                int oldY=(int)(j*scaleH);
                newImage(i,j,k)=image(oldX,oldY,k);

            }

        }

    }
image=newImage;


}



int main(){
    string fileName;
    cout << "Enter the filename of the image to load: ";
    cin >> fileName;

    Image image(fileName);
   int h=image.height;
   int w=image.width;

    resize(image,h,w);

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga:\n ";

    cin >> fileName;
    image.saveImage(fileName);
    return 0;
}