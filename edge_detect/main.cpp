#include <cv.hpp>
#include <cxcore.hpp>
#include <opencv2/opencv.hpp>
 
using namespace cv;
using namespace std;
 
int edgeThresh = 1;
 
// 聲明 原始圖片，灰度圖片，和 canny邊緣圖片
	Mat image, cedge;
	Mat gray, edge;
 
void onTrackbar(int, void*)
{
	//blur 灰度圖片
	blur(gray, edge, Size(3,3));
 
	// Canny 邊緣檢測
	Canny(gray,edge, edgeThresh, edgeThresh*3, 3);
 
	//全部設為0
	cedge = Scalar::all(0);
 
	//拷貝邊緣的象素點
	image.copyTo(cedge, edge);
 
	imshow("Edge map", edge);
 
}



int main(int argc, char** argv)
{
 
 
	// 載入圖片
	image = imread(argv[1], 1);
 
	// 判斷載入圖片是否成功
	if(image.empty())
	{
		printf("miss the image file: %s \n", argv[1]);
		return -1;
	}
 
	// 生成灰度圖片，因為只有灰度圖片才能生成邊緣圖片
         cedge.create(image.size(), image.type());
	cvtColor(image,gray, CV_BGR2GRAY);
 
	//新建一個視窗
	namedWindow("Edge map", 1);
 
	// 生成一個進度條來控制邊緣檢測
	createTrackbar("Canny Threshold", "Edge map", &edgeThresh, 100, onTrackbar);
 
	//初始化圖像
	onTrackbar(0,0);
 
	waitKey(0);
 
	return 0;
}
