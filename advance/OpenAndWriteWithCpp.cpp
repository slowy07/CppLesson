#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    ofstream MyFile("FilesWithCpp.txt");
    
    MyFile<<"c++ fun";
    MyFile.close();
    
    return 0;
}
