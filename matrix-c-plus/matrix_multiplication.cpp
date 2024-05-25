#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

using namespace std;

void transposeMatrix(const vector<vector<int>> &matrix, vector<vector<int>> &transposed, int size) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

void multiplyMatrices(const vector<vector<int>> &a, const vector<vector<int>> &b, vector<vector<int>> &result, int size) {
    vector<vector<int>> bTransposed(size, vector<int>(size, 0));
    transposeMatrix(b, bTransposed, size);

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += a[i][k] * bTransposed[j][k];
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Please provide the matrix size as an argument." << endl;
        return 1;
    }

    int size = stoi(argv[1]);

    vector<vector<int>> a(size, vector<int>(size, 1));
    vector<vector<int>> b(size, vector<int>(size, 1));
    vector<vector<int>> result(size, vector<int>(size, 0));

    auto start = chrono::high_resolution_clock::now();
    multiplyMatrices(a, b, result, size);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsed = end - start;
    cout << "Matrix multiplication took: " << elapsed.count() << " seconds." << endl;

    return 0;
}


