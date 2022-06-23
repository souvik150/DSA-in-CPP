#include <iostream>
using namespace std;

void fun(int a[])
{
    cout << a[0] << " ";
}

int main()
{
    int w[] = {1, 2, 3, 4};
    fun(w + 1);
    cout << w[0] << endl;

    // int a = 10;
    // int *p = &a;
    // int **q = &p;
    // int b = 20;
    // *q = &b;
    // (*p)++;
    // cout << a << " " << b << endl;

    // int z = 100;
    // int *x = &z;
    // int **n = &x;
    // int m = (**n)++ + 4;
    // cout << z << " " << m << endl;

    int a = 100;
    int *p = &a;
    int **q = &p;
    int b = (**q)++;
    int *r = *q;
    (*r)++;
    cout << a << " " << b << endl;
}

// void square(int *p){
//  int a = 10;
//  p = &a;
//  *p = (*p) * (*p);
// }

// int main(){
//  int a = 10;
//  square(&a);
//  cout << a << endl;
// }