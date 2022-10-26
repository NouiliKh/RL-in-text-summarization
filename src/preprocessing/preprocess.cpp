#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "preprocess.h"
# include "csv.h"
using namespace std;



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
    vector<vector<string>>  data;
    // Open file
    csvstream csvin("../data/train_sample.csv");
    // Rows have key = column name, value = cell datum
    map<string, string> row;

    while (csvin >> row) {
        data.push_back(vector<string>{row["id"], row["article"], row["highlights"]});
    }
}