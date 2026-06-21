#include "sorting_algorithms.h"
#include <algorithm>
#include <chrono>

using Clock = std::chrono::high_resolution_clock;

void bubble_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    bool swapped;
    
    auto start = Clock::now();

    for (int i = 0; i < n - 1; i++){
        swapped = false;

        for (int j = 0; j < n - i - 1; j++){

            m.comparisons++;
            if (data[j] > data[j + 1]){
                std::swap(data[j], data[j + 1]);
                
                m.swaps++;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


void selection_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 0; i < n - 1; i++){
         int min_idx = i;

         for (int j = i + 1; j < n; ++j){
            m.comparisons++;
            if (data[j] < data[min_idx]){
                min_idx = j;
            }
         }
         if (min_idx != i){
            std::swap(data[i], data[min_idx]);
            m.swaps++;
         }
    }
    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


void insertion_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 1; i < n; ++i){
        int key = data[i];
        int j = i - 1;

        while(j >= 0){
            m.comparisons++;

            if (data[j] > key){
                data[j + 1] = data[j];
                m.shifts++;

                j--;
            } else {
                break;
            }
        }
        data[j + 1] = key;
    }
    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


void merge(std::vector<int>& data, int left, int mid, int right, Metrics& m) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++){
        L[i] = data[left + i];
    }

    for (int j = 0; j < n2; j++){
        R[j] = data[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2){
        
        m.comparisons++;
        if (L[i] <= R[j]){
            data[k] = L[i];
            i++;
        } 
        else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        data[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        data[k] = R[j];
        j++;
        k++;
    }
}
    void mergeSort(std::vector<int>& data, 
            int left, int right, Metrics& m){
        
        m.recursive_calls++;
        if(left >= right)
            return;
        
        int mid = left + (right - left) / 2;
        
        mergeSort(data, left, mid, m);
        mergeSort(data, mid + 1, right, m);
        merge(data, left, mid, right, m);
    }

void merge_sort(std::vector<int>& data, Metrics& m){
    if (data.empty()) return;
    
    auto start = Clock::now();
    mergeSort(data, 0, data.size() - 1, m);

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


int partition(std::vector<int>& data, int low, int high, Metrics& m){
    int pivot = data[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++){
        
        m.comparisons++;
        if(data[j] < pivot){
            i++;
            std::swap(data[i], data[j]);
            m.swaps++;
        }
    }
    m.swaps++;
    std::swap(data[i + 1], data[high]);
    return i + 1;
}
void quickSort(std::vector<int>& data, int low, int high, Metrics& m){
    
    m.recursive_calls++;
    if(low < high){
        int pi = partition(data, low, high, m);

        quickSort(data, low, pi - 1, m);
        quickSort(data, pi + 1, high, m);

    }
}
void quick_sort(std::vector<int>& data, Metrics& m) {
    if (data.empty()) return;
    auto start = Clock::now();
    quickSort(data, 0, data.size() - 1, m);

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


int getMax(const std::vector<int>& data){
    if (data.empty()) return 0;
    int mx = data[0];
    for (int i = 1; i < data.size(); i++){
        if (data[i] > mx){
            mx = data[i];
        }
    }
    return mx;
}

void count_sort(std::vector<int>& data, int exp, Metrics& m){
    int n = data.size();
    std::vector<int>output(n);
    int i, count[10] = {0};

    for (i = 0; i < n; i++){
        int index = (data[i] / exp) % 10;
        m.array_accesses++;
        count[index]++;
    }
    for (i = 1; i < 10; i++){
        m.array_accesses+= 2;
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--){
        int index = (data[i] / exp) % 10;
        m.array_accesses++;
        output[count[index] - 1] = data[i];
        m.array_accesses++;
        count[index]--;
    }

    for (i = 0; i < n; i++){
    m.array_accesses++;
    data[i] = output[i];
    }
}
void radix_sort(std::vector<int>& data, Metrics& m) {
    if (data.empty()) return;
    auto start = Clock::now();

    int mx = getMax(data);
    for (int exp = 1; mx / exp > 0; exp *=10){
        count_sort(data, exp, m);
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}