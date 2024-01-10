#ifndef HASH_MAP_H
	#define HASH_MAP_H
    
    #include <utility>
    #include <cmath>
    #include <vector>
    #include <forward_list>

    template <typename T, typename U>
    class HashMap {
        private:
            size_t nextSize();

            std::vector<size_t> m_size;
            std::vector<std::forward_list< std::pair<T, U> >* > m_vec;

        public:
            HashMap();
    }
	
    #include "hash_map.hpp"

#endif
