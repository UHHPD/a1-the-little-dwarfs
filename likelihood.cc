#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>


double prob(std::vector<int> daten, double mu) 
{ 
  double result = 1;
   for ( int k : daten ) {
     result *= (pow(mu, k) * exp(-mu))/std::tgamma(k+1);
   }
  return result;
}

int main() {
  std::ifstream fin("datensumme.txt");
  std::vector<int> daten;
  int a;
  while (fin >> a) 
  {
    daten.push_back(a);
  }
  fin.close();
  std::cout << prob(daten,3.11538) << std::endl;
  return 0;
}

