/*
jarus_HSV_filter_on_video='g++ jarus_HSV_filter_on_video.cpp -o jarus_compiled/jarus_HSV_filter_on_video -lueye_api -I/usr/local/include/opencv -I/usr/local/include -lserial -lpthread -lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dpm -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hfs -lopencv_img_hash -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_highgui -lopencv_videoio -lopencv_dnn -lopencv_plot -lopencv_xfeatures2d -lopencv_shape -lopencv_video -lopencv_ml -lopencv_ximgproc -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs -lopencv_features2d -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core'

$jarus_HSV_filter_on_video

jarus_compiled/jarus_HSV_filter_on_video

*/

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace cv;

// global variable
Mat src_img, output;
Mat hsv_img;
Mat hsv_output;
Mat blur_img;
Mat cgray, display_frame;
Mat vid_frame;

int hue1, sat1, lig1;
int hue2, sat2, lig2;
int ero, dil;
int blur_size;

bool temp(false);
Mat filter_on_image(Mat);
void update_image();

void on_HueTrackbar1( int, void* ){if(temp)update_image();}
void on_HueTrackbar2( int, void* ){if(temp)update_image();}

void on_SatTrackbar1( int, void* ){if(temp)update_image();}
void on_SatTrackbar2( int, void* ){if(temp)update_image();}

void on_LigTrackbar2( int, void* ){if(temp)update_image();}
void on_LigTrackbar1( int, void* ){if(temp)update_image();}

void on_erode( int, void* ){if(temp)update_image();}
void on_dilat( int, void* ){if(temp)update_image();}
void on_blur( int, void* ){if(temp)update_image();}



Mat filter_on_image(Mat src_frame)
{
  src_img = src_frame;
  blur( src_img, blur_img, Size(blur_size+1,blur_size+1), Point(-1, -1));
  cvtColor(blur_img, hsv_img, CV_RGB2HSV);

  inRange(hsv_img,  Scalar(hue1, sat1, lig1),    // start
                  Scalar(hue2, sat2, lig2),    // to end  (between show)
        hsv_output);


  Mat matErode, matDilate;

  int ero_dil_type[2] = {MORPH_ELLIPSE, MORPH_ELLIPSE};
  int ero_dil_size[2] = {0, 0};

  ero_dil_size[0] = ero;
  ero_dil_size[1] = dil;

  Mat element = getStructuringElement( ero_dil_type[0],
                                     Size( 2*ero_dil_size[0] + 1, 2*ero_dil_size[0]+1 ),
                                     Point( ero_dil_size[0], ero_dil_size[0] ) );

  erode(hsv_output, matErode, element);
  element = getStructuringElement( ero_dil_type[1],
                                     Size( 2*ero_dil_size[1] + 1, 2*ero_dil_size[1]+1 ),
                                     Point( ero_dil_size[1], ero_dil_size[1] ) );

  dilate(matErode, matDilate, element);


  cvtColor(matDilate, cgray, CV_GRAY2RGB);

  hconcat(src_img, blur_img, display_frame);
  hconcat(display_frame, cgray, display_frame);
  return display_frame;
}
void update_image()
{
  display_frame = filter_on_image(vid_frame);imshow( "jarus_window", display_frame);
}

void mouse_callback(int  event, int  x, int  y, int  flag, void *param)
{
  if (event == EVENT_LBUTTONDOWN)
  {
    Vec3b color = hsv_img.at<Vec3b>(Point(x,y));
    hue1 = color.val[0] - 25;  setTrackbarPos("Hue1", "jarus_window", hue1);
    sat1 = color.val[1] - 25;  setTrackbarPos("Sat1", "jarus_window", sat1);
    lig1 = color.val[2] - 25;  setTrackbarPos("Lig1", "jarus_window", lig1);

    hue2 = color.val[0] + 25;  setTrackbarPos("Hue2", "jarus_window", hue2);
    sat2 = color.val[1] + 25;  setTrackbarPos("Sat2", "jarus_window", sat2);
    lig2 = color.val[2] + 25;  setTrackbarPos("Lig2", "jarus_window", lig2);


    cout << "Cursor position:- [" << x << " " << y << "] ";
    cout << "HSV value:- [" << (int) color.val[0] << " "
                           << (int) color.val[1] << " "
                           << (int) color.val[2] << "]" << endl;

    update_image();

  }
}

