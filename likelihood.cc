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

double likelihoodRatio(std::vector<int> daten, double mu){
  double result = 1;
  for ( int k : daten ) {
     result *= (pow(k, k) * exp(-k))/std::tgamma(k+1);
   }
  result = prob(daten, mu) / result;
  return result;
}

void writeTxt(std::vector<int> daten){
  std::ofstream fout("likelihood.txt");
  double mu = 0;
  
  while(mu <= 6){
    fout << mu << " " << prob(daten, mu) << std::endl;
    mu+=0.1;
  }
  fout.close();
}

void writeNllTxt(std::vector<int> daten){
  std::ofstream fout("nll.txt");
  double mu = 0;
  
  while(mu <= 6){
    fout << mu << " " << -2 * log(prob(daten, mu)) << std::endl;
    mu+=0.1;
  }
  fout.close();
}

void writeDeltaNllTxt(std::vector<int> daten){
  std::ofstream fout("deltanll.txt");
  double mu = 0;

  while(mu <= 6){
    fout << mu << " " << -2 * log(prob(daten, mu)) + 2 * log(prob(daten, 3.11538)) << std::endl;
    mu+=0.1;
  }
  fout.close();
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
  double z = (-2*log(likelihoodRatio(daten,3.11538))-233) / sqrt(2* 233);
  std::cout << "z = " << z << std::endl;
  writeTxt(daten);
  writeNllTxt(daten);
  writeDeltaNllTxt(daten);
  return 0;
}

