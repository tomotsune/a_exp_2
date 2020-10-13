// exp_3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"link.h"
using namespace std;
int main(int argc, char* argv[])
{
    Link<int> list;
    list.insert(0,1);
    list.insert(1,2);
    list.insert(2,3);

    list.insert(3,4);
    cout<<list<<endl;
}
