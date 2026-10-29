#include <iostream>
#include <stdexcept>

void devisir(int a, int b)
{
    

    try
    {
        if (b == 0)
        {
            throw std::runtime_error("Cannot be devided by 0 , sorry(");
        }
        std::cout<<a/b<<std::endl;
    }
    catch(std::runtime_error& e)
    {
        std::cerr<<"An Exception was caught in Catch block."<<e.what()<<std::endl;
    }
    std::cout << "Program works well!" << std::endl;
}

int main()
{
    devisir(10,0);
    return 0;
}