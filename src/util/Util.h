#ifndef UTIL_H
#define UTIL_H

#include <chrono>

class Util
{
    public:
        static double getPreciseSecondTime()
        {   
            return (double) getMillisecondTime() / 1000;
        };

    private:
        static long getMillisecondTime()
        {
            using namespace std::chrono;

            auto now = system_clock::now();
            auto now_ms = time_point_cast<milliseconds>(now);
            auto epoch = now_ms.time_since_epoch();
            auto value = duration_cast<milliseconds>(epoch);
            
            return value.count();
        };
};

#endif
