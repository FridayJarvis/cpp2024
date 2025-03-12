#include "pch.h"
#include "MyLibrary.h"
#include <algorithm>
#include <cmath>

float CalculateAVG(float* data, int size) {
    float sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum / size;
}

float CalculateMedian(float* data, int size) {
    std::sort(data, data + size);
    if (size % 2 == 0) {
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    }
    else {
        return data[size / 2];
    }
}

float CalculateStandardDeviation(float* data, int size) {
    float mean = CalculateAVG(data, size);
    float sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += (data[i] - mean) * (data[i] - mean);
    }
    return std::sqrt(sum / size);
}

float CalculateVariance(float* data, int size) {
    float mean = CalculateAVG(data, size);
    float sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += (data[i] - mean) * (data[i] - mean);
    }
    return sum / size;
}