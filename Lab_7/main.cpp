#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <chrono>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    VideoCapture vc(0);
    if (!vc.isOpened() ) return 1;

    int threshold1 = 100;
    int threshold2 = 100;

    namedWindow("trackbars");
    createTrackbar("threshold1", "trackbars", &threshold1, 500);
    createTrackbar("threshold2", "trackbars", &threshold2, 500);


    namedWindow("Window", WINDOW_AUTOSIZE);
    while (waitKey(10) != 27) {
        Mat frame;
        Mat frame_bw;
        Mat frame_edges;
        vc >> frame;
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();
        flip(frame,frame,1);
        cvtColor(frame, frame_bw, COLOR_BGR2GRAY);
        Canny(frame_bw, frame_edges, threshold1, threshold2);
        auto kernel = getStructuringElement(MORPH_ELLIPSE, {5, 5});
        morphologyEx(frame_edges, frame_edges, MORPH_CLOSE, kernel);
        vector<vector<Point>> contours;
        findContours(frame_edges, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);
        chrono::steady_clock::time_point end = chrono::steady_clock::now();
        drawContours(frame, contours, -1, {0, 0, 255});
        imshow("Window", frame);
        cout<<"Time between frame and contour is " << chrono::duration_cast<chrono::microseconds> (end- begin).count() << " microseconds" << endl;
    }
    return 0;
}