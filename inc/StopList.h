#include <Stop.h>
#include <map>

class StopList
{   
    public:
        StopList();
        std::map<int,Stop> stopMap;
        Stop operator[](int i);
};

