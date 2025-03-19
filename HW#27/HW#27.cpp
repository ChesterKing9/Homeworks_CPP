#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include <chrono>
#include <future>
#include <algorithm>

// Vector elements sum
long long sumVector(const std::vector<int>& vec, int num_threads) {
    size_t size = vec.size();
    std::vector<std::future<long long>> futures;
    long long total_sum = 0;
    size_t chunk_size = size / num_threads;

    for (int i = 0; i < num_threads; ++i) {
        size_t start = i * chunk_size;
        size_t end = (i == num_threads - 1) ? size : (i + 1) * chunk_size;
        futures.push_back(std::async(std::launch::async, [&vec, start, end]() {
            return std::accumulate(vec.begin() + start, vec.begin() + end, 0LL);
            }));
    }
    for (auto& f : futures) total_sum += f.get();
    return total_sum;
}

// quickSort
void quickSort(std::vector<int>& vec, int left, int right) {
    if (left >= right) return;
    int pivot = vec[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (vec[j] < pivot) std::swap(vec[++i], vec[j]);
    }
    std::swap(vec[i + 1], vec[right]);
    int p = i + 1;
    quickSort(vec, left, p - 1);
    quickSort(vec, p + 1, right);
}

// Paralel quickSort
void parallelQuickSort(std::vector<int>& vec, int left, int right, int depth) {
    if (left >= right) return;
    int pivot = vec[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (vec[j] < pivot) std::swap(vec[++i], vec[j]);
    }
    std::swap(vec[i + 1], vec[right]);
    int p = i + 1;

    if (depth > 0) {
        std::thread left_thread(parallelQuickSort, std::ref(vec), left, p - 1, depth - 1);
        parallelQuickSort(vec, p + 1, right, depth - 1);
        left_thread.join();
    }
    else {
        quickSort(vec, left, p - 1);
        quickSort(vec, p + 1, right);
    }
}

// test
void testPerformance(int size, int num_threads) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), rand);

    auto start = std::chrono::high_resolution_clock::now();
    long long sum = sumVector(vec, num_threads);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Sum: " << sum << " Time: " << std::chrono::duration<double>(end - start).count() << " sec\n";

    std::generate(vec.begin(), vec.end(), rand);
    start = std::chrono::high_resolution_clock::now();
    parallelQuickSort(vec, 0, vec.size() - 1, static_cast<int>(std::log2(num_threads)));
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Sorting time: " << std::chrono::duration<double>(end - start).count() << " sec\n";
}

int main() {
    std::vector<int> sizes = { 1000, 10000, 100000, 1000000 };
    int hardware_threads = static_cast<int>(std::thread::hardware_concurrency());
    std::vector<int> threads = { 1, 2, hardware_threads, 2 * hardware_threads };

    for (int size : sizes) {
        std::cout << "\nSize: " << size << "\n";
        for (int t : threads) {
            std::cout << "Flows: " << t << "\n";
            testPerformance(size, t);
        }
    }
    return 0;
}
