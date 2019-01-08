#pragma once

class prota{
  int x;
  int y;
  int vida;
  
  public:
    prota(int a,int b,tablero& v);
    
    int amut_p_gan(int* pos_amut);
  
    int posicion(void);
    void p_pro(tablero& tablerin_);
    
    void b_pro(tablero& tablerin_);
    
    void set_dp(int i,tablero& a);
    
    void Vida(tablero& a);
    
    int con_vida(void);
};