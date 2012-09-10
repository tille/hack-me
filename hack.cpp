#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define pb push_back

int flag,cont=0;
unsigned int t;
vector<int> a;
vector<char> b;
string s;

void calc(){
  freopen("words.in","r",stdin);
  while( cin >> s ){
    flag = 1;
    if(s.size() != t) flag = 0;
    for( unsigned int i = 0; i < a.size() && flag; ++i ){
      if( s[a[i]-1] != b[i] ) flag = 0;
    }
    if(flag){ 
      cout << s << endl;
      cont++;
    }
  }
  cout << cont << endl;
}

void e(int n, char lt){
  a.pb(n); b.pb(lt);
}

int main(){
  cin >> t;
  e(1,'t');
  e(2,'r');
  e(3,'a');
  e(4,'p');
  e(5,'e');
  
  calc();
  return 0;
}