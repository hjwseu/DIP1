#include "func.h"

int main()
{
	//*****************************************************
	//1.1
	// read txt to matrix
	MatrixXi matrix2d_a = txt2matrix(points2d_a_addr);
	MatrixXi matrix2d_b = txt2matrix(points2d_b_addr);

	//Convert an int matrix to a float matrix
	MatrixXf matrix2f_a = matrix2d_a.cast<float>(); 
	MatrixXf matrix2f_b = matrix2d_b.cast<float>();

	//Homogeneous
	MatrixXf matrix2f_a_homo(16, 3);
	MatrixXf mat_one_1(16, 1);
	mat_one_1.setOnes();
	matrix2f_a_homo << matrix2f_a, mat_one_1;

	//calculate M'
	MatrixXf M = matrix2f_a_homo.jacobiSvd(ComputeThinU | ComputeThinV).solve(matrix2f_b);

	//Transpose M' to M
	M.transposeInPlace();
	cout << M << endl;

	Mat input_img_a = imread("./material/A.png");
	Mat input_img_b = imread("./material/B.png");
	Mat mat_M,output_img;
	eigen2cv(M, mat_M);

	warpAffine(input_img_a, output_img, mat_M, output_img.size());

	imwrite("ouputimg_points2d_1.png", output_img);
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

	//Homogenous
	MatrixXf matrix3f_a_homo(16, 4);
	MatrixXf matrix3f_b_homo(16, 4);
	matrix3f_a_homo << matrix3f_a, mat_one;
	matrix3f_b_homo << matrix3f_b, mat_one;

	//K
	MatrixXf K(3,3);
	K << 746.07, 0, 493.94,
		0, 743.92, 488.76,
		0, 0, 1;
	//inverse K and transform K^-1
	K.inverse();
	K.transposeInPlace();

	//calculate 
	MatrixXf RT_a = matrix3f_a_homo.jacobiSvd(ComputeThinU | ComputeThinV).solve(mat2d_homo_a *K);
	MatrixXf RT_b = matrix3f_b_homo.jacobiSvd(ComputeThinU | ComputeThinV).solve(mat2d_homo_b *K);

	RT_a.transposeInPlace();
	RT_b.transposeInPlace();
	cout << "RT_a is " << endl << RT_a << endl;
	cout << "RT_b is " << endl << RT_b << endl;

	////calculate S
	//MatrixXf matrix3f_a = matrix3d_a.cast<float>(); //Convert an int matrix to a float matrix
	//MatrixXf matrix3f_b = matrix3d_b.cast<float>();
	//MatrixXf S = matrix3f_a.jacobiSvd(ComputeThinU | ComputeThinV).solve(matrix2f_b);
	//cout << S << endl;
	////*****************************************************

	waitKey();
	return 1;
}

