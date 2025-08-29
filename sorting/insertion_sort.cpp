#include <iostream>
#include <vector>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr={29,10,14,37,13,5,8,3,9,25};
    int sizee=arr.size();
    for(int i=0;i<sizee;i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){ //change the greter than symbol, to print in either assending or desending order     
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
    for(auto it:arr){
        cout<<it<<" ";
    }
}