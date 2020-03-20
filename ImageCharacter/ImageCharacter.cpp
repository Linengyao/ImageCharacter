// ImageCharacter.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = imread("E:\\课程\\数字图像处理\\coin.png");
	cv::Mat BinaryMat;
	cv::Mat ErodeMat;
	cv::Mat DilateMat;
	cv::Mat  OpenMat;
	cv::Mat CloseMat;
	//二值化
	threshold(srcMat, BinaryMat, 100, 255, THRESH_BINARY);

	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));		//矩形 9*9

	//腐蚀
	//erode(BinaryMat, ErodeMat, MORPH_RECT);
	morphologyEx(BinaryMat, ErodeMat, MORPH_ERODE,element);

	//膨胀
	morphologyEx(BinaryMat, DilateMat, MORPH_DILATE,element);
	//开运算
	morphologyEx(BinaryMat, OpenMat, MORPH_OPEN,  element);
	//闭运算
	morphologyEx(BinaryMat, CloseMat, MORPH_CLOSE, element);


	imshow("bMat", BinaryMat);
	imshow("ErodeMat", ErodeMat);
	imshow("DilateMat", DilateMat);
	imshow("OpenMat", OpenMat);
	imshow("CloseMat", CloseMat);
	waitKey(0);
	return 0;

    //std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
