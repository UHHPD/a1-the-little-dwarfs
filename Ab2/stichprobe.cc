#include<iostream>
#include<fstream>
#include<cmath>
  int main() {
    std::ifstream fin("datensumme.txt");
    const int N = 234;
    int a;
    double mittelwert = 0;
    for(int i = 0 ; i < N ; ++i) {
      fin >> a;
      mittelwert += a;
      }
    fin.close();
    mittelwert /= N;
    std::cout << "Mittelwert: " << mittelwert
    << std::endl;
    std::ifstream fin2("datensumme.txt");
    double varianz = 0;
    for(int i = 0 ; i < N ; ++i) {
      fin2 >> a;
      varianz += (a-mittelwert)*(a-mittelwert);
      }
      varianz /= N;
      std::cout << "Varianz: " << varianz << std::endl;
      std::cout << "Standardabweichung: " << sqrt(varianz)
        << std::endl;
      fin2.close();
}