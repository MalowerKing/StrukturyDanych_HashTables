class HashTableOpenModulo {
private:
unsigned int rozmiarTablicy = 10;
unsigned int zajetosc = 0;

float czynnikZajetosci = 0.0;

unsigned int hashFunction(int i) {return i%rozmiarTablicy;};

public:
int* table;

HashTableOpenModulo(unsigned int rozmiar) {
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
                int i = 0;
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
                int i = 0;
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

            ~HashTableOpenModulo() {
        delete[] table;
    }
};
