// Andy Schiff, Angel Fernandes
// 6/8/2021
// Project 8

#include "Counter.h"

Counter::Counter()
{
    value = 0;
}

void Counter::increment(){
    
    shift();
    value = value | (1 << INCREMENT_POSITION);

}

void Counter::shift(){
    value = value >> 1;
}

void Counter::reset(){
    value = 0;
}

uint8_t Counter::get_value(){
    return value;
}

void Counter::print(){
    
    std::bitset<8> bin{value};
    std::cout << bin << "\n";
    
}

