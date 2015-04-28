# Maurice_CSCI2270_FinalProject
Power Plant Simulation


Project Summary

Welcome to Power Plant Simulator, In this game you will become a Power Plant Manager
and you will take control of either a Nuclear plant, a Hydroelectric Dam, a Solar
farm, or a Coal plant. The object of the game is to have the highest total scores
by the end of 2030 when you retire as manager. You are scored in the game based off 
of the amount of money invested into your plant, your public relations with the 
customers you supply, the power production that your plant produces, and finally the 
board score which is the score that reflects how well you are keeping your employers 
happy. Each year you will have to set a budget that allows you to allocate funds to
different sectors of your plant to keep your score up and each year there is a 
random event that can hurt your score. Based off your budget and your assistant 
manager you will either win or lose the event. Well lets begin!

How to Run

You will first have to compile the .cpp and .h files and then run the executable. 
Remember to have all the text files in the same directory as the exacutable or else
the game will not run properly.

Dependencies

The program relies on 11 different .txt files which can be found within this project directory. These text files
need to be in the same directory as your executable or else the program will not run. Also one of the C++ 
include statements is '#include <unistd.h>'. This is the unix standered lib, which obviously only works with
unix basesd systems. I used to to use the sleep function. The windows include is   #include <windows.h>.

include <windows.h>
  inline void delay( unsigned long ms )
    {
    Sleep( ms );
    }

include <unistd.h>
  inline void delay( unsigned long ms )
    {
    usleep( ms * 1000 );
    }


System Requirements

Since the sleep function is unix only, the program on its own is unix based OS only, a minor change of all usleep to 
Sleep and a change in the include statement #include <unistd.h> to #include <windows.h> would make the program 
windowns compatable 

Group Members

Maxwell Maurice

Contributors

N/A

Open issues/bugs

Ok, their are a ton. 

1 I do not handle all input cases causing errors, 

2 my program can be made C++ only (meaning both OS X and windows compatable) but I do not know how to get a time 
dely using onbly time.h (I havent looked into it very much but it is possible)

3 Possible segementation faults with some of the events

4 I cannot spell

5 my code can be repetitive and I would like to compress it more

6 The foundation of how my code works is many different loops within loops, I feel like thats awful code and I wanna
change that



