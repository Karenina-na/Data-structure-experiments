//
// Created by 15399 on 2023/4/24.
//
#include "../include/Function.h"
//struct CrossListNode{
//    int row;
//    int col;
//    int data;
//    CrossListNode * rnext;
//    CrossListNode * cnext;
//};
//class SparseMatrixCrossList{
//public:
//    int rowNum;
//    int colNum;
//    CrossListNode * rhead[10000]={nullptr};
//    CrossListNode * chead[10000]={nullptr};
//    SparseMatrixCrossList(int row, int col): rowNum(row), colNum(col){}
//    ~SparseMatrixCrossList(){
//        //行删除
//        for (int i = 0; i < rowNum; ++i) {
//            CrossListNode * rnext = this->rhead[i];
//            while (rnext!= nullptr){
//                CrossListNode * temp = rnext;
//                rnext = rnext->rnext;
//                delete temp;
//            }
//        }
//    }
//
//    void append(int row,int col,int data){
//        CrossListNode * n = new CrossListNode();
//        n->row = row;
//        n->col = col;
//        n->data = data;
//        n->cnext = nullptr;
//        n->rnext = nullptr;
//        //列处理
//        CrossListNode *cnext = this->chead[col];
//        if (cnext == nullptr){
//            this->chead[col] = n;
//        }else{
//            while (cnext->cnext != nullptr && cnext->cnext->row < n->row){
//                cnext = cnext->cnext;
//            }
//            n->cnext = cnext->cnext;
//            cnext->cnext = n;
//        }
//        //行处理
//        CrossListNode *rnext = this->rhead[row];
//        if (rnext == nullptr){
//            this->rhead[row] = n;
//        }else{
//            while (rnext->rnext != nullptr && rnext->rnext->col < n->col){
//                rnext = rnext->rnext;
//            }
//            n->rnext = rnext->rnext;
//            rnext->rnext = n;
//        }
//    }
//    SparseMatrixCrossList * add(SparseMatrixCrossList &b){
//        SparseMatrixCrossList * c = new SparseMatrixCrossList(this->rowNum, this->colNum);
//        // 列指针遍历
//        for (int i = 0; i < colNum; i++){
//            CrossListNode * a_cnext = this->chead[i];
//            CrossListNode * b_cnext = b.chead[i];
//            while (a_cnext != nullptr && b_cnext != nullptr){
//                // 相同行列
//                if (a_cnext->row == b_cnext->row){
//                    c->append(a_cnext->row, a_cnext->col, a_cnext->data + b_cnext->data);
//                    a_cnext = a_cnext->cnext;
//                    b_cnext = b_cnext->cnext;
//                }
//                    // a行号小于b行号
//                else if (a_cnext->row < b_cnext->row){
//                    c->append(a_cnext->row, a_cnext->col, a_cnext->data);
//                    a_cnext = a_cnext->cnext;
//                }
//                    // a行号大于b行号
//                else{
//                    c->append(b_cnext->row, b_cnext->col, b_cnext->data);
//                    b_cnext = b_cnext->cnext;
//                }
//            }
//            // a剩余
//            while (a_cnext != nullptr){
//                c->append(a_cnext->row, a_cnext->col, a_cnext->data);
//                a_cnext = a_cnext->cnext;
//            }
//            // b剩余
//            while (b_cnext != nullptr){
//                c->append(b_cnext->row, b_cnext->col, b_cnext->data);
//                b_cnext = b_cnext->cnext;
//            }
//        }
//        return c;
//    }
//    SparseMatrixCrossList * multiple(SparseMatrixCrossList &b){
//        // c = a * b
//        SparseMatrixCrossList * c = new SparseMatrixCrossList(this->rowNum, b.colNum);
//        // 行指针遍历
//        for (int i = 0; i < rowNum; i++){
//            // a的第i行头指针
//            CrossListNode * a_rnext = this->rhead[i];
//            if (a_rnext == nullptr){
//                continue;
//            }
//            // 列指针遍历
//            for (int j = 0; j < colNum; j++){
//                int result = 0;
//                // b的第j列头指针
//                CrossListNode * temp = a_rnext;
//                CrossListNode * b_cnext = b.chead[j];
//                if (a_rnext == nullptr){
//                    continue;
//                }
//                while (temp != nullptr && b_cnext != nullptr){
//                    // 相同行列
//                    if (temp->col == b_cnext->row){
//                        result += temp->data * b_cnext->data;
//                        temp = temp->rnext;
//                        b_cnext = b_cnext->cnext;
//                    }
//                        // a列号小于b行号
//                    else if (temp->col < b_cnext->row){
//                        temp = temp->rnext;
//                    }
//                        // a列号大于b行号
//                    else{
//                        b_cnext = b_cnext->cnext;
//                    }
//                }
//                if (result != 0){
//                    c->append(i, j, result);
//                }
//            }
//        }
//        return c;
//    }
//    void print(){
//        for (int i = 0; i < rowNum; ++i) {
//            CrossListNode * rnext = this->rhead[i];
//            while (rnext!= nullptr){
//                std::cout<<rnext->row<<" "<<rnext->col<<" "<<rnext->data<<std::endl;
//                rnext = rnext->rnext;
//            }
//        }
//    }
//};

void addCrossList(){
    int n,m;
    int num1,num2;
    std::cin>>n>>m>>num1>>num2;
    SparseMatrixCrossList a = SparseMatrixCrossList(n, m);
    for (int i=0;i<num1;i++){
        int row,col,data;
        std::cin>>row>>col>>data;
        a.append(row,col,data);
    }
    SparseMatrixCrossList b = SparseMatrixCrossList(n, m);
    for (int i=0;i<num2;i++){
        int row,col,data;
        std::cin>>row>>col>>data;
        b.append(row,col,data);
    }
    SparseMatrixCrossList * c = a.add(b);
    c->print();
}