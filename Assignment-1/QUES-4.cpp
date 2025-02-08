#include<iostream>
using namespace std;
int main(){
        int n;
        cout<<"Enter the order of matrix:";
        cin>>n;
        int arr[n][n];
        int a=0,i,p=n-1,b=n-1,q=0,num=1;
        while(num<=(n*n)){
            for(i=q;i<=p;i++){
                arr[a][i]=num;
                num++;
            }
            a++;

            for(i=a;i<=b;i++){
                arr[i][p]=num;
                num++;
            }
            p--;

            for(i=p;i>=q;i--){
                arr[b][i]=num;
                num++;
            }
            b--;

            for(i=b;i>=a;i--){
                arr[i][q]=num;
                num++;
            }
            q++;
        }
        cout<<"The spiral pattern array:"<<endl;
        for(i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<" "<<arr[i][j];
            }
            cout<<endl;
        }

    return 0;
}