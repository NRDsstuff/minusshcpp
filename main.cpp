#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "readfile.hpp"

using namespace std;
using json = nlohmann::json;

int main(){

    string data;
    data = readFile("config.json");

    cout << data << endl;

    return 0;
}
