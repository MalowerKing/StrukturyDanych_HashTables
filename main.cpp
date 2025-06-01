#include <cstdlib>
#include <iostream>
#include "include/simple_hash_open_addressing.hpp"
#include "include/multi_hash_open_addressing.hpp"
#include "include/folding_hash_open_addressing.hpp"
#include <chrono>
#include <bits/stdc++.h>
#include <fstream>
#include <time.h>

using namespace std;

#define START_TIMER begin = chrono::steady_clock::now();

#define STOP_TIMER end = chrono::steady_clock::now();\
myFile << chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();

#define MEASURE_SOMETHING(function) START_TIMER;\
function;\
STOP_TIMER;

char buffer[100];
fstream myFile;

void createPlot_open(int i) {

       auto begin = chrono::steady_clock::now();
        auto end = chrono::steady_clock::now();

        int* losowe = new int[i];
        for (int y = 0; y < i; y++) {
               losowe[i] = rand() % (i/10) +1; 
        }

        sprintf(buffer, "Open_Modulo_%d.csv", i);
        
        myFile.open(buffer, ios::app);

        HashTableOpenModulo tableOpen(i);

        cout << buffer << endl;
        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.insertItem(losowe[i])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.insertItem(losowe[i]);}
        };

        myFile.close();

        sprintf(buffer, "Open_Modulo_%d_remove.csv", i);
        
        myFile.open(buffer, ios::app);

        cout << buffer << endl;
        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.deleteItem(losowe[i])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.deleteItem(losowe[i]);}
        };

        myFile.close();


};

void createPlot_openMulti(int i) {

       auto begin = chrono::steady_clock::now();
        auto end = chrono::steady_clock::now();

        sprintf(buffer, "Open_Multi_%d.csv", i);

        int* losowe = new int[i];
        for (int y = 0; y < i; y++) {
               losowe[i] = rand() % i +1; 
        }
        
        myFile.open(buffer, ios::app);

        cout << buffer << endl;
        HashTableOpenMulti tableOpen(i);

        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.insertItem(losowe[i])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.insertItem(losowe[i]);}
        };

        myFile.close();

        sprintf(buffer, "Open_Multi_%d_remove.csv", i);
        
        myFile.open(buffer, ios::app);

        cout << buffer << endl;
        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.deleteItem(losowe[i])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.deleteItem(losowe[i]);}
        };

        myFile.close();
}

void createPlot_openFold(int i) {

       auto begin = chrono::steady_clock::now();
        auto end = chrono::steady_clock::now();

        sprintf(buffer, "Open_Fold_%d.csv", i);
        
        myFile.open(buffer, ios::app);

        int* losowe = new int[i];
        for (int y = 0; y < i; y++) {
               losowe[i] = rand() % i +1; 
        }

        cout << buffer << endl;
        HashTableOpenFoldingAcc tableOpen(i);

        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.insertItem(losowe[i])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.insertItem(losowe[i]);}
        };

        myFile.close();

        sprintf(buffer, "Open_Fold_%d_remove.csv", i);
        
        myFile.open(buffer, ios::app);

        cout << buffer << endl;
        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.deleteItem(losowe[i])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.deleteItem(losowe[i]);}
        };

        myFile.close();
}
int main() {
        srand(time(NULL));

        createPlot_open(100);
        createPlot_open(1000);
        createPlot_open(10000);
        createPlot_open(100000);
        createPlot_open(1000000);

        createPlot_openMulti(100);
        createPlot_openMulti(1000);
        createPlot_openMulti(10000);
        createPlot_openMulti(100000);
        createPlot_openMulti(1000000);

        createPlot_openFold(100);
        createPlot_openFold(1000);
        createPlot_openFold(10000);
        createPlot_openFold(100000);
        createPlot_openFold(1000000);
};
