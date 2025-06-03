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
               losowe[y] = rand() % i +1; 
        }

        sprintf(buffer, "Open_Modulo_%d.csv", i);
        
        myFile.open(buffer, ios::app);

        HashTableOpenModulo tableOpen(i);

        cout << buffer << endl;
        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.insertItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.insertItem(losowe[y]);}
        };

        myFile.close();

        sprintf(buffer, "Open_Modulo_%d_remove.csv", i);
        
        myFile.open(buffer, ios::app);

        cout << buffer << endl;
        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.deleteItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.deleteItem(losowe[y]);}
        };

        myFile.close();


};

void createPlot_openMulti(int i) {

       auto begin = chrono::steady_clock::now();
        auto end = chrono::steady_clock::now();

        sprintf(buffer, "Open_Multi_%d.csv", i);

        int* losowe = new int[i];
        for (int y = 0; y < i; y++) {
               losowe[y] = rand() % i +1; 
        }
        
        myFile.open(buffer, ios::app);

        cout << buffer << endl;
        HashTableOpenMulti tableOpen(i);

        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.insertItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.insertItem(losowe[y]);}
        };

        myFile.close();

        sprintf(buffer, "Open_Multi_%d_remove.csv", i);
        
        myFile.open(buffer, ios::app);

        cout << buffer << endl;
        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.deleteItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.deleteItem(losowe[y]);}
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
               losowe[y] = rand() % i +1; 
        }

        cout << buffer << endl;
        HashTableOpenFoldingAcc tableOpen(i);

        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.insertItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.insertItem(losowe[y]);}
        };

        myFile.close();

        sprintf(buffer, "Open_Fold_%d_remove.csv", i);
        
        myFile.open(buffer, ios::app);

        cout << buffer << endl;
        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.deleteItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.deleteItem(losowe[y]);}
        };

        myFile.close();
}

void createPlot_open_opt(int i) {

       auto begin = chrono::steady_clock::now();
        auto end = chrono::steady_clock::now();

        int* losowe = new int[i];
        for (int y = 0; y < i; y++) {
               losowe[y] = y+1; 
        }

        sprintf(buffer, "Open_Modulo_%d_opt.csv", i);
        
        myFile.open(buffer, ios::app);

        HashTableOpenModulo tableOpen(i);

        cout << buffer << endl;
        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.insertItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.insertItem(losowe[y]);}
        };

        myFile.close();

        sprintf(buffer, "Open_Modulo_%d_remove_opt.csv", i);
        
        myFile.open(buffer, ios::app);

        cout << buffer << endl;
        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.deleteItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.deleteItem(losowe[y]);}
        };

        myFile.close();


};

void createPlot_openMulti_opt(int i) {

       auto begin = chrono::steady_clock::now();
        auto end = chrono::steady_clock::now();

        sprintf(buffer, "Open_Multi_%d_opt.csv", i);

        int* losowe = new int[i];
        for (int y = 0; y < i; y++) {
               losowe[y] =  y+1; 
        }
        
        myFile.open(buffer, ios::app);

        cout << buffer << endl;
        HashTableOpenMulti tableOpen(i);

        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.insertItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.insertItem(losowe[y]);}
        };

        myFile.close();

        sprintf(buffer, "Open_Multi_%d_remove_opt.csv", i);
        
        myFile.open(buffer, ios::app);

        cout << buffer << endl;
        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.deleteItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.deleteItem(losowe[y]);}
        };

        myFile.close();
}

void createPlot_openFold_opt(int i) {

       auto begin = chrono::steady_clock::now();
        auto end = chrono::steady_clock::now();

        sprintf(buffer, "Open_Fold_%d_opt.csv", i);
        
        myFile.open(buffer, ios::app);

        int* losowe = new int[i];
        for (int y = 0; y < i; y++) {
               losowe[i] =  y +1; 
        }

        cout << buffer << endl;
        HashTableOpenFoldingAcc tableOpen(i);

        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.insertItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.insertItem(losowe[y]);}
        };

        myFile.close();

        sprintf(buffer, "Open_Fold_%d_remove_opt.csv", i);
        
        myFile.open(buffer, ios::app);

        cout << buffer << endl;
        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.deleteItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.deleteItem(losowe[y]);}
        };

        myFile.close();
}

void createPlot_open_pes(int i) {

       auto begin = chrono::steady_clock::now();
        auto end = chrono::steady_clock::now();

        int* losowe = new int[i];
        for (int y = 0; y < i; y++) {
               losowe[y] =  y*i; 
        }

        sprintf(buffer, "Open_Modulo_%d_pes.csv", i);
        
        myFile.open(buffer, ios::app);

        HashTableOpenModulo tableOpen(i);

        cout << buffer << endl;
        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.insertItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.insertItem(losowe[y]);}
        };

        myFile.close();

        sprintf(buffer, "Open_Modulo_%d_remove_pes.csv", i);
        
        myFile.open(buffer, ios::app);

        cout << buffer << endl;
        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.deleteItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.deleteItem(losowe[y]);}
        };

        myFile.close();


};

void createPlot_openMulti_pes(int i) {

       auto begin = chrono::steady_clock::now();
        auto end = chrono::steady_clock::now();

        sprintf(buffer, "Open_Multi_%d_pes.csv", i);

        int* losowe = new int[i];
        for (int y = 0; y < i; y++) {
               losowe[y] = y*i; 
        }
        
        myFile.open(buffer, ios::app);

        cout << buffer << endl;
        HashTableOpenMulti tableOpen(i);

        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.insertItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.insertItem(losowe[y]);}
        };

        myFile.close();

        sprintf(buffer, "Open_Multi_%d_remove_pes.csv", i);
        
        myFile.open(buffer, ios::app);

        cout << buffer << endl;
        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.deleteItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.deleteItem(losowe[y]);}
        };

        myFile.close();
}

void createPlot_openFold_pes(int i) {

       auto begin = chrono::steady_clock::now();
        auto end = chrono::steady_clock::now();

        sprintf(buffer, "Open_Fold_%d_pes.csv", i);
        
        myFile.open(buffer, ios::app);

        int* losowe = new int[i];
        for (int y = 0; y < i; y++) {
               losowe[y] = y*i; 
        }

        cout << buffer << endl;
        HashTableOpenFoldingAcc tableOpen(i);

        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.insertItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.insertItem(losowe[y]);}
        };

        myFile.close();

        sprintf(buffer, "Open_Fold_%d_remove_pes.csv", i);
        
        myFile.open(buffer, ios::app);

        cout << buffer << endl;
        myFile << "czas,czynnik\n";
        for(int y = 0; y < i; y++) {

                if(y % (i/20) == 0) {MEASURE_SOMETHING(tableOpen.deleteItem(losowe[y])); myFile << "," << tableOpen.peekZajetosc() << "\n";}
                else {tableOpen.deleteItem(losowe[y]);}
        };

        myFile.close();
}


int main() {
        srand(time(NULL));

        createPlot_open(10000);
        createPlot_open(100000);

        createPlot_openMulti(10000);
        createPlot_openMulti(100000);

        createPlot_openFold(10000);
        createPlot_openFold(100000);

        createPlot_open_opt(10000);
        createPlot_open_opt(100000);

        createPlot_openMulti_opt(10000);
        createPlot_openMulti_opt(100000);

        createPlot_openFold_opt(10000);
        createPlot_openFold_opt(100000);

        createPlot_open_pes(10000);
        createPlot_open_pes(100000);

        createPlot_openMulti_pes(10000);
        createPlot_openMulti_pes(100000);

        createPlot_openFold_pes(10000);
        createPlot_openFold_pes(100000);


};
