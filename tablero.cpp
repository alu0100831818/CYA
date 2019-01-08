    #include "tablero.hpp"
     
    tablero::tablero(int a,int b)
     {
         x=a; //FILAS!!
         y=b; //COLUMNAS!!
         int d=x*y;
         T_= new char [d];
        
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                T_[(i-1)*y+j-1]=' ';
                if(i==1||j==1)
                    T_[(i-1)*y+j-1]='*';
                else{
                    if(i==x||j==y)
                        T_[(i-1)*y+j-1]='*';
                    else 
                        T_[(i-1)*y+j-1]=' ';
                }
            }
        }   
     }
  
    int tablero::datos_tabler(int a){
         if(a==1)
            return x;
         else{
                return y;
            }
        }
        
    void tablero::pintar_tablero(void){
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                cout << " ";
                cout << T_[(i-1)*y+j-1];
           }
            cout << endl;
        }
     }
     
    void tablero::set_pos(int i,int j,char c){
         T_[(i-1)*y+j-1]=c;
     }
     
    char tablero::get_dato(int i,int  j){
        return T_[(i-1)*y+j-1];
    }
