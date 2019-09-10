#include "func.h"

MatrixXi txt2matrix(string addr)
{
	fstream file_a(addr);
	if (!file_a)
	{
		cout << "can't open file_a!" << endl;
	}
	MatrixXi points2d(16, 2);

	int a, b;
	int i = 0;
	char buffer[256];
	while (!file_a.eof())
	{
		file_a.getline(buffer, 10);
		sscanf(buffer, "%d,%d", &a, &b);
		points2d(i,0) = a;
		points2d(i,1) = b;
		++i;
	}

	file_a.close();
	return points2d;
}

MatrixXf txt2matrix_3(string addr)
{
	fstream file_a(addr);
	if (!file_a)
	{
		cout << "can't open file_a!" << endl;
	}
	MatrixXf points3f(16, 3);

	float a, b, c;
	int i = 0;
	char buffer[256];
	while (!file_a.eof())
	{
		file_a.getline(buffer, 30);
		sscanf(buffer, "%f,%f,%f", &a, &b, &c);
		points3f(i, 0) = a;
		points3f(i, 1) = b;
		points3f(i, 2) = c;
		++i;
	}

	file_a.close();
	return points3f;
	return MatrixXf();
}
