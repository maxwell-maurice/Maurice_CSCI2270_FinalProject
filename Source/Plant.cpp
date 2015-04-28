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

PowerPlant::PowerPlant(){}
PowerPlant::~PowerPlant(){}

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

void PowerPlant::printScores(){
    std::cout<<"\n";
    std::cout<<"Current Scores"<<std::endl;
    std::cout<<"InvestmentScore: "<<InvestmentScore<<std::endl;
    std::cout<<"PublicRelationsScore: "<<PublicRelationsScore<<std::endl;
    std::cout<<"PowerProductionScore: "<<PowerProductionScore<<std::endl;
    std::cout<<"BoardScore: "<<BoardScore<<"\n"<<std::endl;
    std::cout<<"\n";
}

void PowerPlant::SetPlantBudget(){
    
    std::string InvestBudget;
    std::string PRBudget;
    std::string StaffBudget;
    std::string MaintenanceBudget;
    std::string Confirm;
    bool Continue = true;
    bool Flag = false;
    
    std::cout<<"November 4, "<<year<<std::endl;
    std::cout<<"Current State of Affairs"<<std::endl;
    printScores();
    
    int Budget = InvestmentScore *IncomeRate;
    while (Flag == false) {
        std::cout<<"\n";
        std::cout<<"Current Budget for the "<<year+1<<" Fiscal year: "<<Budget<<std::endl;
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
        }
        if (atoi(InvestBudget.c_str())+atoi(MaintenanceBudget.c_str())+atoi(PRBudget.c_str())+atoi(StaffBudget.c_str()) <= Budget) {
            while (Continue != false) {
                std::cout<<"Confirm "<<year+1<<" Budget?(Y/N): ";
                getline(std::cin,Confirm);
                
                if (Confirm== "yes" || Confirm== "Yes" || Confirm== "y"||Confirm== "Y"){
                    InvestmentBudget = atoi(InvestBudget.c_str());
                    MaintenanceBudget = atoi(MaintenanceBudget.c_str());
                    PublicRelationsBudget= atoi(PRBudget.c_str());
                    StaffBudget= atoi(StaffBudget.c_str());
                    Continue = false;
                    Flag = true;
                }
            }
        }
        
    }
}


void PowerPlant::ifFailed(){
    if (PowerProductionScore ==0) {
        std::cout<<"\n";
        std::cout<<"Your Company has failed, Your plant either due to a lack of matinace"<<std::endl;
        std::cout<<"has not produced enough power for the ciy and as a result the city has"<<std::endl;
        std::cout<<"turned to alternitive energy supplies"<<std::endl;
        
    }
    if (BoardScore ==0) {
        std::cout<<"\n";
        std::cout<<"Your Company has failed, The board members who own the power plant have found"<<std::endl;
        std::cout<<"it to be in their best intest to replace you with someone more compentent. "<<std::endl;
    }
    if (PublicRelationsScore ==0) {
        std::cout<<"\n";
        std::cout<<"Your Company has failed, The city you were supplying energy to has had enough"<<std::endl;
        std::cout<<"of your service and has voted to ban your power plant from any further opperation"<<std::endl;
    }
}

void PowerPlant::getAssistantManager(){
    std::cout<<"Generating Manager Applications..."<<std::endl;
    AssistantManager TedBeneke = AssistantManager();
    TedBeneke.WildCardFactor = TedBeneke.WildCardFactor+7;
    std::cout<<"Finding Optimal Plant Location..."<<std::endl;
    AssistantManager NewtGingrich = AssistantManager();
    NewtGingrich.PublicRelationsAbility = NewtGingrich.PublicRelationsAbility + 7;
    std::cout<<"Looking at Zoneing Laws..."<<std::endl;
    AssistantManager BenBernanke = AssistantManager();
    BenBernanke.InvestmentAbility = BenBernanke.InvestmentAbility +7;
    std::cout<<"Constructing Plant Facility..."<<std::endl;
    AssistantManager EmmaWatson = AssistantManager();
    EmmaWatson.StaffManAbility = EmmaWatson.StaffManAbility +7;
    std::cout<<"Running Plant Safety Check..."<<std::endl;
    AssistantManager MITCollegeGrad = AssistantManager();
    MITCollegeGrad.MaintenanceAbility = MITCollegeGrad.MaintenanceAbility+7;
    AssistantManager Applications[5] = {TedBeneke,NewtGingrich,BenBernanke,EmmaWatson,MITCollegeGrad};
    
    //Bios?
    
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
        std::cout<<"(Ted Beneke, Newt Gingrich, Ben Bernanke, Emma Watson, MIT College Grad)"<<std::endl;
        std::cout<<"Please select an Applicant by Name: ";
        std::cin >> Name;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        if (Name == "Ted Beneke" || Name == "Ted" || Name == "ted" || Name == "ted beneke") {
            Assistant = TedBeneke;
            quit = true;
            break;
        }
        if (Name == "Newt Gingrich" || Name == "Newt" || Name == "newt gingrich" || Name == "newt") {
            Assistant= NewtGingrich;
            quit = true;
            break;
        }
        if (Name == "Ben Bernanke" || Name == "Ben" || Name == "ben bernanke" || Name == "ben") {
            Assistant= BenBernanke;
            quit = true;
            break;
        }
        if (Name == "Emma Watson" || Name == "Emma" || Name == "emma watson" || Name == "emma") {
            Assistant= EmmaWatson;
            quit = true;
            break;
        }
        if (Name == "MIT College Grad" || Name == "MIT" || Name == "College Grad") {
            Assistant= MITCollegeGrad;
            quit = true;
            break;
        }
        else{
            std::cout << "Invalid Input, Please Select Again" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
    }
}

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




