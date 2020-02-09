
// header guard
#ifndef _HEADER_GUARD_VECTOR_OPERATIONS_H_
#define _HEADER_GUARD_VECTOR_OPERATIONS_H_

// main deps

#include <vector>
#include <array>
#include <iostream>

//Function Prototypes
void printVector2DInt(std::vector<std::vector <int>>);
void printVector2DFloat(std::vector<std::vector <float>>);
std::vector<std::vector <float>> generateGaussianKernel(int);
std::vector<std::vector <int>> fillFromFileVector2DInt(std::ifstream&);
std::vector<std::vector <int>> negateVector2DInt(std::vector<std::vector <int>>);
std::vector<std::vector <int>> averageXNeigboursVector2DInt(std::vector<std::vector<int>>, int);
std::vector<std::vector <int>> applyingGaussianToVector2DInt(std::vector<std::vector<int>>, int);
std::array<int,255> generateHistogram(std::vector<std::vector<int>>);
void writeToFileArray255Int(std::array<int,255>, std::ofstream&);
void writeToFileVector2DInt(std::vector<std::vector <int>>, std::ofstream&);
int reflectImage(int, int);
#endif // _HEADER_GUARD_VECTOR_OPERATIONS_H_
