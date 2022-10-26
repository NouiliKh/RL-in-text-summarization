cmake_minimum_required(VERSION 3.23)
project(RL_in_text_summarization)

set(CMAKE_CXX_STANDARD 14)

add_executable(RL_in_text_summarization
        src/main.cpp
        src/preprocessing/preprocess.cpp
        src/preprocessing/preprocess.h src/utils/storing.cpp src/utils/storing.h src/utils/handle_csv.h)
