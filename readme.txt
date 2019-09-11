DIP1-仿射变换及透视变换
文件夹
    3rdparty:放置了Eigen和OpenCV的第三方库
    material:放置了点集（txt）和输入图片

文件
    func.h：
    Eigen和OpenCV库的使用声明
    定义了四个点集的相对路径

    func.cpp：
    MatrixXi txt2matrix(string addr):输入2d点集txt文件地址，返回int型矩阵
    MatrixXf txt2matrix_3(string addr):输入3d点集txt文件地址，返回float型矩阵

    main.cpp：
    1.1仿射变换：
        将2d点集读入int矩阵;
        将int矩阵转化为float型;
        将A坐标齐次化;
        利用最小二乘法求出M的转置;(从txt读入实际上为A、B的转置，由MA=B，A'M'=B'得知，实际上求出的是M的转置M')
        由M'求出M，即warpAffine的第三个参数M，使用该函数;
        得到A通过M变换后的图片。

        分析：
        A通过M变换后的图和B图相比，图中的两人关节位置基本对齐，有一点误差(最小二乘法求出的近似解M)。但是左边的人
        两腿关节并没有很好对齐。可能是两腿关节的水平位置过于接近。
    1.2透视变换：
        将A\B两图的2d坐标都其次化;
        读入A\B两图的3d坐标，并且齐次化;
        输入矩阵K，求K逆的转置k^';(根据透视变换,X=K[R,T]x,因为K可逆,所以x'[R,T]'=K^'X')
        通过最小二次法求[R,T]矩阵的转置[R,T]';
        由[R,T]'转置得到[R,T];即所求的变换矩阵。