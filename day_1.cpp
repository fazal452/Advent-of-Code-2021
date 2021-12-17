#include <iostream>
#include <fstream>
#include <ios>
#include <string>

using namespace ::std;


int main() {

    //Open File
    ifstream myfile ("C:\\Users\\FazalR\\CLionProjects\\SpacialPlace\\distances.txt");
    string line;

    //Create Empty Array

    int num_of_elements = 0;
    int* arr = new int[200047];

    //Get number of elements
    if (myfile.is_open())
    {
        while (getline (myfile,line) )
        {
            arr[num_of_elements] = stoi(line);
            num_of_elements++;

        }
    }

    myfile.close();



    //Finally start algorithm
    int increments = 0;

    for(int i = 3; i < num_of_elements+1; i++){

        int sum1 = arr[i-3] + arr[i-2] + arr[i-1];

        int sum2 = arr[i-2] + arr[i-1] + arr[i];

        if (sum2 > sum1){
            increments ++;
        }

    }

    cout << increments;

    return 0;
}


