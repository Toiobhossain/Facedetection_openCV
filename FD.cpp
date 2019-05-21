#include<iostream>
#include<stdlib.h>
#include<opencv2\objdetect\objdetect.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
	CascadeClassifier faceDetection;
	if (!faceDetection.load("C:\\Users\\dcL\\Downloads\\Programs\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml"))
	{
		cout << "\n File is not loaded properly";
		exit(0);
	}
	char path[100];
	cout << "\n Enter the path to image for face detection: ";
	cin.getline(path, 100);
	Mat img = imread(path, CV_LOAD_IMAGE_UNCHANGED);
	if (img.empty())
	{
		cout << "\nImage is not loaded properly";

	}
	else
	{
		cout << "\n Image is found!";
		cout << "\n Processing...";

		vector<Rect> faces;
		faceDetection.detectMultiScale(img, faces);
		for (int i = 0; i < faces.size(); i++)
		{
			Point pt1(faces[i].x, faces[i].y);
			Point pt2((faces[i].x + faces[i].height), (faces[i].y + faces[i].width));
			rectangle(img, pt1, pt2, Scalar(0, 0, 255), 2, 8, 0);



		}

		imwrite("C:\\gs\\output.jpg", img);
		cout << "\n Face detected ok";

	}

	return 0;
}