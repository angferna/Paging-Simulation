// Andy Schiff, Angel Fernandes
// 6/8/2021
// Project 8

#include "PageTableEntry.h"

PageTableEntry::PageTableEntry(uint32_t bits_needed)
{
    
    this->bits_needed = bits_needed;
    entry = 0;
    
}

void PageTableEntry::set_present_bit(){
    
    //std::cout << "setting present bit \n";
    
    entry = entry | (1 << PRESENT_BIT_POSITION);
}

void PageTableEntry::clear_present_bit(){
    entry = entry & ~(1 << PRESENT_BIT_POSITION);
}

uint32_t PageTableEntry::get_present_bit(){
    
    uint32_t present_bit = entry & (1 << PRESENT_BIT_POSITION);
    present_bit = present_bit >> PRESENT_BIT_POSITION;
    
    return present_bit;
    
}
    
void PageTableEntry::set_r_bit(){
    entry = entry | (1 << R_BIT_POSITION);
}

void PageTableEntry::clear_r_bit(){
    entry = entry & ~(1 << R_BIT_POSITION);
}
uint32_t PageTableEntry::get_r_bit(){
    
    uint32_t r_bit = entry & (1 << R_BIT_POSITION);
    r_bit = r_bit >> R_BIT_POSITION;
    
    return r_bit;
    
}
  
void PageTableEntry::set_m_bit(){
    entry = entry | (1 << M_BIT_POSITION);
}

void PageTableEntry::clear_m_bit(){
    entry = entry & ~(1 << M_BIT_POSITION);
}

uint32_t PageTableEntry::get_m_bit(){
    
    uint32_t m_bit = entry & (1 << M_BIT_POSITION);
    m_bit = m_bit >> M_BIT_POSITION;
    
    return m_bit;
    
}

void PageTableEntry::set_frame_num(uint32_t num){
    
    entry = entry >> bits_needed;
    entry = entry << bits_needed;
    
    entry = entry | num;
    
}

uint32_t PageTableEntry::get_frame_num(){
    
    uint32_t frame_num = entry;
    frame_num = frame_num << (32 - bits_needed);
    frame_num = frame_num >> (32 - bits_needed);
    
    return frame_num;
    
}

void PageTableEntry::clear(){
    entry = 0;
}



