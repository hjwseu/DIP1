#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

#include<Eigen/Dense>
#include<opencv2/opencv.hpp>
#include<opencv2/core/eigen.hpp>

#if _DEBUG
#pragma comment(lib,"opencv_world411d.lib")
#else 
#pragma comment(lib,"opencv_world411.lib")
#endif

using namespace std;
using namespace cv;
using namespace Eigen;

#define points2d_a_addr "./material/points2d_A.txt"
#define points2d_b_addr "./material/points2d_B.txt"
#define points3d_a_addr "./material/points3d_A.txt"
#define points3d_b_addr "./material/points3d_B.txt"


MatrixXi txt2matrix(string addr);
