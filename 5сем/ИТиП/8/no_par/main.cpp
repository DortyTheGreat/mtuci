#include <iostream>
#include <vector>
#include <random>
#include <omp.h>

using namespace std;

void initialize_matrix(std::vector<std::vector<double>>& matrix, int n, int m) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = dis(gen);
        }
    }
}

void print_matrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }
}

std::vector<std::vector<double>> multiply_matrices(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B) {
    int n = A.size();
    int m = A[0].size();
    int p = B[0].size();

    std::vector<std::vector<double>> C(n, std::vector<double>(p, 0.0));

    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < m; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}


/// C = (B - A) + A^2
void compute_C(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B, std::vector<std::vector<double>>& C) {
    int n = A.size();
    int m = A[0].size();

    std::vector<std::vector<double>> A_squared = multiply_matrices(A, A);

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            C[i][j] = (B[i][j] - A[i][j]) + A_squared[i][j];
        }
    }
}


/// -fopenmp
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = 300;
    int m = 300;
    omp_set_num_threads(1);

    std::vector<std::vector<double>> A(n, std::vector<double>(m));
    std::vector<std::vector<double>> B(n, std::vector<double>(m));
    std::vector<std::vector<double>> C(n, std::vector<double>(m, 0.0));

    initialize_matrix(A, n, m);
    initialize_matrix(B, n, m);

    std::cout << "Matrix A:" << std::endl;
    print_matrix(A);
    std::cout << "Matrix B:" << std::endl;
    print_matrix(B);

    double startTime = omp_get_wtime();
    compute_C(A, B, C);
    double endTime = omp_get_wtime();






    std::cout << "Matrix C = (B - A) + A^2:" << std::endl;

    print_matrix(C);

    std::cout << std::endl << "Elapsed time: " << endTime - startTime << " seconds" << "\n";

    return 0;
}
