#include<iostream>
using namespace std;
// namespace std;

void swap(float* p1,float*p2){
    float t;
    t=*p1;
    *p1=*p2;
    *p2=t;

}
void sub( char b[]){
    b[]= "world";
}

int  main(){
    float a,b;
    // cin>>a>>b;
    float *p1 =&a;
    float *p2 =&b;
    swap(p1,p2);
    char str[10] ="hello";
    sub(str);
    // cout<<a<<b<<endl;
    cout<<str<<endl;
    return 0;
}