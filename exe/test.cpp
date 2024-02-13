#include <iostream>
#include "cppargs.h"

int main(int argc, char** argv) {
    auto parser = ArgumentParser(argc, argv).setDescription("The mighty thereshold scanner");
    parser.add_argument("rawdata").metavar("FILENAME").help("raw data file to be processed").add_finish();
    parser.add_argument("--bins").add_minor_argument("-b").type("int").add_domain({"1", "2", "4", "8", "16", "32"}).help("bin size").set_default("1").add_finish();
    parser.add_argument("--max").add_minor_argument("-M").type("int").help("color scale limit").add_finish();
    parser.add_argument("--path").help("Output plots path").set_default(".").add_finish();
    parser.add_argument("--dump-raw-hits").help("Dump hit pixel addresses for each event to file").set_default("true").add_finish();
    parser.add_argument("--dump-acc-hits").help("Dump hit pixel addresses sorted by frequency to file").set_default("true").add_finish();
    parser.parse_args();
    
    return 0;
}