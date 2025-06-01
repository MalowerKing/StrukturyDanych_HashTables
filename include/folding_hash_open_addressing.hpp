#include <cmath>
#include <cstdlib>
#include <cstdint>
using namespace std;

class HashTableOpenFoldingAcc {        
private:
unsigned int rozmiarTablicy = 10;
unsigned int zajetosc = 0;

float czynnikZajetosci = 0.0;

const uint32_t a = 37;                   // Base for polynomial hash
const uint32_t p = 4294967291u;  

unsigned int hashFunction(int key) {
         uint32_t ukey = static_cast<uint32_t>(key);
        uint64_t hash = 0;

        for (int i = 0; i < 4; ++i) {
            uint8_t byte = (ukey >> (8 * i)) & 0xFF;
            hash = (hash * a + byte) % p;
        }

        return static_cast<unsigned int>(hash % rozmiarTablicy);
};

public:
int* table;

HashTableOpenFoldingAcc(unsigned int rozmiar) {
        rozmiarTablicy = rozmiar;

        table = new int[rozmiarTablicy]();
        for (int i = 0; i < rozmiarTablicy; i++) {
                table[i] = 0;
        }
};

void deleteItem(int item) {
       int hashed = hashFunction(item);

        if(table[hashed] == item) table[hashed] = 0;
        else{
                int i = hashed;
               while (table[i] != 0 && table[i] != item) {
                        i = (i + 1) % rozmiarTablicy;
                }
                        table[i] = 0;
                };

        zajetosc--;
        czynnikZajetosci = (float)zajetosc / rozmiarTablicy;
        };

void insertItem(int item){
        int hashed = hashFunction(item);

        if (table[hashed] == 0) table[hashed] = item;
        else{
                unsigned int i = hashed;
                while (table[i] != 0 && table[i] != item) {
                        i = (i + 1) % rozmiarTablicy;
                }

                        table[i] = item;
                };

        zajetosc++;
        czynnikZajetosci = (float)zajetosc / rozmiarTablicy;

        };

float peekZajetosc() {
        return czynnikZajetosci;
        };

        ~HashTableOpenFoldingAcc() {
        delete[] table;
    }
};
