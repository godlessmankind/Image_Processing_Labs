// main includes
#include "main.h"
#include "VectorOperations.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


// namespaces
using namespace std;


int main(int argv, char** argc)
{

    
    ifstream inFile("testimage.dat");
    ofstream outFile("result.dat");
    ofstream outGraph("histogram.dat");
    vector<vector<int>> bytemap;
    vector<vector<int>> nega_bytemap;
    vector<vector<int>> average_bytemap;
    vector<vector<int>> gaussianBlured_bytemap;
    int level = 3;
    bytemap = fillFromFileVector2DInt(inFile);

    inFile.close();


   // printVector2DInt(bytemap);


    



 
    //    nega_bytemap = negateVector2DInt(bytemap);
    //    printVector2DInt(nega_bytemap);

    //    average_bytemap = averageXNeigboursVector2DInt(bytemap, level);
    //    printVector2DInt(average_bytemap);

    // gaussianBlured_bytemap = applyingGaussianToVector2DInt(bytemap,level);
    // printVector2DInt(gaussianBlured_bytemap);

    
    
    writeToFileArray255Int(generateHistogram(bytemap),outGraph);

    //    writeToFileVector2DInt(nega_bytemap,outFile);
    //    writeToFileVector2DInt(average_bytemap,outFile);
    //    writeToFileVector2DInt(gaussianBlured_bytemap,outFile);

    cout << "DONE" << endl;
    return 0;
}

