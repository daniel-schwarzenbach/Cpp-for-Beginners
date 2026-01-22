#include <iostream>
#include <chrono>
#include <random>

using std::cout;
using std::endl;
using namespace std::chrono_literals;

double generate_and_average(int n, double mean, double stddev) {
  std::default_random_engine generator;
  std::normal_distribution<double> dist(mean, stddev);
  double sum = 0.0;
  for (int i = 0; i < n; ++i) {
    double num = dist(generator);
    sum += num;
  }
  return sum / n;
}

int main() { 
	// start timer
	auto start = std::chrono::high_resolution_clock::now();
	generate_and_average(10000000, 5, 2); 
	// stop timer
	auto end = std::chrono::high_resolution_clock::now();
	// get duration in milliseconds
	double duration_ms = (end - start) / 1ms;
	double duration_s = (end - start) / 1s;
	cout << duration_ms << " , " << duration_s << endl;
}