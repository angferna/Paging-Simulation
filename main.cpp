// Andy Schiff, Angel Fernandes
// 6/8/2021
// Project 8

#include <iostream>
#include <string>

#include "PageTableEntry.h"
#include "PagingSimulator.h"
#include "Counter.h"
#include "Process.h"

int main(int argc, char* argv[])
{
    if(argc != 2){
    
        std::cerr << "Incorrect amount of arguments.";
        return 1;
        
    }
    
    PagingSimulator sim(argv[1]);
    
    sim.run();

    return 0;
    
}