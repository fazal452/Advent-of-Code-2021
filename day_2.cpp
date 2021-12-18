#include <iostream>
#include <fstream>
#include <ios>
#include <string>

using namespace ::std;


int main() {






    string input = "forward 6";
    string limit = "up 8";


    int height = 0; // Track Height
    int position = 0; //x axis
    int aim = 0;

    //Open File
    ifstream myfile ("C:\\Users\\FazalR\\CLionProjects\\SpacialPlace\\distances.txt");
    string line;

    //Get number of elements
    if (myfile.is_open())
    {
        while (getline (myfile,line) )
        {


            int len = line.size();

            line = line.substr(len-3,len-2);


            int thing = stoi(line);


            //If forward
            if (len == 10){
                position += (thing);
                height += aim*thing;
            }

            //If Up

            else if (len == 5){
                aim -= (thing);
            }

            //If Down
            else{
                aim += (thing);
            }



        }
        myfile.close();
    }



    cout << position * height;

    return 0;
}


