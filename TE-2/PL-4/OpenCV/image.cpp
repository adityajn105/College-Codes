/*
        By- Aditya Jain
        Class - TE-1
        Roll-no - 302029
*/

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

int main(){
	Mat image,imgH,new_image;
	int choice;

	image=imread("/home/aditya/workspace/openCV/image12.jpeg",CV_LOAD_IMAGE_GRAYSCALE);
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
		case 3:{
			Mat rot_img= Mat::zeros(image.size(),image.type());
			int px, py, ox, oy;
			double theta;cout<<"Enter theta :";
			cin>>theta;
			theta=(3.14/180)*theta;
			ox=image.cols/2;
			oy=image.rows/2;

			for(int y=0;y<image.rows;y++){
				for(int x=0;x<image.cols;x++){
					Vec3b color = image.at<Vec3b>(Point(x,y));

					px=cos(theta)*(x-ox)-sin(theta) * (y-oy)+ ox;
					py=sin(theta)*(x-ox)+cos(theta)*(y-oy)+oy;

					if(px<image.cols && py<image.rows && py>0 && px>0)
						rot_img.at<Vec3b>(Point(px,py)) = color;
				}
			}
			cvNamedWindow("Rotated Image", CV_WINDOW_AUTOSIZE);
			cvMoveWindow("Rotated Image",300,50);
			imshow("Rotated Image", rot_img);
			break;
		}
		case 4:{
				float sum;
				float Kernel[3][3] = {
								{1/9.0, 1/9.0, 1/9.0},
								{1/9.0, 1/9.0, 1/9.0},
								{1/9.0, 1/9.0, 1/9.0}
							};
				Mat blur_img = image.clone();
				for(int y = 0; y < image.rows; y++)
					for(int x = 0; x < image.cols; x++)
						blur_img.at<uchar>(y,x) = 0.0;
				//convolution operation
				for(int y = 1; y < image.rows - 1; y++){
					for(int x = 1; x < image.cols - 1; x++){
						sum = 0.0;
						for(int k = -1; k <= 1;k++){
							for(int j = -1; j <=1; j++){
								sum = sum + Kernel[j+1][k+1]*image.at<uchar>(y - j, x - k);
							}
						}
						blur_img.at<uchar>(y,x) = sum;
					}
				}
				cvNamedWindow("Blurred Image", CV_WINDOW_AUTOSIZE);
				cvMoveWindow("Blurred Image",300,50);
				imshow("Blurred Image", blur_img);
				break;
		}


	}
	waitKey(0);
	return 0;
}



