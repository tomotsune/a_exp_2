// exp_3.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
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
    Link<int> list;
    list.insertHead(6);
    list.insertHead(4);
    list.insertHead(3);
    list.insertHead(2);
    list.insertHead(1);

    //1. test LinkPrint()
    list.print();

    //2. ���ͷָ��.
    cout<<list.getHead()<<endl;

    //3. ��pos=4��λ�ò�����Ϊ5��ֵ.
    list.insert(5,4);
    list.print();

    //4. ɾ�������е�һ��ֵΪ6�Ľ��.
    list.remove(6);
    list.print();

    //5. ��������һ������.
    Link<int> list_2;;
    list_2.insertHead(7);
    list_2.insertHead(6);
    list.connect(list_2);
    list.print();
    return 0;


}
void dataStructTest(){
    // ��Ŀ1 ˳�����
    Link<int> list;
    list.insertHead(5);
    list.insertHead(3);
    list.insertHead(2);
    list.insertHead(1);
    cout<<"list: ";
    list.print();
    list.addByOrdered(4);
    cout<< "after adding: ";
    list.print();

    //��Ŀ2 ����
    list.reverse();
    cout<<"after reversing: ";
    list.print();

    //��Ŀ3 ����
    Link<int> list_2;
    list_2.insertHead(8);
    list_2.insertHead(7);
    list_2.insertHead(6);
    cout<<"list_2: ";
    list_2.print();
    list.connect(list_2);
    cout<<"list + list_2: ";
    list.print();
    list.sort();
    cout<< "after sorting: ";
    list.print();
    list.reverse();
    cout<< "after reversing: ";
    list.print();
}
void test_1(){
    Link<Empoyee> list;
    Empoyee no1{ "no1",001 }, no2{ "no2",002 }, no3{"no3",003}, no4{ "no4",004 };

    //���빦�ܲ���.
    cout << "Insert test:" << endl;
    list.insertHead(no1);
    list.insert(no2, 1);
    list.insert(no3, 2);
    list.insert(no4, 3);
    list.print();

    //���Է�����.
    cout << "reserve test:" << endl;
    list.reverse();
    cout << "reversed link is:" << endl;
    list.print();

    //����ɾ������.
    cout << "remove test:" << endl;
    cout << "the longth of link is:" << list.getLength()<<endl;
    list.remove(no4);
    list.print();
    cout << "the length of link is:" << list.getLength()<< endl;
    list.remove(no4);
    list.print();

    //List�����
}
