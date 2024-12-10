#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    ifstream infile("in.txt");
    ofstream outfile("out.txt");

    vector<int> numbers;
    string line, num;

    if (infile.is_open()) {
        getline(infile, line);
        stringstream ss(line);

        while (ss >> num)
            numbers.push_back(stoi(num));
    }

    mergeSort(numbers, 0, numbers.size() - 1);

    for (size_t i = 0; i < numbers.size(); i++) {
        outfile << numbers[i];
        if (i != numbers.size() - 1)
            outfile << " ";
    }

    infile.close();
    outfile.close();

    return 0;
}