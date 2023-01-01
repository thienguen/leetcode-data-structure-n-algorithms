#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void resize(string a[], string arr[], int n);

int main()
{
    int size = 0;
    int counter = 1;
    int iter = -1;
    string str[100] = {};

    string fileName = "name.txt";
    ifstream inFile;
    inFile.open(fileName);

    //  clear data in the file
    std::ofstream ofs;
    ofs.open("output.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    // ouput to a different file
    ofstream outFile;
    outFile.open("output.txt");

    if (inFile.is_open())
    {
        while (!inFile.eof())
        {
            string s;
            getline(inFile, s);
            str[++iter] = s;
            ++size;
        }

        string *temp = new string[size];

        resize(str, temp, size);
        std::sort(temp, temp + size);

        do
        {
            outFile << "\n\nPermutations: " << counter++ << endl;
            for (size_t i = 0; i < size; i++)
            {
                // output the permutations to a different file
                outFile << temp[i] << " ";
            }

        } while (next_permutation(temp, temp + size));

        temp = nullptr;

        outFile.close();
        inFile.close();
    }
    else
    {
        cout << "File not found" << endl;
    }

    return EXIT_SUCCESS;
}

void resize(string a[], string arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = a[i];
    }
}

