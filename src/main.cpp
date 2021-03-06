#include <iostream>
#include <StopList.h>
#include <iterator>

int main()
{
    //Test
    StopList stoplist;
    std::cout<<"Stop list loaded sucesfully\n Stoplist has size "<<stoplist.stopMap.size()<<"\n";
    //Get and print stop
    auto sss = stoplist[100000351];
    std::cout<<sss<<"\n";
    std::cout<<"Have "<<sss.dests.size()<<" destinations\n";

    //Test time
    TTime t1("20211011:10:11:52");
    TTime t2("20211011:16:13:51");
    if(t1<t2)
    {
        std::cout<<"t1 smaller than t2\n";
    }
    if(!(t2<t1))
    {
        std::cout<<"t2 not smaller than t1\n";
    }

    std::map<int,Stop>::iterator it;
    for(it = stoplist.stopMap.begin();it!=stoplist.stopMap.end();it++)
    {
        it->second.writeToFile();
    }

    return 0;
}
