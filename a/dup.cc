#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>


int main()
{
    std::vector<int> v;
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(), std::back_inserter(v));

    std::copy(v.begin(), v.end(), std::back_inserter(v));
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\n"));
}
