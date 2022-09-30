// Andy Schiff, Angel Fernandes
// 6/8/2021
//Project 8

#ifndef COUNTER_H
#define COUNTER_H

#include <stdint.h>
#include <bitset>
#include <iostream>

class Counter
{
public:
    Counter();
    
    void increment();
    void shift();
    void reset();
    uint8_t get_value();
    void print();
    
private:
    uint8_t value;
    
    const int INCREMENT_POSITION = 7;

};

#endif // COUNTER_H
