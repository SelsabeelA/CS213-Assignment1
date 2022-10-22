// Author: Selsabeel Asim Ali Elbagir
// ID: 20210714
//Date: 2022/10/09
// Second year, semester 1.
//Course:CS213 Object Oriented Programming
//Professor: Dr.El-Ramly

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    struct PlayerInfo{
        string name;
        int score;
    };
    //vector for all the players with their scores?
    vector<PlayerInfo> scores;
    //array for the top 10 scores since size is known, 10 elements
    PlayerInfo topscores[10];
    // I am initializing them since if I don't, the array fills each one with garbage
    // which will make it difficult to compare which one is the top score.
    topscores[0].name = "None.";
    topscores[1].name = "None.";
    topscores[2].name = "None.";
    topscores[3].name = "None.";
    topscores[4].name = "None.";
    topscores[5].name = "None.";
    topscores[6].name = "None.";
    topscores[7].name = "None.";
    topscores[8].name = "None.";
    topscores[9].name = "None.";

    topscores[0].score = 0;
    topscores[1].score = 0;
    topscores[2].score = 0;
    topscores[3].score = 0;
    topscores[4].score = 0;
    topscores[5].score = 0;
    topscores[6].score = 0;
    topscores[7].score = 0;
    topscores[8].score = 0;
    topscores[9].score = 0;


    int option = 1;
    while(option!= 0){
        cout << "Welcome, dear user! What would you like to do?" << endl <<
             "1. Add a new player and score." << endl <<
             "2. Print the top 10 names and scores." << endl <<
             "3. Find a player's highest score if they're in the top 10." << endl <<
             "Please enter 1, 2, or 3. If you want to exit, choose 0." << endl;
        cin >> option;

        if(option==1){
            cout << "NOTE: If a player has more than one score, enter their name and score multiple times." << endl <<
                 "When you're done, please enter 0." << endl;
            int choice = 1;
            PlayerInfo temp_score;

            while(choice!= 0){
                cout << "Please enter the scorer's name: ";
                cin >> temp_score.name;
                cout << endl << "Please enter their score: ";
                cin >> temp_score.score;
                scores.push_back(temp_score);
                //entering into top score if needed.
                for(int i=0;i<10;i++){
                    if(topscores[i].score<temp_score.score){
                        topscores[i].name = temp_score.name;
                        topscores[i].score = temp_score.score;
                        break;
                    }
                }
                cout << "Are you done? If yes, enter 0. If not, press 1." << endl;
                cin >> choice;
            }

        }
        if(option==2){
            for(int i=0;i<10;i++){
                cout << "Top " << (i+1) << " player: " << topscores[i].name << topscores[i].score << endl;
            }
            return 0;
        }
        if(option==3){
            string playername;
            cout << "Please enter the player's name you'd like to check for: ";
            cin >> playername;
            for(int i=0; i<10;i++){
                if(topscores[i].name == playername){
                    cout << "This player is a top player! They are the top " << (i+1) << " player!" << endl;
                    cout << playername << "'s score is: " << topscores[i].score << endl;
                }
                else if (i==9){ // if i=9 and their name wasn't the 10th, this means that they are not from the top 10.
                    cout << "Unfortunately, this player is not a top player, or maybe not in the system!" << endl;
                }
            }
            return 0;
        }
    }
    cout << "Would you like to exit? Then press 0. Else, press 1.";

}
