#include <iostream>
#include <fstream>
#include <string>

#define EDGES_MAX 1024

int main()
{
    std::fstream input_file;
    input_file.open("input.txt", std::ios::in | std::ios::out);
    std::string display;
    int X, Y, Z;
    
    if (input_file.good() == true)
    {
        std::cout << "Plik otwarty poprawnie" << std::endl;
        //tu operacje na pliku (zapis/odczyt)
        // X - wierzchołek startowy
        // Y - łączna liczba węzłów
        // Z - łączna liczba krawędzi 
        input_file >> X >> Y >> Z;
        int graph[Z][3];
        int temp_node_a, temp_node_b, temp_edge_weight;
        for(int i = 0; i < Z; i++){
            input_file >> temp_node_a >> temp_node_b >> temp_edge_weight;
            try{
                if((temp_node_a > Y) || (temp_node_b > Y)){
                    throw "Nieprawidlowy numer wierzcholka!";
                }else if(temp_node_a == temp_node_b){
                    throw "Nie mozna utworzyc autostrady wychodzacej i wchodzacej do tego samego miasta";
                }else if(temp_edge_weight <= 0){
                    throw "Podano niedodatnia wage krawedzi";
                }
            }catch(const char* msg) {
                std::cerr << msg << std::endl;
                return 0;
            }
            graph[i][0] = temp_node_a;
            graph[i][1] = temp_node_b;
            graph[i][2] = temp_edge_weight;
        }
        //sprawdzenie poprawnosci wczytanych wartosci
        //indeks 0 - pierwszy wierzcholek
        //indeks 1 - drugi wierzcholek
        //indeks 2 - waga polaczenia
        for(int i = 0; i < Z; i++){
            std::cout << graph[i][0] << " " << graph[i][1] << " " << graph[i][2] << std::endl;
        }

        input_file.close();
    }
    else {
        std::cout << "Plik nie zostal otwarty poprawnie" << std::endl;
    }

}
