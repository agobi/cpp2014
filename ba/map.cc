#include <map>
#include <iostream>
#include <string>

template<typename A, typename B>
struct mypair
{
    A first;
    B second;
};


int main()
{
    std::map<std::string, int> szamok;
    szamok.insert(std::pair<std::string, int>("egy", 1));
    szamok.insert(std::make_pair("ketto", 2));
    szamok["harom"]=3;

    std::string s;
    while(std::cin>>s)
    {
//        std::cout<<szamok[s]<<std::endl;
        std::map<std::string, int>::iterator it = szamok.find(s);
        if(it != szamok.end())
            std::cout<<it->second<<std::endl;
    }

    std::cout<<szamok.size()<<std::endl;
}
