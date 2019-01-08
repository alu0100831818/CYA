#pragma once
class habitacion{
  int px,py;      //posicion de inicio
  int* p_puertas; // posicion de las puertas, pasillos!
  int* p_amut;    //posicion del amuleto.
  int x,y;        //tamaño paredes habitacion.
  int t_hm; // tipo de habitacion.
  public:
   
 habitacion(void);
  
  void fun_fiche_datos(int t_p,tablero& tablerin_);
 
  void dat_lee_fich(int t_p,int c,int b,tablero& a);
 
  int datos_maz(int i);
  
  void atributos(int i,tablero& tablerin_,int u);
  
  int* puertas_maz(void);
  
  int* amult(void);
  
  int tipo_hm(void);
  
  void set_amut_pos(int d,int b,tablero& a);
  
  
};