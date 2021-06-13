#include <TTime.h>

class Dest
{
    public:
        Dest(int id,TTime goT,TTime aT):id(id),goTime(goT),arrTime(aT){};
        int id;
        TTime goTime;
        TTime arrTime;
        bool operator<(const Dest& rhs) const;
        std::string getGoStr(){return std::to_string(goTime.date)+":"+std::to_string(goTime.hour)+":"+std::to_string(goTime.minute)+":"+std::to_string(goTime.second);};
        std::string getArrStr(){return std::to_string(arrTime.date)+":"+std::to_string(arrTime.hour)+":"+std::to_string(arrTime.minute)+":"+std::to_string(arrTime.second);};
};

inline bool Dest::operator<(const Dest& rhs) const
{
    return (goTime<rhs.goTime);
}