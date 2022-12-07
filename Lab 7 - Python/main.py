import datetime
import cv2
import keyboard as keyboard

vid = cv2.VideoCapture(0)

threshold1 = 100
threshold2 = 100


def nothing(x):
    pass


cv2.namedWindow("trackbars")
cv2.createTrackbar("threshold1", "trackbars", threshold1, 500, nothing)
cv2.createTrackbar("threshold2", "trackbars", threshold2, 500, nothing)

while True:
    ret, frame = vid.read()
    start_time = datetime.datetime.now()
    flipped = cv2.flip(frame, 1)
    grey = cv2.cvtColor(flipped, cv2.COLOR_BGR2GRAY)
    Canny = cv2.Canny(grey, cv2.getTrackbarPos('threshold1', 'trackbars'),
                      cv2.getTrackbarPos('threshold2', 'trackbars'))
    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5, 5))
    morph = cv2.morphologyEx(Canny, cv2.MORPH_CLOSE, kernel)
    contours, find = cv2.findContours(morph, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    end_time = datetime.datetime.now()
    draw = cv2.drawContours(flipped, contours, -1, (0, 0, 255))
    cv2.imshow('final', draw)

    time_diff = (end_time - start_time)
    execution_time = time_diff.total_seconds() * 1000000
    print(f'Time between frame and contour is {int(execution_time)} microseconds')

    if cv2.waitKey(1) & keyboard.is_pressed('Esc'):
        break

vid.release()
cv2.destroyAllWindows()
