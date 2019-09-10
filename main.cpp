#include "func.h"

int main()
{
	//*****************************************************
	//1.1
	// read txt to matrix
	MatrixXi matrix2d_a = txt2matrix(points2d_a_addr);
	MatrixXi matrix2d_b = txt2matrix(points2d_b_addr);

	//calculate M
	MatrixXf matrix2f_a = matrix2d_a.cast<float>(); //Convert an int matrix to a float matrix
	MatrixXf matrix2f_b = matrix2d_b.cast<float>();
	MatrixXf M = matrix2f_a.jacobiSvd(ComputeThinU | ComputeThinV).solve(matrix2f_b);
	cout << M <<endl;
	
	Mat input_img_a = imread("./material/A.png");
	Mat input_img_b = imread("./material/B.png");
	Mat mat_M,output_img;
	eigen2cv(M, mat_M);

	//registration
	copyMakeBorder(mat_M, mat_M, 0, 0, 0, 1, BORDER_CONSTANT, Scalar(0));
	cout << mat_M << endl;
	warpAffine(input_img_a, output_img, mat_M, output_img.size());

	//imshow("input_img_a", input_img_a);
	//imshow("output_a", output_img);
	//imshow("input_img_b", input_img_b);
	//imwrite("ouputimg_points2d.png", output_img);
	//*****************************************************

	//*****************************************************
	//1.2
	//transform 2d to Homogeneous coordinates
	MatrixXf mat2d_homo_a(16, 3); 
	MatrixXf mat2d_homo_b(16, 3);
	MatrixXf mat_one(16, 1);
	mat_one.setOnes();
	mat2d_homo_a << matrix2f_a, mat_one;
	mat2d_homo_b << matrix2f_b, mat_one;

	//read the point3d txt
	MatrixXf matrix3f_a = txt2matrix_3(points3d_a_addr);
	MatrixXf matrix3f_b = txt2matrix_3(points3d_b_addr);

	//K
	MatrixXf K(3,3);
	K << 746.07, 0, 493.94,
		0, 743.92, 488.76,
		0, 0, 1;
	MatrixXf Sa = mat2d_homo_a.jacobiSvd(ComputeThinU | ComputeThinV).solve(matrix3f_a*K);
	MatrixXf Sb = mat2d_homo_b.jacobiSvd(ComputeThinU | ComputeThinV).solve(matrix3f_b*K);
	cout << "Sa is " << endl<< Sa <<endl;
	cout << "Sb is " << endl << Sb << endl;

	////calculate S
	//MatrixXf matrix3f_a = matrix3d_a.cast<float>(); //Convert an int matrix to a float matrix
	//MatrixXf matrix3f_b = matrix3d_b.cast<float>();
	//MatrixXf S = matrix3f_a.jacobiSvd(ComputeThinU | ComputeThinV).solve(matrix2f_b);
	//cout << S << endl;
	////*****************************************************

	waitKey();
	return 1;
}

