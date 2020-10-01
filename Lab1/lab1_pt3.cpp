#include <iostream>
#include <fstream>
#include <string>

//TODO: Complementary work needed, 7-1: Initialize variables using
//braces when possible
//DONE

//TODO: Complementary work needed, 1-15: Use cerr for error output
//DONE

//TODO: Complementary work needed, 8-8: Your average value will always
//be of type integer. Hint: Use static_cast to convert to double.
//DONE

//TODO: Complementary work needed, 8-8: Your program ends with a
//floating point exception when the file is empty. It should give an
//error.
//DONE

int main() {
    int count{0};
    std::string word{};
    int shortest{100};
    int longest{0};
    int total_word_length{0};
    double average{0};
    std::string shortest_word{};
    std::string longest_word{};

    std::ifstream in{"testing.txt"};

    //https://stackoverflow.com/questions/26228424/how-to-detect-an-empty-file-in-c/26228684#:~:text=4%20Answers&text=The%20function%20tellg()%20returns,0%20it%20must%20be%20empty.
    if (in.peek() == std::ifstream::traits_type::eof()){
        std::cerr << "Error: empty file" << std::endl;
        return 0;
    }
    while(in >> word) {
        total_word_length += word.length();
        int longest_temp{word.length()};
        int shortest_temp{word.length()};

        if (shortest_temp < shortest) {
            shortest = {shortest_temp};
            shortest_word = {word};
        }
        if (longest_temp > longest) {
            longest = {longest_temp};
            longest_word = {word};
        }
        ++count; 
    }

    average = {static_cast<double>(total_word_length)/count};

    std::cout << "There are " << count << " words in the file." << std::endl;
    std::cout << "The shortest word was " << shortest_word << " with " << shortest << " character(s)." << std::endl;
    std::cout << "There longest word was " << longest_word << " with " << longest << " character(s)." << std::endl;
    std::cout << "There average word length was " << average << " character(s)." << std::endl;

    in.close();
    return 0;
}
