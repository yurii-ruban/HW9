#include "wine.h"

#ifdef USE_COMPOSITION
    Wine::Wine(const char* l, int y, const int yr[], const int bot[]) : name(new char[strlen(l)]),
                                                                        bottlingInfo(std::make_pair(ArrayIntT(yr, y), ArrayIntT(bot, y))),
                                                                        ages(y)
    {
        strcpy(name, l);
        calculateAges();
    }

    Wine::Wine(const char* l, int y) : name(new char(strlen(l))),
                                       bottlingInfo(std::make_pair(ArrayIntT(y), ArrayIntT(y))),
                                       ages(y)             
    {
        strcpy(name, l);
    }

    Wine::~Wine()
    {
        delete[] name;
    }

    void Wine::getBottles()
    {
        std::cout << "The wine " << name 
                  << " has been prepared for " << bottlingInfo.first.size() << " years of bottling."
                  << " Please, fill the info: " << std::endl;

        size_t year;
        size_t bottles;

        for(size_t i = 0; i < bottlingInfo.first.size(); ++i)
        {
            std::cout << "Enter the year of bottling: ";
            std::cin >> year;
            std::cout << "Enter the count of bottles, were bottled in " << year << ": ";
            std::cin >> bottles;
            bottlingInfo.first[i] = year;
            bottlingInfo.second[i] = bottles;
        }
        calculateAges();
        std::cout << std::endl;
    }

    void Wine::show() const
    {
        std::cout << "The wine " << name << " info: " << std::endl;

        for(size_t i = 0; i < bottlingInfo.first.size(); ++i)
        {
            std::cout << "Year: " << bottlingInfo.first[i] << " | "
                      << "Bottles: " << bottlingInfo.second[i] << " | "
                      << "Age: " << ages[i] << std::endl;
        }
        std::cout << std::endl;
    }

    const char* Wine::label() const
    {
        return name;
    }

    size_t Wine::sum() const
    {
        return bottlingInfo.second.sum();
    }

    void Wine::calculateAges()
    {
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);
        int year = aTime->tm_year + 1900;

        for(size_t i = 0; i < bottlingInfo.first.size(); ++i)
        {
            ages[i] = year - bottlingInfo.first[i];
        }
    }
#else
    Wine::Wine(const char* l, int y, const int yr[], const int bot[]) : name(new char[strlen(l)]),
                                                                        PairArrayT(std::make_pair(ArrayIntT(yr, y), ArrayIntT(bot, y))),
                                                                        ArrayIntT(y)
    {
        strcpy(name, l);
        calculateAges();
    }

    Wine::Wine(const char* l, int y) : name(new char(strlen(l))),
                                       PairArrayT(std::make_pair(ArrayIntT(y), ArrayIntT(y))),
                                       ArrayIntT(y)
    {
        strcpy(name, l);
    }

    Wine::~Wine()
    {
        delete[] name;
    }

    void Wine::getBottles()
    {
        std::cout << "The wine " << name
                  << " has been prepared for " << PairArrayT::first.size() << " years of bottling."
                  << " Please, fill the info: " << std::endl;

        size_t year;
        size_t bottles;

        for(size_t i = 0; i < PairArrayT::first.size(); ++i)
        {
            std::cout << "Enter the year of bottling: ";
            std::cin >> year;
            std::cout << "Enter the count of bottles, were bottled in " << year << ": ";
            std::cin >> bottles;
            PairArrayT::first[i] = year;
            PairArrayT::second[i] = bottles;
        }
        calculateAges();
        std::cout << std::endl;
    }

    void Wine::show() const
    {
        std::cout << "The wine " << name << " info: " << std::endl;

        for(size_t i = 0; i < PairArrayT::first.size(); ++i)
        {
            std::cout << "Year: " << PairArrayT::first[i] << " | "
                      << "Bottles: " << PairArrayT::second[i] << " | "
                      << "Age: " << ArrayIntT::operator[](i) << std::endl;
        }
        std::cout << std::endl;
    }

    const char* Wine::label() const
    {
        return name;
    }

    size_t Wine::sum() const
    {
        return PairArrayT::second.sum();
    }

    void Wine::calculateAges()
    {
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);
        int year = aTime->tm_year + 1900;

        for(size_t i = 0; i < PairArrayT::first.size(); ++i)
        {
            ArrayIntT::operator[](i) = year - PairArrayT::first[i];
        }
    }
#endif