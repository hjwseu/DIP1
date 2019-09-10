#include "func.h"

int main()
{
	// read txt to matrix
	MatrixXi matrix2d_a = txt2matrix(points2d_a_addr);
	MatrixXi matrix2d_b = txt2matrix(points2d_b_addr);

	//calculate M
	MatrixXf matrix2f_a = matrix2d_a.cast<float>();
	MatrixXf matrix2f_b = matrix2d_b.cast<float>();
	MatrixXf M = matrix2f_a.jacobiSvd(ComputeThinU | ComputeThinV).solve(matrix2f_b);
	cout << M <<endl;

	//registration
	Mat input_img_a = imread("./material/A.png");
	Mat input_img_b = imread("./material/B.png");
	Mat mat_M,output_img;
	eigen2cv(M, mat_M);
	//mat_M.t();
	//Mat acol = Mat::zeros(1, 2, mat_M.type());
	//mat_M.push_back(acol);
	//mat_M.t();
	//cout << mat_M << endl;
	copyMakeBorder(mat_M, mat_M, 0, 0, 0, 1, BORDER_CONSTANT, Scalar(0));
	cout << mat_M << endl;
	warpAffine(input_img_a, output_img, mat_M, output_img.size());

	imshow("input_img_a", input_img_a);
	imshow("output_a", output_img);
	imshow("input_img_b", input_img_b);
	imwrite("ouputimg_points2d.png", output_img);
	waitKey();
	return 1;
}

