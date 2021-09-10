//2019055078_Ω≈√§øµ

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct Heap heap;

struct Heap {
    int size;
    int* arr;
};
heap* CreateHeap(int);
void Heapify(heap*, int);1
int DeleteMax(heap*);
void Insertion(heap*, int);

int main() {
    heap* h = CreateHeap(100000);
    int* array = new int[100000];
    int cnt = 0;
    while (true) {
        int f_int, num, index;
        cin >> f_int;
        if (f_int == 1) {
            cin >> num;
            Insertion(h, num);
        }
        else if (f_int == 2) {
            array[cnt++] = DeleteMax(h);
        }
        else if (f_int == 3) {
            cin >> index >> num;
            h->arr[index] = num;
            for (int j = index;j > 0;j /= 2)
                Heapify(h, j);

        }
        else if (f_int == 0) {
            for (int j = 0;j < cnt;++j)
                cout << array[j]<<" ";
            cout << endl;
            for (int j = 1;j <= h->size;++j)
                cout << h->arr[j]<<" ";
            cout << endl;
            break;
        }
        else
            break;

    }

}

heap* CreateHeap(int size) {
    heap* h;
    h = new heap();
    h->size = 0;
    h->arr = new int [size + 1];
    return h;
}
void Heapify(heap* heap, int k) {
    int child = k * 2;
    int tmp;
    if (heap->size >= child) {
        if (child != heap->size && heap->arr[child] <= heap->arr[child + 1]) child++;
        if (heap->arr[child] > heap->arr[k]) {
            tmp = heap->arr[k];
            heap->arr[k] = heap->arr[child];
            heap->arr[child] = tmp;
            Heapify(heap, child);
        }
    }

}
void Insertion(heap* h, int x) {
    int i;
    for (i = ++h->size;i / 2 > 0 && h->arr[i / 2] < x;i /= 2) {
        h->arr[i] = h->arr[i / 2];
    }
    h->arr[i] = x;

}
int DeleteMax(heap* h) {
    int i, child, max, end;
    max = h->arr[1];
    end = h->arr[h->size--];

    for (i = 1;i * 2 <= h->size;i = child) {
        child = i * 2;
        if (child != h->size && h->arr[child] <= h->arr[child + 1]) child++;
        if (end < h->arr[child]) h->arr[i] = h->arr[child];
        else break;
    }
    h->arr[i] = end;
    return max;
}