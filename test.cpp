// C++ program for the above approach
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

// Driver code
int main(int argc, char **argv)
{
	// Read the image file as
	// imread("default.jpg");
	/*Mat image = imread("Enter the Address"
					"of Input Image",
					IMREAD_GRAYSCALE);*/

	Mat image = imread("Longitude1120.png", IMREAD_GRAYSCALE);

	// Error Handling
	if (image.empty())
	{
		cout << "Image File "
			 << "Not Found" << endl;

		// wait for any key press
		cin.get();
		return -1;
	}

	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			std::cout << (int) image.at<uchar>(i, j) << std::endl;
			if (image.at<uchar>(i, j) < 70){
				image.at<uchar>(i, j) = 0;
			}
		}
	}

	// Show Image inside a window with
	// the name provided
	imshow("Window Name", image);

	// Wait for any keystroke
	waitKey(0);
	return 0;
}
