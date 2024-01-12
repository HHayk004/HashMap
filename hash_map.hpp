#ifndef HASH_MAP_HPP
#define HASH_MAP_HPP

template <typename T, typename U>
HashMap<T, U>::HashMap()
{
    m_prime = {2, 3};
    m_vec.resize(m_prime.back());
}

template <typename T, typename U>
void HashMap<T, U>::insert(std::pair<T, U> elem)
{
    size_t index = hash(elem.first);

    m_vec[index].second.push_front(elem);
    ++m_vec[index].first;

    if (m_vec[index].first > m_vec.size())
    {
        rehash();
    }
}

template <typename T, typename U>
void HashMap<T, U>::rehash()
{
    std::vector<std::pair<size_t, std::forward_list<std::pair<T, U> > > > tmp;
    tmp.resize(nextSize());

    for (int i = 0; i < m_vec.size(); ++i)
    {
        for (auto it = m_vec[i].second.begin(); it != m_vec[i].second.end(); ++it)
        {
            size_t index = hash(it->first);

            tmp[index].second.push_front(*it);
            ++tmp[index].first;
        }
    }

    m_vec = std::move(tmp);
}

template <typename T, typename U>
U& HashMap<T, U>::get(T key)
{
    const size_t index = hash(key);

    for (auto it = m_vec[index].second.begin(); it != m_vec[index].second.end(); ++it)
    {
        if (it->first == key)
        {
            return it->second;
        }
    }

    std::cerr << "The element doesn't exist!\n";
    exit(1);
}

template <typename T, typename U>
size_t HashMap<T, U>::nextSize() const
{
    size_t num = m_prime.back() + 2;

    while (true)
    {
        size_t val = std::sqrt(num);

        bool check = true;
        for (int i = 0; i < m_prime.size() && m_prime[i] <= val; ++i)
        {
            if (num % m_prime[i] == 0)
            {
                check = false;
                break;
            }
        }

        if (check)
        {
            break;
        }

        num += 2;
    }

    return num;
}

template <typename T, typename U>
size_t HashMap<T, U>::hash(T key) const
{
    return static_cast<size_t>(key) % m_vec.size(); 
}

template <typename T, typename U>
size_t HashMap<T, U>::hash(std::string str) const
{
    const size_t prime_const = 31; // can be any number
    size_t result = 0;
    for(int i = 0; i < str.size(); ++i)
    {
        result += str[i] * pow(prime_const, i);
    }

    return result % m_vec.size();
}

template <typename T, typename U>
size_t HashMap<T, U>::size() const
{
    size_t result = 0;
    for (int i = 0; i < m_vec.size(); ++i)
    {
        result += m_vec[i].first;
    }

    return result;
}

template <typename T, typename U>
bool HashMap<T, U>::empty() const
{
    for (int i = 0; i < m_vec.size(); ++i)
    {
        if (m_vec[i].first)
        {
            return true;
        }
    }
 
    return false;
}

template <typename T, typename U>
bool HashMap<T, U>::containsKey(T key) const
{
    size_t index = hash(key);

    for (auto it = m_vec[index].second.begin(); it != m_vec[index].second.end(); ++it)
    {
        if (it->first == key)
        {
            return true;
        }
    }

    return false;
}

template <typename T, typename U>
bool HashMap<T, U>::containsValue(U val) const
{
    for (int i = 0; i < m_vec.size(); ++i)
    {
        for (auto it = m_vec[i].second.begin(); it != m_vec[i].second.end(); ++it)
        {
            if (it->second == val)
            {
                return true;
            }
        }
    }

    return false;
}
    
#endif
