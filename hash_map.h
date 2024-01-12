#ifndef HASH_MAP_H
	#define HASH_MAP_H
    
    #include <utility>
    #include <cmath>
    #include <vector>
    #include <forward_list>

    template <typename T, typename U>
    class HashMap {
        private:
            size_t nextSize() const;

            std::vector<size_t> m_prime;
            std::vector<std::pair<size_t, std::forward_list< std::pair<T, U> > > > m_vec; // first element is size of list

        private:
            size_t hash(T key) const;
            size_t hash(std::string str) const;

        public:
            HashMap();
            ~HashMap() = default;

            void insert(std::pair<T, U>);
            void rehash();

            U& get(T key);

            size_t size() const;
            
            bool empty() const;
    
            bool containsKey(T key) const;
            bool containsValue(U val) const;
    };
	
    #include "hash_map.hpp"

#endif
