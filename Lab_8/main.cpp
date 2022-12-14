#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

int main() {
    using namespace std;
    using namespace cv;

    VideoCapture vc(0);
    if (!vc.isOpened()) return 1;

    Mat frame, frame_bw, frame_edges;
    array low = {0, 120, 125};
    array high = {15, 255, 255};

    namedWindow("trackbars");

    createTrackbar("lh", "trackbars", &low[0], 255);
    createTrackbar("ls", "trackbars", &low[1], 255);
    createTrackbar("lv", "trackbars", &low[2], 255);
    createTrackbar("hh", "trackbars", &high[0], 255);
    createTrackbar("hs", "trackbars", &high[1], 255);
    createTrackbar("hv", "trackbars", &high[2], 255);

    while (waitKey(10) != 27) {
        vc >> frame;
        cvtColor(frame, frame_bw, COLOR_BGR2HSV);
        inRange(frame_bw, low, high, frame_edges);
        auto kernel = getStructuringElement(MORPH_ELLIPSE, {5, 5});
        morphologyEx(frame_edges, frame_edges, MORPH_CLOSE, kernel);
        morphologyEx(frame_edges, frame_edges, MORPH_OPEN, kernel);

        imshow("frame_edges", frame_edges);
        imshow("frame", frame);

        vector<vector<Size>> contours;
        findContours(frame_edges, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

        if (contours.size() >= 2) {

            sort(contours.begin(), contours.end(), [](const vector<Size>& a, const vector<Size>& b) {
                return contourArea(a) > contourArea(b);
            });

            auto c1 = moments(contours[0], false);
            auto c2 = moments(contours[1], false);

            int s1 = contours[0].size()/2;
            int s2 = contours[1].size()/2;

            int x_center_c1 = (int) (c1.m10 / c1.m00);
            int y_center_c1 = (int) (c1.m01 / c1.m00);
            int x_center_c2 = (int) (c2.m10 / c2.m00);
            int y_center_c2 = (int) (c2.m01 / c2.m00);

            Point p1 = {x_center_c1, y_center_c1};
            Point p2 = {x_center_c2,y_center_c2};

            ellipse(frame, p1, Size{5+s1, 5+s1}, 0.0, 0, 360, {0, 255, 0}, 2);
            ellipse(frame, p2, Size{5+s2, 5+s2}, 0.0, 0, 360, {0, 255, 0}, 2);

            imshow("frame", frame);

            if ((y_center_c1 - y_center_c2 > -5) && (y_center_c1 - y_center_c2 < 5) ) {
                line(frame, Point (x_center_c1, y_center_c1 + 5),Point (x_center_c2, y_center_c2 + 5), {255,0,0}, 2);
                line(frame, Point (x_center_c1, y_center_c1 - 5),Point (x_center_c2, y_center_c2 - 5), {255,0,0}, 2);

                imshow("frame", frame);
            }
        }
    }
    return 0;
}