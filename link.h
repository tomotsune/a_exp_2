#pragma once

#include<iostream>

using namespace std;

template<typename ElemType>
struct Node {
    ElemType val;
    Node *next;

    Node() = default;

    explicit Node(ElemType x) : val(x), next(nullptr) {}

    Node(const Node &rhs) { val = rhs.val; }

    bool operator<(const Node &rhs) const { return val < rhs.val; }

    void operator=(const Node &rhs) { val = rhs.val; }
};

template<typename ElemType>
class Link {
private:
    Node<ElemType> *first;
    Node<ElemType> *head;

    int length{};
public:

    Link();

    Node<ElemType> *getElem(int pos);

    void insert(int pos, ElemType val);

    friend ostream &operator<<(ostream &os, const Link &link) {
        auto temp{link.head->next};
        while (nullptr != temp) {
            os << temp->val<<" ";
            temp=temp->next;
        }
        return os;
    }
};

template<typename ElemType>
Node<ElemType> *Link<ElemType>::getElem(int pos) {
    if (pos < 0)
        throw "the pos is out of range";
    auto temp{head};
    int index{0};
    while (temp != nullptr && index < pos) {
        temp = temp->next;
        ++index;
    }
    if (temp == nullptr)
        throw "the pos is out of range";
    return temp;
}

template<typename ElemType>
void Link<ElemType>::insert(int pos, ElemType val) {
    ++pos; //根据获取的是位序还是下表决定是否添加此步骤.
    if (pos < 1)
        throw "the pos is out of range";
    try {
        auto temp{getElem(pos - 1)};
        auto node{new Node<ElemType>(val)};
        node->next = temp->next;
        temp->next = node;
    } catch (const char *msg) {
        cerr << msg << endl;
    }
}

template<typename ElemType>
Link<ElemType>::Link():head(new Node<ElemType>{}) {
    head->next= nullptr;
}
