#include"iostream.h"
#include"graph.h"
#define MaxInt 32767
#define m 30
typedef int** DistanceMatrix;
typedef int** PathMatrix;

template <class T>
void ShortestPathFloyd(Graph<T> G, PathMatrix &Path, DistanceMatrix& A)
{
    int n = G.NumberOfVertices();
    int i, j, k, t;
    T u, v, w;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)  {
             A[i][j] = Edge[i][j];
             if (i <> j && A[i][j] < MAXINT)  Path[i][j] = i;		//i到j有路径 
             else Path[i][j] = 0;	    //i到j无路径
        }
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (A[i][k] + A[k][j] < A[i][j])  {
                    A[i][j] = A[i][k] + A[k][j];
                    Path[i][j] = Path[k][j];
                }//缩短路径长度, 绕过k到j
}

