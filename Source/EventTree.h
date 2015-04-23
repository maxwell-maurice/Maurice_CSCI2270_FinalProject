//
//  EventTree.h
//  PowerPlant
//
//  Created by Maxwell Maurice on 4/21/15.
//  Copyright (c) 2015 Maxwell Maurice. All rights reserved.
//

#ifndef __PowerPlant__EventTree__
#define __PowerPlant__EventTree__

#include <iostream>
#include "Plant.h"
struct EventNode{
    
    bool Marked;
    int InvestmentChange;
    int PublicRelationsChange;
    int PowerProductionChange;
    int BoardChange;
    std::string Text;
    int TreeID;
    
    EventNode *leftChild;
    EventNode *rightChild;
    
    EventNode(int IC,int PRC,int PPC,int BC,std::string T,int ID){
        InvestmentChange = IC;
        PublicRelationsChange = PRC;
        PowerProductionChange = PPC;
        BoardChange = BC;
        Text = T;
        TreeID =ID;
        Marked = false;
    };
};





class EventTree{
    
public:
    EventTree();
    virtual ~EventTree();
    void addEventNode(int IC,int PRC,int PPC,int BC,std::string T,int ID);
    void EventHandler(PowerPlant UserPlant,EventNode* CurrentEvent, AssistantManager AM);
    void RunEvent(int ID);
    void TreeSetup(std::string PlantTyp);
    EventNode* searchEventTree(EventNode* node, int ID);
    EventNode* getRandomEvent();
    EventNode* root;
    
protected:
    
private:
    
    
};

#endif /* defined(__PowerPlant__EventTree__) */
