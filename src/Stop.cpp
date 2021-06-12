#include <Stop.h>

std::ostream & operator << (std::ostream& os, const Stop& st)
{
    os << "Id: "<<st.stop_id<<" Name: "<<st.stop_name;
    return os;
}
void Stop::appDest(Dest d)
{
     dests.push_back(d);
}
