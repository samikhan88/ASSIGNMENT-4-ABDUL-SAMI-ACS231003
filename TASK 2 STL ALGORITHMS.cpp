#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main() {
    std::vector<int> data(100000);
    for (int i = 99999; i >= 0; --i) {
        data.push_back(i);
    }

    // Bubble Sort
    auto start_bubble = std::chrono::steady_clock::now();
    bubbleSort(data);
    auto end_bubble = std::chrono::steady_clock::now();
    std::chrono::duration<double> bubble_time = end_bubble - start_bubble;
    std::cout << "Time taken by bubble sort: " << bubble_time.count()
        << " seconds" << std::endl;

    // STL Sort
    auto start_stl = std::chrono::steady_clock::now();
    std::sort(data.begin(), data.end());
    auto end_stl = std::chrono::steady_clock::now();
    std::chrono::duration<double> stl_time = end_stl - start_stl;
    std::cout << "Time taken by STL sort: " << stl_time.count() << " seconds"
        << std::endl;
}