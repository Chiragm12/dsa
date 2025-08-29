#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
using namespace std;

void explain_pairs(){
    pair<int, int> p={1,3};
    cout<<p.first<<" "<<p.second<<endl;
    pair<int, pair<int,int>> q={1,{2,3}};
    cout<<q.first<<" "<<q.second.first<<" "<<q.second.second<<endl;
    pair<int,int> arr[]={{1,2},{3,4},{5,6}};   
    cout<<arr[0].first<<" "<<arr[0].second<<endl;
    cout<<arr[1].first;
}

void explain_vector(){
    //vector is a dynamic array and can change in size
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int,int>> vec;

    vec.push_back({1,2});
    vec.emplace_back(3,4);

    vector<int>v2(5,1); //5 elements with value 1
    vector<int>v3(5);   //5 elements with value 0
    vector<int>v4(5,2,3); //5 elements with value 2 and 3 incremented by 1
    vector<int>v5(v2);   //copy of v2

    //iterators
    vector<int>::iterator it=v.begin(); //iterator to first element, points to the first element
    it++;
    cout<<*it<<endl; // this is the second element
    it=it+2;
    cout<<*it<<endl; // this is the fourth element
    cout<<v.end()-v.begin()<<endl; // this is the size of the vector
    vector<int>::iterator it2=v.end(); // points to the element after the last ele, do it2-- to go back to the last ele
    vector<int>::iterator it3=v.rend();
    vector<int>::iterator it4=v.rbegin();
    cout<<v.back()<<endl; // this is the last element
    //printing
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    for(auto it:v){
        cout<<it<<" ";
    }

    //{10,20,30,40}
    v.erase(v.begin()+2); //erase the element at index 2 {10,20,40}
    v.erase(v.begin()+1,v.begin()+3); //erase the elements from index 1 to index 3 {10,40}
    //insert
    vector<int>v6(2,100); //{100,100}
    v.insert(v6.begin(),300);//{300,100,100}
    v.insert(v.begin()+2,400);//{300,100,400,100}
    v.insert(v.begin()+1,2,1000);//{300,100,400,1000,1000}
    vector<int>copy(2,50);
    v.insert(v.begin()+1,copy.begin(),copy.end());//{300,100,400,1000,50,50}
    cout<<v.size()<<endl;//this is the size of the vector
    v.pop_back();//{300,100,400,1000,50}
    v.pop_back();//{300,100,400,1000}
    
    //sort
    sort(v.begin(),v.end());//{100,100,300,400}
    sort(v.begin(),v.end(),[](int a,int b){return a>b;});//{400,300,100,100}

    //find
    int a=*find(v.begin(),v.end(),100);
    if(a==100){
        cout<<"found"<<endl;
    }
    v.clear();
    cout<<v.empty()<<endl; //this is true
}

void explain_list(){
    list<int> ls;

    ls.push_back(1); //{1} pushes from back
    ls.push_front(2);//{2,1} pushes from front
    ls.push_front(3);//{3,2,1} pushes from front again
    ls.pop_front(); //{1}
    ls.pop_back();//{}
}

void explain_deque(){
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    dq.push_front(3);
    dq.pop_front();
    dq.pop_back();
}

void explain_stack(){
    stack<int> st;
    st.push(1); //{1}
    st.push(2);//{2,1}
    st.push(3);//{3,2,1}
    st.pop();//{2,1}
    st.pop();//{1}
    cout<<st.top();
    cout<<st.empty();
    cout<<st.size();
    stack<int> st2(2,100);
    st1.swap(st2);
}

void explain_queue(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.pop();
    cout<<q.front();
    cout<<q.empty();
    cout<<q.size();
    queue<int> q2(2,100);
    q1.swap(q2);
}

void explain_pq(){
    priority_queue<int> pq;
    //keeps the max element at the top
    pq.push(5); //{5}
    pq.push(2);//{5,2}
    pq.push(8);//{8,2,5}
    cout<<pq.top();//8
    
    //minimum heap
    priority_queue<int,vector<int>,greater<int>> pq2;
    pq2.push(2); //{2}
    pq2.push(5);//{2,5}
    pq2.push(8);//{2,5,8}
    cout<<pq2.top();//2
}

void explain_set(){
    //set is a collection of unique elements and sorted
    set<int> s;
    s.insert(1); //{1}
    s.insert(2);//{1,2}
    s.insert(3);//{1,2,3}
    //{1,2,3,4,5}
    auto it=s.find(2); //finds the element 2 in the set
    auto it=s.find(6); //returns end iterator
    s.erase(it); //erases the element 2 from the set, takes O(logn) time
    st.erase(2); //erases the element 2 from the set, takes O(n) time
    st.erase(it1,it2)// [begining,end)
}

void explain_multiset(){ 
    //multiset is a collection of unique elements and sorted, and stores duplicates
    multiset<int> ms;
    ms.insert(1); //{1}
    ms.insert(1);//{1,1}
    ms.erase(1)//deletes all the 1's
    ms.erase(ms.find(1));//deletes the element 1 from the set, takes O(logn) time

}

void explain_map(){ 
    map<int,int> m;
    // key,value is how its stored
    map<pair<int, int>,int>m2;
    mpp[1]=2;//inserts the element (1,2) into the map
    mpp.emplaec(1,2);//inserts the element (1,2) into the map
    mpp.insert({1,2});//inserts the element (1,2) into the map
    mpp[{1,2}]=3;//inserts the element (1,2) into the map
    for(auto it:mpp){
        cout<<it.first<<" "<<it.second<<endl; // prints 1 2 then 1 2 then 1 2
    }
    cout<<mpp[1]<<endl;//prints 2
    auto it=mpp.find(1);//finds the element (1,2) in the map
    cout<<*it<<endl//prints 1 2
}   

bool comp(pair<int,int> p1,pair<int,int> p2){
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;
    //they are same is 3d cond
    if(p1.first>p2.first) return true;
    return false;
}


void explain_extra(){
    sort(a,a+n); //this sorts the array a
    sort(v.begin(),v.end());
    sort(a+2,a+4); //you want only part of the array to be sorted
    sort(a,a+n,greater<int>()); //sorts the array a in descending order
    //sort it according to the user like->
    pair<int,int> a[]={{1,2},{2,1},{4,1}};
    //sort it according to the second ele, if second ele same then sort according to the first ele
    sort(a,a+n,comp);

    int num=7;
    
}