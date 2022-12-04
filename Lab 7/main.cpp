#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    VideoCapture vc(0);
    if (!vc.isOpened() ) return 1;
    Mat frame;

    namedWindow("Window", WINDOW_AUTOSIZE); // Create a window for display.
    while (waitKey(10) != 27) {
        vc >> frame;
        cout << "frame info: " << frame.rows << " " << frame.cols << endl;
        flip(frame,frame,1);
        imshow("Window", frame);
    }
    return 0;
}