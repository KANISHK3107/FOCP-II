#include<iostream>
#include<climits>
using namespace std;
int main(){
        int n;
        cout<<"Enter array size:";
        cin>>n;
        cout<<"Enter the array:"<<endl;
        int arr[n];

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        cout<<endl<<"Array in reverse:"<<endl;

        for(int i=n-1;i>0;i--){
            cout<<arr[i]<<endl;
        }

        int SS=INT_MAX;
        int S=INT_MAX;

        for(int i=0;i<n;i++)
        {
            if (arr[i]<SS && arr[i]>S)
                SS=arr[i];
            else if (arr[i]<S)
            {
                SS=S;
                S=arr[i];
            }
        }

        if (SS==INT_MAX)
        {
            cout<<endl<<"No second smallest element";
        }

        else 
        {
            cout<<endl<<"The second smallest element is: "<<SS;
        }

        int SL=INT_MIN;
        int L=INT_MIN;

        for(int i=0;i<n;i++)
        {
            if (arr[i]>SL && arr[i]<L)
                SL=arr[i];
            else if (arr[i]>S)
            {
                SL=L;
                L=arr[i];
            }
        }

        if (SL==INT_MAX)
        {
            cout<<endl<<" thier was no second largest element";
        }

        else 
        {
            cout<<endl<<"The second largest element is: "<<SL;
        }


    return 0;
}