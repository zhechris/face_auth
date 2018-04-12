#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <dirent.h>
#include <unistd.h>

#include "alg_one.hpp"
#include "alg_two.hpp"
#include "alg_three.hpp"
#include "face_detect.hpp"

#define THRESHOLD 30

using namespace std;
using namespace cv;

bool file_exists(string name)
{
  ifstream f(name.c_str());
  return f.good();
}

void save_face()
{
  VideoCapture camera(0);
  if (!camera.isOpened())
  {
    cout << "Error: Camera is missing." << endl;
    exit(-1);
  }

  Mat frame;
  Mat face;

  Face_Detect face_detect;


  while (true) 
  {
    camera >> frame;
    // cout << "Capturing frame..." << endl;

    if (!frame.empty() && face_detect.has_face(frame))
    {
      // cout << "Face found!." << endl;
      face = face_detect.get_face();

      if (!face.empty())
      {
        cout << "Face found!" << endl;
        break;
      }
    }

    //Wait to allow other processes to run
    imshow("Secure Your Face", frame);
  }

  int iCount = 0;
  while (true) 
  {
    stringstream ss;
    ss << "database/user_" << iCount << ".jpg";
    string dir = ss.str();

    if (!file_exists(dir))
    {
      imwrite(dir,face);
      cout << "File saved to: " << dir << endl;
      exit(0);
    } else {
      iCount++;
    }
  }
}

int main(int argc, char* argv[])
{
  char c;

  if (argc == 2)
  {
    if (strcmp(argv[1], "-s") == 0)
    {
      save_face();
    }
  }

	VideoCapture camera(0);
	if (!camera.isOpened())
	{
		cout << "Error: Camera is missing." << endl;
		exit(-1);
	}

	Mat frame;
  Mat face;

  vector<Mat> users;
  users.push_back(imread("database/user_0.jpg", CV_LOAD_IMAGE_COLOR));

  Face_Detect face_detect;
  Algorithm_One algorithm_one(users);
  Algorithm_Two algorithm_two(users);
  Algorithm_Three algorithm_three(users);

  while (true) 
  {
  	camera >> frame;
  	// cout << "Capturing frame..." << endl;

    if (!frame.empty() && face_detect.has_face(frame))
    {
      // cout << "Face found!." << endl;
      face = face_detect.get_face();

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
}
