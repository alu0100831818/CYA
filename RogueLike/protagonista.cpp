
    #include "protagonista.hpp"

    prota::prota(int a,int b,tablero& v){
      x=a;
      y=b;
      vida=5;
      p_pro(v);
  }
  
    int prota::amut_p_gan(int* pos_amut){
      if((x==pos_amut[0])&&(y==pos_amut[1])){
          return 1;
      }
  }
  
    int prota::posicion(void){
      if((x==2)&&(y==2)){
          return 2;
      }
  }
 
    void prota::p_pro(tablero& tablerin_){
        
        tablerin_.set_pos(x,y,'@');
    }
    
    void prota::b_pro(tablero& tablerin_){
        tablerin_.set_pos(x,y,' ');
    }
    
    void prota::set_dp(int i,tablero& a){
        if(i==1){ //i
           if(a.get_dato(x-1,y)!='*'){
                if((a.get_dato(x-1,y)=='+')||(a.get_dato(x-1,y)=='x')){
                    x-=2; 
                }
                else{
                    if(a.get_dato(x-1,y)=='O'){
                    }
                    else
                        x--;
                }
            }
        }
    
        else{
            if(i==2){ //j
                if(a.get_dato(x,y-1)!='*'){
                    if((a.get_dato(x,y-1)=='+')||(a.get_dato(x,y-1)=='x')){
                        y-=2; 
                    }
                    else{
                        if(a.get_dato(x,y-1)=='O'){
                        }
                        
                        else
                            y--;
                    }
                }
            }
            else{
                if(i==3){//k
                    if(a.get_dato(x+1,y)!='*'){
                        if((a.get_dato(x+1,y)=='+')||(a.get_dato(x+1,y)=='x')){
                            x+=2; 
                        }
                        else{
                            if(a.get_dato(x+1,y)=='O'){
                            }
                            
                            else
                                x++;
                        }
                    }     
                }
                else{//4=l
                    if(a.get_dato(x,y+1)!='*'){
                        if((a.get_dato(x,y+1)=='+')||(a.get_dato(x,y+1)=='x')){
                            y+=2; 
                        }
                        else{
                            if(a.get_dato(x,y+1)=='O'){
                            }
                            else
                                y++;
                        }
                    }
                }
            }
        }
    }
    
    void prota::Vida(tablero& a){
      if((a.get_dato(x-1,y)=='O')||(a.get_dato(x+1,y)=='O')||(a.get_dato(x,y-1)=='O')||(a.get_dato(x,y+1)=='O')){
          vida--;
      }
    }
    
    int prota::con_vida(void){
        return vida;
    }
