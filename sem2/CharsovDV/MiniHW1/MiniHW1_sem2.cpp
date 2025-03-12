#include <iostream>
#include "MyLibrary.h"

int main() {
    double data[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    int size = sizeof(data) / sizeof(data[0]);

    std::cout << "Mean: " << CalculateMean(data, size) << std::endl;
    std::cout << "Median: " << CalculateMedian(data, size) << std::endl;
    std::cout << "Standard Deviation: " << CalculateStandardDeviation(data, size) << std::endl;
    std::cout << "Variance: " << CalculateVariance(data, size) << std::endl;

    return 0;
}