// Andy Schiff, Angel Fernandes
// 6/8/2021
// Project 8

#ifndef PROCESS_H
#define PROCESS_H

#include <stdint.h>
#include <vector>
#include "PageTableEntry.h"
#include "Counter.h"

#include <math.h>

#include <iostream>

class Process
{
public:
    Process(uint32_t num_pages, uint32_t num_frames);

    void age();
    
private:
    uint32_t num_pages;
    uint32_t num_frames;
    
    std::vector<PageTableEntry> table;
    std::vector<Counter> counters;
    
friend class PagingSimulator;

};

#endif // PROCESS_H
