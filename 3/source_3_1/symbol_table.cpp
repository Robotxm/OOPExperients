/**
 * Experiment 3
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-05-08
 * Description: Implementation of symbol table
 */

#include "symbol_table.hpp"
#include "error.hpp"

namespace symboltable
{
    double SymbolTable::Get(const std::string &key, bool check)
    {
        // Symbol not found
        if (check && symbol_table_.find(key) == symbol_table_.end())
            throw error::UnknownSymbolException("No symbol named '" + key + "'");

        return symbol_table_[key];
    }

    void SymbolTable::Put(const std::string key, const double value)
    {
        symbol_table_[key] = value;
    }
} // namespace symboltable
