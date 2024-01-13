#include <iostream>
#include "hash_map.h"

int main()
{
    HashMap<std::string, int> map;

    for (int i = 'a'; i <= 'z'; ++i)
    {
        std::string str = "letter-";
        str += i;
        map.insert({str, i - 'a'});
    }

    std::vector<std::string> keys = map.keys();
    for (int i = 0; i < keys.size(); ++i)
    {
        std::cout << keys[i] << ' ';
    }
    std::cout << std::endl;

    std::vector<int> values = map.values();
    
    for (int i = 0; i < values.size(); ++i)
    {
        std::cout << values[i] << ' ';
    }
    std::cout << std::endl;

    std::vector<std::pair<std::string, int> > pairs = map.pairs();
    
    for (int i = 0; i < pairs.size(); ++i)
    {
        std::cout << '{' << pairs[i].first << ", " << pairs[i].second << "} ";
    }
    std::cout << std::endl;

    return 0;
}
