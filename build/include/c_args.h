#ifndef __C_ARGS_H__
#define __C_ARGS_H__

#include <string>
#include <typeinfo>
#include <unordered_map>
#include <cctype> // For isalpha() and isdigit()
#include <sstream>
#include <regex>
#include <exception>
#include <algorithm>

const std::string SUPPRESS = "==SUPPRESS==";
const std::string OPTIONAL = "?";
const std::string ZERO_OR_MORE = "*";
const std::string ONE_OR_MORE = "+";
const std::string PARSER = "A...";
const std::string REMAINDER = "...";
const std::string _UNRECOGNIZED_ARGS_ATTR = "_unrecognized_args";



bool isIdentifier(const std::string& str) {
    if (str.empty() || !isalpha(str[0]) && str[0] != '_') {
        return false; // Doesn't start with a letter or underscore
    }
    
    for (char c : str) {
        if (!isalnum(c) && c != '_') {
            return false; // Contains invalid characters
        }
    }
    
    return true;
}


class _AttributeHolder {
private:
    std::unordered_map<std::string, std::string> attributes;
public:
    std::string repr() {
        std::string type_name = typeid(*this).name();
        std::vector<std::string> arg_strings;
        std::unordered_map<std::string,std::string> star_args;
        for (const auto& arg : get_args()) {
            arg_strings.push_back(arg);
        }

        for (const auto& pair : get_kwargs()) {
            if (isIdentifier(pair.first) == true) {
                arg_strings.push_back(pair.first+"="+pair.second);
            } else {
                star_args[pair.first] = pair.second;
            }
        }

        if (!star_args.empty()) {

        }
        std::ostringstream returnStr;
        returnStr << type_name << "(";
        int i = 0;
        for (const auto& str : arg_strings) {
            if (i != 0) {
                returnStr << ", ";
            }
            returnStr << str;
            i++;
        }
        return returnStr.str();
    }

    virtual std::vector<std::string> get_args() {
        return std::vector<std::string>();
    }

    virtual std::vector<std::pair<std::string, std::string>> get_kwargs() {
        std::vector<std::pair<std::string, std::string>> kwargs;
        for (const auto& pair : attributes) {
            kwargs.emplace_back(pair.first, pair.second);
        }
        return kwargs;
    }
};

// template<typename T>
// std::vector<T> _copy_items(const T& items) {
//     if (items.empty()) {
//         return std::vector<T>();
//     }
//     if (typeid(items) == typeid(std::vector<typename T::value_type>)) {
//         return items; // Shallow copy
//     }
//     return std::vector<T>(items.begin(), items.end()); // Shallow copy
// }

// // Formatting Help

// class _Section {
// private:
//     HelpFormatter& formatter;
//     _Section* parent;
//     std::string heading;
//     std::vector<std::string> items;
// public:
//     _Section(HelpFormatter& formatter, _Section* parent, std::string heading = "") 
//     : formatter(formatter), parent(parent), heading(heading) {}
//     std::string format_help() {
//         if ( parent != nullptr  ) { formatter._indent(); }
//         // join = self.formatter._join_parts 없음
//         std::string item_help;
//             for (auto& item : items)
//                 item_help += item;
            
//             if (parent != nullptr)
//                 formatter._dedent();


        
//         return "dd";
//     }
// };

// class HelpFormatter {
// private:
//     std::string _prog;
//     int _indent_increment;
//     int _max_help_position; 
//     int _width;

//     int _current_indent = 0;
//     int _level = 0;
//     int _action_max_length = 0;

//     _Section* _root_section;
//     _Section* _current_section;

//     std::string _whitespace_matcher;
//     std::string _long_break_matcher;
// public:
//     HelpFormatter(std::string prog, int indent_increment = 2, int max_help_position = 24, int width = NULL) 
//     : _prog(prog), _indent_increment(indent_increment), _width(width)
//     {
//         _max_help_position = std::min(max_help_position, std::max(width - 20, indent_increment * 2));
//         _root_section = new _Section(NULL,NULL,NULL);
//         _current_section = _root_section;
//         _whitespace_matcher = _re.compile(r'\s+', _re.ASCII);
//         _long_break_matcher = _re.compile(r'\n\n\n+');
//     }
//     void _indent() {
//         _current_indent += _indent_increment;
//         _level++;
//     }
//     void _dedent() {
//         _current_indent -= _indent_increment;
//         assert(_current_indent >= 0);
//         _level--;
//     }

    

//     void _add_item(std::string func, std::string args) {
//     } // 구축 필요

//     void start_section();

//     void end_section();

//     void add_text();

//     void add_usage();

//     void add_argument();

