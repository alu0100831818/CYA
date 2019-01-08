#include "tablero.cpp"
#include <cstdlib>
#include "Monstruos.cpp"
#include "habitaciones.hpp"

  habitacion::habitacion(void){}
  
  void habitacion::fun_fiche_datos(int t_p,tablero& tablerin_){
    t_hm=t_p;
   //redistribucion de la posicion segun el tablero..
    int t_x=tablerin_.datos_tabler(1);
    int t_y=tablerin_.datos_tabler(2);
    int l_x,l_y;
      //area disponible para la mazmorra...
      // x/2,y/2 siempre cogiendo la mas pequeña para el caso de maz_1

      if(t_p==1){
        x=rand()%5+ 4+(t_x/10);
        y=rand()%5+ 4+(t_y/10);
         
        px=3;
        py=3;
        
        
      }
      else{
          if(t_p==2){
            x=rand()%5+ 4+(t_x/10);
            y=rand()%5+ 4+(t_y/10);
         
            px=3;
            py=3+((t_y/2)+1);
        }
        else{
            x=rand()%5+ 5+(t_x/10);
            y=rand()%5+ 6+(t_y/10);
         
            px=3+((t_x/2)+1);
            py=3*(t_y/8);
        }
      }
    //comprobaciones:
    
    int f1=px+x;
    int f2=py+y;
    
      for(int i=px;i<f1;i++){
        for(int j=py;j<f2;j++){
          if(i==px||i==(f1-1))
              tablerin_.set_pos(i,j,'*');
          else{
            if(j==py||j==(f2-1))
              tablerin_.set_pos(i,j,'*');
          }
        }
      }
    atributos(t_p,tablerin_,1);
 } // cdatos aleatorios.
 
  void habitacion::dat_lee_fich(int t_p,int c,int b,tablero& a){
    t_hm=t_p;
    px=c;
    py=b;
    
    int t_x=a.datos_tabler(1);
    int t_y=a.datos_tabler(2);
    
    x=rand()%5+ 4+(t_x/10);
    y=rand()%5+ 4+(t_y/10);
    
    int f1=px+x;
    int f2=py+y;
    
      for(int i=px;i<f1;i++){
        for(int j=py;j<f2;j++){
          if(i==px||i==(f1-1))
              a.set_pos(i,j,'*');
          else{
            if(j==py||j==(f2-1))
              a.set_pos(i,j,'*');
          }
        }
        
      }
    atributos(t_p,a,2);
    
  } //datos desde ficheros.
 
  int habitacion::datos_maz(int i){
    if(i==1)
      return px;
    else{
      if(i==2){
        return px+x;
      }
      else{
        if(i==3){
          return py;
        }
        else
          return py+y;
      }
      
    }
  }
  
  void habitacion::atributos(int i,tablero& tablerin_,int u){
    p_puertas=new int [6];
    p_amut=new int [2];
    int p=tablerin_.datos_tabler(2);
    if(i==1) { //pintaremos la entrada a la primera mazmorra..
        tablerin_.set_pos(px,py+1,'x');
        
        tablerin_.set_pos(px+x-2,py+y-1,'+');
        p_puertas[0]=px+x-2;
        p_puertas[1]=py+y-1;
        
        tablerin_.set_pos(px+x-1,py+y-3,'+');
        p_puertas[2]=px+x-1;
        p_puertas[3]=py+y-3;
    }
    else{
        if(i==2){
            tablerin_.set_pos(px+3,py,'+');
            p_puertas[0]=px+3;
            p_puertas[1]=py;
            
            tablerin_.set_pos(px+x-1,py+3,'+');
            p_puertas[2]=px+x-1;
            p_puertas[3]=py+3;
      }
      else{
            tablerin_.set_pos(px,py+3,'+');
            p_puertas[0]=px;
            p_puertas[1]=py+3;
            
            tablerin_.set_pos(px,py+5,'+');
            p_puertas[2]=px;
            p_puertas[3]=py+5;
            if(u==1){
              p_amut[0]=px+x-2;
              p_amut[1]=py+5;
              tablerin_.set_pos(p_amut[0],p_amut[1],'&');
            }
            
            
        }
    }
  }
  
  int* habitacion::puertas_maz(void){
      return p_puertas;
  }
  
  int* habitacion::amult(void){
      return p_amut;
  }
  
  int habitacion::tipo_hm(void){
    return t_hm;
  }
  
  void habitacion::set_amut_pos(int d,int b,tablero& a){
    p_amut=new int [2];
    p_amut[0]=d;
    p_amut[1]=b;
    a.set_pos(p_amut[0],p_amut[1],'&');
  }
  
  
