/* compile

multi_inRange_filter='g++ multi_inRange_filter.cpp -o multi_inRange_filter -lueye_api -I/usr/local/include/opencv -I/usr/local/include -lserial -lpthread -lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dpm -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hfs -lopencv_img_hash -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_highgui -lopencv_videoio -lopencv_dnn -lopencv_plot -lopencv_xfeatures2d -lopencv_shape -lopencv_video -lopencv_ml -lopencv_ximgproc -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs -lopencv_features2d -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core'

$multi_inRange_filter

./multi_inRange_filter

*/
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

const int intensity_slider_max_value = 255;
int slider_value=1;

Mat src_img, output;
Mat hsv_img;
Mat hsv_output;
Mat blur_img;

char *outText;

int Hrange(50), Srange(50), Lrange(50);
int imageName(0);

int hue1, sat1, lig1;
int hue2, sat2, lig2;
int ero, dil;
int blur_size;


struct j_color
{
  int blur;

  int color1;
  int color2;
  int color3;


  int erode;
  int dilute;
}
Mat j_updateImage(struct j_color *color, Mat scr_img)
{
  blur( src_img, blur_img, Size(blur_size+1,blur_size+1), Point(-1, -1));
  //cvtColor(blur_img, hsv_img, CV_RGB2HSV);
  hsv_img = blur_img;

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

  Mat cgray, both;
  cvtColor(matDilate, cgray, CV_GRAY2RGB);

  hconcat(src_img, blur_img, both);

  hconcat(both, cgray, both);
  imshow( "jarus_window", both);

}

}

int main(int argc, char** argv)
{

  string filename = argv[1];
  src_img = imread(filename, CV_LOAD_IMAGE_COLOR);

  namedWindow("jarus_window", WINDOW_NORMAL);
  resizeWindow("jarus_window", 900, 900);


/*
char x;
cin >> x;
while (x == 'e')
{
  cout << x << endl;
}*/
  namedWindow("jarus_window", WINDOW_NORMAL);
  resizeWindow("jarus_window", 900, 900);
/*
  setMouseCallback("jarus_window", mouse_callback);

  createTrackbar( "blur", "jarus_window", &blur_size, 50, on_blur);   on_blur( blur_size, 0);

  createTrackbar( "Hue1", "jarus_window", &hue1, intensity_slider_max_value, on_HueTrackbar1);   on_HueTrackbar1( hue1, 0);
  createTrackbar( "Hue2", "jarus_window", &hue2, intensity_slider_max_value, on_HueTrackbar2);   on_HueTrackbar2( hue2, 0);

  createTrackbar( "Sat1", "jarus_window", &sat1, intensity_slider_max_value, on_SatTrackbar1);   on_SatTrackbar1( sat1, 0);
  createTrackbar( "Sat2", "jarus_window", &sat2, intensity_slider_max_value, on_SatTrackbar2);   on_SatTrackbar2( sat2, 0);

  createTrackbar( "Lig1", "jarus_window", &lig1, intensity_slider_max_value, on_LigTrackbar1);   on_LigTrackbar1( lig1, 0);
  createTrackbar( "Lig2", "jarus_window", &lig2, intensity_slider_max_value, on_LigTrackbar2);   on_LigTrackbar2( lig2, 0);

  createTrackbar( "erode", "jarus_window", &ero, 20, on_erode);   on_erode( ero, 0);
  createTrackbar( "dilat", "jarus_window", &dil, 20, on_dilat);   on_dilat( dil, 0);



  waitKey(0);*/

  return 0;
}
