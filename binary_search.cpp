#include<iostream>

void binary_search(int arr[],int data,int maxSize)
{
int lower=0;
int upper=maxSize-1;
bool found=false;
int pos=-1;

while(lower<=upper && found==false)
{
    int mid=(lower+upper)/2;
    if(arr[mid]==data) 
    {
        found=true;
        pos=mid;
        break;
    }
    else{
        if(data<=arr[mid]) upper = mid - 1;
        else lower = mid + 1;
    }
    
}

if(found==true)std::cout<<"Succesfully found in postition "<<pos<<std::endl;
else std::cout<<"Not Found\n";
}


int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    binary_search(arr,4,10);

    return 0;
}