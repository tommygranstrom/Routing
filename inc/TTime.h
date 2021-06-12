#include <string>

class TTime
{   
    public:
        int date,hour,minute,second;
        TTime(std::string input);
        bool operator<(const TTime& rhs) const;
};