#ifndef _ALGORITHM_TWO_
#define _ALGORITHM_TWO_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

class Algorithm_Two
{

public:
    Algorithm_Two(vector<Mat> users);
    int compare(Mat image);

private:
};

#endif
