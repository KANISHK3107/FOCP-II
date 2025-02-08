#include<iostream>
using namespace std;
int main(){
        int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<" "<<arr[i][j];
            }
            cout<<endl;
        }

        cout<<"the matric after rotating 90 degree clockwise:"<<endl;
        int a,b;

        for(int i=0;i<3;i++){
            if(i==0)
            a=2,b=0;
            else if(i==1)
            a=1,b=1;
            else if(i==2)
            a=0,b=2;
            for(int j=0;j<3;j++){
                cout<<" "<<arr[i+a][j+b];
                a--;
                b--;                
            }
            cout<<endl;
        }

    return 0;
}