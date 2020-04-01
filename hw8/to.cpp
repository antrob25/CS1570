



using namespace std;

#include <iostream>
#include <cstring>
#include <fstream>

int main()
{
  srand(time(NULL));
  ifstream fin;
  ofstream fout;
  char in[20]= "in.txt", out[20]= "out.txt";
  char replace[30]="bob", temp[300], x[30];
  char first[30] = "one", sec[30]= "goat";

  fin.open(in);
  fout.open(out);
  while (fin>>x)
  {
    if (!strcmp(x,first))
    {
      fout<<replace;
      fin.getline(temp,299);
      fout<<temp<<endl;
    }
    else if(!strcmp(x,sec))
    {
      fout<<replace;
      fin.getline(temp,299);
      fout<<temp<<endl;
    }
    else
    { 
      fout<<x;
      fin.getline(temp,299);
      fout<<temp<<endl;
    }
  }
  fin.close();
  fout.close();
  return 0;
}
