#include<iostream>
using namespace std;

void selection_sort(int arr[],int size)
{

    for(int i=0;i<size-1;i++)
    {
        int min=i;
        for(int j=i;j<size;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }

}


int main ()
{
    int arr[] = {29, 10, 14, 37, 14};
    int n = 5;


    selection_sort(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}