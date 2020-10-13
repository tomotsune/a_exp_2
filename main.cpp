// exp_3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include"link.h"
using namespace std;
int main(int argc, char* argv[])
{
    Link<int> list{1,2,3,4};
    list.insert(3,9);
    cout<<list<<endl;
}
