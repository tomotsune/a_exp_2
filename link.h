#pragma once
#include<iostream>
using namespace std;
template<typename T>
struct Node
{
	T val;
	Node* next;

    Node()=default;

    explicit Node(T x) :val(x), next(nullptr) {}

    bool operator<(const Node &rhs) const {
        return val<rhs.val;
    }

    Node(const Node &rhs) {
        val = rhs.val;
    }
    void operator=(const Node &rhs) {
        val = rhs.val;
    }
};
template<typename T>
class Link
{
private:
	Node<T>* first;
	Node<T>* head;

	int length{};
public:
	Link();
	Link(const Link& l);
	void insertHead(T var);
	void insert(T val, const int& pos);
	void addByOrdered(const T& val);
	void remove(const T& val);
	int getLength();
	void reverse();
	int find(T val);
	void print();
	void sort();
	void connect(const Link& l);

    Node<T> *getHead() const;

    ~Link();
};

template<typename T>
inline Link<T>::Link()
{
	head =new Node<T>{};
	first=head->next;
	length == 0;
}

template<typename T>
inline void Link<T>::insertHead(T var)
{
	insert(var, 0);
}

template<typename T>
inline void Link<T>::insert(T val, const int& pos)
{
	if (pos < 0) {
		cout << "pos must be greater than zero" << endl;
		return;
	}
	int index{ 1 };//walking stick of temp
	Node<T>* temp{ first };
	auto* node = new Node<T>{ val };
	if (pos == 0) {
		node->next = temp;
		first = node;
		length++;
		return;
	}
	//将temp置于要插入的节点之前.
	while (temp != nullptr && index < pos) {
		temp = temp->next;
		++index;
	}
	//插入位置不当
	if (temp == nullptr) {
		cout << "Insert failed!" << endl;
	}
	//交接后续结点.
	node->next = temp->next;
	temp->next = node;
	++length;
}

template<typename T>
inline void Link<T>::remove(const T& val)
{
	int pos = find(val);
	if (-1 == pos) {
		cout << "delete failed";
		return;
	}
	if (0==pos) {
		first = first->next;
		--length;
		return;
	}
	int index{ 0 };
	Node<T>* temp = first;
	while (++index < pos) {
		temp = temp->next;
	}
	//temp停在了将要删除的element之前.
	//为了防止temp->next->next空指针异常.
	Node<T>* removeNode{ temp->next };

	temp->next = temp->next->next;

	delete removeNode;
	--length;
}

template<typename T>
inline int Link<T>::getLength()
{
	return length;
}

template<typename T>
inline void Link<T>::reverse()
{
	if (first == nullptr) {
		return;
	}
	Node<T>* curNode{ first }, * nextNode{ first->next }, * temp;
	//保存3号位置结点,
	// 把1号位置结点放到3号职位,
	// 2号移到1号,
	// 将被保存的原三号位置结点放到2号位置.
	while (nextNode!=nullptr)
	{
		temp = nextNode->next;
		nextNode->next = curNode;
		curNode = nextNode;
		nextNode = temp;
	}
	first->next = nullptr ;
	first = curNode;
}

template<typename T>
inline int Link<T>::find(T val)
{
	Node<T>* temp = first;
	int index{};
	while (temp != nullptr) {
		if (temp->val == val) {
			return index;
		}
		temp = temp->next;
		++index;
	}
	return -1;
}

template<typename T>
inline void Link<T>::print()
{
	if (first == nullptr) {
		cout << "List is empty" << endl;
		return;
	}
	Node<T>* temp{ first };
	while (temp!=nullptr)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<typename T>
inline Link<T>::~Link()
{
	Node<T>* temp;
	for (int  i = 0; i < length+1; i++)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

template<typename T>
void Link<T>::sort() {
    if (length == 1)return;
    for (auto p = first; p->next != nullptr; p = p->next) {
        for (auto q = p->next; q != nullptr; q = q->next) {
            if (*p < *q) {
                auto temp{*q};
                *q = *p;
                *p = temp;
            }
        }
    }
}

template<typename T>
void Link<T>::connect(const Link& l) {
    if(first== nullptr)return;
    auto temp{first};
    while(temp->next!= nullptr){
        temp=temp->next;
    }
    temp->next=l.first;
}

template<typename T>
void Link<T>::addByOrdered(const T& val) {
    auto temp{first};
    auto index{0};
    while(temp!= nullptr){
        if(temp->val >= val)break;
        temp=temp->next;
        ++index;
    }
    insert(val,index);
}

template<typename T>
Link<T>::Link(const Link &l):Link() {
    auto temp{l.head};
    for (int i = 0; i < length; ++i) {
        insertHead(temp->val);
        temp=temp->next;
    }
}

template<typename T>
Node<T> *Link<T>::getHead() const {
    return head;
}

