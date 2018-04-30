/*
 *
 *  Third Algorithm to test image
 *    against known dataset
 *
 */

#include "alg_three.hpp"

Algorithm_Three::Algorithm_Three(vector<Mat> users)
{
    // Constructor
}

template <typename _Tp>
int Algorithm_Three::compare(Mat face) //int Algorithm_Three::compare(Mat _src, Mat _dst)
{
    
	/*
	Mat src = _src.getMat()
	_dst.create(src.rows-2, src.cols-2, CV_8UC1);
	Mat dst = _dst.getMat();
	dst.setTo(0);
	for(int i=1; i < src.rows-1; i++) {
		for(int j=1; j < src.cols-1; j++) {
			_Tp center = src.at<_Tp>(i,j);
			unsigned char code = 0;
			code |= (src.at<_Tp>(i-1,j-1) > center) << 7;
			code |= (src.at<_Tp>(i-1,j) > center) << 6;
			code |= (src.at<_Tp>(i-1,j+1) > center) << 5;
			code |= (src.at<_Tp>(i,j+1) > center) << 4;
			code |= (src.at<_Tp>(i+1,j+1) > center) << 3;
			code |= (src.at<_Tp>(i+1,j) > center) << 2;
			code |= (src.at<_Tp>(i+1,j-1) > center) << 1;
			code |= (src.at<_Tp>(i,j-1) > center) << 0;
			dst.at<unsigned char>(i-1,j-1) = code;
		}
	}
	*/
	
	
  return 0;
}
