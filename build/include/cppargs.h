#ifndef __CPPARGS_H__
#define __CPPARGS_H__

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <map>
#include <cctype> // For isalpha() and isdigit()
#include <sstream>
#include <regex>
#include <exception>
#include <algorithm>

enum ActionType {
    ACTION_NONE,
    ACTION_STORE,
    ACTION_STORE_CONST,
    ACTION_STORE_TRUE,
    ACTION_STORE_FALSE,
    ACTION_APPEND,
    ACTION_APPEND_CONST,
    ACTION_COUNT,
    ACTION_HELP,
    ACTION_VERSION,
    ACTION_PARSERS,
    ACTION_EXTEND
};

class HelpMessage {
private: 
    std::string usage;
public:
    HelpMessage(std::string prog, std::string description);
    void positional_args();
    void optional_args(); 
};

class ArgumentParser {
private:
    char** argv;                                    //
    std::string prog = "";                      // The name of the program (default: argv[0])   
    std::string description = "";               // A description of what the program does                         // Allow long options to be abbreviated unambiguously
public:
    ArgumentParser(char** _argv);

    // Setter
    ArgumentParser& setDescription(std::string _description) { description = _description; return *this; }    
    ArgumentParser& init();

    void add_argument(const std::string& str, ...);
};


#endif