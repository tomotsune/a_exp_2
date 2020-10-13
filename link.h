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
    Node<ElemType> *head;
public:

    Link();

    Link(const std::initializer_list<ElemType> &val);

    virtual ~Link();

    Node<ElemType> *getElem(int pos);

    void insert(int pos, const ElemType &vals);

    void remove(int pos);

    void insertNextNode(Node<ElemType> *n, const ElemType &val);

    Node<ElemType> *LocateElem(const ElemType &val) const;


    [[nodiscard]] int length() const;

    friend ostream &operator<<(ostream &os, const Link &link) {
        auto temp{link.head->next};
        while (nullptr != temp) {
            os << temp->val << " ";
            temp = temp->next;
        }
        return os;
    }
};

//constructs.
template<typename ElemType>
Link<ElemType>::Link():head(new Node<ElemType>{}) {
    head->next = nullptr;
}

//destruct.
template<typename ElemType>
Link<ElemType>::~Link() {
    while (head != nullptr) {
        auto temp{head};
        head = head->next;
        delete temp;
    }
}

//Find element in bit order
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

//Post-insertion operation of specified node
template<typename ElemType>
void Link<ElemType>::insertNextNode(Node<ElemType> *n, const ElemType &val) {
    if (n == nullptr)
        throw "error: insertNextNode(Node, val): null pointer!";
    auto node{new Node<ElemType>{val}};
    node->next = n->next;
    n->next = node;
}

//Insert an element in bit order
template<typename ElemType>
void Link<ElemType>::insert(int pos, const ElemType &val) {
    ++pos; //根据获取的是位序还是下表决定是否添加此步骤.
    try {
        if (pos < 1)
            throw "error: inser(int, ElmeType): underflow";
        auto temp{getElem(pos - 1)};
        insertNextNode(temp, val);
    } catch (const char *msg) {
        cerr << msg << endl;
    }
}

template<typename ElemType>
void Link<ElemType>::remove(int pos) {
    ++pos;
    try {
        if (pos < 1)
            throw "remove(int pos): underflow";
        auto temp{getElem(pos - 1)};
        if (temp == nullptr || temp->next == nullptr)
            throw "error: remove(int pos): overflow";
        auto removeNode{temp->next};
        temp->next = removeNode->next;
        delete removeNode;
    } catch (const char *msg) {
        cerr << msg << endl;
    }
}

//Find by value
template<typename ElemType>
Node<ElemType> *Link<ElemType>::LocateElem(const ElemType &val) const {
    auto temp{head->next};
    while (temp != nullptr && temp->val != val)
        temp = temp->next;
    return temp;
}

template<typename ElemType>
int Link<ElemType>::length() const {
    int len{};
    auto temp{head};
    while (temp->next != nullptr) {
        temp = temp - next;
        ++len;
    }
    return len;
}

template<typename ElemType>
Link<ElemType>::Link(const initializer_list<ElemType> &vals):Link() {
    auto left{head};
    for (auto const &val  : vals) {
        auto right{new Node<ElemType>{val}};
        left->next = right;
        left = right;
    }
    left = nullptr;
}



