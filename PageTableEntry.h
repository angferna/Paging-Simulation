// Andy Schiff, Angel Fernandes
// 6/8/2021
// Project 8

#ifndef PAGETABLEENTRY_H
#define PAGETABLEENTRY_H

#include <stdint.h>

//delete after testing
#include <bitset>
#include <iostream>

class PageTableEntry
{
public:
    PageTableEntry(uint32_t bits_needed);
    
    void set_present_bit();
    void clear_present_bit();
    uint32_t get_present_bit();
    
    void set_r_bit();
    void clear_r_bit();
    uint32_t get_r_bit();
    
    void set_m_bit();
    void clear_m_bit();
    uint32_t get_m_bit();
    
    void set_frame_num(uint32_t num);
    uint32_t get_frame_num();
    
    void clear();
    
private:
    const int PRESENT_BIT_POSITION = 29;
    const int R_BIT_POSITION = 31;
    const int M_BIT_POSITION = 30;

    uint32_t entry;
    uint32_t bits_needed;

};

#endif // PAGETABLEENTRY_H
