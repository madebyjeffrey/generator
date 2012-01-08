//
//  main.cpp
//  generator
//
//  Created by Jeffrey Drake on 12-01-07.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

#include <boost/tokenizer.hpp>

std::vector<std::string> startConsonants, endConsonants, vowels;
std::unordered_map<std::string, std::string> assimilations;

std::hash<std::string> checksum;

void usage()
{
    std::cout << "Usage: generator [words] [syllableformat]" << std::endl 
    << "    where words          is the number of words to generator" << std::endl
    << "          syllableformat is the file containing the syllable rules" << std::endl;
    
}

bool loadDataFile(const std::string &filename)
{
    std::ifstream input(filename);
    std::string temp;
    
    size_t sectionStartConsonants = checksum("<<StartConsonants");
    size_t sectionEndConsonants = checksum("<<EndConsonants");
    size_t sectionVowels = checksum("<<Vowels");
    size_t sectionAssimilations = checksum("<<Assimilations");
    size_t sectionSyllableOrder = checksum("<<SyllableOrder");
    size_t sectionEnd = checksum("<<End");

    if (input.is_open())
    {
        while(1)
        {
            std::getline(input, temp);

            size_t section = checksum(temp);
        
            if (section == sectionStartConsonants)
            {
                std::cout << "Section Start Consonants" << std::endl;
                std::string inputSet;
                std::getline(input, inputSet, '<');
                input.putback('<');
                
                boost::char_separator<char> sep(" \t\n");
                boost::tokenizer<boost::char_separator<char>> tokens(inputSet, sep);
                
                std::copy(begin(tokens), end(tokens), std::back_inserter(startConsonants));
            }
            else if (section == sectionEndConsonants)
            {
                std::cout << "Section End Consonants" << std::endl;
                std::string inputSet;
                std::getline(input, inputSet, '<');
                input.putback('<');
                
                boost::char_separator<char> sep(" \t\n");
                boost::tokenizer<boost::char_separator<char>> tokens(inputSet, sep);
                
                std::copy(begin(tokens), end(tokens), std::back_inserter(endConsonants));
            }
            else if (section == sectionVowels)
            {
                std::cout << "Section Vowels" << std::endl;
                std::string inputSet;
                std::getline(input, inputSet, '<');
                input.putback('<');
                
                boost::char_separator<char> sep(" \t\n");
                boost::tokenizer<boost::char_separator<char>> tokens(inputSet, sep);
                
                std::copy(begin(tokens), end(tokens), std::back_inserter(vowels));
            }
            else if (section == sectionAssimilations)
            {
                std::cout << "Section Vowels" << std::endl;
                std::string inputSet;
                std::getline(input, inputSet, '<');
                input.putback('<');
                
                boost::char_separator<char> sep(" \t\n");
                boost::tokenizer<boost::char_separator<char>> tokens(inputSet, sep);

                for (auto i = begin(tokens); i < end(tokens); i++)
                {
                    auto first = *i; 
                    auto second =
                }
            }
            else
            {
                std::cout << "End of Input" << std::endl;
            }
    }
    else {
        std::cout << "File not open." << std::endl;
        return false;
    }
    
    return false;
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

    loadDataFile(syllableFormat);
    return 0;
}

