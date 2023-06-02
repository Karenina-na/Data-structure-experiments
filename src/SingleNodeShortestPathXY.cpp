//
// Created by 15399 on 2023/6/2.
//
// 单节点最短路径
#include "../include/Function.h"
void singleNodeShortestPath(){
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
    DijResult *res = graph.Dijkstra(0);
    for (int i = 0; i < n; ++i) {
        std::cout << res->dist[i] << std::endl;
    }
}