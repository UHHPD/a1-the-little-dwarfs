#include<iostream>
#include<fstream>
#include<cmath>
int main() {
  std::ifstream fin("datensumme.txt");
  std::ifstream fin2("datensumme.txt");

  const int N = 234;
  const int M = 9;
  double mitmit = 0;
  double mitvar = 0;
  std::ofstream fmit("mittelwerte.txt");
  std::ofstream fvar("varianzen.txt");
  int a;
for(int i = 0 ; i < N/M ; ++i) {
    double mittelwert = 0;
    for(int j = 0 ; j < M ; ++j) {
    fin >> a;
    mittelwert += a;
    }
    mittelwert /= M;
    std::cout << "Mittelwert: " << mittelwert << std::endl;
    fmit << mittelwert << std::endl;
    mitmit += mittelwert;
    double varianz = 0;
    for(int j = 0 ; j < M ; ++j) {
      fin2 >> a;
      varianz += (a-mittelwert)*(a-mittelwert);
      }
      varianz /= M;
      std::cout << "Varianz: " << varianz << std::endl;
      fvar << varianz << std::endl;
      mitvar += varianz;
      }
      fin.close();
      fin2.close();
      fmit.close();
      fvar.close();
      mitmit /= N/M;
      mitvar /= N/M;
      std::cout << "mittlerer Mittelwert:" << mitmit << std::endl;
      std::cout << "mittlere Varianz:" << mitvar << std::endl;
}