#ifndef PicMapAPI
#define PicMapAPI

#include <iostream>
#include <set>
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

    void insert(const cv::Mat& input);
    void insert(unsigned long long &input);
    // вставляет картинку в контейнер. На вход подяется либо картинка в явном виде либо хэш

    bool exist(const cv::Mat& input);
    bool exist(unsigned long long &input);
    // проверяет наличие картинки в контейнере. На вход подяется либо картинка в явном виде либо хэш

    void erase(const cv::Mat& input);
    void erase(unsigned long long &input);
    // удаляет картинку из контейнера. На вход подяется либо картинка в явном виде либо хэш
    
    void clear();
    // очищает контейнер
    
    bool isEmpty();
    // проверяет контейнер на пустоту

    unsigned long long size();
    // возращает размер контейнера

    std::ofstream& writeTo(std::ofstream& ostrm);
    std::ifstream& readFrom(std::ifstream& istr);
    // считывание/запись контейнеров

private:
    std::set<unsigned long long> Container_;
    // контейнер

    unsigned long long gethash_(const cv::Mat& input);
    // высчитать хэш от картинки

};

#endif
