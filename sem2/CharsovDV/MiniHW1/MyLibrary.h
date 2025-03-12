#pragma once

#ifdef MYLIBRARY_EXPORTS
#define MYLIBRARY_API __declspec(dllexport)
#else
#define MYLIBRARY_API __declspec(dllimport)
#endif

extern "C" MYLIBRARY_API double CalculateMean(double* data, int size);
extern "C" MYLIBRARY_API double CalculateMedian(double* data, int size);
extern "C" MYLIBRARY_API double CalculateStandardDeviation(double* data, int size);
extern "C" MYLIBRARY_API double CalculateVariance(double* data, int size);