#ifndef PicMapAPI
#define PicMapAPI

#include <iostream>
#include <map>
#include <string>
#include <exception>
#include <fstream>

#include <opencv2\highgui\highgui.hpp>
#include <xxhash64.h>


//http://create.stephan-brumme.com/xxhash/

class Container
{
public:
    Container();
    ~Container();
    void insert(const cv::Mat& input, const unsigned long long& index);
    bool exist(const cv::Mat& input);
    unsigned long long find(const cv::Mat& input);
    void erase(const cv::Mat& input);
    void clear();
    bool isEmpty();
    unsigned long long size();

    std::ofstream& writeTo(std::ofstream& ostrm);
    std::ifstream& readFrom(std::ifstream& istr);

private:
    std::map<unsigned long long, unsigned long long> Container_;
    unsigned long long gethash_(const cv::Mat& input);

};

#endif