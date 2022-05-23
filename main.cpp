#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "NZTK.hpp"
#include <chrono>
#include <ctime>

using namespace std;
using json = nlohmann::json;

void run(){

    Date date;

    json config;
    ifstream cfg("config.json");
    cfg >> config;
    cfg.close();

    string line = askForInput(ReplaceAll(config["PS1"], "'FD'", date.getFullDate()));

    cout << line << endl;

    if(line == "amongst"){

        exit(1);
    }else{

        run();
    }
}

int main(){

    run();

    return 0;
}
