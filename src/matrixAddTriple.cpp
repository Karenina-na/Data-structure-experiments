//
// Created by 15399 on 2023/4/23.
//
#include "../include/Function.h"
//# define MAXSIZE 1000
//struct triple {
//    int row;
//    int col;
//    int value;
//};
//
//class SparseMatrix {
//public:
//    int row;
//    int col;
//    int num;
//    triple data[MAXSIZE];
//    SparseMatrix(int row, int col):row(row), col(col), num(0) {}
//    ~SparseMatrix() {}
//    void append(int row, int col, int value) {
//        //添加
//        data[num].row = row;
//        data[num].col = col;
//        data[num].value = value;
//        num++;
//    }
//    void print() {
//        //打印
//        for (int i = 0; i < num; i++) {
//            std::cout << data[i].row << " " << data[i].col << " " << data[i].value << std::endl;
//        }
//    }
//
//    void transpose(){
//        //转置
//        for (int i = 0; i < num; i++) {
//            int temp = data[i].row;
//            data[i].row = data[i].col;
//            data[i].col = temp;
//        }
//    }
//    SparseMatrix* add(SparseMatrix &b){
//        //加法
//        SparseMatrix *c = new SparseMatrix(row, col);
//        //双指针加法
//        int i=0,j=0;
//        while (i<num && j<b.num) {
//            if (data[i].row<b.data[j].row || (data[i].row==b.data[j].row && data[i].col<b.data[j].col)) {
//                c->append(data[i].row, data[i].col, data[i].value);
//                i++;
//            }
//            else if (data[i].row>b.data[j].row || (data[i].row==b.data[j].row && data[i].col>b.data[j].col)) {
//                c->append(b.data[j].row, b.data[j].col, b.data[j].value);
//                j++;
//            }
//            else {
//                if (data[i].value+b.data[j].value!=0) {
//                    c->append(data[i].row, data[i].col, data[i].value+b.data[j].value);
//                }
//                i++;
//                j++;
//            }
//        }
//        //this剩余部分
//        while (i<num) {
//            c->append(data[i].row, data[i].col, data[i].value);
//            i++;
//        }
//        //b剩余部分
//        while (j<b.num) {
//            c->append(b.data[j].row, b.data[j].col, b.data[j].value);
//            j++;
//        }
//        return c;
//    }
//private:
//    void sort(){
//        //排序
//        for (int i=0;i<num;i++){
//            for (int j=i+1;j<num;j++){
//                if (data[i].row>data[j].row){
//                    triple temp = data[i];
//                    data[i] = data[j];
//                    data[j] = temp;
//                }
//                else if (data[i].row==data[j].row && data[i].col>data[j].col) {
//                    triple temp = data[i];
//                    data[i] = data[j];
//                    data[j] = temp;
//                }
//            }
//        }
//    }
//};

void addTriple(){
    int n, m;
    int l1, l2;
    std::cin >> n >> m;
    SparseMatrixTriple matrix1(n, m);
    SparseMatrixTriple matrix2(n, m);
    std::cin >> l1 >> l2;
    int row, col, value;
    for (int i=0;i<l1;i++){
        std::cin >> row >> col >> value;
        matrix1.append(row, col, value);
    }
    for (int i=0;i<l2;i++){
        std::cin >> row >> col >> value;
        matrix2.append(row, col, value);
    }
    SparseMatrixTriple *matrix3 = matrix1.add(matrix2);
    matrix3->print();
}