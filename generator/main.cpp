//
//  main.cpp
//  generator
//
//  Created by Jeffrey Drake on 12-01-07.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

std::vector<std::string> startConsonants, endConsonants, vowels;
std::unordered_map<std::string, std::string> assimilations;

void usage()
{
    std::cout << "Usage: generator [words] [syllableformat]" << std::endl 
    << "    where words          is the number of words to generator" << std::endl
    << "          syllableformat is the file containing the syllable rules" << std::endl;
    
}

int main(int argc, const char * argv[])
{
    // How many words do we want?
    unsigned long words = 0;
    std::string syllableFormat;
    
    if (argc == 3)
    {
        try {
            words = std::stoul(argv[1]);
            std::cout << "Generating " << words << " words." << std::endl;
            syllableFormat = std::string(argv[2]);
        } catch (std::invalid_argument)
        {
            std::cout << "No quantity of words could be found." << std::endl;
            usage();
            return 1;
        }
    }
    else
    {
        usage();
        return 1;
    }

    return 0;
}

