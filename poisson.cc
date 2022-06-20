#include <vector>
#include <fstream>
#include <iostream>

int main(void){
std::vector<int> zaehler(11); 

std::ifstream fin("datensumme.txt");
int a;
while (fin >> a) {
  zaehler[a]+=1;
     }
  fin.close();
  for ( unsigned int k = 0 ; k < zaehler . size () ; ++ k ) {
std :: cout << k << ":" << zaehler [ k ] << std :: endl ;
}
  return 0;
  }