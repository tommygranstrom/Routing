#include <TTime.h>

class Dest
{
    public:
        Dest(int id,TTime goT,TTime aT):id(id),goTime(goT),arrTime(aT){};
        int id;
        TTime goTime;
        TTime arrTime;
};