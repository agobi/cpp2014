#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

bool comparelength(const std::string &a, const std::string &b)
{
    return a.size() < b.size();
}

int main()
{
    std::vector<std::string> v;

    std::string s;
    while(getline(std::cin, s))
        v.push_back(s);

    std::sort(v.begin(), v.end(), &comparelength);

    std::copy(v.begin(), v.end(),
            std::ostream_iterator<std::string>(std::cout, "\n"));
}
