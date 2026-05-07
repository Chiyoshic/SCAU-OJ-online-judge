#include <iostream>
#include <stdlib.h>
#include <algorithm> 
using namespace std;

const int SIZE = 10001;
int a[SIZE];
int b[SIZE]; 



void RecurInsertionSort(int p, int q) 
{
    if (p >= q) return; 
    
    
    RecurInsertionSort(p, q - 1);
    
    
    int key = a[q];
    int i = q - 1;
    while (i >= p && a[i] > key) {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = key;
}


void Merge(int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= right) b[k++] = a[j++];
    
    for (i = 0; i < k; i++) {
        a[left + i] = b[i];
    }
}


void NaturalMergeSort(int n) 
{
    int runs[SIZE]; 
    while (true) {
        int count = 0;
        runs[count++] = 0; 
        
        
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) { 
                runs[count++] = i + 1;
            }
        }
        runs[count++] = n; 
        
        
        if (count == 2) break;
        
        
        for (int i = 0; i < count - 2; i += 2) {
            Merge(runs[i], runs[i + 1] - 1, runs[i + 2] - 1);
        }
    }
}


int Partition(int x, int p, int q) 
{
    
    swap(a[x], a[p]);
    int pivot = a[p];
    int i = p, j = q;
    
    while (i < j) {
        while (i < j && a[j] >= pivot) j--; 
        if (i < j) a[i++] = a[j];
        
        while (i < j && a[i] <= pivot) i++; 
        if (i < j) a[j--] = a[i];
    }
    a[i] = pivot; 
    return i;     
}


int RandomizedPartition(int p, int q) {
    int x = p + rand() % (q - p + 1);
    return Partition(x, p, q);
}


int RandomizedSelect(int p, int q, int target_idx) 
{
    if (p == q) return p;
    
    
    int mid = RandomizedPartition(p, q);
    
    if (mid == target_idx) return mid; 
    
    
    if (mid > target_idx) 
        return RandomizedSelect(p, mid - 1, target_idx);
    
    else 
        return RandomizedSelect(mid + 1, q, target_idx);
}


int median(int p, int q) 
{
    
    
    return RandomizedSelect(p, q, p + (q - p) / 2);
}


void QuickSort(int p, int q)   
{
    if (p >= q) return;
    
    int x = median(p, q);       
    int i = Partition(x, p, q); 
    
    QuickSort(p, i - 1);        
    QuickSort(i + 1, q);        
}

int main()
{
    int i, n;
    if (!(cin >> n)) return 0;

    for(i = 0; i < n; i++) {
         cin >> a[i];
    }
    RecurInsertionSort(0, n - 1);
    cout << "Insert sort: ";
    for(i = 0; i < n; i++) {
         cout << a[i] << ' ';
    }

    for(i = 0; i < n; i++) {
         cin >> a[i];
    }
    NaturalMergeSort(n);
    cout << "\nNatural merge sort: ";
    for(i = 0; i < n; i++) {
         cout << a[i] << ' ';
    }

    for(i = 0; i < n; i++) {
         cin >> a[i];
    }
    QuickSort(0, n - 1);
    cout << "\nQuick sort: ";
    for(i = 0; i < n; i++) {
         cout << a[i] << ' ';
    }
    cout << "\n";

    return 0;
}