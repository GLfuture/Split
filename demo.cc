#include"split.hpp"
#include<iostream>
using namespace std;
int main()
{
    Split base("hello  world  !  select  *  \r\n");
    base.Spilt_With_Str("\r\n");
    vector<string_view> res=base.Get_Result();
    for(auto&v:res) cout<<v<<endl;
    return 0;
}