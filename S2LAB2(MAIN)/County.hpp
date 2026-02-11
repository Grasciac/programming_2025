#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
#include <vector>

class Country
{
public:
    Country();
    Country(const std::string &name, const std::string &capital,
            int day, int month, int year,
            long double square, const std::vector<std::string> &cities);

    Country(const Country &other);
    Country &operator=(const Country &other);
    ~Country();

    Country &operator+=(const Country &other);
    friend Country operator+(Country left, const Country &right);
    friend Country operator*(const Country &a, const Country &b);

    void setCapital(const std::string &capital);
    void print() const;

private:
    std::string _name;
    std::string _capital;
    int _day = 1;
    int _month = 1;
    int _year = 1;
    long double _square;
    std::vector<std::string> _cities;
};

#endif // COUNTRY_H
