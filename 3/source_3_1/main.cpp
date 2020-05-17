/**
 * Experiment 3
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-05-08
 * Description: Entry of application
 */

#include <iostream>
#include <fstream>
#include "lexer.hpp"
#include "parser.hpp"
#include "error.hpp"

int main(int argc, char *argv[])
{
    using namespace lexer;
    using namespace std;

    auto &lexer_instance = Lexer::GetInstance();

    if (argc == 1) // Retrieve input from standard input stream
    {
        try
        {
            lexer_instance.SetInput(&cin);
            lexer_instance.Start(true);
        }
        catch (error::InvalidStreamException &e)
        {
            cout << e.what() << endl;
            return error::BaseException::GetCount();
        }
    }
    else // Retrieve input from file
    {
        for (int i = 1; i < argc; i++)
        {
            cout << "== File " << i << ": " << argv[i] << " ==" << endl;
            try
            {
                ifstream in(argv[i]);
                if (!in.is_open()) // Check file
                    throw error::FileIOException("Cannot open " + string(argv[i]));

                lexer_instance.SetInput(&in);
                lexer_instance.Start(false);

                in.close();
            }
            catch (exception &e)
            {
                cout << e.what() << endl;
                return error::BaseException::GetCount();
            }
        }
    }

    return error::BaseException::GetCount();
}
