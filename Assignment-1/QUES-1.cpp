#include<iostream>
using namespace std;
int main(){
  int n;
  cout<<"Enter the number:";
  cin>>n;
    int ans=0;
  for(int i=2;i<n;i++){
        if(n%i==0){
            ans++;
            break;
        }
  }
    if(ans==0){
    cout<<"the number is a prime number"<<endl;
    cout<<"the next greater prime number is:"<<endl;
    n++;
    int gp=1;
    while(gp!=0){
        gp=0;
        int i;
    for( i=2;i<n;i++){
        
        if(n%i==0){
            gp=1;
            break;
        }
    }
        if(gp==0){
            cout<<i<<endl;
            break;
        }

    
    n++;
    }
    }
    else{
    cout<<"the number is not a prime number"<<endl;
    cout<<"all its factors are as follow"<<endl;
    for(int i=1;i<n;i++){
        if(n%i==0){
        cout<<i<<endl;
        }
    }

    }

  

    return 0;
}