#include <iostream>
#include <vector>
#include <ctime>
//Generate random numbers for the StressTest
#include <cstdlib>


long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
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
      max_product = std::max(max_product, (long long)(numbers[first]) * (long long)(numbers[second]));
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
  //   std::cin >> numbers[i];
  // }

//Medición de los tiempos de computo
  time_t t0, t1, t2, t3;

//Entradas para test de los tiempos
  std::vector<int> numbers(10000, 0);

//Slow model
  time(&t0);
  std::cout << MaxPairwiseProduct(numbers) << "\n";
  time(&t1);
  double timeSlow = double(t1-t0);

//Fast model
  time(&t2);
  std::cout << MaxPairwiseProductFast(numbers) << "\n";
  time(&t3);
  double timeFast = double(t3-t2);

//Timing output

  std::cout << "\n\nPrimera ejecucion"  <<"\n\n";

  std::cout << "  Tiempo de ejecucion Slow: "  << timeSlow <<"\n";
  std::cout << "  Tiempo de ejecucion Fast: "  << timeFast <<"\n";

//Start StressTest
std::cout << "\n\nComienza StressTest"  <<"\n\n";

  int n = 0;
  int count_test = 1;

  long long solution_slow = 0;
  long long solution_fast = 0;

  while(true)
  {
    std::cout << "  Test: "  << count_test << "\n";
    n = rand() % 10 + 2; //Range 2-11

    std::vector<int> numbers_test;
    std::cout << "\n    Elementos: "  << n << "\n";
    std::cout << "    Datos: ";
    for (int i = 0; i < n; ++i)
    {
      numbers_test.push_back(rand() % 100000); //Rango 0-100000
      std::cout<< numbers_test[i] << "  ";
    }

    solution_slow = MaxPairwiseProduct(numbers_test);
    solution_fast = MaxPairwiseProductFast(numbers_test);

    if (solution_slow !=solution_fast)
    {
      std::cout << "\n\n" << "    Respuestas incorrectas: " << "\n";
      std::cout << "      Slow: "  << solution_slow << "\n";
      std::cout << "      Fast: "  << solution_fast << "\n";
      break;
    }else{
      std::cout << "\n\n" << "    Test OK" << "\n\n";
    }

    count_test+=1;
    if (count_test == 10000)
    {
      break;
    }
  }
  return 0;
}
