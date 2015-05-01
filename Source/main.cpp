//
//  main.cpp
//  PowerPlant
//
//  Created by Maxwell Maurice on 4/17/15.
//  Copyright (c) 2015 Maxwell Maurice. All rights reserved.
//

#include <iostream>
#include "Plant.h"
#include "EventTree.h"
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std;

/*
 TO DO:
 Floating point exception after some events
 Determain Number game
 Test More
 Delete Crap
 */

//Final Function that is called at the end of both loops, Displays Users Score
void quitMenu(PowerPlant UserPlant){
    cout<<"Thank you for playing!"<<endl;
    UserPlant.printScores();
}
//Function that strictly reads every line of a .txt file.
void Read(string Type){
    string line;
    ifstream myfile (Type);
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            cout<<line<<endl;
        }
        myfile.close();
    }
}

//Runs the Power plant time cycle. This function has 2 objects, the Plant and the event tree for the plant. The run displays the date, calls Event handler to displays an event and event outcome, calls set budget to allow user to set the budget for each year, allows user to exit after every 2 years, checks if a score is below a threshold and fails the plant if so. Once loops is exited the game compleates and calls quitMenu.
void MasterRun(PowerPlant UserPlant, string Type){
    EventTree Events;
    Events.TreeSetup(Type);
    UserPlant.getAssistantManager();
    cout<<"\n";
    std::string Months[12] = {"January","Febuary","March","April","May","June","July","August","September","October","November","December"};
    
    Read("InstructionsBudget.txt");
    UserPlant.ifFailed();
    UserPlant.SetPlantBudget();
    cout<<"\n";
    cout<<Months[rand() % 11]<<" "<<rand() % 27<<", "<<UserPlant.year<<endl;
    UserPlant=Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
    UserPlant.year++;
    cout<<"\n";
    while (UserPlant.year != 2030) {
        if (UserPlant.year == 2018 ||UserPlant.year == 2020||UserPlant.year == 2022||UserPlant.year == 2024 ||UserPlant.year ==2026||UserPlant.year == 2028) {
            string Confirm;
            UserPlant.printScores();
            cout<<"Would you like to Retire?(Y/N): ";
            getline(cin,Confirm);
            if (Confirm== "yes" || Confirm== "Yes" || Confirm== "y"||Confirm== "Y") {
                break;
            }else if (Confirm== "no"|| Confirm== "No"||Confirm== "n"||Confirm== "N"){
                UserPlant.ifFailed();
                UserPlant.SetPlantBudget();
                cout<<"\n";
                cout<<Months[rand() % 11]<<" "<<rand() % 27<<", "<<UserPlant.year<<endl;
                Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
                UserPlant.year++;
            }
        }else{
            UserPlant.ifFailed();
            UserPlant.SetPlantBudget();
            cout<<"\n";
            cout<<Months[rand() % 11]<<" "<<rand() % 27<<", "<<UserPlant.year<<endl;
            Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
            UserPlant.year++;
        }
        
    }
    quitMenu(UserPlant);
}



//Just displays primary Menu
void TitleMenu(){
    cout<<"\n"<<"\n"<<"             Welcome To Power Plant Simulator"<<endl;
    cout<<"                Press Enter Key To Continue"<<endl;
    std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
}
//Displays plant types for user
void PickMenu(){
    cout << "\n"<<"======Select Plant Type=====" << endl;
    cout << "1. Nuclear Plant" << endl;
    cout << "2. Solar Plant" << endl;
    cout << "3. Coal Plant" << endl;
    cout << "4. Hydroelectric Plant" << endl;
}
//Display menu that shows the information for all types of plants
void DifficultyMenu(string PR,string PP,string CF,string IR,string D){
    std::cout<<"\n";
    cout << "======Information=====" << endl;
    cout<<"Public Opinion: "<<PR<<endl;
    cout<<"Power Production: "<<PP<<endl;
    cout<<"Cost Factor: "<<CF<<endl;
    cout<<"Income Rate: "<<IR<<endl;
    cout<<"Difficulty: "<<D<<endl;
}


//Delay Fucntion. VERY IMPORTNAT IF YOU ARE RUNNING WINODWS THIS WILL NOT WORK!!!
//for Windows users [Sleep( X )] should replace [sleep(4)] and one incude statement should change from
//#include <unistd.h> to #include <windows.h>

void Delay(){
    sleep(4);
}

