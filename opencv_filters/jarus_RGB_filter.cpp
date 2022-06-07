/* compile

jarus_HSV_filter='g++ jarus_HSV_filter.cpp -o jarus_RGB_filter -lueye_api -I/usr/local/include/opencv -I/usr/local/include -lserial -lpthread -lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dpm -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hfs -lopencv_img_hash -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_highgui -lopencv_videoio -lopencv_dnn -lopencv_plot -lopencv_xfeatures2d -lopencv_shape -lopencv_video -lopencv_ml -lopencv_ximgproc -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs -lopencv_features2d -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core'

$jarus_HSV_filter

./jarus_HSV_filter

need to adjust erosion and dilotion value
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
char *outText;

int Hrange(50), Srange(50), Lrange(50);
int imageName(0);

int hue1, sat1, lig1;
int hue2, sat2, lig2;

void refrashImage()
{

  // inRange(hsv_img,  Scalar(hue1 - Hrange/2, sat1 - Srange/2, lig1 - Lrange/2),    // start
  //                   Scalar(hue1 + Hrange/2, sat1 + Srange/2, lig1 + Lrange/2),    // to end  (between show)
  //         hsv_output);
  inRange(hsv_img,  Scalar(hue1, sat1, lig1),    // start
                    Scalar(hue2, sat2, lig2),    // to end  (between show)
          hsv_output);




    Mat both, cgray, color_masked;
    IplImage tmp = hsv_output;

    // color_masked = hsv_img;
    // for (int x = 0; x < hsv_output.size().width; x++)
    // {
    //   for (int y = 0; y < hsv_output.size().height; y++)
    //   {
    //     Scalar intensity = hsv_output.at<uchar>(Point(x, y));
    //     if (graysacle_frame.at<uchar>(Point(x, y))  > 200)
    //     {
    //       color_masked
    //     }
    //   }
    // }


    cvtColor(hsv_output, cgray, CV_GRAY2RGB);

    hconcat(src_img, cgray, both);


    //imshow( "jarus_window1", color_masked);
    imshow( "jarus_window", both);



/*    Mat image = output;
    Mat new_image = Mat::zeros( image.size(), image.type() );
    Mat sub_mat = Mat::ones(image.size(), image.type())*255;
    subtract(sub_mat, image, new_image);

    output = new_image;
*/
/*
    int erosion_type = MORPH_RECT;     //MORPH_RECT, MORPH_CROSS, MORPH_ELLIPSE
    int erosion_size = 1;
    Mat element = getStructuringElement( erosion_type,
                                       Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                                       Point( erosion_size, erosion_size ) );

    Mat matErode, matDilate;
    erode(output, matErode, element);

    erosion_size = 2;
    element = getStructuringElement( erosion_type,
                                       Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                                       Point( erosion_size, erosion_size ) );

    dilate(matErode, matDilate, element);

    imshow( "e", matErode);
    imshow( "d", matDilate);
*/
}

void on_HueTrackbar1( int, void* ){refrashImage();}
void on_SatTrackbar1( int, void* ){refrashImage();}
void on_LigTrackbar1( int, void* ){refrashImage();}

void on_HueTrackbar2( int, void* ){refrashImage();}
void on_SatTrackbar2( int, void* ){refrashImage();}
void on_LigTrackbar2( int, void* ){refrashImage();}


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

    refrashImage();
  }
  if(event == EVENT_RBUTTONDOWN)
  {
  }

    /*else if (event == EVENT_RBUTTONDOWN)
    {

        std::string name = std::to_string(imageName);
        name = name + ".png";
        imwrite(name, output);
        imageName++;

        std::string argument = "./myTess " + name;
        const char *abc = argument.c_str();
        system(abc);


        std::string argument1 = "rm " + name;
        const char *abc1 = argument1.c_str();
        system(abc1);
    }*/

}

int main(int argc, char** argv)
{
  Mat blur_img;

  string filename = argv[1];
  src_img = imread(filename, CV_LOAD_IMAGE_COLOR);

  blur( src_img, blur_img, Size(4,4), Point(-1, -1));
  cvtColor(blur_img, hsv_img,  CV_RGB2HSV);

  namedWindow("jarus_window", WINDOW_NORMAL);
  resizeWindow("jarus_window", 900, 900);
  setMouseCallback("jarus_window", mouse_callback);

  createTrackbar( "Hue1", "jarus_window", &hue1, intensity_slider_max_value, on_HueTrackbar1);   on_HueTrackbar1( hue1, 0);
  createTrackbar( "Hue2", "jarus_window", &hue2, intensity_slider_max_value, on_HueTrackbar2);   on_HueTrackbar2( hue2, 0);

  createTrackbar( "Sat1", "jarus_window", &sat1, intensity_slider_max_value, on_SatTrackbar1);   on_SatTrackbar1( sat1, 0);
  createTrackbar( "Sat2", "jarus_window", &sat2, intensity_slider_max_value, on_SatTrackbar2);   on_SatTrackbar2( sat2, 0);

  createTrackbar( "Lig1", "jarus_window", &lig1, intensity_slider_max_value, on_LigTrackbar1);   on_LigTrackbar1( lig1, 0);
  createTrackbar( "Lig2", "jarus_window", &lig2, intensity_slider_max_value, on_LigTrackbar2);   on_LigTrackbar2( lig2, 0);

  waitKey(0);
  return 0;
}
