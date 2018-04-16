/*
 *
 *  First Algorithm to test image
 *    against known dataset
 *
 */

#include "alg_one.hpp"

Algorithm_One::Algorithm_One(vector<Mat> users) 
{
    // Constructor
}

int Algorithm_One::compare(Mat face)
{
    // INSERT ALGORITHM HERE
    if (argc <2)   
　　{  
        cout <<"usage: "<< argv[0]<<" <csv.ext> <output_folder> "<< endl;  
        exit(1);  
  
    }  
  
    string output_folder;  
  
    if (argc ==3)   
　　{  
  
        output_folder = string(argv[2]);  
  
    }  
  
    //读取你的CSV文件路径.  
  
    string fn_csv = string(argv[1]);  
    // 2个容器来存放图像数据和对应的标签  
    vector<Mat> images;  
    vector<int> labels;  
    // 读取数据. 如果文件不合法就会出错  
    // 输入的文件名已经有了.  
    try {  
  
        read_csv(fn_csv, images, labels);  
  
    } catch (cv::Exception& e) {  
        cerr <<"Error opening file \""<< fn_csv <<"\". Reason: "<< e.msg << endl;  
        // 文件有问题，我们啥也做不了了，退出了  
        exit(1);  
    }  
  
    // 如果没有读取到足够图片，我们也得退出.  
    if(images.size()<=1) {  
        string error_message ="This demo needs at least 2 images to work. Please add more images to your data set!";  
        CV_Error(CV_StsError, error_message);  
    }  
  
    // 得到第一张照片的高度. 在下面对图像  
    // 变形到他们原始大小时需要  
    int height = images[0].rows;  
    // 下面的几行代码仅仅是从你的数据集中移除最后一张图片  
    //[gm:自然这里需要根据自己的需要修改，他这里简化了很多问题]  
    Mat testSample = images[images.size() -1];  
    int testLabel = labels[labels.size() -1];  
    images.pop_back();  
    labels.pop_back();  
    // 下面几行创建了一个特征脸模型用于人脸识别，  
    // 通过CSV文件读取的图像和标签训练它。  
    // T这里是一个完整的PCA变换  
    //如果你只想保留10个主成分，使用如下代码  
    //      cv::createEigenFaceRecognizer(10);  
    //  
    // 如果你还希望使用置信度阈值来初始化，使用以下语句：  
    //      cv::createEigenFaceRecognizer(10, 123.0);  
    //  
    // 如果你使用所有特征并且使用一个阈值，使用以下语句：  
    //      cv::createEigenFaceRecognizer(0, 123.0);  
    //  
    Ptr<FaceRecognizer> model1 = createFisherFaceRecognizer();
    model->train(images, labels);  
    // 下面对测试图像进行预测，predictedLabel是预测标签结果  
    int predictedLabel = model->predict(testSample);  
    //  
    // 还有一种调用方式，可以获取结果同时得到阈值:  
    //      int predictedLabel = -1;  
    //      double confidence = 0.0;  
    //      model->predict(testSample, predictedLabel, confidence);  
    //  
  
    string result_message = format("Predicted class = %d / Actual class = %d.", predictedLabel, testLabel);  
    cout << result_message << endl;  
    return 0;
}
