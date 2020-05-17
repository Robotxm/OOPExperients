/**
 * Experiment 3
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-05-08
 * Description: Definition of symbol table
 */

#ifndef _SYMBOL_TABLE_HPP
#define _SYMBOL_TABLE_HPP

#include <string>
#include <map>
#include <cmath>

namespace symboltable
{
    class SymbolTable
    {
    public:
        SymbolTable(const SymbolTable &) = delete;
        SymbolTable &operator=(const SymbolTable &) = delete;
        static SymbolTable &GetInstance()
        {
            static SymbolTable instance;
            return instance;
        }

        /**
        * Return value related to specified key
        * 
        * @param check If this is true and specified key does not exist,
        *              an exception will be thrown
        */
        double Get(const std::string &key, bool check);

        /**
        * Put a new key-value pair in table
        */
        void Put(const std::string key, const double value);

    private:
        std::map<std::string, double> symbol_table_;
        SymbolTable()
        {
            // Initialize built-in symbols
            symbol_table_["pi"] = acos(-1);
            symbol_table_["e"] = exp(1);
        }
    };
} // namespace symboltable

#endif
