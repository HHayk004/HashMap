#include <iostream>
#include "hash_map.h"

int main()
{
    HashMap<char, int> map;

    for (int i = 'a'; i <= 'z'; ++i)
    {
        map.insert({i, i - 'a'});
    }

    std::cout << map.containsKey('z') << std::endl;
    std::cout << map.containsKey('A') << std::endl;
    std::cout << map.containsValue(4) << std::endl;
    std::cout << map.containsValue(-1) << std::endl;

    return 0;
}
