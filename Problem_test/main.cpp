#include <iostream>
#include <random>
unsigned long long matrix_chain(const unsigned long long *p, unsigned long long size); // Неправильное решение через жадные алгоритмы

unsigned long long matrix_chain(const unsigned long long *p, unsigned long long size) {
    if (size == 2) {
        return 0;
    }
    unsigned long long idx = -1;
    unsigned long long tmp = -1;
    for (int i = 0; i < size; ++i) {
        if (tmp < 0 or tmp > p[i]) {
            tmp = p[i];
            idx = i;
        }
    }
    unsigned long long res = 0;
    for (int i = idx - 1; i > 0; --i) {
        res += p[idx] * p[i] * p[i - 1];
    }
    for (int i = idx + 1; i <= size - 2; ++i) {
        res += p[idx] * p[i] * p[i + 1];
    }
    if(idx != 0 and idx != size -1) {
        res += p[idx] * p[0] * p[size - 1];
    }
    return res;
}

std::pair<unsigned long long*, unsigned long long> create_test_case(unsigned long long n) {
    std::mt19937 rng(n);
    std::uniform_int_distribution<int> dist(1, 10 * n);
    unsigned long long *matrices = new unsigned long long[n + 1];
    for (int i = 0; i <= n; ++i) {
        matrices[i] = dist(rng);
    }
    return std::make_pair(matrices, n + 1);
}


unsigned long long chain(const unsigned long long *p, unsigned long long m, unsigned long long n, unsigned long long **memo) {
    if (m == n or n - m == 1) {
        return 0;
    }
    if (memo[m][n] != 0) {
        return memo[m][n];
    }
    if (n - m == 2) {
        memo[m][n] = p[m] * p[m + 1] * p[n];
    }
    unsigned long long tmp = -1;
    for (unsigned long long i = m + 1; i <= n - 1; ++i) {
        if (tmp < 0 or tmp > chain(p, m, i, memo) + chain(p, i, n, memo) + p[m] * p[i] * p[n]) {
            tmp = chain(p, m, i, memo) + chain(p, i, n, memo) + p[m] * p[i] * p[n];
        }
    }
    memo[m][n] = tmp;
    return tmp;
}


// Решение через динамическое програмирование
unsigned long long matrix_chain_dynamic(const unsigned long long *p, unsigned long long size){
    unsigned long long **array = new unsigned long long*[size];
    for(unsigned long long i = 0; i < size; ++i){
        array[i] = new unsigned long long[size] {0};
    }
    unsigned long long res;

    res = chain(p,0 ,size - 1, array);

    for(int i = 0; i < size; ++i){
        delete []array[i];
    }
    delete []array;
    return res;
}


int main() {
    int tmp;
    float counter = 0;
    {
        for (int n = 1; n < 1000; ++n) {
            auto test_case = create_test_case(n);
            /*for(int i = 0; i < n + 1; ++i){
                std::cout<<test_case.first[i]<<" ";
            }*/

            tmp = matrix_chain(test_case.first, test_case.second) -
                    matrix_chain_dynamic(test_case.first, test_case.second); // Сравниваю значения;

            std::cout<<matrix_chain_dynamic(test_case.first, test_case.second);

        }
    }



    return 0;
}
