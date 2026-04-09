#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 마우스 콜백 함수 선언
void on_mouse(int event, int x, int y, int flags, void* userdata);

int main(void)
{
    // 1. 영상을 컬러 영상으로 읽기
    Mat img = imread("lenna.bmp", IMREAD_COLOR);

    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    namedWindow("img");

    // 2. 마우스 콜백 설정: Mat 객체의 주소를 전달
    setMouseCallback("img", on_mouse, &img);

    imshow("img", img);
    cout << "영상 위를 클릭하면 (x, y) 좌표와 BGR 값을 출력합니다. (종료: q)" << endl;

    while (true) {
        if (waitKey(10) == 'q') break;
    }

    destroyAllWindows();
    return 0;
}

// 마우스 콜백 함수 정의
void on_mouse(int event, int x, int y, int flags, void* userdata)
{
    // 전달받은 void* 타입을 Mat* 타입으로 형변환
    Mat& img = *(Mat*)userdata;

    if (event == EVENT_LBUTTONDOWN) {
        // [중요] 컬러 영상의 한 픽셀은 Vec3b (unsigned char 3개) 타입입니다.
        // 마우스 y가 행(row), x가 열(column)입니다.
        Vec3b pixel = img.at<Vec3b>(y, x);

        // B, G, R 순서로 저장되어 있습니다.
        int b = pixel[0];
        int g = pixel[1];
        int r = pixel[2];

        cout << "클릭 좌표: (" << x << ", " << y << ")" << endl;
        cout << "화소값(BGR): [" << b << ", " << g << ", " << r << "]" << endl;
        cout << "------------------------------------" << endl;
    }
}