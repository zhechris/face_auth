#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

#include "alg_one.hpp"
#include "alg_two.hpp"
#include "alg_three.hpp"
#include "face_detect.hpp"

#define THRESHOLD 30

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	VideoCapture camera(0);
	if (!camera.isOpened())
	{
		cout << "Error: Camera is missing." << endl;
		exit(-1);
	}

	Mat frame;
  Mat face;

  vector<Mat> users;

  Face_Detect face_detect;
  Algorithm_One algorithm_one(users);
  Algorithm_Two algorithm_two(users);
  Algorithm_Three algorithm_three(users);

  // init_detect();

  while (true) 
  {
  	camera >> frame;
  	// cout << "Capturing frame..." << endl;

    if (!frame.empty() && face_detect.has_face(frame))
    {
      // cout << "Face found!." << endl;
      face = face_detect.get_face(frame);

      int result = 0;
      result = algorithm_one.compare(face);
      result = algorithm_two.compare(face);
      result = algorithm_three.compare(face);

      if (result > THRESHOLD)
      {
        cout << "You passed!!!!!!" << endl;
        break;
      }
    }

    //Wait to allow other processes to run
    imshow("Secure Your Face", frame);
    int c = cvWaitKey(40);

    //Exit the loop if esc key
    if(27 == char(c)) break;
  }
  imwrite("test.jpg",frame);
}
