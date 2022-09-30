// Andy Schiff, Angel Fernandes
// 6/8/2021
// Project 8

#include "Process.h"

Process::Process(uint32_t num_pages, uint32_t num_frames)
{
    
    this->num_pages = num_pages;
    this->num_frames = num_frames;
    
    uint32_t bits_needed = log2(num_frames) + 1;
    
    for(int i = 0; i < num_pages; i++){
        table.push_back(PageTableEntry(bits_needed));
        counters.push_back(Counter());
    }
    
}

void Process::age(){
    
    for(int i = 0; i < num_pages; i++){
        if(table.at(i).get_r_bit() == 1){
            counters.at(i).increment();
            table.at(i).clear_r_bit();
        }else{
            counters.at(i).shift();
        }
    }

}