//MainMenu that runs the difficulty menu and Pick menu and reads Plant Dependedt introductions. Gets parameters for the power plant such as plant type, assistaint manager and when compleates launches to MasterRun
void MainMenu(){
    int input;
    bool quit = false;
    bool Continue = true;
    string Confirm;
    
    while(quit != true){
        PickMenu();
        cin >> input;
        cin.clear();
        cin.ignore(10000,'\n');
        if (input == 1) {
            DifficultyMenu("Very Low","High","High","Moderate","Moderate");
            while (Continue != false) {
                std::cout<<"\n";
                cout<<"Confirm Nuclear Plant?(Y/N): ";
                getline(cin,Confirm);
                
                if (Confirm== "yes" || Confirm== "Yes" || Confirm== "y"||Confirm== "Y") {
                    Read("NuclearIntro.txt");
                    cout<<"Loading..."<<endl;
                    Delay();
                    cout<<"Press Eneter to continue"<<endl;
                    std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
                    cout<<"Loading..."<<endl;
                    NuclearPlant UserPlant;
                    MasterRun(UserPlant,"Nuclear");
                    quit = true;
                }else if (Confirm== "no"|| Confirm== "No"||Confirm== "n"||Confirm== "N"){
                    Continue = false;
                }else{
                    cout << "Invalid Input, Please Select Again" << endl;
                }
            }
            Continue = true;
        }
        if (input == 2) {
            DifficultyMenu("High","Moderate to Low","low","Low","Easy");
            while (Continue != false) {
                std::cout<<"\n";
                cout<<"Confirm Solar Plant?(Y/N): ";
                getline(cin,Confirm);
                
                if (Confirm== "yes" || Confirm== "Yes" || Confirm== "y"||Confirm== "Y") {
                    Read("SolarIntro.txt");
                    cout<<"Loading..."<<endl;
                    Delay();
                    cout<<"Press Eneter to continue"<<endl;
                    std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
                    cout<<"Loading..."<<endl;
                    SolarPlant UserPlant;
                    MasterRun(UserPlant,"Solar");
                    quit = true;
                }else if (Confirm== "no"|| Confirm== "No"||Confirm== "n"||Confirm== "N"){
                    Continue = false;
                }else{
                    cout << "Invalid Input, Please Select Again" << endl;
                }
            }
            Continue = true;
        }
        if (input == 3) {
            DifficultyMenu("Low","High","Very Low","Moderate","Moderate");
            while (Continue != false) {
                std::cout<<"\n";
                cout<<"Confirm Coal Plant?(Y/N): ";
                getline(cin,Confirm);
                
                if (Confirm== "yes" || Confirm== "Yes" || Confirm== "y"||Confirm== "Y") {
                    Read("CoalIntro.txt");
                    cout<<"Loading..."<<endl;
                    Delay();
                    cout<<"Press Eneter to continue"<<endl;
                    std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
                    cout<<"Loading..."<<endl;
                    CoalPlant UserPlant;
                    MasterRun(UserPlant,"Coal");
                    quit = true;
                }else if (Confirm== "no"|| Confirm== "No"||Confirm== "n"||Confirm== "N"){
                    Continue = false;
                }else{
                    cout << "Invalid Input, Please Select Again" << endl;
                }
            }
            Continue = true;
        }
        if (input == 4) {
            DifficultyMenu("Moderate","High","Moderate","Moderate","Moderate");
            while (Continue != false) {
                std::cout<<"\n";
                cout<<"Confirm Hydro Plant?(Y/N): ";
                getline(cin,Confirm);
                
                if (Confirm== "yes" || Confirm== "Yes" || Confirm== "y"||Confirm== "Y") {
                    Read("HydroIntro.txt");
                    cout<<"Loading..."<<endl;
                    Delay();
                    cout<<"Press Eneter to continue"<<endl;
                    std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
                    cout<<"Loading..."<<endl;
                    HydroPlant UserPlant;
                    MasterRun(UserPlant,"Hydro");
                    quit = true;
                }else if (Confirm== "no"|| Confirm== "No"||Confirm== "n"||Confirm== "N"){
                    Continue = false;
                }else{
                    cout << "Invalid Input, Please Select Again" << endl;
                }
            }
            Continue = true;
        }
        if (input > 6 || input < 1){
            cout << "Invalid Input, Please Select Again" << endl;
            cin.clear();
            cin.ignore(10000,'\n');
        }
    }
}


//short main, calls title menu, reads primart instructions and then runs MainMenu. A return to main only happends when quit menu is run
int main(int argc, const char * argv[]){
    TitleMenu();
    cout<<"\n"<<endl;
    Read("InstructionsGeneral.txt");
    MainMenu();
    return 0;
}

