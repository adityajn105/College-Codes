/*
 * Main.cpp
 *
 *  Created on: 19-Jan-2017
 *      Author: student
 */

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int computeOutput(int x, int r1, int s1, int r2, int s2);

int main(int argc, char **argv) {

	Mat image = imread(argv[1], 0);

	if(!image.data) {
		cout << "No image data." << endl;
		return -1;
	}

	cout << "1. Contrast Enhancement\n";
	cout << "2. Brightness\n";
	cout << "3. Rotate\n";
	cout << "4. Image Blurring\n";
	cout << "5. Sharpening\n";
	cout << "6. Histogram\n";
	cout << "7. PMF\n";
	cout << "8. Mean and Std Deviation\n";
	cout << "n. Exit\n";
	cout << "Enter your choice: ";
	int ch;
	cin >> ch;

	if(ch == 1) { // Contrast
	Mat newImage = image.clone();
	int r1, s1, r2, s2;
	cout << "Enter (r1, s1): ";
	cin >> r1 >> s1;
	cout << "Enter (r2, s2): ";
	cin >> r2 >> s2;


	for(int i = 0; i < newImage.rows; i++) {
		for(int j = 0; j < newImage.cols; j++) {

			for(int p = 0; p < 3; p++) { // Iterate over 3 RGB values
				int out = computeOutput(newImage.at<Vec3b>(i, j)[p], r1, s1, r2, s2);
				newImage.at<Vec3b>(i, j)[p] = saturate_cast<uchar>(out);
			}
		}
	}

	namedWindow("Original", WINDOW_NORMAL);
	imshow("Original", image);

	namedWindow("Edited", WINDOW_NORMAL);
	imshow("Edited", newImage);
	waitKey(0);
	}
	if(ch == 2) { // Brightness
		Mat bImage = image.clone();
		float bright = 0.0f;
		cout << "Enter brightness % to increase/decrease: ";
		cin >> bright;
		bright /= 100;
		for(int i = 0; i < bImage.rows; i++) {
			for(int j = 0; j < bImage.cols; j++) {

				for(int p = 0; p < 3; p++) {
					int og = bImage.at<Vec3b>(i, j)[p];
					bImage.at<Vec3b>(i, j)[p] = saturate_cast<uchar>(og + (og * bright));
				}
			}
		}

		namedWindow("Original", WINDOW_NORMAL);
		imshow("Original", image);

		namedWindow("Brightness Edited", WINDOW_NORMAL);
		imshow("Brightness Edited", bImage);
		waitKey(0);
	}

	if(ch == 3) { // Rotate
		Mat rotated = Mat::zeros(image.size(), image.type());
		double angle;
		cout << "Enter rotation angle: ";
		cin >> angle;
		const double conv = 3.1415 / 180.0;
		angle = conv * angle;

		int cx = image.cols / 2;
		int cy = image.rows / 2;

		int targetX = 0, targetY = 0;

		for(int i = 0; i < image.rows; i++) {
			for(int j = 0; j < image.cols; j++) {

				Vec3b src = image.at<Vec3b>(i, j);


				targetX = cos(angle) * (j - cx) - sin(angle) * (i - cy) + cx;
				targetY = sin(angle) * (j - cx) + cos(angle) * (i - cy) + cy;


				if(targetX < image.cols && targetY < image.rows && targetX > 0 && targetY > 0)
					rotated.at<Vec3b>(targetX, targetY) = src;
			}
		}


		namedWindow("Original", WINDOW_NORMAL);
		imshow("Original", image);

		namedWindow("Rotated", WINDOW_NORMAL);
		imshow("Rotated", rotated);

		waitKey(0);
	}

	if(ch == 4) { // Blurring
		Mat image2 = imread(argv[1], 0);
		Mat dst = Mat::zeros(image2.size(), image2.type());
		double kernel[3][3] = {
				{1/9.0, 1/9.0, 1/9.0},
				{1/9.0, 1/9.0, 1/9.0},
				{1/9.0, 1/9.0, 1/9.0}
		};
		for(int y = 1; y < image2.rows - 1; y++) {
			for(int x = 1; x < image2.cols - 1; x++) {

				float sum = 0.0f;

					for(int l = -1; l <= 1; l++) {
						for(int k = -1; k <= 1; k++) {
							sum +=  kernel[l + 1][k + 1] * image2.at<uchar>(x - l, y - k);
						}
					}

				sum = cvRound(sum);

				dst.at<uchar>(x, y) = sum;
			}
		}

		namedWindow("Original", WINDOW_NORMAL);
		imshow("Original", image);

		namedWindow("Blurred", WINDOW_NORMAL);
		imshow("Blurred", dst);

		waitKey(0);
	}

	if(ch == 5) { // Sharpening
			Mat image2 = imread(argv[1], 0);
			Mat dst = Mat::zeros(image2.size(), image2.type());
			double kernel[3][3] = {
					{-1, -1, -1},
					{-1,  4, -1},
					{-1, -1, -1},
			};
			for(int y = 1; y < image2.rows - 1; y++) {
				for(int x = 1; x < image2.cols - 1; x++) {

					float sum = 0.0f;

						for(int l = -1; l <= 1; l++) {
							for(int k = -1; k <= 1; k++) {
								sum +=  kernel[l + 1][k + 1] * image2.at<uchar>(x - l, y - k);
							}
						}

					sum = cvRound(sum);

					dst.at<uchar>(x, y) = sum;
				}
			}

			namedWindow("Original", WINDOW_NORMAL);
			imshow("Original", image);

			namedWindow("Sharpened", WINDOW_NORMAL);
			imshow("Sharpened", dst);

			waitKey(0);
		}

	if(ch == 6) { // Histogram

		double histogram[255];

		for(int i = 0; i < 256; i++)
			histogram[i] = 0;

		for(int row = 0; row < image.rows; row++) {
			for(int col = 0; col < image.cols; col++) {
				histogram[(int)image.at<uchar>(row,col)]++;
			}
		}

		for(int i = 0; i < 256; i++)
			cout << histogram[i] << " ";
		cout << endl;


		// draw the histograms
		int hist_w = 512;
		int hist_h = (ch == 7) ? 100 : 400;
		int bin_w = cvRound((double) hist_w/256);

		Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(255, 255, 255));

		// Find max
		double max = histogram[0];
		for(int i = 0; i < 256; i++) {
			if(max < histogram[i])
				max = histogram[i];
		}

		for(int i = 0; i < 256; i++) {
			histogram[i] = (histogram[i]/max) * histImage.rows;
		}

		for(int i = 0; i < 256; i++)
			cout << histogram[i] << " ";
		cout << endl;


		// Draw line
		for(int i = 0; i < 256; i++) {
			line(histImage, Point(bin_w * i, hist_h), Point(bin_w * i, hist_h - histogram[i]), Scalar(0,0,0), 1, 8, 0);
		}

		imshow("Original", image);
		imshow("Histogram", histImage);
		waitKey(0);

	}
	if (ch == 7) {
		double histogram[255];

				for(int i = 0; i < 256; i++)
					histogram[i] = 0;

				for(int row = 0; row < image.rows; row++) {
					for(int col = 0; col < image.cols; col++) {
						histogram[(int)image.at<uchar>(row,col)] += 1.0;
					}
				}

				for(int i = 0; i < 256; i++)
					cout << histogram[i] << " ";
				cout << endl;


				// draw the histograms
				int hist_w = 512;
				int hist_h = 100;
				int bin_w = cvRound((double) hist_w/256);

				Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(255, 255, 255));

				int pixels = image.rows * image.cols;

				for(int i = 0; i < 256; i++)
					histogram[i] = histogram[i] / pixels;

				// Find max
				double max = histogram[0];
				for(int i = 0; i < 256; i++) {
					if(max < histogram[i])
						max = histogram[i];
				}

				for(int i = 0; i < 256; i++) {
					histogram[i] = (histogram[i]/max) * histImage.rows;
				}


				// Draw line
				for(int i = 0; i < 256; i++) {
					line(histImage, Point(bin_w * i, hist_h), Point(bin_w * i, hist_h - histogram[i]), Scalar(0,0,0), 1, 8, 0);
				}

				imshow("Original", image);
				imshow("PMF", histImage);
				waitKey(0);
	}

	if (ch == 8) {
		double mean;
		double stddev;
		double total = 0.0;
		double sqrsum = 0;

		double histogram[255];

				for(int i = 0; i < 256; i++)
					histogram[i] = 0;

				for(int row = 0; row < image.rows; row++) {
					for(int col = 0; col < image.cols; col++) {
						histogram[(int)image.at<uchar>(row,col)] += 1.0;
					}
				}

				for(int i = 0; i < 256; i++)
					cout << histogram[i] << " ";
				cout << endl;

				for(int i = 0; i < 256; i++) {
					total += histogram[i];
				}

				mean = total / 256;

				for(int i = 0; i < 256; i++) {
					sqrsum += (histogram[i] - mean) * (histogram[i] - mean);
				}

				stddev = sqrt(sqrsum) / 255;

				cout << "Mean: " << mean << endl;
				cout << "Std Deviation: " << stddev << endl;
	}


	return 0;
}

int computeOutput(int x, int r1, int s1, int r2, int s2) {
	float res = 0.0f;
	if(0 <= x && x <= r1) {
		res = s1 / r1 * x;
	} else if(r1 < x && x <= r2) {
		res = ((s2 - s1) / (r2 - r1)) * (x - r1) + s1;
 	} else if(r2 < x && x <= 255) {
 		res = ((255 - s2)/(255 - r2)) * (x - r2) + s2;
 	}

	return (int) res;
}
