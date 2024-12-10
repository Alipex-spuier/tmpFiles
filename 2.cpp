#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int main() {
    ifstream infile("in.txt");
    ofstream outfile("out.txt");

    vector<int> numbers;
    string line;
    int num;

    if (infile.is_open()) {
        while (infile >> num) {
            numbers.push_back(num);
        }
    }

    quickSort(numbers, 0, numbers.size() - 1);

    int count = min(10, static_cast<int>(numbers.size()));
    for (int i = 0; i < count; i++) {
        outfile << numbers[i];
        if (i != count - 1)
            outfile << " ";
    }

    infile.close();
    outfile.close();

    return 0;
}