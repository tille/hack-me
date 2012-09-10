//g++ -framework ApplicationServices  test.cpp && ./a.out
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <ApplicationServices/ApplicationServices.h>

using namespace std;

#define pb push_back
#define S 30

int leters[S] = {'a','b','c','d','e',
                  'f','g','h','i','j',
                  'k','l','m','n','o',
                  'p','q','r','s','t',
                  'u','v','w','x','y','z'
                };

int codes[S] = {0,11,8,2,14,
                3,5,4,34,38,
                40,37,46,45,31,
                35,12,15,1,17,
                32,9,13,7,16,6
               };

int flag,cont=0;
unsigned int t;
vector<int> a;
vector<char> b;
string s;

CGEventRef events_down[S];
CGEventRef events_up[S];
CGEventRef especial,especial2;

void events_create(){
  for( int i=0; i < 26; ++i ){
    events_down[i] = CGEventCreateKeyboardEvent (NULL, (CGKeyCode)codes[i], true);
    events_up[i] = CGEventCreateKeyboardEvent (NULL, (CGKeyCode)codes[i], false);
  }
  especial = CGEventCreateKeyboardEvent (NULL, (CGKeyCode)76, true);
  especial2 = CGEventCreateKeyboardEvent (NULL, (CGKeyCode)76, false);
}

// enter 76
void event_key(int cc){

  CGEventPost(kCGHIDEventTap, events_down[cc]);
  CGEventPost(kCGHIDEventTap, events_up[cc]);
  
  CFRelease;
  CFRelease;
}

void print_word(string h){
  //events_create();
  for( int i=0; i<h.size(); ++i ){
    for( int j=0; j<26; ++j ){
      if(h[i] == leters[j] ){
        events_down[j] = CGEventCreateKeyboardEvent (NULL, (CGKeyCode)codes[j], true);
        CGEventPost(kCGHIDEventTap, events_down[j]);
        CFRelease(events_down[j]);
        
        events_up[j] = CGEventCreateKeyboardEvent (NULL, (CGKeyCode)codes[j], false);
        CGEventPost(kCGHIDEventTap, events_up[j]);
        CFRelease(events_up[j]);
        
        for( int i = 0; i < 4500; ++i){
          for( int j = 0; j < 4500; ++j){
          }
        }
        
      }
    }
  }
  especial = CGEventCreateKeyboardEvent (NULL, (CGKeyCode)76, true);
  CGEventPost(kCGHIDEventTap, especial);
  CFRelease(especial);
  
  especial2 = CGEventCreateKeyboardEvent (NULL, (CGKeyCode)76, false);
  CGEventPost(kCGHIDEventTap, especial2);
  CFRelease(especial2);
  

}

void create_event(int x, int y){
  
  CGEventRef click1_down, click1_up;
  
  click1_down = CGEventCreateMouseEvent(
    NULL, kCGEventLeftMouseDown, 
    CGPointMake(x, y), 
    kCGMouseButtonLeft 
  );
  
  CGEventPost(kCGHIDEventTap, click1_down);
  CFRelease(click1_down);
  
  
  click1_up = CGEventCreateMouseEvent(
    NULL, kCGEventLeftMouseUp,
    CGPointMake(x, y),
    kCGMouseButtonLeft
  );
  
  CGEventPost(kCGHIDEventTap, click1_up);
  CFRelease(click1_up);
}

void calc(){
  freopen("words.in","r",stdin);
  while( cin >> s ){
    flag = 1;
    if(s.size() != t) flag = 0;
    for( unsigned int i = 0; i < a.size() && flag; ++i ){
      if( s[a[i]-1] != b[i] ) flag = 0;
    }
    if(flag){ 
      print_word(s);
      cont++;
    }
  }
  print_word("");
  //cout << cont << endl;
}

void e(int n, char lt){
  a.pb(n); b.pb(lt);
}

int main(int argc, char* argv[]){
  cin >> t;
  int x=1075,y=670;
  create_event(x,y);
  
  for( int i = 660; i < 670; i++){
    create_event(x,i);
  }
  
  
  e(1,'g');
  //e(,7,'p');
  //e(6,'d');
  calc();
    
    return 0;
}