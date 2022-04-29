#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std; 

#define COUNTRYNUM 196

bool checkingRedundancy(const string filename2, string thatone){
    string countr; 
    fstream file2; 
    file2.open(filename2); 
    if(file2.is_open()){
    for(short i = 0; getline(file2, countr); i++){
        if(countr == thatone){
          file2.close(); 
            return true; 
        }
    }
file2.close(); 
    }
return false; 
}

string loadCountry(const string filename, string chosen, int randomLine){
    fstream file; 
    string line; 
    file.open(filename); 
    if(file.is_open()){
    for(short i = 0; getline(file, line); i++){
        if(i == randomLine){
            chosen = line;
            if(checkingRedundancy("donecountries.txt", chosen)==false){
                file.close();
                ofstream file3; 
                file3.open("donecountries.txt", ios_base::app);
                file3 << chosen;
                file3 << "\n";  
                file3.close(); 
                return chosen; 
            } else {
                return loadCountry(filename, chosen, rand()%COUNTRYNUM+1);
            }
        }
    }
    } 
     else {
        cout << "Can't open file. "<<endl; 
    }
}

int main(){

    srand(time(0)); 
    string dailyCountry; 
    int randline = rand()%COUNTRYNUM+1;
    dailyCountry = loadCountry("countries.txt", dailyCountry, randline);
    cout << "Today's country is... "<< dailyCountry<<endl; 
    return 0; 
}