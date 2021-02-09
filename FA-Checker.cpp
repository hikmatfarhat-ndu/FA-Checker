
#include <iostream>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <boost/container_hash/hash.hpp>
#include "FA.h"
#include "utils.h"
bool debug=false;
int main(int argc,char **argv)
{
    FA nfa;
    if (argc < 3) {
        std::cout << "Usage FA-checker NFA-description Tests\n";
        exit(1);
    }
    if (argc == 4) {
        debug = true;
    }
    try {
        nfa=parse_fa(argv[1]);
    }
    catch (invalid_spec& e) {
        std::cout << e.what()<<"\n";
    }
    catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }
    
    nfa.debug();
    try {
        float total = 0;
        auto tests= parse_tests(argv[2]);
        for (auto& [a, b, c] : tests) {

            bool r = nfa.accept(a);
            if (r == b) {
                std::cout << success("input " + a + " passed. Points=")<<c << "\n";
                total += c;
            }
            else {
                std::cout << fail("input " + a + " failed expecting ") <<
                    std::boolalpha<<b<<" got "<<r<<"\n";
            }
        }
        std::cout << "total=" << total << "\n";
    }
    catch (invalid_spec& e) {
        std::cout << e.what() << "\n";
    }
    catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }
    std::cout << "checker done\n";
    
    /*if (auto n = readFA(argv[1]) ) {
        
        FA nfa = *n;
        if (debug) {
            std::cout << "checking \n";
            nfa.debug();
        }
        if (auto t = readTests(argv[2])) {
            std::vector<std::tuple<std::string, bool,std::string>> v = *t;
            int count = 1;
            for (auto& [a, b,c] : v) {
                bool r = nfa.accept(a);
                if (r == b)std::cout << "\x1B[32mcheck " << count
                <<" passed \033[0m "<<c<<" / "<<c<<"\n";
                else {
                    std::cout << "\x1B[31mcheck "<<count
                        <<" failed \033[0m "<<0<<" / "<<c<<" ";
                    std::cout << " Input:" << a
                        << " Expected: " << b<< " Result:" << r << std::endl;
                }
                ++count;
            }
        }
       
    }
    else {
        std::cout << "\x1B[31mcheck ALL failed \033[0m 0 / 10 could not read input\n";
        exit(1);
    }*/
}
