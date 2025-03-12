#include "pch.h"
#include "MyLibrary.h"
#include <algorithm>
#include <cmath>

double CalculateMean(double* data, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum / size;
}

double CalculateMedian(double* data, int size) {
    std::sort(data, data + size);
    if (size % 2 == 0) {
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    }
    else {
        return data[size / 2];
    }
}

double CalculateStandardDeviation(double* data, int size) {
    double mean = CalculateMean(data, size);
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += (data[i] - mean) * (data[i] - mean);
    }
    return std::sqrt(sum / size);
}

double CalculateVariance(double* data, int size) {
    double mean = CalculateMean(data, size);
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += (data[i] - mean) * (data[i] - mean);
    }
    return sum / size;
}