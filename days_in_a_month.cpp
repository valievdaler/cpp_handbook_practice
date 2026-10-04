#include<iostream>
int main()
{
    int year,month;
    int days_1[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days_2[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::cin>>month>>year;
    for(int i=0;i<=11;i++)
    {
        if(month==i+1)
        {
             if(year%400==0 )
        {
            std::cout<<days_2[i];
        }
        else if(year%100==0 )
        {
           std::cout<<days_1[i]; 
        }
        else if(year%4==0 )
        {
            std::cout<<days_2[i];
        }
        else
        {
            std::cout<<days_1[i];
        }
        }
       
        //here we check at first the month, if we are satisfied then we go through the years , whether its leap or not,
        //and then we console it out
    }
    

    return 0;

}