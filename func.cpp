#include "func.h"

MatrixXi txt2matrix(string addr)
{
	fstream file_a(addr);
	if (!file_a)
	{
		cout << "can't open file_a!" << endl;
	}
	MatrixXi points2d(16,2);

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
	//for (int k = 0; k < i; ++k)
	//{
	//	cout << points2d(i, 0) << ", " << points2d(i, 1) << endl;
	//}

	file_a.close();
	return points2d;
}
