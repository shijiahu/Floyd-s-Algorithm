//
//  main.cpp
//  floyd
//
//  Created by shijia hu on 4/6/17.
//  Copyright © 2017 shijia hu. All rights reserved.
//

#include <iostream>
#include <time.h>

using namespace std;

int path[10][10];
int A[10][10];


void Path(int i,int j)
{
    if (path[i][j]==-1)
    {
        return;
    }
    Path(i,path[i][j]);
    cout<<"v"<<path[i][j]+1<<" ";
    Path(path[i][j],j);
}

void Dispath(int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (i != j && i < j) {
                cout<<"From "<<i+1<<" to "<<j+1<<"=>length: "<<A[i][j]<<" The route is: v"<<i+1<<" ";
                Path(i,j);
                cout<<"v"<<j+1<<endl;
            }
        }
    }
}
void Floyd(int **matrixA, int n)
{
    int i,j,k;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            A[i][j]=matrixA[i][j];
            path[i][j]=-1;
        }
    }
    for (k=0;k<n;k++)
    {
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (A[i][j]>A[i][k]+A[k][j])
                {
                    A[i][j]=A[i][k]+A[k][j];
                    path[i][j]=k;
                }
            }
        }
    }
    Dispath(n);
}



int main() {

    srand(time(0));
    int n;
    n = rand() % (10-5+1)+5;
    cout<<"Selected n = "<<n<<endl;
    
    int **matrixA;
    matrixA = new int *[n+1];
    for (int i = 0; i<n; i++) {
        matrixA[i] = new int[n+1];
    }
    for (int i = 0; i<n; i++) {
        matrixA[i][i] = 0;
    }
    for (int i = 0; i<n; i++) {
        for (int j = 1; j<n ; j++) {
            if (i != j && i < j) {
                matrixA[i][j] = rand() % n + 1;
                matrixA[j][i] = matrixA[i][j];
            }
        }
    }
    
//    for (int i = 0; i<n; i++) {
//        for (int j = 0; j<n ; j++) {
//
//                matrixA[i][j] = m[i][j];
//            
//        }
//    }
    

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cout<<matrixA[i][j]<<" ";
        }
        cout<<endl;
    }
    Floyd(matrixA, n);
    return 0;
}