//     void add_arguments();

//     void format_help();

//     std::string _join_parts() {

//     }

//     void _format_usage();

//     void _format_actions_usage();

//     void _format_text();

//     void _format_action();

//     void _format_action_invocation();

//     void _metaver_formatter();

//     void _format_args();

//     void _expand_help();

//     void _iter_indented_subactions();

//     void _split_lines();

//     void _fill_text();

//     void _get_help_string();

//     void _get_default_metaver_for_optional();

//     void _get_default_metaver_for_positional();

// };

// class RawDescriptionHelpFormatter {};

// class RawTextHelpFormatter {};

// class ArgumentDefaultsHelpFormatter {};

// class MetavarTypeHelpFormatter {};

// // Options and Arguments

// std::string _get_action_name();

// class ArgumentError : public std::exception {};

// class ArgumentTypeError : public std::exception {};

// // Action classes

// class Action : public _AttributeHolder {};

// class BooleanOptionalAction : public Action {};

// class _StoreAction : public Action {};

// class _StoreConstAction : public Action {};

// class _StoreTrueAction : public _StoreConstAction {};

// class _Store_FalseAction : public _StoreConstAction {};

// class _AppendAction : public Action {};

// class _AppendConstAction : public Action {};

// class _CountAction : public Action {};

// class _HelpAction : public Action {};

// class _VersionAction : public Action {};

// class SubParsersAction : public Action {};

// class _ExtendAction : public _AppendAction {};

// // Type classes

// class FileType {};

// // Optional and Positional Parsing

// class Namespace : public _AttributeHolder {};

class _ActionsContainer {
private:
    std::string description;
    std::string prefix_chars;
    std::string argument_default;
    std::string conflict_handler;

    // set up registries
    std::unordered_map<std::string, std::string> _registries;

    // action storage
    std::vector<std::string> _actions;
    std::unordered_map<std::string, std::string> _option_string_actions;

    // groups
    std::vector<std::string> _action_groups;
    std::vector<std::string> _mutually_exclusive_groups;

    // defult storage
    std::unordered_map<std::string, std::string> _defualts;

    std::regex *_negative_number_matcher;

    std::vector<std::string> _has_negative_number_optionals;
public:
    _ActionsContainer() {}
    _ActionsContainer(std::string _description,
                      std::string _prefix_chars,
                      std::string _argument_default,
                      std::string _conflict_handler) 
    :
    description(_description),
    prefix_chars(_prefix_chars),
    argument_default(_argument_default),
    conflict_handler(_conflict_handler) {
    
    // Register('actin', NULL, _StoreAction);
    /*
    register action 정의 및 _get_handler 함수 호출해야함
    */

    _negative_number_matcher = new std::regex("^-\\d+$|^-\d*\\.\\d+$");

    }
    void Register(std::string registry_name, std::string value, std::string object) {
        // _registries
    }
};

// class _ArgumentGroup : public _ActionsContainer {};

// class _MutuallyExclusiveGroup : public _ArgumentGroup {};

class ArgumentParser : public _AttributeHolder, public _ActionsContainer {
private:
    std::string prog; 
    std::string usage;
    std::string description;
    std::string pilog;
    std::string parents;
    std::string formatter_class;
    std::string prefix_chars;
    std::string fromfile_prefix_chars;
    std::string argument_default;
    std::string conflict_handler;
    std::string add_help;
    std::string allow_abbrev;
    std::string exit_on_error;
public:
    ArgumentParser(std::string _prog, 
                   std::string _usage, 
                   std::string _description,
                   std::string _pilog,
                   std::string _parents,
                   std::string _formatter_class,
                   std::string _prefix_chars,
                   std::string _fromfile_prefix_chars,
                   std::string _argument_default,
                   std::string _conflict_handler,
                   std::string _add_help,
                   std::string _allow_abbrev,
                   std::string _exit_on_error) 
    : 
    prog(_prog), 
    usage(_usage), 
    description(_description),
    pilog(_pilog),
    parents(_parents),
    formatter_class(_formatter_class),
    prefix_chars(_prefix_chars),
    fromfile_prefix_chars(_fromfile_prefix_chars),
    argument_default(_argument_default),
    conflict_handler(_conflict_handler),
    add_help(_add_help),
    allow_abbrev(_allow_abbrev),
    exit_on_error(_exit_on_error) {}

    
    // superinit = super(ArgumentParser, self).__init__
    // superinit(description=description,
    //             prefix_chars=prefix_chars,
    //             argument_default=argument_default,
    //             conflict_handler=conflict_handler)

    // register types              
    // std::string identify(std::string str) { return str; }


};


#endif