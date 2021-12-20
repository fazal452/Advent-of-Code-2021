#include <iostream>
#include <fstream>
#include <ios>
#include <string>
#include <cmath>
#include <vector>

using namespace ::std;

struct bingo_number{

    int number = 0;
    bool marked = false;

};

struct sheet{

    bingo_number vals[5][5];

};

struct winner{

    int roundOfWin;
    int score;
};


int main() {

    winner currwinner;
    currwinner.roundOfWin = 9;

    int arr[] = {1,76,38,96,62,41,27,33,4,2,94,15,89,25,66,14,30,0,71,21,48,44,87,73,60,50,77,45,29,18,5,99,65,16,93,95,37,3,52,32,46,80,98,63,92,24,35,55,12,81,51,17,70,78,61,91,54,8,72,40,74,68,75,67,39,64,10,53,9,31,6,7,47,42,90,20,19,36,22,43,58,28,79,86,57,49,83,84,97,11,85,26,69,23,59,82,88,34,56,13};
    int size = (sizeof(arr)/sizeof(arr[0]));


    //Open File
    ifstream myfile("C:\\Users\\FazalR\\CLionProjects\\SpacialPlace\\distances.txt");
    string line;

    sheet card;
    int board_num = 0;


    //Get number of elements
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            if (line.size() > 5){

                for(int j = 0; j<5; j++){

                    bingo_number slot;
                    slot.number = stoi(line.substr(j*3,2 + (j*3)));
                    (card.vals[board_num][j]) = slot;
                }

                board_num ++;


                //If Finshed One BOARD
                if(board_num == 5){


                    bool win = false;

                    //Iterate Through Array Adding bingo number

                    for(int i = 0; i < size; i++){
                        int bingo = arr[i];





                        //Populate Array to make number marked

                        for(int row = 0; row < 5; row++){
                            for(int col = 0; col < 5; col++){
                                if(card.vals[row][col].number == bingo) {
                                    card.vals[row][col].marked = true;
                                }
                            }
                        }

                        //Check for win

                        //Row win?
                        for(int row = 0; row < 5; row ++) {
                            int counter = 0;

                            for (int col = 0; col < 5; col++) {
                                if (card.vals[row][col].marked == true) {
                                    counter++;
                                }
                            }
                            if (counter == 5) {
                                win = true;
                            }
                        }
                        //Col win?
                        for(int row = 0; row < 5; row ++) {
                            int counter = 0;

                            for (int col = 0; col < 5; col++) {
                                if (card.vals[col][row].marked == true) {
                                    counter++;
                                }
                            }
                            if (counter == 5) {
                                win = true;
                            }
                        }

                        // If finally win

                        if(win){

                            //Sum up unmarked

                            int unmarked = 0;

                            for(int r = 0; r < 5; r++){
                                for(int c = 0; c < 5 ; c++){
                                    if(card.vals[r][c].marked == false) {
                                        unmarked += card.vals[r][c].number;
                                    }
                                }
                            }

                            winner hand;
                            hand.roundOfWin = i;
                            hand.score = unmarked * bingo;

                            if (hand.roundOfWin > currwinner.roundOfWin){
                                currwinner = hand;
                            }

                            //cout << unmarked * bingo << endl;

                            break;
                        }

                    }

                    board_num = 0;


                }

            }


        }
        myfile.close();
    }

    cout << currwinner.score;


    return 0;
}


