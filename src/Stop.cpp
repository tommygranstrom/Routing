#include <Stop.h>
#include <fstream>
#include <vector>
#include <algorithm>

std::ostream & operator << (std::ostream& os, const Stop& st)
{
    os << "Id: "<<st.stop_id<<" Name: "<<st.stop_name;
    return os;
}
void Stop::appDest(Dest d)
{
     dests.push_back(d);
}

void Stop::writeToFile()
{
    std::string PATH = "C:/Users/Tommy/Documents/Reskoll/nodes/"+std::to_string(stop_id)+".txt";
    //Sort the dests by go time
    std::sort(dests.begin(),dests.end());
    
    std::ofstream file(PATH);
    file<<std::to_string(stop_id);
    file<<stop_name;
    
    for (int i = 0; i<dests.size();i++)
    {
        std::string out = std::to_string(dests[i].id)+","+dests[i].getGoStr()+","+dests[i].getArrStr();
        file<<out;
    }
    file.close();
}