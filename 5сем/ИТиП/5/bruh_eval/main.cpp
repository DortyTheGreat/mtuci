#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <cstdlib>


void saveToFile(const std::string& filename, const std::string& content) {
    std::ofstream out(filename);
    if (!out) {
        throw std::runtime_error("Unable to open file for writing: " + filename);
    }
    out << content;
    out.close();
}

void compileAndRun(const std::string& filename) {
    // Compile the file
    std::string command = "g++ " + filename + " -o output_binary";
    if (system(command.c_str()) != 0) {
        throw std::runtime_error("Compilation failed");
    }

    // Run the compiled binary
    if (system("./output_binary") != 0) {
        throw std::runtime_error("Execution failed");
    }
}

int main() {
    std::string code = R"(
#include <iostream>
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
)";

    // Save decompressed code to file
    std::string filename = "decompressed_code.cpp";
    saveToFile(filename, code);

    // Compile and run the code
    compileAndRun(filename);

    return 0;
}