int main(int argc, char** argv)
{
  string str_filter_values;
  string vid_file_name = argv[1];

  vector<string> parameters;

  ifstream myfile;
  myfile.open(argv[2]);
  if (!myfile.is_open())
  {
    cout << "jarus:- Error opening file" << endl; //return 0;
  }
  else
  {
    myfile >> str_filter_values;
    myfile.close();

    boost::split(parameters, str_filter_values, boost::is_any_of(","));
    blur_size = stoi( parameters[0] );
    hue1      = stoi( parameters[1] );
    hue2      = stoi( parameters[2] );
    sat1      = stoi( parameters[3] );
    sat2      = stoi( parameters[4] );
    lig1      = stoi( parameters[5] );
    lig2      = stoi( parameters[6] );
    ero       = stoi( parameters[7] );
    dil       = stoi( parameters[8] );

  }

  namedWindow("jarus_window", WINDOW_NORMAL);
  resizeWindow("jarus_window", 900, 900);

  setMouseCallback("jarus_window", mouse_callback);

  createTrackbar( "blur", "jarus_window", &blur_size, 50, on_blur);   on_blur( blur_size, 0);

  createTrackbar( "Hue1", "jarus_window", &hue1, 255, on_HueTrackbar1);   on_HueTrackbar1( hue1, 0);
  createTrackbar( "Hue2", "jarus_window", &hue2, 255, on_HueTrackbar2);   on_HueTrackbar2( hue2, 0);

  createTrackbar( "Sat1", "jarus_window", &sat1, 255, on_SatTrackbar1);   on_SatTrackbar1( sat1, 0);
  createTrackbar( "Sat2", "jarus_window", &sat2, 255, on_SatTrackbar2);   on_SatTrackbar2( sat2, 0);

  createTrackbar( "Lig1", "jarus_window", &lig1, 255, on_LigTrackbar1);   on_LigTrackbar1( lig1, 0);
  createTrackbar( "Lig2", "jarus_window", &lig2, 225, on_LigTrackbar2);   on_LigTrackbar2( lig2, 0);

  createTrackbar( "erode", "jarus_window", &ero, 20, on_erode);   on_erode( ero, 0);
  createTrackbar( "dilat", "jarus_window", &dil, 20, on_dilat);   on_dilat( dil, 0);


  VideoCapture cap(vid_file_name);

  if(!cap.isOpened()){
    cout << "Error opening video stream or file" << endl;
    return -1;
  }

char keyPressed('s');
bool play_pause= true;
//VideoWriter v_saving; if (temp) v_saving = VideoWriter("aaa.avi",CV_FOURCC('M','J','P','G'),10, Size(vid_frame.size().width ,vid_frame.size().height));
  while(1)
  {

    if (play_pause)
    {
      for (int myLoop1 = 0; myLoop1 < 5; myLoop1++)  {      cap >> vid_frame;    if (vid_frame.empty())  break;   }
      display_frame = filter_on_image(vid_frame);
      imshow( "jarus_window", display_frame);
      //if(temp) {v_saving.write(vid_frame);cout << "started" << endl;}
      temp = true;
    }

    keyPressed=(char)waitKey(25);   //cout << (int)keyPressed << endl;
    if(keyPressed == 27)        // esc
      break;
    else if(keyPressed == 32)   // spacebar
      play_pause = play_pause ? false : true;
    else if(keyPressed == 's')
    {
      ofstream myfile;
      myfile.open(argv[2]);
      if (!myfile.is_open()) {cout << "jarus:- Error opening file" << endl; return 0;}
      str_filter_values = to_string(blur_size) + "," +
                          to_string(hue1) + "," +
                          to_string(hue2) + "," +
                          to_string(sat1) + "," +
                          to_string(sat2) + "," +
                          to_string(lig1) + "," +
                          to_string(lig2) + "," +
                          to_string(ero) + "," +
                          to_string(dil);
      myfile << str_filter_values;
      myfile.close();
      cout << "save cunnret filter value to file" << endl;
    }
  }

  //v_saving.release();
  cap.release();
  // Closes all the frames
  destroyAllWindows();

  return 0;
}
