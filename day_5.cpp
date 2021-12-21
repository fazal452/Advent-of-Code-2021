#include <iostream>
#include <fstream>
#include <ios>
#include <string>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace ::std;


struct coordinate{

    int x ;
    int y ;
    int crossed = 0;

};

int main() {

    //Create Vector of Coordinates
    vector<coordinate> arr;




    //Open File
    ifstream myfile("C:\\Users\\FazalR\\CLionProjects\\SpacialPlace\\distances.txt");
    string line;


    //Get number of elements
    if (myfile.is_open()) {
        while (getline(myfile, line)){


            int x1,y1,x2,y2;

            //Convert Str to Number Number
            x1 = stoi(line.substr(0,line.find(',')));

            y1 = stoi(line.substr(line.find(',') + 1, line.find("-")-4));

            string secondhalf = line.substr(8);
            string secondNum = secondhalf.substr(secondhalf.find(' '));

            x2 = stoi(secondNum.substr(0,secondNum.find(',')));

            y2 = stoi(secondNum.substr(secondNum.find(',') + 1, secondNum.find("-")-4));

            //Stores String into values DONE
            //cout << x1 << " " << y1 << " "<< x2 << " "<< y2 << " "<< endl;

            //Only deal with orthogonal lines

            // If vertical Line
            if(x1 == x2){

                //If order misplaced
                if ( y1 > y2){
                    int temp = y1; y1 = y2; y2 = temp;
                }

                for (int y = y1; y <= y2; y++){

                    bool toBeAdded = true;

                    for(int k = 0 ; k<arr.size(); k++){
                        if((arr[k].x == x1) && (arr[k].y == y)){
                            arr[k].crossed++;
                            toBeAdded = false;

                        }
                    }

                    if(toBeAdded){
                        coordinate temp;
                        temp.x = x1;
                        temp.y = y;
                        temp.crossed = 0;


                        arr.push_back(temp);
                    }

                }

            }

            //Horizontal Line
            if(y1 == y2){

                //If order misplaced
                if ( x1 > x2){
                    int temp = x1; x1 = x2; x2 = temp;
                }

                for (int x = x1; x <= x2; x++){

                    bool toBeAdded = true;

                    for(int k = 0 ; k<arr.size(); k++){
                        if((arr[k].y == y1) && (arr[k].x == x)){
                            arr[k].crossed++;
                            toBeAdded = false;

                        }
                    }


                    if(toBeAdded){
                        coordinate temp;
                        temp.y = y1;
                        temp.x = x;
                        temp.crossed = 0;

                        arr.push_back(temp);
                    }

                }

            }
            
            

        }
        myfile.close();
    }


    int counter = 0;

    for(coordinate val:arr){

        if (val.crossed >= 1){
            counter ++;
        }
    }


    cout << counter;

    return 0;
}


