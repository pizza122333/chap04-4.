#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 마우스 콜백 함수 선언
void on_mouse(int event, int x, int y, int flags, void* userdata);

int main(void)
{
    // 1. 영상을 그레이스케일로 읽기 (IMREAD_GRAYSCALE)
    Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    namedWindow("img");

    // 2. 마우스 콜백 설정: 영상 객체의 주소를 넘겨줌
    setMouseCallback("img", on_mouse, &img);

    imshow("img", img);

    cout << "영상 위의 점을 클릭하면 좌표와 화소값이 출력됩니다. (종료: q)" << endl;

    while (true) {
        if (waitKey(10) == 'q') break;
    }

    destroyAllWindows();
    return 0;
}

// 마우스 콜백 함수 정의
void on_mouse(int event, int x, int y, int flags, void* userdata)
{
    // void* 타입을 Mat* 타입으로 형변환
    Mat& img = *(Mat*)userdata;

    if (event == EVENT_LBUTTONDOWN) {
        // [중요] 마우스 x는 열(column), y는 행(row)입니다.
        // 그레이스케일 영상이므로 화소 타입은 uchar (unsigned char)입니다.
        int pixel_value = (int)img.at<uchar>(y, x);

        cout << "좌표: (" << x << ", " << y << ") -> 화소값: " << pixel_value << endl;
    }
}