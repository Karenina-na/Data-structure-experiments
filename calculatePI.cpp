//
// Created by 15399 on 2023/4/11.
//
#include "Function.h"
// 链表节点
struct LinkNode {
    int data;
    LinkNode *prior;    // 前驱
    LinkNode *next;    // 后继
};

// 双向链表
class LinkList {
public:
    LinkList() {    // 构造函数
        this->head = nullptr;
        this->tail = nullptr;
    }

    LinkList(int data) {
        LinkNode *p = new LinkNode;
        p->data = data;
        p->next = nullptr;
        p->prior = nullptr;
        this->head = p;
        this->tail = p;
    }

    ~LinkList() {  // 析构函数
        LinkNode *p = head;
        while (p != nullptr) {
            LinkNode *q = p;
            p = p->next;
            delete q;
        }
        this->head = nullptr;
        this->tail = nullptr;
    }

    void append(int data) { // 增加
        LinkNode *p = new LinkNode;
        p->next = nullptr;
        p->prior = nullptr;
        p->data = data;
        if (this->is_empty()) {
            this->head = p;
            this->tail = p;
            return;
        }
        this->tail->next = p;
        p->prior = this->tail;
        this->tail = p;
    }

    void insert(int index, int data) { // 插入
        if (index < 0 || index > this->length() || this->is_empty()) {  // 判断是否越界
            return;
        }
        LinkNode *p = this->head;
        int i = 0;
        while (p != nullptr) {
            if (i == index) {
                LinkNode *q = new LinkNode;
                q->next = nullptr;
                q->prior = nullptr;
                q->data = data;
                if (p->prior == nullptr) {   // 插入头节点
                    q->next = this->head;
                    this->head->prior = q;
                    this->head = q;
                    return;
                }
                if (p->next == nullptr) {    // 插入尾节点
                    q->prior = this->tail;
                    this->tail->next = q;
                    this->tail = q;
                    return;
                }
                p->next = q;    // 插入中间节点
                p->prior = q->prior;
                q->prior->next = p;
                q->prior = p;
                return;
            }
            i++;
            p = p->next;
        }
    }
    void update(int index, int data) {    // 更新
        if (index < 0 || index >= this->length() || this->is_empty()) {  // 判断是否越界
            return;
        }
        LinkNode *p = this->head;
        int i = 0;
        while (p != nullptr) {
            if (i == index) {
                p->data = data;
                return;
            }
            i++;
            p = p->next;
        }
    }
    void remove(int index) {  // 删除
        if (index < 0 || index >= this->length() || this->is_empty()) {  // 判断是否越界
            return;
        }
        LinkNode *p = this->head;
        int i = 0;
        while (p != nullptr) {
            if (i == index) {
                if (p->prior == nullptr) {   // 删除头节点
                    this->head = p->next;
                    p->next->prior = nullptr;
                    delete p;
                    return;
                }
                if (p->next == nullptr) {    // 删除尾节点
                    this->tail = p->prior;
                    p->prior->next = nullptr;
                    delete p;
                    return;
                }
                p->prior->next = p->next;   // 删除中间节点
                p->next->prior = p->prior;
                delete p;
                return;
            }
            i++;
            p = p->next;
        }
    }

    int length() {   // 长度
        int len = 0;
        LinkNode *p = this->head;
        while (p != nullptr) {
            len++;
            p = p->next;
        }
        return len;
    }

    bool is_empty() {    // 判空
        if (this->head == nullptr && this->tail == nullptr) {
            return true;
        }
        return false;
    }

    void print(int n) { // 输出
        LinkNode *p = this->head;
        std::cout << p->data << ".";
        p = p->next;
        int i = 0;
        while (p != nullptr && i < n) {
            std::cout << p->data;
            p = p->next;
            i++;
        }
    }

    LinkNode *getHead() {
        return this->head;
    }

    LinkNode *getTail() {
        return this->tail;
    }

private:
    LinkNode *head; // 头指针
    LinkNode *tail; // 尾指针
};

// 高精度计算pi
void calculatePI(){
    LinkList *result = new LinkList(2);
    LinkList *temp = new LinkList(2);
    int n;
    std::cin >> n;
    // 泰勒展开式 p(n+1) = p(n) * n/(2n+1), arcsin(1) = sum(p(n)) = pi/2
    for (int i = 0; i < 1000; i++) {
        result->append(0);
        temp->append(0);
    }
    int ret;
    // 递归运算
    for (int i = 1; i < 10000; i++) {
        ret = 0;
        int bottom = 2 * i + 1;
        int top = i;
        // 乘法 temp = temp * n
        LinkNode *p = temp->getTail();
        while (p != nullptr){
            int data = (p->data * top) + ret;
            p->data = data % 10;
            ret = data / 10;
            p = p->prior;
        }
        ret = 0;
        // 除法 temp / (2n+1)
        p = temp->getHead();
        while (p != nullptr){
            int data = ret * 10 + p->data;
            p->data = data / bottom;
            ret = data % bottom;
            p = p->next;
        }
        ret = 0;
        // 加法 result = result + temp
        p = result->getTail();
        LinkNode *q = temp->getTail();
        while (p != nullptr && q != nullptr){
            int data = p->data + q->data + ret;
            p->data = data % 10;
            ret = data / 10;
            p = p->prior;
            q = q->prior;
        }
    }
    result->print(n);
    delete result;
    delete temp;
}
