#ifndef _ALGORITHM_THREE_
#define _ALGORITHM_THREE_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

class Algorithm_Three
{

public:
    Algorithm_Three(vector<Mat> users);
    int compare(Mat image);

private:
};


#endif
