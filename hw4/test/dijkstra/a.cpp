#include <boost/heap/fibonacci_heap.hpp>
#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int> PII;
typedef boost::heap::fibonacci_heap<
        PII,
        boost::heap::compare<std::greater<PII> > > MyHeap;
struct Comparator
{
    bool operator()(std::pair<int, int > elem1, std::pair<int, int > elem2) const
    {
        return elem1.first > elem2.first;
    }
};

int main()
{
    MyHeap heap;
    heap.push(make_pair(0,5));
    heap.push(make_pair(1,5));
    heap.push(make_pair(2,5));

    for(const auto& n : heap) {
        std::cout << n.first << "\n";
    }
}
