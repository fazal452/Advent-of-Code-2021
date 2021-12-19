#include <iostream>
#include <fstream>
#include <ios>
#include <string>
#include <cmath>

using namespace ::std;

//Convert String into binary
int strToBin(string number){

    int size = number.size();

    long int result = 0;

    for (int i = 0; i < size; i++){

        //Convert "0" or "1" into 0 and 1
        int currint = 0;
        if (int(number.at(i)) == 49){
            currint = 1;
        }

        result += ((currint) * (pow(2,size-i-1)));

    }

    return (result);
}


int main() {


    long int oxygen = 0;
    long int c02 = 0;

    string oxySoFar = "";
    string co2SoFar = "";

    for (int i = 0; i < 12; i++) {

        int oxyOnes = 0;
        int oxyZeros = 0;

        int co2Ones = 0;
        int co2Zeros = 0;

        //Open File
        ifstream myfile("C:\\Users\\FazalR\\CLionProjects\\SpacialPlace\\distances.txt");
        string line;
        //Get number of elements
        if (myfile.is_open()) {
            while (getline(myfile, line)) {


                //If Oxygen Chain
                if (line.substr(0,i) == oxySoFar){
                    if (line.at(i) == '1'){
                        oxyOnes ++;
                    }
                    else{
                        oxyZeros++;
                    }
                }

                //If Co2 Chain
                if (line.substr(0,i) == co2SoFar){
                    if (line.at(i) == '1'){
                        co2Ones ++;
                    }
                    else{
                        co2Zeros++;
                    }
                }


            }
            myfile.close();
        }

        //if Only one number left
        if((oxyOnes + oxyZeros) == 1){

            if (oxyOnes == 1){
                oxySoFar += "1";
            }
            else{
                oxySoFar += "0";
            }
        }

        else{
            //Oxy Tallying
            string oxyDominant = "0";


            if (oxyOnes >= oxyZeros){
                oxyDominant = "1";
            }

            oxySoFar += oxyDominant;

        }

        if((co2Ones + co2Zeros) == 1){

            if (co2Ones == 1){
                co2SoFar += "1";
            }
            else{
                co2SoFar += "0";
            }
        }

        else{

            //c02 Tallying
            string co2Dominant = "1";

            if(co2Ones >= co2Zeros){
                co2Dominant = "0";
            }

            co2SoFar += co2Dominant;
        }

    }

    //cout << oxySoFar << endl << co2SoFar << endl;
    cout<< strToBin(co2SoFar) * strToBin(oxySoFar);



    return 0;
}


