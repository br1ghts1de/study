#include "PicMapApi.h"

Container::Container() = default;


void Container::clear()
{
    Container_.clear();
}

Container::~Container()
{
    clear();
}

unsigned long long Container::size()
{
    return Container_.size();
}

bool Container::isEmpty()
{
    return size() == 0;
}

void Container::insert(const cv::Mat& input)
{
    unsigned long long h_ = gethash_(input);
    Container_.insert(h_);
}

void Container::insert(unsigned long long &input)
{
    Container_.insert(input);
}

bool Container::exist(const cv::Mat& input)
{
    unsigned long long h_ = gethash_(input);
    return (Container_.find(h_) != Container_.end());
}

bool Container::exist(unsigned long long &input)
{
    return (Container_.find(input) != Container_.end());
}

void Container::erase(const cv::Mat& input)
{
    unsigned long long h_ = gethash_(input);
    auto k = Container_.find(h_);
    if (k == Container_.end())
    {
        throw("No such hash");
    }
    else
    {
        Container_.erase(*k);
    }
}

void Container::erase(unsigned long long &input)
{
    unsigned long long h_ = input;
    auto k = Container_.find(h_);
    if (k == Container_.end())
    {
        throw("No such hash");
    }
    else
    {
        Container_.erase(*k);
    }
}

unsigned long long Container::gethash_(const cv::Mat& input)
{
    XXHash64 h_(0);
    for (int i = 0; i < input.rows; i++)
    {
        size_t sizeInBytes = input.step[0];
        h_.add(input.ptr(i), sizeInBytes);
    }
    return h_.hash();
}


/* 
**BINARY I/O**
*/



std::ofstream& Container::writeTo(std::ofstream& ostr)
{
    unsigned long long cntrlsum = 0;
    unsigned long long t_ = size();
    ostr.write((char*)&(t_), sizeof(t_));

    for (std::set<unsigned long long>::iterator it = Container_.begin(); it != Container_.end(); it++)
    {
        cntrlsum += *it;

        ostr.write((char*)&(*it), sizeof(unsigned long long));
    }

    ostr.write((char*)&(cntrlsum), sizeof(unsigned long long));
    return ostr;
}

std::ifstream& Container::readFrom(std::ifstream& istr)
{
    unsigned long long n;
    unsigned long long cntrlsum1=0;
    unsigned long long cntrlsum2;

    istr.read((char*)&n, sizeof(n));

    for (size_t i = 0; i < n; i++)
    {
        unsigned long long inp1;
        unsigned long long inp2;

        istr.read((char*)&inp1, sizeof(unsigned long long));
        cntrlsum1 += inp1;

        Container_.insert(inp1);
    }
    
    istr.read((char*)&cntrlsum2, sizeof(unsigned long long));

    if (cntrlsum1 != cntrlsum2)
    {
        throw("ERROR. INVALID SUM.");
    }

    return istr;
}
