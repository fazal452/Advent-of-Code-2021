#include <iostream>
#include <fstream>
#include <ios>
#include <string>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace ::std;

struct fish{

    int age;

};

int main() {

    vector<fish> arr;

    //Open File
    ifstream myfile("C:\\Users\\fazal\\CLionProjects\\Black-Jack\\distances.txt");
    string line;


    //Create Vector Of Fishes With Ages Updated
    if (myfile.is_open()) {
        while (getline(myfile, line)){
            int size = line.size();

            for(int i = 0; i <= (size/2); i ++){
                int fishAge = stoi(line.substr((2*i),((2*i)+1)));

                fish tempFish;
                tempFish.age = fishAge;

                arr.push_back(tempFish);

            }

        }
        myfile.close();
    }

    //Calculate Remaining Days
    for(int i = 0; i < 80; i ++){

        int size = arr.size();

        for(int j = 0; j < size; j++){

            int fishAge =  arr[j].age;

            //If Timer Up
            if(fishAge == 0){
                //Create New fish
                fish tempFish; tempFish.age = 8;
                arr.push_back(tempFish);

                arr[j].age = 6;

            }

            //If not timer up
            else{
                arr[j].age --;
            }


        }


    }



    cout << arr.size();
    return 0;
}


