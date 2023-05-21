//
// Created by 15399 on 2023/4/11.
//

#ifndef DATA_STRUCTURE_EXPERIMENTS_FUNCTION_H
#define DATA_STRUCTURE_EXPERIMENTS_FUNCTION_H
//引入所有头文件
//#include <bits/stdc++.h>
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#endif //DATA_STRUCTURE_EXPERIMENTS_FUNCTION_H

void calculatePI();
void merge();
void transpose();
void addTriple();
void addCrossList();
void multipleCrossList();
void huffman();

//双向链表
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

//三元组稀疏矩阵
struct triple {
    int row;
    int col;
    int value;
};

class SparseMatrixTriple {
public:
    int row;
    int col;
    int num;
    triple data[1000];
    SparseMatrixTriple(int row, int col): row(row), col(col), num(0) {}
    ~SparseMatrixTriple() {}
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
    SparseMatrixTriple* add(SparseMatrixTriple &b){
        //加法
        SparseMatrixTriple *c = new SparseMatrixTriple(row, col);
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

//十字链表稀疏矩阵
struct CrossListNode{
    int row;
    int col;
    int data;
    CrossListNode * rnext;
    CrossListNode * cnext;
};

class SparseMatrixCrossList{
public:
    int rowNum;
    int colNum;
    CrossListNode * rhead[10000]={nullptr};
    CrossListNode * chead[10000]={nullptr};
    SparseMatrixCrossList(int row, int col): rowNum(row), colNum(col){}
    ~SparseMatrixCrossList(){
        //行删除
        for (int i = 0; i < rowNum; ++i) {
            CrossListNode * rnext = this->rhead[i];
            while (rnext!= nullptr){
                CrossListNode * temp = rnext;
                rnext = rnext->rnext;
                delete temp;
            }
        }
    }

    void append(int row,int col,int data){
        CrossListNode * n = new CrossListNode();
        n->row = row;
        n->col = col;
        n->data = data;
        n->cnext = nullptr;
        n->rnext = nullptr;
        //列处理
        CrossListNode *cnext = this->chead[col];
        if (cnext == nullptr){
            this->chead[col] = n;
        }else{
            while (cnext->cnext != nullptr && cnext->cnext->row < n->row){
                cnext = cnext->cnext;
            }
            n->cnext = cnext->cnext;
            cnext->cnext = n;
        }
        //行处理
        CrossListNode *rnext = this->rhead[row];
        if (rnext == nullptr){
            this->rhead[row] = n;
        }else{
            while (rnext->rnext != nullptr && rnext->rnext->col < n->col){
                rnext = rnext->rnext;
            }
            n->rnext = rnext->rnext;
            rnext->rnext = n;
        }
    }
    SparseMatrixCrossList * add(SparseMatrixCrossList &b){
        SparseMatrixCrossList * c = new SparseMatrixCrossList(this->rowNum, this->colNum);
        // 列指针遍历
        for (int i = 0; i < colNum; i++){
            CrossListNode * a_cnext = this->chead[i];
            CrossListNode * b_cnext = b.chead[i];
            while (a_cnext != nullptr && b_cnext != nullptr){
                // 相同行列
                if (a_cnext->row == b_cnext->row){
                    c->append(a_cnext->row, a_cnext->col, a_cnext->data + b_cnext->data);
                    a_cnext = a_cnext->cnext;
                    b_cnext = b_cnext->cnext;
                }
                    // a行号小于b行号
                else if (a_cnext->row < b_cnext->row){
                    c->append(a_cnext->row, a_cnext->col, a_cnext->data);
                    a_cnext = a_cnext->cnext;
                }
                    // a行号大于b行号
                else{
                    c->append(b_cnext->row, b_cnext->col, b_cnext->data);
                    b_cnext = b_cnext->cnext;
                }
            }
            // a剩余
            while (a_cnext != nullptr){
                c->append(a_cnext->row, a_cnext->col, a_cnext->data);
                a_cnext = a_cnext->cnext;
            }
            // b剩余
            while (b_cnext != nullptr){
                c->append(b_cnext->row, b_cnext->col, b_cnext->data);
                b_cnext = b_cnext->cnext;
            }
        }
        return c;
    }
    SparseMatrixCrossList * multiple(SparseMatrixCrossList &b){
        // c = a * b
        SparseMatrixCrossList * c = new SparseMatrixCrossList(this->rowNum, b.colNum);
        // 行指针遍历
        for (int i = 0; i <= this->rowNum; i++){
            // a的第i行头指针
            CrossListNode * a_rnext = this->rhead[i];
            if (a_rnext == nullptr){
                continue;
            }
            // 列指针遍历
            for (int j = 0; j <= b.colNum; j++){
                // b的第j列头指针
                CrossListNode * temp = a_rnext;
                CrossListNode * b_cnext = b.chead[j];
                if (b_cnext == nullptr){
                    continue;
                }
                int result = 0;
                while (temp != nullptr && b_cnext != nullptr){
                    // 相同行列
                    if (temp->col == b_cnext->row){
                        result += temp->data * b_cnext->data;
                        temp = temp->rnext;
                        b_cnext = b_cnext->cnext;
                    }
                        // a列号小于b行号
                    else if (temp->col < b_cnext->row){
                        temp = temp->rnext;
                    }
                        // a列号大于b行号
                    else{
                        b_cnext = b_cnext->cnext;
                    }
                }
                if (result != 0){
                    c->append(i, j, result);
                }
            }
        }
        return c;
    }
    void print(){
        for (int i = 0; i <= rowNum; ++i) {
            CrossListNode * rnext = this->rhead[i];
            while (rnext!= nullptr){
                std::cout<<rnext->row<<" "<<rnext->col<<" "<<rnext->data<<std::endl;
                rnext = rnext->rnext;
            }
        }
    }
};

//哈夫曼树
struct HuffmanTreeNode {
    char data;
    HuffmanTreeNode * left;
    HuffmanTreeNode * right;
    int weight;
};
class HuffmanTree{
private:
    // tree
    HuffmanTreeNode * root;
    // pair
    std::vector<std::pair<char,int>> weightList = std::vector<std::pair<char,int>>();
public:
    // code
    std::vector<std::pair<char,std::string>> codeList = std::vector<std::pair<char,std::string>>();
    HuffmanTree(int n, char * ch, int * weight) {
        root = nullptr;
        // 构造pairList
        char * it1 = ch;
        int * it2 = weight;
        while (it1 != ch+n && it2 != weight+n){
            std::pair<char, int> pair = std::pair<char, int>(*it1,*it2);
            this->weightList.push_back(pair);
            it1++;
            it2++;
        }
    }
    ~HuffmanTree() {
        //释放
        delete this->root;
        delete &this->codeList;
        delete &this->weightList;
    }
    // 构造哈夫曼树
    void CreateTree(){
        // 排序,从大到小
        std::sort(this->weightList.begin(),this->weightList.end(),[](std::pair<char,int> a,std::pair<char,int> b){
            return a.second > b.second;
        });
        // 构造栈
        std::stack<HuffmanTreeNode*> s = std::stack<HuffmanTreeNode*>();
        std::vector<std::pair<char, int>>::iterator it = this->weightList.begin();
        while (it != this->weightList.end()){
            HuffmanTreeNode *node = new HuffmanTreeNode();
            node->data = it->first;
            node->left = nullptr;
            node->right = nullptr;
            node->weight = it->second;
            s.push(node);
            this->codeList.push_back(std::pair<char,std::string>(it->first,""));
            it++;
        }
        // 处理栈，从上到下为越来越大，top<top-1
        while (s.size() > 1){
            HuffmanTreeNode *node1= s.top();
            s.pop();
            HuffmanTreeNode *node2 = s.top();
            s.pop();
            HuffmanTreeNode *node = new HuffmanTreeNode();
            // 小的放左子树
            node->left = node1;
            node->right = node2;
            node->weight = node1->weight + node2->weight;
            node->data = '|';
            // 判断是否是最后两个
            if (s.empty()){
                this->root = node;
                break;
            }
            // 按照大小插入栈
            if (node->weight <= s.top()->weight){
                s.push(node);
            } else {
                std::stack<HuffmanTreeNode *> *temp= new std::stack<HuffmanTreeNode *>();
                while (!s.empty() && node->weight > s.top()->weight){
                    temp->push(s.top());
                    s.pop();
                }
                s.push(node);
                while (!temp->empty()){
                    s.push(temp->top());
                    temp->pop();
                }
                delete temp;
            }
        }
    }
    // 打印树
    void printTree(){
        HuffmanTreeNode *node = this->root;
        std::queue<HuffmanTreeNode *> *q = new std::queue<HuffmanTreeNode *>();
        //广度优先遍历哈夫曼树
        q->push(node);
        int count = 1;
        while (!q->empty()){
            HuffmanTreeNode *temp = q->front();
            q->pop();
            count --;
            std::cout << temp->data << " ";
            if (temp->left != nullptr){
                q->push(temp->left);
            }
            if (temp->right != nullptr){
                q->push(temp->right);
            }
            if (count == 0){
                std::cout << std::endl;
                count = q->size();
            }
        }
        std::cout << std::endl;
        //遍历哈夫曼编码
        std::vector<std::pair<char,std::string>>::iterator it = this->codeList.begin();
        while (it != this->codeList.end()){
            std::cout << it->first << " " << it->second << std::endl;
            it++;
        }
    }
    //encoder
    std::string Encode(std::string & data){
        // 构造哈夫曼树
        std::string::iterator itD = data.begin();
        std::string code = "";
        while (itD!=data.end()){
            std::vector<std::pair<char,std::string>>::iterator itC = this->codeList.begin();
            while (itC != this->codeList.end()){
                if (itC->first == *itD){
                    code += itC->second;
                    break;
                }
                itC++;
            }
            itD++;
        }
        return code;
    }
    //decoder
    std:: string Decode(std::string & data){
        std::string::iterator itD = data.begin();
        std::string code = "";
        std::string result = "";
        while (itD!=data.end()){
            code += *itD;
            std::vector<std::pair<char,std::string>>::iterator itC = this->codeList.begin();
            while (itC != this->codeList.end()){
                if (itC->second == code){
                    result += itC->first;
                    code = "";
                    break;
                }
                itC++;
            }
            itD++;
        }
        return result;
    }

    // 构造编码
    void CreateCode(){
        // 从根节点开始
        HuffmanTreeNode *node = this->root;
        std::string code = "";
        this->dfs(node,code);
    };
private:
    //dfs
    void dfs(HuffmanTreeNode *node, std::string & code){
        if (node == nullptr){
            return;
        }
        if (node->left == nullptr && node->right == nullptr){
            std::vector<std::pair<char,std::string>>::iterator it = this->codeList.begin();
            while (it != this->codeList.end()){
                if (it->first == node->data){
                    it->second = code;
                    break;
                }
                it++;
            }
        }
        if (node->left != nullptr){
            code += "0";
            dfs(node->left,code);
            code.pop_back();
        }
        if (node->right != nullptr){
            code += "1";
            dfs(node->right,code);
            code.pop_back();
        }
    }
};