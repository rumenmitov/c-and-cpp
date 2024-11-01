/* 
   CH-230-A 
   a13_p1.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <cstring>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void) {

    // get filename and separate the name from the extension
    const int buf_size = 255;

    char filename[buf_size];
    char ext[buf_size];
    cout << "Enter filename: ";
    cin.getline(filename, buf_size, '.');
    cin.getline(ext, buf_size);

    // open input and output files
    string filename_s(filename);
    string ext_s(ext);

    string file = filename_s + "." + ext_s;
    string file_copy = filename_s + "_copy." + ext_s;


    ifstream in(file);
    if (!in.good()) {
        cout << "Error opening input file!\n" << file << endl;;
        exit(1);
    }

    ofstream out(file_copy);
    if (!out.good()) {
        cout << "Error opening output file!\n";
        exit(1);
    }

    // read from input to output file
    char buf[buf_size];
    while (in.getline(buf, sizeof(buf))) {
        // adding newline because it is removed from getline
        out << buf << '\n'; 
    }

    // close files
    in.close();
    out.close();

    return 0;
}
