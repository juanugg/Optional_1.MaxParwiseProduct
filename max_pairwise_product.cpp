#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>


long long FastMaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    int First=-1;
    int Second=-1;

    for (int i = 0; i < n; ++i) {
      if (First==-1 || numbers[i]>numbers[First]){
        First=i;
      }
    }

    for (int j = 0; j < n; ++j) {
      if (j!=First && (Second==-1 || numbers[j]>numbers[Second])){
        Second=j;
      }
    }

    return (long long)(numbers[First])*numbers[Second];
}


long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                (long long)(numbers[first]) * (long long)(numbers[second]));
        }
    }

    return max_product;
}

int main() {

//Entrada estandar

    // int n;
    // std::cin >> n;
    // std::vector<int> numbers(n);
    // for (int i = 0; i < n; ++i) {
    //     std::cin >> numbers[i];
    // }

//Medición de los tiempos de computo
    unsigned t0, t1, t2, t3;

//Entradas para test de los tiempos
    std::vector<int> numbers(50000, 0);
    t0=clock();
    std::cout << MaxPairwiseProduct(numbers) << "\n";
    t1 = clock();
    double timeSlow = (double(t1-t0)/CLOCKS_PER_SEC);
    std::cout << "Tiempo de ejecución Slow:"  << timeSlow <<"\n";

    t2=clock();
    std::cout << FastMaxPairwiseProduct(numbers) << "\n";
    t3 = clock();
    double timeFast = (double(t3-t2)/CLOCKS_PER_SEC);
    std::cout << "Tiempo de ejecución Fast:"  << timeFast <<"\n";

    return 0;
}
