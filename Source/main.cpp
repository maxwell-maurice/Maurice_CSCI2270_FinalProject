//
//  main.cpp
//  PowerPlant
//
//  Created by Maxwell Maurice on 4/17/15.
//  Copyright (c) 2015 Maxwell Maurice. All rights reserved.
//

#include <iostream>
#include <limits>
#include "Plant.h"
#include "EventTree.h"
#include <string>
#include <time.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std;

/*
 TO DO:
 Organize
 Make ReadMe
 Determain Number game
 Finish writing all intro text files
 AssistaintManager Bios
 Write events for each plant
 change from pointers to a ton of data
 */
void quitMenu(PowerPlant UserPlant){
    cout<<"Thank you for playing!"<<endl;
    UserPlant.printScores();
}
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

void MasterRun(PowerPlant UserPlant, string Type){
    EventTree Events;
    Events.TreeSetup(Type);
    UserPlant.getAssistantManager();
    std::string Months[12] = {"January","Febuary","March","April","May","June","July","August","September","October","November","December"};
    
    Read("InstructionsBudget.txt");
    UserPlant.ifFailed();
    UserPlant.SetPlantBudget();
    cout<<Months[rand() % 11]<<rand() % 27<<", "<<UserPlant.year<<endl;
    Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
    UserPlant.year++;
    std::cout<<"\n";
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
                cout<<Months[rand() % 11]<<rand() % 27<<", "<<UserPlant.year<<endl;
                Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
                UserPlant.year++;
            }
        }else{
            UserPlant.ifFailed();
            UserPlant.SetPlantBudget();
            cout<<Months[rand() % 11]<<rand() % 27<<", "<<UserPlant.year<<endl;
            Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
            UserPlant.year++;
        }
        
    }
    quitMenu(UserPlant);
}




void TitleMenu(){
    std::cout<<"\n";
    std::cout<<"\n";
    cout<<"             Welcome To Power Plant Simulator"<<endl;
    cout<<"                Press Enter Key To Continue"<<endl;
    std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
}
void PickMenu(){
    std::cout<<"\n";
    cout << "======Select Plant Type=====" << endl;
    cout << "1. Nuclear Plant" << endl;
    cout << "2. Solar Plant" << endl;
    cout << "3. Coal Plant" << endl;
    cout << "4. Hydroelectric Plant" << endl;
}
void DifficultyMenu(string PR,string PP,string CF,string IR,string D){
    std::cout<<"\n";
    cout << "======Information=====" << endl;
    cout<<"Public Opinion: "<<PR<<endl;
    cout<<"Power Production: "<<PP<<endl;
    cout<<"Cost Factor: "<<CF<<endl;
    cout<<"Income Rate: "<<IR<<endl;
    cout<<"Difficulty: "<<D<<endl;
}
void Delay(){
    //sleep(4);******************************
}
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
        if (input > 6 || input < 1) {
            cout << "Invalid Input, Please Select Again" << endl;
            cin.clear();
            cin.ignore(10000,'\n');
        }
    }
}

int main(int argc, const char * argv[]){
    Read("InstructionsGeneral.txt");
    TitleMenu();
    MainMenu();
    return 0;
}












