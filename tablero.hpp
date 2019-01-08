#pragma once

using namespace std;
class tablero{
    int x;
    int y;
    char* T_;
    public:
     
    tablero(int a,int b);
  
    int datos_tabler(int a);
        
    void pintar_tablero(void);
     
    void set_pos(int i,int j,char c);
     
    char get_dato(int i,int  j);
};