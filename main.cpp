#include <iostream>
#include <fstream>
#include <string>
#include "graph.h"

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
        // Y - łączna liczba wierzchołków
        // Z - łączna liczba krawędzi 
        input_file >> X >> Y >> Z;
        Graph graph(0, Z);
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
                input_file.close();
                return 0;
            }
            graph.InsertEdge(temp_node_a, temp_node_b, temp_edge_weight, 0);
        }
        //sprawdzenie poprawnosci wczytanych wartosci
        //indeks 0 - pierwszy wierzcholek
        //indeks 1 - drugi wierzcholek
        //indeks 2 - waga polaczenia
        graph.print();

        input_file.close();
    }
    else {
        std::cout << "Plik nie zostal otwarty poprawnie" << std::endl;
    }

}
