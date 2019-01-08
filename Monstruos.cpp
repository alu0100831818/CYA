
        #include "Monstruos.hpp"

        monstruos::monstruos(void){}
    
        void monstruos::set_mons(int x,int y,tablero& m){
        a=x;
        b=y;
            m.set_pos(x,y,'O');
    }
    
        monstruos::monstruos(int x,int y,tablero& m){
        a=x;
        b=y;
            m.set_pos(x,y,'O');
    }
    
        void monstruos::b_b_m(tablero& m){
        m.set_pos(a,b,' ');
    }
    
        void monstruos::mov_m(tablero& m){
        int v=rand()%2;
        if(v==0){
            if(m.get_dato(a,b+1)==' '){
                b_b_m(m);
                m.set_pos(a,b+1,'O');
                b+=1;
            }
            else{
                if(m.get_dato(a+1,b)==' '){
                     b_b_m(m);
                    m.set_pos(a+1,b,'O');
                    a+=1;
                }
            }
        }
        else{
            if(m.get_dato(a,b-1)==' '){
                 b_b_m(m);
                m.set_pos(a,b-1,'O');
                b-=1;
            }
            else{
                if(m.get_dato(a-1,b)==' '){
                     b_b_m(m);
                    m.set_pos(a-1,b,'O');
                    a-=1;
                }
            }
        
        }
    }
   
   