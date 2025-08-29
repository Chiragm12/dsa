#include<iostream>
using namespace std;

// void print(){
//     cout<<"hello world"<<endl;
// }
// int main(){
//     print();
// }

void print(string n){
    cout<<"Hello "<<n;
}

int min1(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

int dosomething(int &a){
    cout<<a<<endl;
    a=a+10;
    return a;
}

int main(){
    // string s;
    // cin>>s;
    // print(s);

    // int num1,num2;
    // cin>>num1>>num2;
    // int min= min1(num1,num2);
    // cout<< "min mumber is "<<min<<endl;

    //passing by reference
    int a=10;
    dosomething(a);
    cout<<a<<endl;


}