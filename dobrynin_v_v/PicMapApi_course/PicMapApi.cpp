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

void Container::insert(const cv::Mat& input, const unsigned long long& index)
{
    unsigned long long h_ = gethash_(input);
    Container_[h_] = index;
}

bool Container::exist(const cv::Mat& input)
{
    unsigned long long h_ = gethash_(input);
    return (Container_.find(h_) != Container_.end());
}

unsigned long long Container::find(const cv::Mat& input)
{
    unsigned long long h_ = gethash_(input);
    if (exist(input))
    {
        return Container_[h_];
    }
}

void Container::erase(const cv::Mat& input)
{
    unsigned long long h_ = gethash_(input);
    if (exist(input))
    {
        unsigned long long h_ = gethash_(input);
        Container_.erase(h_);
    }
}


/* 
**BINARY I/O**
I/O FORMAT: 
*CONTAINER SIZE*

KEY-VALUE |
KEY-VALUE |  N LINES
......... |  SPACE AFTER EACH VALUE
KEY-VALUE |

CONTRL SUM 1

*/



std::ofstream& Container::writeTo(std::ofstream& ostr)
{
    unsigned long long cntrlsum = 0;
    unsigned long long t_ = size();
    ostr.write((char*)&(t_), sizeof(t_));

    for (std::map<unsigned long long, unsigned long long>::iterator it = Container_.begin(); it != Container_.end(); it++)
    {
        cntrlsum += it->first;

        ostr.write((char*)&(it->first), sizeof(unsigned long long));
        ostr.write((char*)&(it->second), sizeof(unsigned long long));
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
        istr.read((char*)&inp2, sizeof(unsigned long long));
        cntrlsum1 += inp1;

        Container_[inp1] = inp2;
    }
    
    istr.read((char*)&cntrlsum2, sizeof(unsigned long long));

    if (cntrlsum1 != cntrlsum2)
    {
        throw("ERROR. INVALID SUM.");
    }

    return istr;
}
