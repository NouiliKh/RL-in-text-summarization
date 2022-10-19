#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "preprocess.h"

using namespace std;


class ReadCSV {
public:
    string fileName;

    vector<vector<string>> readCsv() {
        ifstream infile(this->fileName);
        vector<vector<string> > data;
        vector<string> record;

        string s;
        istringstream ss(s);

        if (infile) {
            getline(infile, s);
            istringstream ss(s);
            int i = 0;
            while (i < 3) {
                string s;
                if (!getline(ss, s, ',')) break;
                record.push_back(s);
                i += 1;
            }
            data.push_back(record);
        }


        while (infile) {
            string s;
            string delimiter = ",\"";
            if (!getline(infile, s)) break;
            vector<string> record;

            istringstream ss(s);

            int i = 0;

            auto start = 0U;
            auto end = s.find(delimiter);
            while (end != std::string::npos) {
                record.push_back(s.substr(start, end - start));
                start = end + delimiter.length();
                end = s.find(delimiter, start);
            }
            record.push_back(s.substr(start, end));
            data.push_back(record);

        }
        if (!infile.eof()) {
            cerr << "Fooey!\n";
        }
        return data;
    }
};

vector<vector<string>> preprocessData() {
    vector<string> message_data;
    vector<vector<string>> tokenized;
    for (auto &i: message_data) {
        // convert messages to lowercase
        transform(i.begin(), i.end(), i.begin(), ::tolower);
        // Remove Punctuation
        i.erase(remove_if(i.begin(), i.end(), ::ispunct), i.end());
        // tokenize
        vector<string> tokens;
        string word;
        istringstream iss(i);
        while (getline(iss, word, ' ')) {
            tokens.push_back(word);
        }
        tokenized.push_back(tokens);
    }
    return tokenized;
}

void read_and_preprocess() {
    // Reading CSV file and store it inside a vector
    ReadCSV csvReader;
    // Access attributes and set values
    csvReader.fileName = "../data/train_sample.csv";
    // get data
    vector<vector<string>> data = csvReader.readCsv();
    vector<string> label_data;
    vector<string> message_data;

}