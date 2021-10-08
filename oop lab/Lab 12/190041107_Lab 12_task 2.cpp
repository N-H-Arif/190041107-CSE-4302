#include<bits/stdc++.h>
using namespace std;
template<class Type>
Type amax(Type* arr,int m,int n)
{
    Type arr2[m];
    copy(arr, arr + m, arr2);
    sort(arr2, arr2 + m);
    return arr2[m-n];
}

int main()
{
    int arr[11]={1,2,7,2,56,89,45,12,45,67,91};
   //float arr[11]={1.2,2.4,7.6,2.1,56.6,8.9,45.5,12.6,4.5,6.7,91.2};
   // double arr[11]= {1.0,2.7,7.9,2.4,5.6,8.9,4.5,1.2,4.5,6.7,91.2};
    cout<<amax(arr,11, 3);
}
