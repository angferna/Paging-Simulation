// Andy Schiff, Angel Fernandes
// 6/8/2021
// Project 8

#include "PagingSimulator.h"

PagingSimulator::PagingSimulator(std::string file_name)
{

    input.open(file_name);
    
    input >> page_count;
    input >> frame_count;
    input >> page_size;
    
    for(int i = 0; i < frame_count; i++){
        frames.push_back(false);
    }
    
    
    input >> process_count;
 
}

void PagingSimulator::print_table(Process p, int process_num){
    
    std::cout << "Process " << process_num << "\n";
    std::cout << "page#\tR\tM\tP\tframe#\taging\n";
    
    for(int i = 0; i < page_count; i++){
        
        std::cout << i << ":\t" << processes.at(process_num).table.at(i).get_r_bit() << "\t" << processes.at(process_num).table.at(i).get_m_bit() << "\t" << processes.at(process_num).table.at(i).get_present_bit() << "\t";
    
        if(processes.at(process_num).table.at(i).get_present_bit() == 0){
            std::cout << "-\n";
        }else{
            std::cout << processes.at(process_num).table.at(i).get_frame_num() << "\t";
            processes.at(process_num).counters.at(i).print();
        }
    
    }
    
     std::cout << "\n";
    
}

void PagingSimulator::evict_page(Process p, int process_num, int page_num){
    
    int lowest = -1;
    
    for(int i = 0; i < page_count; i++){
        if(processes.at(process_num).table.at(i).get_present_bit() == 1 && (lowest == -1 
        || processes.at(process_num).counters.at(lowest).get_value() > processes.at(process_num).counters.at(i).get_value()
        || (processes.at(process_num).counters.at(lowest).get_value() == processes.at(process_num).counters.at(i).get_value() 
        && processes.at(process_num).table.at(page_num).get_m_bit() == 1))){
            lowest = i;
        }
    }
    
    std::cout << "Evicting process " << process_num << " page " << page_num << "\n";

    frames.at(processes.at(process_num).table.at(lowest).get_frame_num()) = false;
    processes.at(process_num).table.at(lowest).clear_present_bit();
    processes.at(process_num).table.at(lowest).clear_r_bit();
    processes.at(process_num).table.at(lowest).clear_m_bit();
    
}

void PagingSimulator::load_page(Process p, int process_num, int page_num){
    
    bool full = true;
    
    for(int i = 0; i < frame_count; i++){
        if(!frames.at(i)){
            full = false;
            break;
        }
    }
    
    if(full){
        evict_page(p, process_num, page_num);
    }
    
    for(int i = 0; i < frame_count; i++){
        if(!frames.at(i)){
            processes.at(process_num).table.at(page_num).set_frame_num(i);
            processes.at(process_num).table.at(page_num).set_present_bit();
            processes.at(process_num).counters.at(page_num).reset();
            
            frames.at(i) = true;
            
            std::cout << "Loading page " << page_num << " of process " << process_num << " into frame " << i << "\n";
            break;
        }
    }
    
}

void PagingSimulator::sim_reference(Process p, int process_num, std::string ref_type, int mem_location){
    
    std::cout << "Process " << process_num << " requests " << ref_type << " " << mem_location << "\n";
    
    int page_num = mem_location/page_size;
    
    std::cout << "Page number: " << page_num << "\n";
    
    if(processes.at(process_num).table.at(page_num).get_present_bit() == 0){
        
        std::cout << "Page fault ...\n";
        load_page(p, process_num, page_num);
        
    }
    
    processes.at(process_num).table.at(page_num).set_r_bit();
    
    if(ref_type.compare("w") == 0)
    {
        processes.at(process_num).table.at(page_num).set_m_bit();
    }

    std::cout << "Frame number: " << processes.at(process_num).table.at(page_num).get_frame_num() << "\n";
    
    int address = (processes.at(process_num).table.at(page_num).get_frame_num() * page_size) + (mem_location - (page_num * page_size));
    std::cout << "Physical address: " << address << "\n";
    
}

void PagingSimulator::run(){
    
    std::string line;
    std::getline(input, line);
    
    for(int i = 0; i < process_count; i++){
        processes.push_back(Process(page_count, frame_count));
    }
    
    std::cout << "INITIAL TABLE SETUP:\n";
    std::cout << "Virtual Memory Size: " << (page_count * page_size) << "\n";
    std::cout << "Physical Memory Size: " << (frame_count * page_size) << "\n";
    std::cout << "Page Size: " << page_size << "\n";
    std::cout << "Number of Pages: " << page_count << "\n";
    std::cout << "Number of Frames: " << frame_count << "\n";
    
    for(int i = 0; i < process_count; i++){
        print_table(processes.at(i), i);
    }
    
    int age = 0;
 
    while(std::getline(input, line)){
        
        std::istringstream stream(line);
        
        std::string word;
        std::string words[3];
        
        int i = 0;
        while(stream >> word){
            
            words[i] = word;
            
            i++;
            
        }
      
        int process_num = std::stoi(words[0]);
        int mem_location = std::stoi(words[2]);
        
        sim_reference(processes.at(process_num), process_num, words[1], mem_location);
        
        for(int i = 0; i < process_count; i++){
            print_table(processes.at(i), i);
        }
        
        if(age == 0){
            age++;
        }else{
            
            std::cout << "\nAging the counters ...\n\n";
            
            processes.at(process_num).age();
            age = 0;
            
        }
        
    }
    
}


