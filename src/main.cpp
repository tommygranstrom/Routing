#include <iostream>
#include <StopList.h>


int main()
{

    //Test
    StopList stoplist;
    std::cout<<"Stop list loaded sucesfully\n Stoplist has size "<<stoplist.stopMap.size()<<"\n";
    //Get and print stop
    auto sss = stoplist[740046254];
    std::cout<<sss<<"\n";
    std::cout<<"Have "<<sss.dests.size()<<" destinations\n";

    //Test time
    TTime t1("10:11:52");
    TTime t2("16:13:51");
    if(t1<t2)
    {
        std::cout<<"t1 smaller than t2\n";
    }
    if(!(t2<t1))
    {
        std::cout<<"t2 not smaller than t1\n";
    }
    return 0;
}
