
#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int computeOutput(int x, int r1, int s1, int r2, int s2)
{
    float result;
    if(0 <= x && x <= r1){
        result = s1/r1 * x;
    }else if(r1 < x && x <= r2){
        result = ((s2 - s1)/(r2 - r1)) * (x - r1) + s1;
    }else if(r2 < x && x <= 255){
        result = ((255 - s2)/(255 - r2)) * (x - r2) + s2;
    }
    return (int)result;
}

int main()
{
	Mat image,imgH,rot_img,new_image;
	int choice;
    /*CV_LOAD_IMAGE_UNCHANGED (<0) loads the image as is (including the alpha channel if present)
	  CV_LOAD_IMAGE_GRAYSCALE ( 0) loads the image as an intensity one
	  CV_LOAD_IMAGE_COLOR (>0) loads the image in the BGR format  */

	image=imread("/home/student/workspace/OpenCV/files/image12.jpeg");
	cout<<image.rows<<" "<<image.cols<<endl;;
	if(!image.data)
	{
		cout<<"No image data\n";
		return -1;
	}
	cvNamedWindow("org",CV_WINDOW_AUTOSIZE);
	cvMoveWindow("bright", 0, 0);
	imshow("org",image);
	cout<<"Menu\n 1.Brightness 2.Contrast Stretching 3.Rotation 4.Blur 5.Sharpness\nYour Choice : ";
	cin>>choice;
	switch(choice){
	case 1:
		imgH = image + Scalar(50,50,50);	//255 - white //increase every pixel value by 50
		cvNamedWindow("bright",CV_WINDOW_AUTOSIZE);
		imshow("bright",imgH);
		break;
	case 2:
			int r1, s1, r2, s2;
			new_image = image.clone();
		    cout<<"Enter r1: "<<endl; cin>>r1;
		    cout<<"Enter s1: "<<endl; cin>>s1;
		    cout<<"Enter r2: "<<endl; cin>>r2;
		    cout<<"Enter s2: "<<endl; cin>>s2;

		    for(int y = 0; y < image.rows; y++){
		        for(int x = 0; x < image.cols; x++){
		            for(int c = 0; c < 3; c++){
		                int output = computeOutput(image.at<Vec3b>(y,x)[c], r1, s1, r2, s2);
		                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>(output);
		            }
		        }
		    }
		    cvNamedWindow("New Image", CV_WINDOW_AUTOSIZE);
		    cvMoveWindow("New Image",300,50);
		    imshow("New Image", new_image);
		    break;
	case 3:
		rot_img=Mat(263,192, CV_64F, cvScalar(0.));
		for(int y = 0; y < image.rows; y++){
			for(int x = 0; x < image.cols; x++){
					rot_img.at<Vec3b>(x,y)  = image.at<Vec3b>(y,x);
			}
		}
		cvNamedWindow("rot_img", CV_WINDOW_AUTOSIZE);
		cvMoveWindow("rot_img",300,50);
		imshow("rot_img", rot_img);
		break;
	}
	waitKey(0);
	return 0;
}



