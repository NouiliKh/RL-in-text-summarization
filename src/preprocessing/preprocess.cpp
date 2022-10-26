//
// Created by khalil Nouili on 14.10.22.
//

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "preprocess.h"
#include "../utils/handle_csv.h"
#include "../utils/storing.h"

using namespace std;

string preprocessData(string input) {

    // convert messages to lowercase
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    // Remove Punctuation
    input.erase(remove_if(input.begin(), input.end(), ::ispunct), input.end());
    // tokenize
    return input;
}


void read_and_preprocess() {
    vector<vector<string>> data;
    // Open file
    csvstream csvin("../data/train_sample.csv");
    // Rows have key = column name, value = cell datum
    map<string, string> row;

    while (csvin >> row) {
        data.push_back(vector<string>{row["id"], preprocessData(row["article"]), preprocessData(row["highlights"])});
    }

    save_data(data, "../processed/processed_data.csv");

    int a =1;
}