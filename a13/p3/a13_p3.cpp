/* 
   CH-230-A 
   a13_p3.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>
#include <fstream>

int main(void) {

    // get number of files and their names
    int n = 0;
    std::cin >> n;

    std::ofstream f_out("concatn.txt", std::ios::binary | std::ios::out);
        if (!f_out.good()) {
            std::cerr << "Error opening file: " << "concatn.txt" << std::endl;
            exit(1);
        }
    std::string filename;

    for (int i = 0; i < n; ++i) {
        std::cout << "Enter file path: ";
        std::cin >> filename;

        std::ifstream f_in(filename, std::ios::binary | std::ios::in);
        if (!f_in.good()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            exit(1);
        }

        // get total bytes in file
        f_in.seekg(std::ios::end);
        int size = f_in.tellg();
        f_in.seekg(std::ios::beg);

        char buf[255];

        // read all bytes
        do {
            f_in.read(buf, sizeof(buf));
            int bytes_read = f_in.gcount();

            f_out.write(buf, bytes_read);

            size -= bytes_read;

        } while (size > 0);

        // separate files
        f_out << "\n";
    }

    return 0;
}
