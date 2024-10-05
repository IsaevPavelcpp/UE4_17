
#include <iostream>

template <typename T>
class my_vector
{
    T* vec = new T[0];
    size_t size = 0;
public:
    T operator[] (const int& count)
            {
                return vec[count];
            };
    void my_push_back(const T &value)
    {
        T* vecBuf = new T[size+1];
        for(int i = 0; i < size; ++i)
        {
            vecBuf[i] = vec[i];
        }
        delete[] vec;
        vecBuf[size] = value;
        vec = vecBuf;
        size++;
    }
    void my_pop_back()
    {
        T* vecBuf = vec;
        size--;
        vec = new T[size];
        for(int i = 0; i < size; ++i)
        {
            vec[i] = vecBuf[i];
        }
        delete[]vecBuf;
    }

    T my_size()
    {
        return size;
    }
    ~my_vector()
    {
        delete[] vec;
    }
};

int main() {
    my_vector <int> my_int;
    for(int i = 0; i < 10; ++i )
    {
        my_int.my_push_back(i);
    }
    std::cout << "use push_back\n";
    for(int i = 0; i < my_int.my_size(); ++i)
    {
        std::cout << my_int[i] << " ";
    }
    my_int.my_pop_back();
    std::cout << "\nuse pop_back\n";
    for(int i = 0; i < my_int.my_size(); ++i)
    {
        std::cout << my_int[i] << " ";
    }
    std::cout << "\nuse push_back 22\n";
    my_int.my_push_back(22);
    for(int i = 0; i < my_int.my_size(); ++i)
    {
        std::cout << my_int[i] << " ";
    }
    return 0;
}
