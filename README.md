# Homework task 9 (9th lecture)
This project contains a binary that represents work with class `Wine`.

## Description
Class `Wine` has a member of string type object for its name and Pair object (`std::pair`) which consists of two `std::valarray<int>` objects:
* 1st one for a year of bottling;
* 2nd one for number of bottles produced that year.

Implemented `Wine` class using "has-a" relationship using:
* composition 
* private inheritance. This class has a default constructor as well as the following ones:

`Wine(const char* l, int y, const int yr[], const int bot[])`
`Wine(const char* l, int y)`

Wine class also has a `getBottles()` method, which asks the user for the year of bottling and number of bottles for that year.

Method `label()` returns a link to wine's label, and `sum()` returns total number of bottles from the second `valarray<int> object` from PairArrayT.

Application asks the user to enter the wine's label, number of elements in array and a year and number of bottles for each array element. It uses this data to create a Wine object and print its information.


## How to check
To run the program cd to root of the repository and create build folder. Then:

1. `cmake -H. -Bbuild / cmake -H. -Bbuild -DUSE_COMPOSITION=1`
2. `cmake --build build`
3. `./build/testapp`