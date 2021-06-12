#include <TTime.h>
#include <vector>
#include <utilities.h>

TTime::TTime(std::string input)
{
    std::vector<std::string> vec = splitString(input,':');
    date = std::stoi(vec[0]);
    hour = std::stoi(vec[1]);
    minute = std::stoi(vec[2]);
    second = std::stoi(vec[3]);
}

bool TTime::operator<(const TTime& rhs) const
{
    if(date<rhs.date)
    {
        return true;
    }
    else if(date==rhs.date&&hour<rhs.hour)
    {
        return true;
    }
    else if (date==rhs.date&&hour==rhs.hour && minute<rhs.minute)
    {
        return true;
    }
    else if(date==rhs.date&&hour==rhs.hour && minute==rhs.minute && second<rhs.second)
    {
        return true;
    }
    return false;
}