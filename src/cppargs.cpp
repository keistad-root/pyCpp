#include "cppargs.h"
// HelpMessage class
HelpMessage::HelpMessage(std::string prog, std::string description) {
}

// Argument class
    Argument::Argument(std::string str) : _argOpt(str) {}

    void Argument::setArgType(ARGTYPES typ) {
        _argType = typ;
    }

    void Argument::setArgValue(std::string str) {
        _argValueList.push_back(str);
    }

    void Argument::setArgValueList(std::vector<std::string> strList) {
        _argValueList.reserve(_argValueList.size() + strList.size());
        _argValueList.insert(_argValueList.end(), strList.begin(), strList.end());
    }

    void Argument::setArgDomain(std::string str) {
        _argDomain.push_back(str);
    }

    void Argument::setArgDomain(std::vector<std::string> strList) {
        _argDomain.reserve(_argDomain.size() + strList.size());
        _argDomain.insert(_argDomain.end(), strList.begin(), strList.end());
    }

    void Argument::setArgName(std::string str) {
        _argName = str;
    }

    void Argument::setArgOpt(std::string str) {
        _argOpt = str;
    }

    void Argument::setArgMinorOpt(std::string str) {
        _argMinorOpt.push_back(str);
    }

    void Argument::setArgMinorOpt(std::vector<std::string> strList) {
        _argMinorOpt.reserve(_argMinorOpt.size() + strList.size());
        _argMinorOpt.insert(_argMinorOpt.end(), strList.begin(), strList.end());
    }

    void Argument::setArgDenoteOut(std::string str) {
        _argDenoteOut = str;
    }

    void Argument::setArgDenoteIn(std::string str) {
        _argDenoteIn = str;
    }

    void Argument::setArgDescription(std::string description) {
        _description = description;
    }

    void Argument::isArgMulti() {
        _isArgMulti = true;
    }

    void Argument::notArgMulti() {
        _isArgMulti = false;   
    }

    void Argument::isArgConst() {
        _isArgConst = true;
    }

    void Argument::notArgConst() {
        _isArgConst = false;
    }

    ARGTYPES Argument::getArgType() const {
        return _argType;
    }

    std::string Argument::getArgValue(const int order) const {
        return _argValueList[order];
    }

    std::vector<std::string> Argument::getArgValueList() const {
        return _argValueList;
    }

    std::string Argument::getArgDomain(const int order) const {
        return _argDomain[order];
    }

    std::vector<std::string> Argument::getArgDomain() const {
        return _argDomain;
    }

    std::string Argument::getArgName() const {
        return _argName;
    }

    std::string Argument::getArgOpt() const {
        return _argOpt;
    }

    std::vector<std::string> Argument::getArgMinorOpt() const {
        return _argMinorOpt;
    }

    std::string Argument::getArgDenoteOut() const {
        return _argDenoteOut;
    }

    std::string Argument::getArgDenoteIn() const {
        return _argDenoteIn;
    }

    std::string Argument::getArgDescription() const {
        return _description;
    }

    bool Argument::getArgMulti() const {
        return _isArgMulti;
    }

    bool Argument::getArgConst() const {
    return _isArgConst;
}

// ArgumentParser class
ArgumentParser::ArgumentParser(int _argc, char** _argv) {
    for (int arg = 0; arg < _argc; arg++) {
        argv.push_back(_argv[arg]);
    }
    std::string key = "Positional";
    std::vector<std::string> temp_value;

    bool onlyPositional = true;

    for (std::string arg : argv) {
        if (arg[0] != '-' && arg[0] != '.') {
            temp_value.push_back(arg);
        }
        
        if (arg[0] == '-') {
            argv_init.insert({key,temp_value});
            key = arg;
            temp_value.clear();
        }
        if ( arg == argv.back() && onlyPositional ) {
            argv_init.insert({key,temp_value});
        }
    }
}

ArgumentParser::~ArgumentParser() {}

ArgumentParser& ArgumentParser::add_argument(const std::string& opts) {
    args_temp = new Argument(opts);
    std::string name;
    for (int i = 0; i < opts.length(); i++) {
        if (opts[i] != '-') {
            name = opts.substr(i,opts.length()-1);
            break;
        }
    }
    args_temp->setArgDenoteIn(name);
    args_temp->setArgDenoteOut(opts);
    return *this;
}

ArgumentParser& ArgumentParser::add_minor_argument(const std::string& opts) {
    args_temp->setArgMinorOpt(opts);
    return *this;
}

ArgumentParser& ArgumentParser::add_domain(const std::vector<std::string>& opts) {
    args_temp->setArgDomain(opts);
    return *this;
}

ArgumentParser& ArgumentParser::dest(const std::string& str) {
    args_temp->setArgDenoteIn(str);
    return *this;
}

ArgumentParser& ArgumentParser::metavar(const std::string& str) {
    args_temp->setArgDenoteOut(str);
    return *this;
}

ArgumentParser& ArgumentParser::set_const() {
    args_temp->isArgConst();
    return *this;
}

ArgumentParser& ArgumentParser::nargs() {
    args_temp->isArgMulti();
    return *this;
}

ArgumentParser& ArgumentParser::type(std::string typeOpt) {
    ARGTYPES argType;
    if (typeOpt == "int") {
        argType = ARGTYPES::INT;
    } else if (typeOpt == "double") { 
        argType = ARGTYPES::DOUBLE;
    } else if (typeOpt == "bool") {
        argType = ARGTYPES::BOOL;
    } else if (typeOpt == "string") {
        argType = ARGTYPES::STRING;
    } else {
        argType = ARGTYPES::NONE;
        std::cout << "NO TYPE WARNING (SET TO ARBITRARY TYPE)" << std::endl;
    }
    args_temp->setArgType(argType);
    return *this;
}

ArgumentParser& ArgumentParser::help(std::string message) {
    args_temp->setArgDescription(message);
    return *this;
}

ArgumentParser& ArgumentParser::set_default(std::string value) {
    args_temp->setArgValue(value);
    return *this;
}

void ArgumentParser::add_finish() {
    Argument* args_add = args_temp;
    args_add->getArgOpt()[0] == '-' ? Opt_args.push_back(*args_add) : Pos_args.push_back(*args_add);
    args_temp = nullptr;
}

void ArgumentParser::parse_args() {
    if ( Pos_args.size() > argv_init["Positional"].size()) {
        std::cout << "ERROR: Not enough required arguments." << std::endl;
        exit(0);
    }
    int numOfMulti = 0;
    for (Argument pos : Pos_args) {
        if (pos.getArgMulti()) {
            numOfMulti++;
        }
    }
    if (numOfMulti > 2 || (numOfMulti == 1 && !Pos_args.back().getArgMulti())) {
        std::cout << "Cannot classify that the arguments are belong to group" << std::endl;
        exit(0);
    }

    for (std::pair<std::string,std::vector<std::string>> argv : argv_init) {
        if (argv.first == "Positional") continue;
        bool isArguExist = false;
        for (Argument opt : Opt_args) {
            if ( opt.getArgOpt() == argv.first) 
                {
                    isArguExist = true;
                    break;
                }
        }
        if (!isArguExist) {
            std::cout << "Undefined argument" << std::endl;
            exit(0);
        }
    }


    // for (std::pair<std::string,std::vector<std::string>> argv : argv_init) {
    //     std::cout << argv.first;
    //     for (std::string arg : argv.second) {
    //         std::cout << " " << arg;
    //     }
    //     std::cout << std::endl;
    // }
}
template<typename T>
T ArgumentParser::get_value(const std::string& valueName) const {
    int temp = 0;
    return temp;
}