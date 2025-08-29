#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int print_name(string s, int n){
	if(n==0){
		return 0;
	}
	else{
        cout<<s<<endl;
        return print_name(s,n-1);
    }
}
int main(){
    string s;
    cin>>s;
    cout<<"enter the number of times you want to print the name"<<endl;
    int n;
    cin>>n;
    print_name(s,n);
    return 0;
}

