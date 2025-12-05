#include <iostream>
#include <ctime>
using namespace std;

int main() {
    time_t now = time(0); 

    tm* local_tm = localtime(&now);
    std::cout << "Year: " << local_tm->tm_year + 1900 << std::endl; // tm_year is years since 1900
    std::cout << "Month: " << local_tm->tm_mon + 1 << std::endl; // tm_mon is 0-indexed (0 for January)
    std::cout << "Day: " << local_tm->tm_mday << std::endl;
    std::cout << "Hour: " << local_tm->tm_hour << std::endl;
    std::cout << "Minute: " << local_tm->tm_min << std::endl;
    std::cout << "Second: " << local_tm->tm_sec << std::endl;
}