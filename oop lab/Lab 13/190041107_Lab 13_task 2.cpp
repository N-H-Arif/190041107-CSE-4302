#include <iostream>

int division(int x,int y)
{
    if(y==0)
    {
        std::cout<<"Cannot be Calculated"<<std::endl;
        return 0;
    }
    return (x/y);
}

namespace my_namespace
{
int division(int x, int y)
{
    if(y==0)
    {
        std::cout<<"Cannot be Calculated"<<std::endl;
        return 0;
    }
    return (x*y);
}
}

int main()
{
    std::cout << division(16,4)<< std::endl;
    std::cout << my_namespace::division(16,4) << std::endl;
    return 0;
}
