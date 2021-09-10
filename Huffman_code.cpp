//2019055078_Ω≈√§øµ

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <string.h>
#include <queue>
using namespace std;

int freq[30001];
int arr[30001];
int n;

int N;

typedef struct node
{
    node* right;
    node* left;
    int length;
    double freq;
}node;

struct cmp {
    bool operator()(const node& u, const node& v) {
        return u.freq > v.freq;
    }
};

priority_queue < node, vector<node>, cmp> pq;

node Tree() {
    while (!pq.empty()) {
        node* n1 = new node;
        node* n2 = new node;
        node* n3 = new node;

        *n2 = pq.top();
        pq.pop();
        *n3 = pq.top();
        pq.pop();

        n1->left = n2;
        n1->right = n3;
        n1->freq = n2->freq + n3->freq;
        pq.push(*n1);

        if (pq.size() == 1) break;
    }
    return pq.top();
}

void bfs(node* r, int length) {
    node* root1 = new node;
    root1 = r;
    root1->length = length;
    if (root1->right == NULL && root1->left == NULL) {
        freq[n] = length;
        arr[n] = root1->freq;
        n++;
        delete[] root1;
    }
    else {
        root1->left->length = length + 1;
        root1->right->length = length + 1;
        bfs(root1->left, root1->left->length);
        bfs(root1->right, root1->right->length);
    }
}

void HuffmanCodes() {

    string s; int f;
    cin >> N;
    for (int i = 0; i < N; i++) {
        node n;
        cin >> s >> f;
        n.freq = f;
        n.left = NULL;
        n.right = NULL;
        pq.push(n);
    }

    int total;
    cin >> total;
    int fixed_length = int((log(N - 1) / log(2) + 1)) * total;
    cout << fixed_length << endl;

    node root = Tree();

    bfs(&root, 0);
}

int main(void) {
    HuffmanCodes();

    int hc = 0;
    for (int i = 0; i < N; i++) {
        hc += freq[i] * arr[i];
    }

    cout << hc;
}