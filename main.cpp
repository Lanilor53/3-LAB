#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cmath>

using namespace std;
/**
 * Performs given operation
 * @tparam T Type of the arguments
 * @param A First argument
 * @param B Second argument
 * @param operation Operation to be done
 * @return Result of the operation
 */
template<typename T>
T handleOperation(T A, T B, string operation) {
    T result;
    if (operation == "+"){
        result = A + B;
    } else if (operation == "-") {
        result = A - B;
    } else if (operation == "*") {
        result = A * B;
    } else if (operation == "/") {
        if(B!=0) {
            result = A / B;
        }else{
            throw(std::invalid_argument("Division by zero!"));
        }
    } else if (operation == "pow") {
        result = pow(A, B);
    }
    return result;
}
int main() {
    // word is used to store the number and the output type
    string word;
    string operation;
    // Operands
    int intA;
    int intB;
    int intResult;
    float floatA;
    float floatB;
    float floatResult;
    string stringA;
    string stringB;
    string stringResult;

    // File opening
    const string INPUTFILENAME =  R"(C:\\Users\Lenovo\Desktop\C++\lab3\tsv.txt)";
    const string OUTPUTFILENAME =  R"(C:\\Users\Lenovo\Desktop\C++\lab3\tsvparsed.txt)";
    ifstream ifs;
    ofstream ofs;
    ifs.open(INPUTFILENAME);
    ofs.open(OUTPUTFILENAME);
    // Main loop
    while (!ifs.eof()) {
        ifs >> word;
        ofs << word << " ";
        ifs >> operation;
        ifs >> word;
        // Operation handling
        if (word == "int") {
            // Operands
            ifs >> intA;
            ifs >> intB;
            // Output type
            ifs >> word;
            try {
                intResult = handleOperation(intA, intB, operation);
            } catch(...) {
                continue;
            }
            if (word == "int") {
                ofs << intResult << endl;
            } else if (word == "float") {
                ofs << (float)intResult << endl;
            }
        } else if (word == "float") {
            // Operands
            ifs >> floatA;
            ifs >> floatB;
            // Output type
            ifs >> word;
            try {
                floatResult = handleOperation(floatA, floatB, operation);
            } catch (...) {
                continue;
            }
            if (word == "int") {
                ofs << (int)floatResult << endl;
            } else if (word == "float") {
                ofs << floatResult << endl;
            }
        } else if (word == "string") {
            // Operands
            ifs >> stringA;
            ifs >> stringB;
            // Output type
            ifs >> word;
            if (operation == "+") {
                ofs << stringA + stringB << endl;
            }
        }
    }
    return 0;
}


/*
// Lookup tables, because stackoverflow said it's faster https://stackoverflow.com/questions/931890/what-is-more-efficient-a-switch-case-or-an-stdmap
map<string, int> typeDict;
typeDict["int"] = 1;
typeDict["float"] = 2;
typeDict["string"] = 3;
map<string, int> operationDict;
operationDict["+"] = 1;
operationDict["-"] = 2;
operationDict["*"] = 3;
operationDict["/"] = 4;
operationDict["pow"] = 5;
*/

/*
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <sstream>

using namespace std;

string* parseTSV(string filename){
    ifstream tsvFile;
    tsvFile.open(filename);
    if(!tsvFile.is_open()){
        cout << "FATAL ERROR: File " << filename << "could not be opened";
        exit(-1);
    }
    int linecount  = 0;
    string curline;
    while(!tsvFile.eof()){
        linecount++;
        getline(tsvFile, curline);
        istringstream iss(curline);
        copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             ostream_iterator<string>(cout, "\n"));
    }
    //parsedLines = new string[linecount/5];
    return &curline;
}


int main() {
    string FILENAME =  "C:\\\\Users\\Lenovo\\Desktop\\C++\\lab3\\tsv.txt";
    string* parsedLines;
    parsedLines = parseTSV(FILENAME);

    return 0;
}*/