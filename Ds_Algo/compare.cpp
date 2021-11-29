#include<iostream>
 using namespace std;
 
struct s
{
    int a;
    int b;
    bool operator == (const s &rhs);
};
 
bool s::operator == (const s &rhs)
{
    return ((a == rhs.a) && (b == rhs.b));
}
 
int main()
{
    struct s s1, s2;
    s1.a = 1;
    s1.b = 2;
    s2.a = 1;
    s2.b = 2;
    if (s1 == s2)
        cout << "两个结构体相等" << endl;
    else
        cout << "两个结构体不相等" << endl;
    return 0;
}