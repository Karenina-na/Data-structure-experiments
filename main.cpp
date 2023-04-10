#include <iostream>
#include <math.h>


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

    void print() { // 输出
        LinkNode *p = this->head;
        while (p != nullptr) {
            std::cout << p->data;
            p = p->next;
        }
    }

private:
    LinkNode *head; // 头指针
    LinkNode *tail; // 尾指针
};


int main() {
    LinkList *linkList = new LinkList;
    int n;
    std::cin >> n;
    // 反正弦泰勒展开式 arcsin(1) = pi/2 = sum((2n-
    delete linkList;
    return 0;
}

// 合并有序数组
void merge() {
    // 读入两个数组
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    int b[m];
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    int c[n + m];
    int i = 0, j = 0, k = 0;

    // 合并
    while (i < n && j < m) {
        if (a[i] < b[j]) { // 从小到大排序
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    // 将a的剩余的元素放入数组
    while (i < n) {
        c[k++] = a[i++];
    }
    // 将b的剩余的元素放入数组
    while (j < m) {
        c[k++] = b[j++];
    }
    for (int i = 0; i < n + m; ++i) {
        std::cout << c[i] << std::endl;
    }
}