/*
 
 void CoalPlantRun(CoalPlant UserPlant){
 EventTree Events;
 Events.TreeSetup("Coal");
 UserPlant.getAssistantManager();
 std::string Months[12] = {"January","Febuary","March","April","May","June","July","August","September","October","November","December"};
 
 
 UserPlant.ifFailed();
 UserPlant.SetPlantBudget();
 cout<<Months[rand() % 11]<<rand() % 27<<", "<<UserPlant.year<<endl;
 Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
 UserPlant.year++;
 std::cout<<"\n";
 
 while (UserPlant.year != 2030) {
 
 if (UserPlant.year == 2018 ||UserPlant.year == 2020||UserPlant.year == 2022||UserPlant.year == 2024 ||UserPlant.year ==2026||UserPlant.year == 2028) {
 string Confirm;
 cout<<"Would you like to Retire?(Y/N): ";
 getline(cin,Confirm);
 if (Confirm== "yes" || Confirm== "Yes" || Confirm== "y"||Confirm== "Y") {
 break;
 }else if (Confirm== "no"|| Confirm== "No"||Confirm== "n"||Confirm== "N"){
 UserPlant.ifFailed();
 UserPlant.SetPlantBudget();
 cout<<Months[rand() % 11]<<rand() % 27<<", "<<UserPlant.year<<endl;
 Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
 UserPlant.year++;
 }
 }else{
 UserPlant.ifFailed();
 UserPlant.SetPlantBudget();
 cout<<Months[rand() % 11]<<rand() % 27<<", "<<UserPlant.year<<endl;
 Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
 UserPlant.year++;
 }
 
 }
 quitMenu();
 }
 void SolarPlantRun(SolarPlant UserPlant){
 EventTree Events;
 Events.TreeSetup("Solar");
 UserPlant.getAssistantManager();
 std::string Months[12] = {"January","Febuary","March","April","May","June","July","August","September","October","November","December"};
 
 UserPlant.ifFailed();
 UserPlant.SetPlantBudget();
 cout<<Months[rand() % 11]<<rand() % 27<<", "<<UserPlant.year<<endl;
 Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
 UserPlant.year++;
 std::cout<<"\n";
 
 while (UserPlant.year != 2030) {
 if (UserPlant.year == 2018 ||UserPlant.year == 2020||UserPlant.year == 2022||UserPlant.year == 2024 ||UserPlant.year ==2026||UserPlant.year == 2028) {
 string Confirm;
 cout<<"Would you like to Retire?(Y/N): ";
 getline(cin,Confirm);
 if (Confirm== "yes" || Confirm== "Yes" || Confirm== "y"||Confirm== "Y") {
 break;
 }else if (Confirm== "no"|| Confirm== "No"||Confirm== "n"||Confirm== "N"){
 UserPlant.ifFailed();
 UserPlant.SetPlantBudget();
 cout<<Months[rand() % 11]<<rand() % 27<<", "<<UserPlant.year<<endl;
 Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
 UserPlant.year++;
 }
 }else{
 UserPlant.ifFailed();
 UserPlant.SetPlantBudget();
 cout<<Months[rand() % 11]<<rand() % 27<<", "<<UserPlant.year<<endl;
 Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
 UserPlant.year++;
 }
 }
 }
 void HydroPlantRun(HydroPlant UserPlant){
 EventTree Events;
 Events.TreeSetup("Hyro");
 UserPlant.getAssistantManager();
 std::string Months[12] = {"January","Febuary","March","April","May","June","July","August","September","October","November","December"};
 
 UserPlant.ifFailed();
 UserPlant.SetPlantBudget();
 cout<<Months[rand() % 11]<<rand() % 27<<", "<<UserPlant.year<<endl;
 Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
 UserPlant.year++;
 std::cout<<"\n";
 
 while (UserPlant.year != 2030) {
 if (UserPlant.year == 2018 ||UserPlant.year == 2020||UserPlant.year == 2022||UserPlant.year == 2024 ||UserPlant.year ==2026||UserPlant.year == 2028) {
 string Confirm;
 cout<<"Would you like to Retire?(Y/N): ";
 getline(cin,Confirm);
 if (Confirm== "yes" || Confirm== "Yes" || Confirm== "y"||Confirm== "Y") {
 break;
 }else if (Confirm== "no"|| Confirm== "No"||Confirm== "n"||Confirm== "N"){
 UserPlant.ifFailed();
 UserPlant.SetPlantBudget();
 cout<<Months[rand() % 11]<<rand() % 27<<", "<<UserPlant.year<<endl;
 Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
 UserPlant.year++;
 }
 }else{
 UserPlant.ifFailed();
 UserPlant.SetPlantBudget();
 cout<<Months[rand() % 11]<<rand() % 27<<", "<<UserPlant.year<<endl;
 Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
 UserPlant.year++;
 }
 }
 }
 
 
 
 void NuclearPlantRun(NuclearPlant UserPlant){
 EventTree Events;
 Events.TreeSetup("Nuclear");
 UserPlant.getAssistantManager();
 std::string Months[12] = {"January","Febuary","March","April","May","June","July","August","September","October","November","December"};
 
 UserPlant.ifFailed();
 UserPlant.SetPlantBudget();
 cout<<Months[rand() % 11]<<rand() % 27<<", "<<UserPlant.year<<endl;
 Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
 UserPlant.year++;
 std::cout<<"\n";
 
 while (UserPlant.year != 2030) {
 if (UserPlant.year == 2018 ||UserPlant.year == 2020||UserPlant.year == 2022||UserPlant.year == 2024 ||UserPlant.year ==2026||UserPlant.year == 2028) {
 string Confirm;
 cout<<"Would you like to Retire?(Y/N): ";
 getline(cin,Confirm);
 if (Confirm== "yes" || Confirm== "Yes" || Confirm== "y"||Confirm== "Y") {
 break;
 }else if (Confirm== "no"|| Confirm== "No"||Confirm== "n"||Confirm== "N"){
 UserPlant.ifFailed();
 UserPlant.SetPlantBudget();
 cout<<Months[rand() % 11]<<rand() % 27<<", "<<UserPlant.year<<endl;
 Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
 UserPlant.year++;
 }
 }else{
 UserPlant.ifFailed();
 UserPlant.SetPlantBudget();
 cout<<Months[rand() % 11]<<rand() % 27<<", "<<UserPlant.year<<endl;
 Events.EventHandler(UserPlant, Events.getRandomEvent(),UserPlant.Assistant);
 UserPlant.year++;
 }
 }
 }
 
 */
