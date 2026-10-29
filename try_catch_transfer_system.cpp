#include<iostream>
#include<stdexcept>

void transferMoney(double balance,int amount)
{
    try
    {
        if(amount <0 || balance<0) throw std::runtime_error("Amount or Balance are with negative sign!\n");
        
        else if(amount >balance)throw std::runtime_error("Amount cant be more than Balance!\n");

    }
    catch(std::runtime_error & e)
    {
        std::cerr<<"\nExceprion in function is Caught!"<< e.what()<<"\n";
        throw;
    }

    balance=balance+amount;
    std::cout<<"Balance:"<<balance<<std::endl;
}


int main()
{
    try
    {
        transferMoney(100,120);
    }
    catch(std::runtime_error&e)
    {
        std::cerr<<"Exception in Main is caught!"<<e.what();
    }
    
    return 0;
}