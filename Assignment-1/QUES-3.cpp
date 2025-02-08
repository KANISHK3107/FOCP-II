#include<iostream>
#include<string>
using namespace std;
int main(){
    
    string str;
    cout<<"Enter the string:";
    cin>>str;
    int l=str.length(),flag=0;
    for(int i=0;i<l;i++){
        str[i]=tolower(str[i]);
    }
    if(l==1){
        cout<<"The word is a palindrome";
    }
    else{
    int i=0,j=str[l-1];
    while(i<j){
    if(str[i]==str[j]){
        i++;
        j--;
        continue;
    }
    else{
        flag++;
        break;
    }
   
    }
     if(flag==0){
        cout<<"the work is a palindrome";
    }
    else{
        cout<<"the word is a not palindrome"<<endl;
    }
    }
    
    cout<<"Frequency of each letter:"<<endl;
    for(int i=97;i<=122;i++){
        char S=i;
        flag=0;
        for(int j=0;j<l;j++){
            if(S==str[j])
            flag++;
        }
        if(flag!=0)
        cout<<S<<"->"<<flag<<endl;
    }
    for(int i=0;i<l;i++){
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
            str[i]='*';
        }
    }
    cout<<"All vowel replaced by '*':\t"<<str;

    return 0;
}