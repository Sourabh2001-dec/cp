#include <iostream>
#include <thread>

struct F
{
    void operator()() const
    {
        std::cout << "Printing from another thread" << std::endl;
    }
};

int main()
{
    F f;
    std::thread t(f);
    t.join();

    return 0;
}