#include <iostream>
#include <fstream>
#include <string>

int main() {
    int count{0};
    std::string word;
    int shortest{100};
    int longest{0};
    int total_word_length{0};
    double average{0};
    std::string shortest_word;
    std::string longest_word;

    std::ifstream in{"testing.txt"};

    if(!in) {
        std::cout << "Warning: the given file is empty" << std::endl;
        return 1;
    }
    while(in >> word) {
        total_word_length += word.length();
        int longest_temp = word.length();
        int shortest_temp = word.length();

        if (shortest_temp < shortest) {
            shortest = shortest_temp;
            shortest_word = word;
        }
        if (longest_temp > longest) {
            longest = longest_temp;
            longest_word = word;
        }
        count++; 
    }

    //std::cout << total_word_length << count << std::endl;
    average = total_word_length/count;

    std::cout << "There are " << count << " words in the file." << std::endl;
    std::cout << "The shortest word was " << shortest_word << " with " << shortest << " character(s)." << std::endl;
    std::cout << "There longest word was " << longest_word << " with " << longest << " character(s)." << std::endl;
    std::cout << "There average word length was " << average << " character(s)." << std::endl;

    in.close();
    return 0;
}