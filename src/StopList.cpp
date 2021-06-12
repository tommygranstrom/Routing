#include <StopList.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <utilities.h>
#include <iostream>
#include <set>

StopList::StopList()
{
    std::string PATH_TO_STOPSFILE = "C:/Users/Tommy/Documents/Reskoll/sweden/stops.txt";
    std::ifstream STOPS_FILE(PATH_TO_STOPSFILE);
    if(STOPS_FILE)
    {
        std::string tp;
        getline(STOPS_FILE,tp);
        while(std::getline(STOPS_FILE,tp))
        {   
            std::vector<std::string> out = splitString(tp,',');
            Stop newStop(std::stoi(out[0]),out[1]);
            stopMap.insert(std::pair<int,Stop> (std::stoi(out[0]),newStop));
        }
    }
    else{
        std::cout<<"Cannot load file sweden/stops.txt\n";
    }

    //Load all the links 

    //1. Load all the trips id to be able to map trip id to service ID
    std::string PATH_TO_TRIPSFILE = "C:/Users/Tommy/Documents/Reskoll/sweden/trips.txt";
    std::ifstream TRIPS_FILE(PATH_TO_TRIPSFILE);
    
    if(TRIPS_FILE)
    {   
        std::map<std::string,std::string> trips;
        std::map<std::string,std::string> serviceId;
        
        std::string tp;
        getline(TRIPS_FILE,tp);
        while(getline(TRIPS_FILE,tp))
        {
            std::vector<std::string> out = splitString(tp,',');
            trips[out[2]]=out[1];
            serviceId[out[1]]=out[2];
        }
    
        //2. Load all the dates for each service ID
        std::string PATH_TO_CALENDARDATES = "C:/Users/Tommy/Documents/Reskoll/sweden/calendar_dates.txt";
        std::ifstream CALENDAR_FILE(PATH_TO_CALENDARDATES);
        if(CALENDAR_FILE)
        {   
            std::map<std::string,std::vector<std::string>> dates;
            std::string tp;
            getline(TRIPS_FILE,tp);
            while(getline(TRIPS_FILE,tp))
            {
                std::vector<std::string> out = splitString(tp,',');
                dates[out[0]].push_back(out[1]);
            }

            //3. Load all the links
            std::string PATH_TO_STOPSTIMES = "C:/Users/Tommy/Documents/Reskoll/sweden/stop_times.txt";
            std::ifstream STOPTIME_FILE(PATH_TO_STOPSTIMES);
            if(STOPTIME_FILE)
            {   
                std::string previous;
                std::string current;
                getline(STOPTIME_FILE,current);
                getline(STOPTIME_FILE,previous);
                getline(STOPTIME_FILE,current);
        
                while(getline(STOPTIME_FILE,current))
                {
                    std::vector<std::string> previousVec=splitString(previous,',');
                    std::vector<std::string> currentVec=splitString(current,',');
                    if(currentVec[0]==previousVec[0])
                    {
                        std::string trId = currentVec[0];
                        std::string serId = serviceId[trId]; 
                        int goFrom = std::stoi(previousVec[3]);
                        int goTo = std::stoi(currentVec[3]);
                        std::vector<std::string> dateVec = dates[serId];
                        for(int i = 0; i<dateVec.size();i++)
                        {
                            TTime goTime(dateVec[i]+":"+previousVec[1]);
                            TTime arrTime(dateVec[i]+":"+currentVec[1]);
                            if(goTime<arrTime)
                            {
                                Dest newDest(goTo,goTime,arrTime);
                                stopMap[goFrom].appDest(newDest);
                            }
                        }
                    }
                    previous=current;
                }
            }
            else
            {
                std::cout<<"Cannot load file sweden/calendar_dates.txt\n";
            }
        }
        else
        {
            std::cout<<"Cannot load file sweden/calendar_dates.txt\n";
        }
    }
    else
    {
        std::cout<<"Cannot load file sweden/trips.txt\n";
    }
}

Stop StopList::operator[](int i)
{
    Stop el = stopMap.find(i)->second;
    return el; 
}