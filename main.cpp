#include <iostream>
#include <iomanip>
#include "habitaciones.cpp"
#include <fstream>
//#include "ncurses.h"
using namespace std;
#include "protagonista.cpp"

void cleare(void){ 
    cout << "\x1B[2J\x1B[H";
}

void pasillo(tablero& a,int b,int * pm1,int* pm2,int* pm3){
    
      if(b==1){
        int i=pm1[0];
        int h=(pm2[1]-i)/2;
        int j=pm1[1]+1;
        int x=h;
       while(h>0){
           a.set_pos(i,j,'#');
           a.set_pos(pm2[0],pm2[1]-x,'#');
           j++;
           h--;
           x--;
       }
       for(int m=pm1[0]-1;m>=pm2[0];m--){
           a.set_pos(m,j-1,'#');
       }
    }
     else{
        if(b==2){
            int i=pm3[2]-1;
            int j=pm3[3];
            int h=(pm3[2]-pm2[2])/2;
            int x=h;
            while(h>0){
                a.set_pos(i,j,'#');
                a.set_pos(pm2[2]+x,pm2[3],'#');
                i--;
                h--;
                x--;
            }
            for(int m=pm3[3]+1;m<=(pm2[3]-1);m++){
           		a.set_pos(pm3[2]-((pm3[2]-pm2[2])/2),m,'#');
            }	
        }
        else{
            int i=pm1[2]+1;
            int j=pm1[3];
            int h=(pm3[0]-pm1[2])/2;
            int x=h;
            while(h>0){
            	a.set_pos(i,j,'#');
            	a.set_pos(pm3[0]-x,pm3[1],'#');
            	i++;
            	h--;
            	x--;
            	
            }
            for(int m=pm3[1]-1;m>=pm1[3];m--){
            	a.set_pos(pm3[0]-(pm3[0]-pm1[2])/2,m,'#');
            }
            
        }
    }
    
}
int main(void){
	// variables necesarias..
	//1º posicion de inicio habittaciones mazmo..
	int* x_maz;
	int* y_maz;
	int* p_maz;
	int* p_maz1;
	int* p_maz2;
	int* p_m_a;
	//inicializacion..
	x_maz=new int [3];
	y_maz=new int [3];
	
		// Menu de entrada:
	cout << "Bienvenido al juego.."<< endl;
	cout << "Desea crear una mazmorra aleatoriamente o leerla desde un fichero.."
		 << "elija (a) ó (f)..."<< endl;
	char eleg;
	cin >> eleg; //eleccion de la opcion
	cout << "elija las dimensiones del tablero: \n\n\n" <<
			"UN MINIMO DE 28 Y UN MAXIMO DE 40 PARA FILAS Ó COLUMNAS.."<< endl;
			
	int d_1,d_2;// dimensiones del tablero..
	bool k=false;
	while(!k){
			cout << "filas: " ; 	
			cin>> d_1; 
			cout << endl;
			cout << "columnas: "; 	
			cin >>d_2; 
			cout << endl;
			if(((d_1>=28)&&(d_1<=40))&&((d_2<=40)&&(d_2>=28))){
				k=true;
				
			}
			else{
				cout << "Datos incorrectos elija de nuevo..."<< endl;
				cout << "elija las dimensiones del tablero: \n\n\n" 
					 <<"UN MINIMO DE 28 Y UN MAXIMO DE 40 PARA FILAS Ó COLUMNAS.."<< endl;
			}
			
	}
	
	//	habitacionArray = new habitacion[8];
	//monstruosArray[0] = new habitacion(a,b,a);
	tablero a(d_1,d_2); //tablero
	prota mayra(2,2,a); //protagonista
	
	
	monstruos* monstruosArray;
	int n_m=6;
	monstruosArray= new monstruos[n_m]; //inicializacion por defecto
	habitacion* habitacionArray;
	int n_h=3;
	habitacionArray= new habitacion[n_h]; //inicializacion por defecto
	
	bool elecc_=true;  //eleccion de un a pocion adecuada..
	while(elecc_){
		if(eleg=='a'){ // error del switch.. no crea variables..
			 habitacionArray[0].fun_fiche_datos(1,a);
			 x_maz[0]=habitacionArray[0].datos_maz(1);
			 y_maz[0]=habitacionArray[0].datos_maz(3);
			 p_maz=habitacionArray[0].puertas_maz();
			 
			 habitacionArray[1].fun_fiche_datos(2,a);
			 x_maz[1]=habitacionArray[1].datos_maz(1);
			 y_maz[1]=habitacionArray[1].datos_maz(3);
			 p_maz1=habitacionArray[1].puertas_maz();
			 
			 habitacionArray[2].fun_fiche_datos(3,a);
			 x_maz[2]=habitacionArray[2].datos_maz(1); 
			 y_maz[2]=habitacionArray[2].datos_maz(3);
			 p_maz2=habitacionArray[2].puertas_maz();
			 p_m_a=habitacionArray[2].amult();
			 elecc_=false;
			
    		pasillo(a,1,p_maz,p_maz1,p_maz2);
 			pasillo(a,3,p_maz,p_maz1,p_maz2);
			pasillo(a,2,p_maz,p_maz1,p_maz2);
			
			monstruosArray[0].set_mons(x_maz[0]+2,y_maz[0]+2,a);
			monstruosArray[1].set_mons(x_maz[0]+2,y_maz[0]+3,a);
			monstruosArray[2].set_mons(x_maz[1]+2,y_maz[1]+2,a);
			monstruosArray[3].set_mons(x_maz[1]+2,y_maz[1]+3,a);
			monstruosArray[4].set_mons(x_maz[2]+2,y_maz[2]+2,a);
			monstruosArray[5].set_mons(x_maz[2]+2,y_maz[2]+3,a);

			
		}
		else{
			if(eleg=='f'){
				elecc_=false;
				ifstream textfile;
				char nombrefichero[80];
				cout << "introduzca el nombre del fichero: ";
				cin >> nombrefichero;
				textfile.open(nombrefichero);
				if(!textfile.is_open())
    			{
    				cout <<"el fichero no se ha podido abrir .. intentelo de nuevo.."<< endl;
    				cin>> nombrefichero;
    				
					
    				textfile.open(nombrefichero);
				}
    			
    				int** p_mazz;
    				int datos,j;
					char t_e;
					textfile >>datos;
					for(int i=1;i<=datos;i++){
						textfile>>t_e;
						textfile>> j;
						if(t_e=='m'){
							habitacionArray= new habitacion[j];
							p_mazz=new int* [j];
							n_h=j;
							i+=j;
							int d_m,d_m1,t_pm;
							for(int m=0;m<j;m++){
								textfile>>d_m;
								textfile>>d_m1;
								textfile>> t_pm;
								
								habitacionArray[m].dat_lee_fich(t_pm,d_m,d_m1,a);
							}
						}
						else{
							if(t_e=='o'){
								monstruosArray=new monstruos[j];
								i+=j;
								int d_m,d_m1;
								for(int m=0;m<j;m++){
									textfile>>d_m;
									textfile>>d_m1;
									monstruosArray[m].set_mons(d_m,d_m1,a);
								}
							}
							else{
								if(t_e=='a'){
									int d_m,d_m1;
									textfile>>d_m;
									textfile>>d_m1;
									habitacionArray[n_h-1].set_amut_pos(d_m,d_m1,a);
									i+=j;
								}
							}
							
						}
    				}
			
				for(int m=0;m<n_h;m++){
					pasillo(a,habitacionArray[m].tipo_hm(),habitacionArray[0].puertas_maz(),habitacionArray[1].puertas_maz(),habitacionArray[2].puertas_maz());
				}
			
			}
			else{
				cout << "el argumento no es correcto.."<< endl;
				cout << " (a)leatorio ó lectura desde (f)ichero: ";
				cin >> eleg;
				cout << endl;
			}
		}
	}
	
	
	char p;	//almacenamiento de direccion hacia la que moverse
	bool juego=false; // mantiene el juego 
 	// JUEGO..
 
	while(!juego){
		a.pintar_tablero();
		for(int i=0;i<n_m;i++){
			monstruosArray[i].mov_m(a);
		}	
		cout << "Numero de vidas restantes: "<<mayra.con_vida()<< endl;
	 	cin >> p;
		cleare();
		switch (p){
			case 'i': 	
				mayra.b_pro(a);
				mayra.set_dp(1,a);
				mayra.p_pro(a);
				mayra.Vida(a);
			break;
			case 'j':
				mayra.b_pro(a);
				mayra.set_dp(2,a);
				mayra.p_pro(a);
				mayra.Vida(a);
			break;
			case 'l':
				mayra.b_pro(a);
				mayra.set_dp(4,a);
				mayra.p_pro(a);
				mayra.Vida(a);
			break;
			case 'k':
				mayra.b_pro(a);
				mayra.set_dp(3,a);
				mayra.p_pro(a);
				mayra.Vida(a);
			break;
			case 'f':
				juego=true;
			break;
			default:
				cout << "ELIJA OTRA OPCION.."<< endl; 
				cout <<setw(30)<<" (Arriba) i "<< endl;
				cout << "   (Izquierda) j                  (Derecha) l"<< endl;
				cout << setw(30)<<" (Abajo) k "<< endl;
		}
		int es_pos;
		if(mayra.amut_p_gan(p_m_a)==1){
			es_pos=1;
		}
		if((es_pos==1)&&(mayra.posicion()==2)){
			cleare();
	 		cout <<"\n\n\n"<< setw(50)  <<"HAS GANADO!!	" << endl;
	 		cout <<"\n\n\n"<< setw(50)  <<"HAS GANADO!!	" << endl;
	 		cout <<"\n\n\n"<< setw(50) 	<<"HAS GANADO!!	" << endl;
	 		cout <<"\n\n\n"<< setw(50)  <<"HAS GANADO!!	" << endl;
	 		cout <<"\n\n\n";
	 		juego=true;
		}
		int u=1;
	 	if(mayra.con_vida()<=0){
	 		juego=true;
	 		u=0;
	 	}
	 	if((juego==true)&&(u==0)){
	 		
	 		cleare();
	 		cout << setw(50)<<"\n\n\nGAME OVER!!	" << endl;
	 		cout << setw(50)<<"\n\n\nGAME OVER!!	" << endl;
	 		cout << setw(50)<<"\n\n\nGAME OVER!!	" << endl;
	 		cout << setw(50)<<"\n\n\nGAME OVER!!	" << endl;
	 	}
	}
}
