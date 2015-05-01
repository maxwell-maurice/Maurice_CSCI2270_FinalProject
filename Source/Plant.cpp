//
//  Plant.cpp
//  PowerPlant
//
//  Created by Maxwell Maurice on 4/17/15.
//  Copyright (c) 2015 Maxwell Maurice. All rights reserved.
//

#include "Plant.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

//Empty Constructor
PowerPlant::PowerPlant(){}
//Empty Destructor
PowerPlant::~PowerPlant(){}

//Same as Read from main.cpp, reads each line of a .txt file
void PowerPlant::ReadInstuctions(std::string Type){
    std::string line;
    std::ifstream myfile (Type);
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            std::cout<<line<<std::endl;
        }
        myfile.close();
    }
}
//Prints Users power plants score
void PowerPlant::printScores(){
    std::cout<<"\n"<<"Current Scores"<<std::endl;
    std::cout<<"InvestmentScore: "<<InvestmentScore<<std::endl;
    std::cout<<"PublicRelationsScore: "<<PublicRelationsScore<<std::endl;
    std::cout<<"PowerProductionScore: "<<PowerProductionScore<<std::endl;
    std::cout<<"BoardScore: "<<BoardScore<<"\n"<<"\n"<<std::endl;
}
//Sets the budget for each year. Runs off a nested loop. first loop gets the budget for each catagory and will reject negitive numbers, under budget declarations, and over budget declarations. The second loop is the confimation of the budget. KNOWN BUG IF INPUT IS NOT A NUMBER THEN GAME QUITS. Thoughts, either I have some system that displays 5 or so possible budgets and the user selects from there or I find some way to catch non number chars.
void PowerPlant::SetPlantBudget(){
    
    std::string InvestBudget,PRBudget,StaffBudget,MaintenanceBudget,Confirm;
    bool Continue = false;
    bool BudgetFlag = false;
    
    std::cout<<"November 4, "<<year<<"\n"<<"Current State of Affairs"<<std::endl;
    printScores();
    
    int Budget = InvestmentScore *IncomeRate;
    while (BudgetFlag == false) {
        Continue = false;
        
        std::cout<<"\n"<<"Current Budget for the "<<year+1<<" Fiscal year: "<<Budget<<std::endl;
        std::cout<<"Set Maintenance Budget: ";
        std::cin >> MaintenanceBudget;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout<<"Set Public Relations Budget: ";
        std::cin >> PRBudget;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout<<"Set Staff Budget: ";
        std::cin >> StaffBudget;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout<<"Set Investment Budget: ";
        std::cin >> InvestBudget;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        
        
        if (atoi(InvestBudget.c_str())+atoi(MaintenanceBudget.c_str())+atoi(PRBudget.c_str())+atoi(StaffBudget.c_str()) > Budget) {
            std::cout << "Invalid Input, You went over budget Please Select Again" << std::endl;
        }else if (atoi(InvestBudget.c_str())+atoi(MaintenanceBudget.c_str())+atoi(PRBudget.c_str())+atoi(StaffBudget.c_str()) < Budget) {
            std::cout << "Invalid Input, You went Under budget Please Select Again" << std::endl;
        }else if (atoi(InvestBudget.c_str())<0 || atoi(MaintenanceBudget.c_str())<0 ||atoi(PRBudget.c_str())<0 ||atoi(StaffBudget.c_str()) <0) {
            std::cout << "Invalid Input, One of your budgets is a negitive number" << std::endl;
        }else if (atoi(InvestBudget.c_str())+atoi(MaintenanceBudget.c_str())+atoi(PRBudget.c_str())+atoi(StaffBudget.c_str()) <= Budget) {
            while (Continue == false) {
                std::cout<<"Confirm "<<year+1<<" Budget?(Y/N): ";
                getline(std::cin,Confirm);
                std::cin.clear();
                if (Confirm== "yes" || Confirm== "Yes" || Confirm== "y"||Confirm== "Y"){
                    InvestmentBudget = atoi(InvestBudget.c_str());
                    MaintenanceBudget = atoi(MaintenanceBudget.c_str());
                    PublicRelationsBudget= atoi(PRBudget.c_str());
                    StaffBudget= atoi(StaffBudget.c_str());
                    Continue = true;
                    BudgetFlag = true;
                }if (Confirm== "no"|| Confirm== "No"||Confirm== "n"||Confirm== "N"){
                    Continue = true;
                }else{
                    std::cout << "Invalid Input, Please Select Again" << std::endl;
                }
                
            }
        }
        
    }
}

