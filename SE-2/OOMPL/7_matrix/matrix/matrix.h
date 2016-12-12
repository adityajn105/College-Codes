#ifndef MATRIX_H
#define MATRIX_H
template<class T>
class matrix{
    T mat[3][3];
public:
    matrix()
    {
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                    mat[i][j]=0;
    }
    matrix <T> add(matrix<T>z)
    {
        matrix temp;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                temp.mat[i][j]=mat[i][j]+z.mat[i][j];
        return temp;
    }
    matrix <T> subtract(matrix<T>z)
    {
        matrix temp;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                temp.mat[i][j]=mat[i][j]-z.mat[i][j];
        return temp;
    }
    matrix <T> multiply(matrix<T>z);

    matrix <T> trans()
    {
        matrix temp;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                temp.mat[i][j]=mat[j][i];
            }
        return temp;
    }
    friend class MainWindow;
};
#endif // MATRIX_H
