//
// Created by 15399 on 2023/5/21.
//
#include "../include/Function.h"
// HuffmanTree
//struct HuffmanTreeNode {
//    char data;
//    HuffmanTreeNode * left;
//    HuffmanTreeNode * right;
//    int weight;
//};
//class HuffmanTree{
//private:
//    // tree
//    HuffmanTreeNode * root;
//    // pair
//    std::vector<std::pair<char,int>> weightList = std::vector<std::pair<char,int>>();
//public:
//    // code
//    std::vector<std::pair<char,std::string>> codeList = std::vector<std::pair<char,std::string>>();
//    HuffmanTree(int n, char * ch, int * weight) {
//        root = nullptr;
//        // 构造pairList
//        char * it1 = ch;
//        int * it2 = weight;
//        while (it1 != ch+n && it2 != weight+n){
//            std::pair<char, int> pair = std::pair<char, int>(*it1,*it2);
//            this->weightList.push_back(pair);
//            it1++;
//            it2++;
//        }
//    }
//    ~HuffmanTree() {
//        //释放
//        delete this->root;
//        delete &this->codeList;
//        delete &this->weightList;
//    }
//    // 构造哈夫曼树
//    void CreateTree(){
//        // 排序,从大到小
//        std::sort(this->weightList.begin(),this->weightList.end(),[](std::pair<char,int> a,std::pair<char,int> b){
//            return a.second > b.second;
//        });
//        // 构造栈
//        std::stack<HuffmanTreeNode*> s = std::stack<HuffmanTreeNode*>();
//        std::vector<std::pair<char, int>>::iterator it = this->weightList.begin();
//        while (it != this->weightList.end()){
//            HuffmanTreeNode *node = new HuffmanTreeNode();
//            node->data = it->first;
//            node->left = nullptr;
//            node->right = nullptr;
//            node->weight = it->second;
//            s.push(node);
//            this->codeList.push_back(std::pair<char,std::string>(it->first,""));
//            it++;
//        }
//        // 处理栈，从上到下为越来越大，top<top-1
//        while (s.size() > 1){
//            HuffmanTreeNode *node1= s.top();
//            s.pop();
//            HuffmanTreeNode *node2 = s.top();
//            s.pop();
//            HuffmanTreeNode *node = new HuffmanTreeNode();
//            // 小的放左子树
//            node->left = node1;
//            node->right = node2;
//            node->weight = node1->weight + node2->weight;
//            node->data = '|';
//            // 判断是否是最后两个
//            if (s.empty()){
//                this->root = node;
//                break;
//            }
//            // 按照大小插入栈
//            if (node->weight <= s.top()->weight){
//                s.push(node);
//            } else {
//                std::stack<HuffmanTreeNode *> *temp= new std::stack<HuffmanTreeNode *>();
//                while (!s.empty() && node->weight > s.top()->weight){
//                    temp->push(s.top());
//                    s.pop();
//                }
//                s.push(node);
//                while (!temp->empty()){
//                    s.push(temp->top());
//                    temp->pop();
//                }
//                delete temp;
//            }
//        }
//    }
//    // 打印树
//    void printTree(){
//        HuffmanTreeNode *node = this->root;
//        std::queue<HuffmanTreeNode *> *q = new std::queue<HuffmanTreeNode *>();
//        //广度优先遍历哈夫曼树
//        q->push(node);
//        int count = 1;
//        while (!q->empty()){
//            HuffmanTreeNode *temp = q->front();
//            q->pop();
//            count --;
//            std::cout << temp->data << " ";
//            if (temp->left != nullptr){
//                q->push(temp->left);
//            }
//            if (temp->right != nullptr){
//                q->push(temp->right);
//            }
//            if (count == 0){
//                std::cout << std::endl;
//                count = q->size();
//            }
//        }
//        std::cout << std::endl;
//        //遍历哈夫曼编码
//        std::vector<std::pair<char,std::string>>::iterator it = this->codeList.begin();
//        while (it != this->codeList.end()){
//            std::cout << it->first << " " << it->second << std::endl;
//            it++;
//        }
//    }
//    //encoder
//    std::string Encode(std::string & data){
//        // 构造哈夫曼树
//        std::string::iterator itD = data.begin();
//        std::string code = "";
//        while (itD!=data.end()){
//            std::vector<std::pair<char,std::string>>::iterator itC = this->codeList.begin();
//            while (itC != this->codeList.end()){
//                if (itC->first == *itD){
//                    code += itC->second;
//                    break;
//                }
//                itC++;
//            }
//            itD++;
//        }
//        return code;
//    }
//    //decoder
//    std:: string Decode(std::string & data){
//        std::string::iterator itD = data.begin();
//        std::string code = "";
//        std::string result = "";
//        while (itD!=data.end()){
//            code += *itD;
//            std::vector<std::pair<char,std::string>>::iterator itC = this->codeList.begin();
//            while (itC != this->codeList.end()){
//                if (itC->second == code){
//                    result += itC->first;
//                    code = "";
//                    break;
//                }
//                itC++;
//            }
//            itD++;
//        }
//        return result;
//    }
//
//    // 构造编码
//    void CreateCode(){
//        // 从根节点开始
//        HuffmanTreeNode *node = this->root;
//        std::string code = "";
//        this->dfs(node,code);
//    };
//private:
//    //dfs
//    void dfs(HuffmanTreeNode *node, std::string & code){
//        if (node == nullptr){
//            return;
//        }
//        if (node->left == nullptr && node->right == nullptr){
//            std::vector<std::pair<char,std::string>>::iterator it = this->codeList.begin();
//            while (it != this->codeList.end()){
//                if (it->first == node->data){
//                    it->second = code;
//                    break;
//                }
//                it++;
//            }
//        }
//        if (node->left != nullptr){
//            code += "0";
//            dfs(node->left,code);
//            code.pop_back();
//        }
//        if (node->right != nullptr){
//            code += "1";
//            dfs(node->right,code);
//            code.pop_back();
//        }
//    }
//};

void huffman(){
    int n;
    std::cin>>n;
    char ele[110]={0};
    int weight[110]={0};
    for (int i = 0;i < n;i++){
        std::cin>>ele[i];
    }
    for (int i = 0;i < n;i++){
        std::cin>>weight[i];
    }
    std::string data;
    std::cin>>data;
    HuffmanTree *h = new HuffmanTree(n, ele, weight);
    h->CreateTree();
    h->CreateCode();
//    h->printTree();
    std::string s = h->Encode(data);
    std::cout << s << std::endl;
    std::string result = h->Decode(s);
    std::cout << result << std::endl;
}