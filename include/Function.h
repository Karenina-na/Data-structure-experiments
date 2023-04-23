//
// Created by 15399 on 2023/4/11.
//

#ifndef DATA_STRUCTURE_EXPERIMENTS_FUNCTION_H
#define DATA_STRUCTURE_EXPERIMENTS_FUNCTION_H
#include <iostream>
#include <math.h>
# define MAXSIZE 1000
#endif //DATA_STRUCTURE_EXPERIMENTS_FUNCTION_H

void calculatePI();
void merge();
void transpose();
void add();

struct LinkNode {
    int data;
    LinkNode *prior;    // 前驱
    LinkNode *next;    // 后继
};

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

struct triple {
    int row;
    int col;
    int value;
};

class SparseMatrix {
public:
    int row;
    int col;
    int num;
    triple data[MAXSIZE];
    SparseMatrix(int row, int col):row(row), col(col), num(0) {}
    ~SparseMatrix() {}
    void append(int row, int col, int value) {
        //添加
        data[num].row = row;
        data[num].col = col;
        data[num].value = value;
        num++;
    }
    void print() {
        //打印
        for (int i = 0; i < num; i++) {
            std::cout << data[i].row << " " << data[i].col << " " << data[i].value << std::endl;
        }
    }

    void transpose(){
        //转置
        for (int i = 0; i < num; i++) {
            int temp = data[i].row;
            data[i].row = data[i].col;
            data[i].col = temp;
        }
    }
    SparseMatrix* add(SparseMatrix &b){
        //加法
        SparseMatrix *c = new SparseMatrix(row, col);
        //双指针加法
        int i=0,j=0;
        while (i<num && j<b.num) {
            if (data[i].row<b.data[j].row || (data[i].row==b.data[j].row && data[i].col<b.data[j].col)) {
                c->append(data[i].row, data[i].col, data[i].value);
                i++;
            }
            else if (data[i].row>b.data[j].row || (data[i].row==b.data[j].row && data[i].col>b.data[j].col)) {
                c->append(b.data[j].row, b.data[j].col, b.data[j].value);
                j++;
            }
            else {
                if (data[i].value+b.data[j].value!=0) {
                    c->append(data[i].row, data[i].col, data[i].value+b.data[j].value);
                }
                i++;
                j++;
            }
        }
        //this剩余部分
        while (i<num) {
            c->append(data[i].row, data[i].col, data[i].value);
            i++;
        }
        //b剩余部分
        while (j<b.num) {
            c->append(b.data[j].row, b.data[j].col, b.data[j].value);
            j++;
        }
        return c;
    }
private:
    void sort(){
        //排序
        for (int i=0;i<num;i++){
            for (int j=i+1;j<num;j++){
                if (data[i].row>data[j].row){
                    triple temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
                else if (data[i].row==data[j].row && data[i].col>data[j].col) {
                    triple temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
    }
};