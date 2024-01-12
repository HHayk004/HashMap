#include <iostream>
#include "hash_map.h"

int main()
{
    HashMap<char, int> map;

    for (int i = 'a'; i <= 'z'; ++i)
    {
        map.insert({i, i - 'a'});
    }

    for (int i = 'a'; i <= 'z'; ++i)
    {
        map.insert({i, 'a' - i});
    }

    std::vector<char> keys = map.keys();
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

    std::vector<std::pair<char, int> > pairs = map.pairs();
    
    for (int i = 0; i < pairs.size(); ++i)
    {
        std::cout << '{' << pairs[i].first << ", " << pairs[i].second << "} ";
    }
    std::cout << std::endl;

    return 0;
}
