#include <string>
#include <ostream>
#include <vector>
#include <Dest.h>
#include <iostream>
class Stop
{
    public:
        Stop(int id, std::string name):stop_id(id),stop_name(name){}
        Stop():stop_id(0),stop_name(""){}
        const int stop_id;
        const std::string stop_name;
        std::vector<Dest> dests;
        friend std::ostream & operator << (std::ostream& os, const Stop& st);
        void appDest(Dest d);
        void writeToFile();
};

