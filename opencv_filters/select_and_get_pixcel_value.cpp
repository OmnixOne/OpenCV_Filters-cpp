/* compile

select_and_get_pixcel_value='g++ select_and_get_pixcel_value.cpp -o select_and_get_pixcel_value -lueye_api -I/usr/local/include/opencv -I/usr/local/include -lserial -lpthread -lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dpm -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hfs -lopencv_img_hash -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_highgui -lopencv_videoio -lopencv_dnn -lopencv_plot -lopencv_xfeatures2d -lopencv_shape -lopencv_video -lopencv_ml -lopencv_ximgproc -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs -lopencv_features2d -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core'

$select_and_get_pixcel_value; ./select_and_get_pixcel_value

*/

#include <iostream>
#include "opencv2/opencv.hpp"
#include <stdio.h>

using namespace std;
using namespace cv;


Mat src,img,ROI;
Rect cropRect(0,0,0,0);
 Point P1(0,0);
 Point P2(0,0);

const char* winName="Crop Image";
bool clicked=false;
int i=0;
char imgName[15];

void checkBoundary(){
       //check croping rectangle exceed image boundary
       if(cropRect.width>img.cols-cropRect.x)
         cropRect.width=img.cols-cropRect.x;

       if(cropRect.height>img.rows-cropRect.y)
         cropRect.height=img.rows-cropRect.y;

        if(cropRect.x<0)
         cropRect.x=0;

       if(cropRect.y<0)
         cropRect.height=0;
}

void showImage()
{
  img=src.clone();
  checkBoundary();
  if( cropRect.width>0 && cropRect.height>0 )
  {
    ROI=src(cropRect);
    imshow("cropped",ROI);
  }
  rectangle(img, cropRect, Scalar(0,255,0), 4, 8, 0 );
  imshow(winName,img);
}


void onMouse( int event, int x, int y, int f, void* )
{
switch(event)
{
  case CV_EVENT_RBUTTONDOWN:
  {
    //cout << ROI << endl;
  }
  case  CV_EVENT_LBUTTONDOWN  :
    clicked=true;

    P1.x=x;
    P1.y=y;

    P2.x=x;
    P2.y=y;

    break;

  case  CV_EVENT_LBUTTONUP    :
    P2.x=x;
    P2.y=y;
    clicked=false;
    break;

  case  CV_EVENT_MOUSEMOVE :
    if(clicked)
    {
      P2.x=x;
      P2.y=y;
    }
    break;
  default:
    break;


    }


    if(clicked){
     if(P1.x>P2.x){ cropRect.x=P2.x;
                       cropRect.width=P1.x-P2.x; }
        else {         cropRect.x=P1.x;
                       cropRect.width=P2.x-P1.x; }

        if(P1.y>P2.y){ cropRect.y=P2.y;
                       cropRect.height=P1.y-P2.y; }
        else {         cropRect.y=P1.y;
                       cropRect.height=P2.y-P1.y; }

    }


    showImage();


}

int main(int argc, char** argv)
{
  //system("clear");
  string filename = argv[1];
  src = imread(filename, CV_LOAD_IMAGE_COLOR);


  namedWindow(winName, WINDOW_NORMAL);
  resizeWindow(winName, 800, 800);

  namedWindow("cropped", WINDOW_NORMAL);
  resizeWindow("cropped", 500, 500);

  setMouseCallback(winName,onMouse,NULL );
  imshow(winName,src);

  while(1)
  {
    showImage();
    char c=waitKey(5);
    if (c == 32) {break;}
    else if (c == 's')
    {
      Mat image;
      int avr_hue, avr_sat, avr_lig, total_points;
      avr_hue = avr_sat = avr_lig = total_points = 0;

      vector<int> vec_hue;
      vector<int> vec_sat;
      vector<int> vec_lig;
      //cvtColor(ROI, image, CV_RGB2HSV);
      image = ROI;
      string str;
      Vec3b intensity;
      for (int i = 0; i < image.cols; i++)
      {
          for (int j = 0; j < image.rows; j++)
          {
              intensity = image.at<Vec3b>(j, i);
              total_points++;
              vec_hue.push_back(intensity.val[0]);
              vec_sat.push_back(intensity.val[1]);
              vec_lig.push_back(intensity.val[2]);
              cout << (int)intensity.val[0] << " "<<(int)intensity.val[1] << " " << (int)intensity.val[2] << endl;
          }

      }

      vector<int>::iterator ptr;
      for (ptr = vec_hue.begin(); ptr < vec_hue.end(); ptr++) avr_hue = avr_hue + (*ptr);
      for (ptr = vec_sat.begin(); ptr < vec_sat.end(); ptr++) avr_sat = avr_sat + (*ptr);
      for (ptr = vec_lig.begin(); ptr < vec_lig.end(); ptr++) avr_lig = avr_lig + (*ptr);


      avr_hue = avr_hue / total_points;
      avr_sat = avr_sat / total_points;
      avr_lig = avr_lig / total_points;
      cout << avr_hue << " "<< avr_sat << " " << avr_lig << endl;

      cout << "min HSV [" << *min_element (vec_hue.begin(), vec_hue.end()) << ", " <<
                             *min_element (vec_sat.begin(), vec_sat.end()) << ", " <<
                             *min_element (vec_lig.begin(), vec_lig.end()) << "]" << endl;
      cout << "max HSV [" << *max_element (vec_hue.begin(), vec_hue.end()) << ", " <<
                             *max_element (vec_sat.begin(), vec_sat.end()) << ", " <<
                             *max_element (vec_lig.begin(), vec_lig.end()) << "]" << endl;


    }




    }




  return 0;
}
