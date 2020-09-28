// exp_3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"link.h"
using namespace std;
struct Empoyee {
    string name;
    int id;
    friend std::ostream& operator<<(std::ostream& os, const Empoyee& e) {
        os << "name: " << e.name<<","<<"id: "<<e.id;
        return os;
    };
    bool operator==(const Empoyee& e) {
        return (name == e.name && id == e.id);
    }
};
int main(int argc, char* argv[])
{
    // 题目1 顺序插入
    Link<int> list;
    list.insertHead(5);
    list.insertHead(3);
    list.insertHead(2);
    list.insertHead(1);
    cout<<"list: ";
    list.print();
    list.add(4);
    cout<< "after adding: ";
    list.print();

    //题目2 倒置
    list.reverse();
    cout<<"after reversing: ";
    list.print();

    //题目3 链接
    Link<int> list_2;
    list_2.insertHead(8);
    list_2.insertHead(7);
    list_2.insertHead(6);
    cout<<"list_2: ";
    list_2.print();
    list.join(list_2);
    cout<<"list + list_2: ";
    list.print();
    list.sort();
    cout<< "after sorting: ";
    list.print();
    list.reverse();
    cout<< "after reversing: ";
    list.print();
    return 0;
}
void test_1(){
    Link<Empoyee> list;
    Empoyee no1{ "no1",001 }, no2{ "no2",002 }, no3{"no3",003}, no4{ "no4",004 };

    //插入功能测试.
    cout << "Insert test:" << endl;
    list.insertHead(no1);
    list.insert(no2, 1);
    list.insert(no3, 2);
    list.insert(no4, 3);
    list.print();

    //测试反序功能.
    cout << "reserve test:" << endl;
    list.reverse();
    cout << "reversed link is:" << endl;
    list.print();

    //测试删除功能.
    cout << "remove test:" << endl;
    cout << "the longth of link is:" << list.getLength()<<endl;
    list.remove(no4);
    list.print();
    cout << "the length of link is:" << list.getLength()<< endl;
    list.remove(no4);
    list.print();

    //List类测试
}
