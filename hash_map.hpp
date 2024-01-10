template <typename T, typename U>
void HashMap<T, U>::nextSize()
{
    size_t num = m_prime.back() + 2;
    while (true)
    {
        size_t val = std::sqrt(num);

        check = true;
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
HashMap<T, U>::HashMap()
{
    m_prime = {7};
    m_vec.reserve(m_prime.back());
}
