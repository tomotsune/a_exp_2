// exp_3.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
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
