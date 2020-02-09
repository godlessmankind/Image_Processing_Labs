// main includes
#include "VectorOperations.h"
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip> 

// namespace
using namespace std;


array<int,255> generateHistogram(vector<vector<int>> matrix)
{
    array<int,255> histogramDataSet{0};

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            histogramDataSet[matrix[i][j]]++;
        }
    }
    return histogramDataSet;
}

void writeToFileArray255Int(array<int,255> arr, ofstream& file)
{
    for (int i = 0; i < arr.size(); i++)
    {
        file << arr[i] << " ";
    }
}

vector<vector <int>> applyingGaussianToVector2DInt(vector<vector<int>> matrix, int level)
{
    vector<vector<float>> kernel = generateGaussianKernel(level);
    vector<vector <int>> filtered(matrix.size(),vector<int>(matrix[0].size()));    
    float sum_of_neigbours;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            sum_of_neigbours = 0;

            for (int k = -level; k <= level; k++)
            {
                for (int l = -level; l <= level; l++)
                {
                    sum_of_neigbours += matrix[reflectImage(i+k,matrix.size())][reflectImage(j+l,matrix[i].size())] * kernel[k+level][l+level];
                    
                }              
            }
            filtered[i][j] = sum_of_neigbours;
        }        
    }
    return filtered;
}

vector<vector <float>> generateGaussianKernel(int level)
{
    vector<vector <float>> mask(level*2+1,vector<float>(level*2+1));
    float stdv = level;
    float sum = 0.0;   // Initialization of sum for normalization
    for (int i = -level; i <= level; i++) // Loop to generate (level*2+1)x(level*2+1) kernel
    {
        for(int j = -level; j <= level; j++)
        {
            mask[i + level][j + level] = exp(-(i*i + j*j)/(2.0 * stdv * stdv));
            sum += mask[i + level][j + level];
        }
    }
     for(int i = 0; i < level*2+1; ++i) // Loop to normalize the kernel
         for(int j = 0; j < level*2+1; ++j)
             mask[i][j] /= sum;
    
    return mask;
}

vector<vector <int>> averageXNeigboursVector2DInt(vector<vector<int>> matrix, int level)
{
    vector<vector <int>> average(matrix.size(),vector<int>(matrix[0].size()));

    int sum_of_neigbours;
    int number_of_neigbours;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            sum_of_neigbours = 0;
            number_of_neigbours = 0;
            for (int k = -level; k <= level; k++)
            {
                for (int l = -level; l <= level; l++)
                {
                    sum_of_neigbours += matrix[reflectImage(i+k,matrix.size())][reflectImage(j+l,matrix[i].size())];
                    number_of_neigbours++;
                }              
            }
            average[i][j] = sum_of_neigbours / number_of_neigbours;
        }        
    }
    return average;
}
    
int reflectImage(int i, int dim)
{
    if (i<0)
        return abs(i);
    else if (i>=dim)
        return (dim-(i%dim)-1);
    else
        return i;
}

void printVector2DInt(vector<vector <int>> matrix)
{
    //Function prints provided 2D Vector.
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printVector2DFloat(vector<vector <float>> matrix)
{
    //Function prints provided 2D Vector.
    cout << fixed << setprecision(12); 
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector <int>> fillFromFileVector2DInt(ifstream& file)
{
    //Function gets all the data bits from input file and dynamicly fills 2D Vector. 
    vector<vector<int>> matrix;
    while (!file.eof())
    {
        string buffer;
        getline(file, buffer);
        if(buffer == "") continue;
        stringstream stream(buffer);
        vector<int> row;

        while (1)
        {
            int n;
            stream >> n;
            if (!stream)
                break;
            row.push_back(n);
        }
        matrix.push_back(row);
    }
    return matrix;
}

vector<vector <int>> negateVector2DInt(vector<vector <int>> matrix)
{
    //Function produces a negative of the 2D Vector and assignes it to a new vector.
    vector<vector <int>> negative;
    for (int i = 0; i < matrix.size(); i++)
    {
        vector<int> temp;

        for (int j = 0; j < matrix[i].size(); j++)
        {
            temp.push_back(256 - matrix[i][j]);
        }
        negative.push_back(temp);
    }
    return negative;
}

void writeToFileVector2DInt(vector<vector <int>> matrix, ofstream& file)
{
    //Function writes a 2D Vector to output file. 
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            file << matrix[i][j] << " ";
        }
        file << endl;
    }
}