//Checks to see if one of the scores is at or below 0. The game quits if found to fail.
void PowerPlant::ifFailed(){
    if (PowerProductionScore ==0) {
        std::cout<<"\n"<<"Your Company has failed, Your plant either due to a lack of matinace"<<"\n"<<"has not produced enough power for the ciy and as a result the city has"<<"\n"<<"turned to alternitive energy supplies"<<std::endl;
    }
    if (BoardScore ==0) {
        std::cout<<"\n"<<"Your Company has failed, The board members who own the power plant have found"<<"\n"<<"it to be in their best intest to replace you with someone more compentent."<<std::endl;
    }
    if (PublicRelationsScore ==0) {
        std::cout<<"\n"<<"Your Company has failed, The city you were supplying energy to has had enough"<<"\n"<<"of your service and has voted to ban your power plant from any further opperation"<<std::endl;
    }
}
//Function that creates the 5 Assistaint manager applications and allows the user to select one. The user reads an application and hits enter to see the next. After the user slects a manager.
void PowerPlant::getAssistantManager(){
    std::cout<<"Generating Manager Applications..."<<std::endl;
    AssistantManager TedBeneke = AssistantManager();
    TedBeneke.WildCardFactor = TedBeneke.WildCardFactor+7;
    TedBeneke.Bio = "Former president and owner of Beneke Fabricators";
    std::cout<<"Finding Optimal Plant Location..."<<std::endl;
    AssistantManager NewtGingrich = AssistantManager();
    NewtGingrich.PublicRelationsAbility = NewtGingrich.PublicRelationsAbility + 7;
    NewtGingrich.Bio = "Former Speaker of the U.S. House of Representatives from 1995 to 1999.";
    std::cout<<"Looking Through Municiple Zoning Laws..."<<std::endl;
    AssistantManager BenBernanke = AssistantManager();
    BenBernanke.InvestmentAbility = BenBernanke.InvestmentAbility +7;
    BenBernanke.Bio = "Former chairman of the Federal Reserve, the central bank of the United States from 2006 to 2014.";
    std::cout<<"Constructing Plant Facility..."<<std::endl;
    AssistantManager EmmaWatson = AssistantManager();
    EmmaWatson.StaffManAbility = EmmaWatson.StaffManAbility +7;
    EmmaWatson.Bio = "Former actress, model, and activist.";
    std::cout<<"Running Plant Safety Check..."<<std::endl;
    AssistantManager MITCollegeGrad = AssistantManager();
    MITCollegeGrad.MaintenanceAbility = MITCollegeGrad.MaintenanceAbility+7;
    MITCollegeGrad.Bio ="Former Computer Science Intern at Massachusetts Institute of Technology.";
    AssistantManager Applications[5] = {TedBeneke,NewtGingrich,BenBernanke,EmmaWatson,MITCollegeGrad};
    std::cout<<"Initialization Complete!"<<std::endl;
    
    ReadInstuctions("InstructionsManager.txt");
    for (int i=0; i<5; i++) {
        std::cout << "\n======Assistant Manager Applications=====" << std::endl;
        if (i==0) {
            std::cout<<"Name: Ted Beneke"<<std::endl;
        }
        if (i==1) {
            std::cout<<"Name: Newt Gingrich"<<std::endl;
        }
        if (i==2) {
            std::cout<<"Name: Ben Bernanke"<<std::endl;
        }
        if (i==3) {
            std::cout<<"Name: Emma Watson"<<std::endl;
        }
        if (i==4) {
            std::cout<<"Name: MIT College Grad"<<std::endl;
        }
        std::cout<<"Resume: "<<Applications[i].Bio<<std::endl;
        std::cout<<"Investment Ability: "<<Applications[i].InvestmentAbility<<std::endl;
        std::cout<<"Staff Managment Ability: "<<Applications[i].StaffManAbility<<std::endl;
        std::cout<<"Plant Maintenance Ability: "<<Applications[i].MaintenanceAbility<<std::endl;
        std::cout<<"Public Relations Ability: "<<Applications[i].PublicRelationsAbility<<std::endl;
        std::cout<<"Press Enter For Next Applicant"<<std::endl;
        std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
    }
    bool quit = false;
    std::string Name;
    while(quit != true){
        std::cout<<"(Ted Beneke, Newt Gingrich, Ben Bernanke, Emma Watson, MIT College Grad)"<<"\n"<<"Please select an Applicant by Name: ";
        getline (std::cin,Name);
        std::cin.clear();
        if (Name == "Ted Beneke" || Name == "Ted" || Name == "ted" || Name == "ted beneke") {
            Assistant = TedBeneke;
            break;
        }
        if (Name == "Newt Gingrich" || Name == "Newt" || Name == "newt gingrich" || Name == "newt") {
            Assistant= NewtGingrich;
            break;
        }
        if (Name == "Ben Bernanke" || Name == "Ben" || Name == "ben bernanke" || Name == "ben") {
            Assistant= BenBernanke;
            break;
        }
        if (Name == "Emma Watson" || Name == "Emma" || Name == "emma watson" || Name == "emma") {
            Assistant= EmmaWatson;
            break;
        }
        if (Name == "MIT College Grad" || Name == "MIT" || Name == "College Grad") {
            Assistant= MITCollegeGrad;
            break;
        }
        else{
            std::cout << "Invalid Input, Please Select Again" << std::endl;
            std::cin.clear();
        }
    }
}


//Below are all the constuctors for each type of plant. They differ in base scores and income rates

CoalPlant::CoalPlant(){
    PublicRelationsScore=200;
    PowerProductionScore=300;
    CostFactor = .9;
    IncomeRate=((PowerProductionScore/10)+(PublicRelationsScore/10))*(CostFactor);
}
CoalPlant::~CoalPlant(){}
SolarPlant::SolarPlant(){
    PublicRelationsScore=400;
    PowerProductionScore=100;
    CostFactor = .8;
    IncomeRate=((PowerProductionScore/10)+(PublicRelationsScore/10))*(CostFactor);
}
SolarPlant::~SolarPlant(){}
HydroPlant::HydroPlant(){
    PublicRelationsScore=300;
    PowerProductionScore=400;
    CostFactor = .7;
    IncomeRate=((PowerProductionScore/10)+(PublicRelationsScore/10))*(CostFactor);
}
HydroPlant::~HydroPlant(){}
NuclearPlant::NuclearPlant(){
    PublicRelationsScore=100;
    PowerProductionScore=200;
    CostFactor = .6;
    IncomeRate=((PowerProductionScore/10)+(PublicRelationsScore/10))*(CostFactor);
}
NuclearPlant::~NuclearPlant(){}
