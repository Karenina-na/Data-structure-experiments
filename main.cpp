#include <iostream>
#include "include/Function.h"

struct Node{
    int row;
    int col;
    int data;
    Node * rnext;
    Node * cnext;
};

class CrossList{
public:
    int rowNum;
    int colNum;
    Node * rhead[1000]={nullptr};
    Node * chead[1000]={nullptr};
    CrossList(int row,int col):rowNum(row),colNum(col){}
    ~CrossList(){
        //行删除
        for (int i = 0; i < rowNum; ++i) {
            Node * rnext = this->rhead[i];
            while (rnext!= nullptr){
                Node * temp = rnext;
                rnext = rnext->rnext;
                delete temp;
            }
        }
        //列删除
        for (int i = 0; i < colNum; ++i) {
            Node * cnext = this->chead[i];
            while (cnext!= nullptr){
                Node * temp = cnext;
                cnext = cnext->cnext;
                delete temp;
            }
        }
    }

    void append(int row,int col,int data){
        Node * n = new Node();
        n->row = row;
        n->col = col;
        n->data = data;
        n->cnext = nullptr;
        n->rnext = nullptr;
        //列处理
        Node *cnext = this->chead[col];
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
        Node *rnext = this->rhead[row];
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

    void print(){
        for (int i = 0; i < rowNum; ++i) {
            Node * rnext = this->rhead[i];
            for (int j = 0; j < colNum; ++j) {
                if (rnext!= nullptr && rnext->col==j){  //如果行指针不为空且列号相等
                    std::cout<<rnext->data<<" ";
                    rnext = rnext->rnext;   //行指针后移
                }else{
                    std::cout<<"0 ";
                }
            }
            std::cout<<std::endl;
        }
    }
};

int main() {
//    merge();
//    calculatePI();
//    transpose();
//    add();
    int n,m;
    int num1,num2;
    std::cin>>n>>m>>num1>>num2;
    CrossList a = CrossList(n,m);
    for (int i=0;i<num1;i++){
        int row,col,data;
        std::cin>>row>>col>>data;
        a.append(row-1,col-1,data);
    }
    CrossList b = CrossList(n,m);
    for (int i=0;i<num2;i++){
        int row,col,data;
        std::cin>>row>>col>>data;
        b.append(row-1,col-1,data);
    }
    return 0;
}

