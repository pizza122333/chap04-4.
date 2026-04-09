#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
    // 1. Lenna 영상을 컬러 영상으로 읽기
    Mat img = imread("lenna.bmp", IMREAD_COLOR);

    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    namedWindow("img");

    int key;
    while (true) {
        imshow("img", img);
        key = waitKey(0); // 키 입력을 기다림 (0 혹은 적절한 ms 설정)

        if (key == 'q' || key == 'Q') {
            // 'q'를 누르면 종료
            break;
        }
        else if (key == 'l' || key == 'L') {
            // 'l'을 누르면 얼굴 아래에 직선 그리기
            // line(영상, 시작점, 끝점, 색상, 두께)
            line(img, Point(200, 400), Point(350, 400), Scalar(0, 0, 255), 3);
            cout << "Line drawn under the face." << endl;
        }
        else if (key == 'c' || key == 'C') {
            // 'c'를 누르면 얼굴 주위에 원 그리기
            // circle(영상, 중심점, 반지름, 색상, 두께)
            circle(img, Point(270, 270), 100, Scalar(0, 255, 0), 3);
            cout << "Circle drawn around the face." << endl;
        }
        else if (key == 't' || key == 'T') {
            // 't'를 누르면 영상 상단에 문자열 출력
            // putText(영상, 문자열, 위치, 폰트, 크기, 색상, 두께)
            putText(img, "Hello, Lenna!", Point(50, 50), FONT_HERSHEY_SIMPLEX,
                1.2, Scalar(255, 0, 0), 2);
            cout << "Text printed on top." << endl;
        }
    }

    destroyAllWindows();
    return 0;
}