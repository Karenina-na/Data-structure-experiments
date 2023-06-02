//
// Created by 15399 on 2023/6/2.
//
#include "../include/Function.h"
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