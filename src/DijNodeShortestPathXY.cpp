//
// Created by 15399 on 2023/6/2.
//
#include "../include/Function.h"
// Dij算法结果
//struct DijResult{
//    int *dist;
//    int *path;
//};
//// Floyd算法结果
//struct FloydResult{
//    int **dist;
//    int **path;
//};
////无向赋权图
//class UndirectedGraph {
//private:
//    int vertexNum; //顶点数
//    int edgeNum; //边数
//    int **matrix;
//    int Unreachable = 10000;
//public:
//    UndirectedGraph(int n){
//        this->matrix = new int*[n];
//        for (int i = 0; i < n; ++i) {
//            this->matrix[i] = new int[n];
//            for (int j = 0; j < n; ++j) {
//                this->matrix[i][j] = this->Unreachable;
//                if (i == j){
//                    this->matrix[i][j] = 0;
//                }
//            }
//        }
//        this->vertexNum = n;
//        this->edgeNum = 0;
//    }
//    ~UndirectedGraph(){
//        for (int i = 0; i < this->vertexNum; ++i) {
//            delete[] this->matrix[i];
//        }
//        delete[] this->matrix;
//    }
//    void insertEdge(int v1, int v2, int weight){
//        if (this->matrix[v1][v2] == this->Unreachable){
//            this->edgeNum++;
//        }
//        this->matrix[v1][v2] = weight;
//        this->matrix[v2][v1] = weight;
//        if (this->matrix[v1][v2] == this->Unreachable){
//            this->edgeNum--;
//        }
//    }
//    DijResult * Dijkstra(int v){
//        int *dist = new int[this->vertexNum]; // 记录最短路径
//        bool *visited = new bool[this->vertexNum]; // 记录是否访问过
//        int *path = new int[this->vertexNum]; // 记录路径
//        for (int i = 0; i < this->vertexNum; ++i) {
//            dist[i] = this->matrix[v][i];
//            visited[i] = false;
//        }
//        visited[v] = true;
//        dist[v] = 0;
//        path[v] = -1;
//        while (true){
//            int min = this->Unreachable;
//            int minIndex = -1;
//            int pathNum = 0;
//            int pathIndex = 0;
//            for (int i = 0; i < this->vertexNum; ++i) {
//                if (visited[i]){
//                    for (int j = 0; j < this->vertexNum; ++j) {
//                        if (!visited[j] && this->matrix[i][j] + dist[i] < min + dist[pathIndex]){
//                            pathNum = dist[i];
//                            pathIndex = i;
//                            min = this->matrix[i][j];
//                            minIndex = j;
//                        }
//                    }
//                }
//            }
//            if (minIndex == -1){
//                break;
//            }
//            visited[minIndex] = true;
//            dist[minIndex] = pathNum + min;
//            path[minIndex] = pathIndex;
//        }
//        DijResult *result = new DijResult;
//        result->dist = dist;
//        result->path = path;
//        return result;
//    }
//    FloydResult * Floyd(){
//        int **dist = new int*[this->vertexNum];
//        int **path = new int*[this->vertexNum];
//        for (int i = 0; i < this->vertexNum; ++i){
//            dist[i] = new int[this->vertexNum];
//            path[i] = new int[this->vertexNum];
//            for (int j = 0; j < this->vertexNum; ++j) {
//                if (this->matrix[i][j] == this->Unreachable){
//                    dist[i][j] = this->Unreachable;
//                    path[i][j] = -1;
//                } else {
//                    dist[i][j] = this->matrix[i][j];
//                    path[i][j] = i;
//                }
//                if (i==j){
//                    dist[i][j] = 0;
//                    path[i][j] = -1;
//                }
//            }
//        }
//        // i->k->j
//        for (int k = 0; k < this->vertexNum; ++k) {
//            for (int i = 0; i < this->vertexNum; ++i) {
//                for (int j = 0; j < this->vertexNum; ++j) {
//                    if (dist[i][k] + dist[k][j] < dist[i][j]){
//                        dist[i][j] = dist[i][k] + dist[k][j];
//                        path[i][j] = k;
//                    }
//                }
//            }
//        }
//        FloydResult *result = new FloydResult;
//        result->dist = dist;
//        result->path = path;
//        return result;
//    }
//    void printGraph(){
//        for (int i = 0; i < this->vertexNum; ++i) {
//            for (int j = 0; j < this->vertexNum; ++j) {
//                if (this->matrix[i][j] == this->Unreachable){
//                    std::cout << "n" << " ";
//                } else{
//                    std::cout << this->matrix[i][j] << " ";
//                }
//            }
//            std::cout << std::endl;
//        }
//    }
//};
void dijNodeShortestPath(){
    int n;
    std::cin >> n;
    UndirectedGraph graph(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j){
            int weight;
            std::cin >> weight;
            graph.insertEdge(i, j, weight);
        }
    }
    int v1, v2;
    std::cin >> v1 >> v2;
    DijResult *res = graph.Dijkstra(v1);
    int node = v2;
    auto *s = new std::stack<int>;
    while (node != -1){
        s->push(node);
        node = res->path[node];
    }
    while (!s->empty()){
        std::cout << s->top() << std::endl;
        s->pop();
    }
}