#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v;
    v.push_back(2);
    std::vector<int>::iterator it = v.begin();
    std::cout<<*it<<std::endl;

    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);

    // invalid iterator
    std::cout<<*it<<std::endl;

    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    std::cout<<v.size()<<" "<<v.capacity()<<std::endl;

    std::vector<int>(v).swap(v);
    std::cout<<v.size()<<" "<<v.capacity()<<std::endl;
}
