### Stream

Abstraction for input/output. Convert between data and the string representatipon of the data. 

* Output stream
  * `std::cout` 
  * type: `std::ostream`
  * convert data to string and ***send*** it to output streams using `<<` operator
  * `std::cout` goes to console 
  * No need to initialise cout object because `std::cout` is  ***global constant object*** you can get from `#include <iostream>` (only exception)
  * `std::cout << 5 << std::endl;`

* Output file stream
  * type: `std::ofstream`
  * use `<<` to convert data to string and ***send*** it to file stream
  * ***Must initiliase*** output file stream object to link it to a file, ex. `std::ofstream out("out.txt");`, `out` is an ofsteam that outputs to `out.txt` 
  * `out << 5 << std::endl;`

* Input stream
  * `std::cin`
  * type: `std::istream`
  * convert the string data gotten from console to data using `>>` and send it to a variable. ex. `std::cin >> x;`
  * `std::cin` the input stream gets inputs from console 
  * ***when the input matches the receiver varible type correctly***, i.e. input 3 and put it in `int x;`, ``>>`` reads until the next whitespace
  *  ***Caveat***: however, if you input `3th` without putting a whitespace and apparently `th` is not int, ``>>``reads until the valid int and moves one to read the remaining until it hits whitespace or invalid input.  
  * whitespace is actually read into inoup stream, but it is eaten by C++ and won't show up in output. 
  * *Think of a `std::istream` as a sequence of characters*

* getline
  * signature `istream& std::getline(istream& is, string& str, char delim)`
    * `is`: stream to read from 
    * `str`: place to store stream
    * `delim`: when to stop reading (`\n` by default) 
  * type: `std::istream`
  * Usage: read a string or a line from an input stream
  * stop condition:
    1. reach end of file condition on `is` -> sets `EOF` bit, check by `is.eof()`
    2. next char in `is` is `delim`, extract but does not store 
    3. str max size reached, wil fail, `is.fail()` is asserted.  
    4. no char at all to extract. fail. 
  * Example, read from console, ` std::string line; std::getline(cin, line)`


* Input file stream 
  * type: `std::ifstream`
  * `>>` receives strings from a input file and converts it to data of any type 
  * ***Must initialise*** `ifstream` object linked to the input file. Like this `std::ifstream in("out.txt");`
  * `in`, the ifstream reads from `out.txt` 
  * Ex. ` in >> str;` first word in `out.txt` goes into `str`. 
  

