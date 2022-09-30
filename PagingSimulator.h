// Andy Schiff, Angel Fernandes
// 6/8/2021
// Project 8

#ifndef PAGINGSIMULATOR_H
#define PAGINGSIMULATOR_H

#include <string>
#include <stdint.h>
#include <fstream>
#include <sstream>

#include "Process.h"

class PagingSimulator
{
public:
    PagingSimulator(std::string file_name);
    
    void run();
    
private:
    int page_count;
    int frame_count;
    int page_size;
    int process_count;
    std::vector<Process> processes;
    std::vector<bool> frames;
    std::ifstream input;
    
    void print_table(Process p, int process_num);
    void print();
    void evict_page(Process p, int process_num, int page_num);
    void load_page(Process p, int process_num, int page_num);
    void sim_reference(Process p, int process_num, std::string ref_type, int mem_location);
    

};

#endif // PAGINGSIMULATOR_H
