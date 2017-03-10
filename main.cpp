#include <iostream>
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
const int N=4;

struct vektor {
    int x;
    int y;
};

//заполнение значений координат ввершин четырехугольника
void filling(vektor A[])
{
    for (int i=0; i<N; ++i)
    {
        printf ("\n Coordinates of the vertex %d x y \n",i);
        scanf ("%d %d",&A[i].x,&A[i].y);
        system("cls");
    }

}
// подсчет псевдоскалярного произведения
int Bridle(vektor B[], vektor C[], int i, int j)
{
    int a;
    if (j<=N-1) a=((B[i].x-C[j].x)*(C[j+1].y-C[j].y)-(B[i].y-C[j].y)*(C[j+1].x-C[j].x));
        else a=((B[i].x-C[j].x)*(C[0].y-C[j].y)-(B[i].y-C[j].y)*(C[0].x-C[j].x));
    return a;
}
//проверка расположения одного прямоугольника относительно другого
int test(vektor A[], vektor B[])
{
    int k, minone=0, zero=0, one=0,minone1=0, zero1=0, one1=0;
    for (int i=0; i<N; ++i)
    {
        minone=0;
        zero=0;
        one=0;
        for (int j=0; j<N; ++j)
        {
            if (Bridle(A,B,i,j)<0) minone++;
            else if (Bridle(A,B,i,j)>0) one++;
                 else zero++;
        }
        if (((zero==1)||(zero==2))&&((minone==N-zero)||(one==N-zero))) zero1++;
        else if ((zero==0)&&((minone==N)||(one==N))) one1++;
             else minone1++;
    }

    if (zero1==N) k=3;
    else if (minone1==N) k=0;
         else if ((one1>0)&&(minone1==0)) k=2;
              else k=1;
//  0 не пересекаются
//  1 пересекаются
//  2 второй лежит в первом
//  3 совпадают
return k;
}

int main()
{
    vektor Quadrilateral1[N], Quadrilateral2[N];
    filling(Quadrilateral1);
    filling(Quadrilateral2);
    if (test(Quadrilateral1,Quadrilateral2)==3) printf("match up");
    if (test(Quadrilateral1,Quadrilateral2)==2) printf("The second lies in the first");
    if (test(Quadrilateral1,Quadrilateral2)==1) printf("Intersect");
    if ((test(Quadrilateral1,Quadrilateral2)==0)&&(test(Quadrilateral2,Quadrilateral1)==2)) printf("The first lies in the second");
    else printf("Do not intersect");
system("pause");
return 1;
}
