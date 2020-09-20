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


    return 0;
}
