#ifndef _WINE_H
#define _WINE_H

#include <valarray>
#include <cstring>
#include <utility>
#include <string>
#include <time.h>
#include <iostream>

using ArrayIntT = std::valarray<int>;
using PairArrayT = std::pair<ArrayIntT, ArrayIntT>;


#ifdef USE_COMPOSITION
    class Wine
    {
        public:
            Wine(const char* l, int y, const int yr[], const int bot[]);
            Wine(const char* l, int y);
            ~Wine();
            void getBottles();
            void show() const;
            const char* label() const;
            size_t sum() const;
        
        private:
            char* name;
            PairArrayT bottlingInfo;
            ArrayIntT ages;

            void calculateAges();          
    };
#else
    class Wine : PairArrayT, ArrayIntT
    {
        public:
            Wine(const char* l, int y, const int yr[], const int bot[]);
            Wine(const char* l, int y);
            ~Wine();
            void getBottles();
            void show() const;
            const char* label() const;
            size_t sum() const;

        private:
            char* name;

            void calculateAges();
    };
#endif

#endif