#include <stdio.h>
#include <string>
#include <pthread.h>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

std::string Convert (float number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();
}

int n;// variable para cantidad de puertos
int u=0;
int v=0;
int claseA=0;
int claseB=0;
int claseC=0;
float Promedio=0;
float sumaPeso=0;
int ContenedoresPre=0;
int ContenedoresEco=0;
string texto;
int NumContenedores;
int Porcentaje;
int TotalContenedores=0;
int ContenedoresEnElUltimoPuerto=0;
string marca;
int peso=0;
string MarcasZonaEco [14];
string MarcasZonaPre[6];
int nombrespuertos(){
	int s=1;
	int menu=0;
	cout << "ingrese el numero de puertos" <<endl; //nombres de los puertos 
	cin >>n;
	string texto[n]; //vector de puertos
	string puertosPeso[2][n];
	int ban=n;   //bandera
	int ban2=0;   //bandera2
    while(ban>0){
    	for(int i = 0; i < n; i++){
    		cout <<"ingrese nombre del puerto"<<endl;
    		cin >> texto[i];
    		puertosPeso[0][i]=texto[i];
    		ban=ban-1;
		}
    	cout <<"los puertos ingresados son :" <<endl;
    	int filas = (sizeof(texto)/sizeof(texto[0]));
    	for(int j=0;j<filas;j++){
    		cout<<"         "<<texto[j] <<"\t";
		}
		cout<<"\n";
			
	}
	int celdas [4][5]={0};
	string marcas [4][5]={{"x","x","x","x","x"},{"x","x","x","x","x"},{"x","x","x","x","x"},{"x","x","x","x","x"}};
	string tipoArticulo[4][5]={{"x","x","x","x","x"},{"x","x","x","x","x"},{"x","x","x","x","x"},{"x","x","x","x","x"}};
	int pesos[4][5]={0};
	string puertos[4][5];
	
	while (ban2<n){
		int fil;
		int col;
		string marca;
		string producto;
		int RecaudoPuerto=0;
		int asd=0;
		string Nombre = texto[ban2]; cout<<"\n";
		cout<<"Bienvenido a la seccion de llenado del puerto: " <<Nombre <<endl;
		ban2++;	
		int filas = (sizeof(celdas)/sizeof(celdas[0]));
    	int columnas = (sizeof(celdas[0])/sizeof(celdas[0][0]));
		cout<<"\nLas celdas disponibles en el barco se encuentran en ceros\n\n";
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				cout<<"    "<<celdas[i][j] <<"\t"; 
			}
			cout<<"\n";
		}
		int fi = (sizeof(marcas)/sizeof(marcas[0]));
    	int co = (sizeof(marcas[0])/sizeof(marcas[0][0]));
		cout<<"\nLas marcas ingresadas hasta ahora son:\n\n";
		for(int l=0;l<fi;l++){
			for(int m=0;m<co;m++){
				cout<<"          "<<marcas[l][m] <<"\t";
			}
			cout<<"\n";
		}
		int t = (sizeof(tipoArticulo)/sizeof(tipoArticulo[0]));
    	int w = (sizeof(tipoArticulo[0])/sizeof(tipoArticulo[0][0]));
		cout<<"\nLos ariculos hasta ahora son:\n\n";
		for(int r=0;r<t;r++){
			for(int s=0;s<w;s++){
				cout<<"          "<<tipoArticulo[r][s] <<"\t";
			}
			cout<<"\n";
		}
		int c = (sizeof(pesos)/sizeof(pesos[0]));
    	int d = (sizeof(pesos[0])/sizeof(pesos[0][0]));
		cout<<"\nEl peso hasta ahora es:\n\n";
		for(int y=0;y<c;y++){
			for(int z=0;z<d;z++){
				cout<<"         "<<pesos[y][z] <<"\t";
			}
			cout<<"\n";
		}
		cout <<"cuantos contenedores desea ingresar?" <<endl;
		cin >>NumContenedores;
		for(int k=0;k<NumContenedores;k++){
			cout<<"ingrese la fila de la 0 a la 3 para ubicar el contenedor"<<endl;
			cin>>fil;
			cout<<"ingrese la columna de la 0 a la 4 para ubicar el contenedor"<<endl;
			cin>>col;
			int tem=celdas[fil][col];
			if(tem!=0){
				cout<<"ingrese la fila valida a ubicar el contenedor"<<endl;
				cin>>fil;
				cout<<"ingrese la columna valida a ubicar el contenedor"<<endl;
				cin>>col;
			}
			if(fil>=4||col>=5){
				cout<<"ingrese la fila valida a ubicar el contenedor"<<endl;
				cin>>fil;
				cout<<"ingrese la columna valida a ubicar el contenedor"<<endl;
				cin>>col;
			}
			celdas[fil][col]=1;
			cout<<"ingrese la marca del contenedor"<<endl;
			cin>>marca;
			if(fil==0||col==0||fil==3||col==4){
				RecaudoPuerto=RecaudoPuerto+100;
				MarcasZonaEco[u]=marca;
				u++;	
			}
			if((fil==1&&(col==1||col==2||col==3))||(fil==2&&(col==1||col==2||col==3))){
				RecaudoPuerto=RecaudoPuerto+300;
				MarcasZonaPre[v]=marca;
				v++;
			}
			marcas[fil][col]=marca;
			cout<<"ingrese el tipo de producto"<<endl;
			cout<<"presione la letra a para Alimentos"<<endl;
			cout<<"presione la letra b para Dispositivos Electronicos"<<endl;
			cout<<"presione la letra c para Ropa y Textiles"<<endl;
			cin>>producto;
			tipoArticulo[fil][col]=producto;
			if (producto=="a"){
				claseA++;
			}
			if (producto=="b"){
				claseB++;
			}
			if (producto=="c"){
				claseC++;
			}
			cout<<"ingrese el peso del contenedor"<<endl; 
			cin>>peso;
			pesos[fil][col]=peso;
			ContenedoresEnElUltimoPuerto++;
			sumaPeso=sumaPeso+peso;
			
			
		}
		TotalContenedores=TotalContenedores+NumContenedores;
		int pesoPuert=0;
		pesoPuert=pesoPuert+sumaPeso;
		Porcentaje=((100*TotalContenedores)/20);
		float promedioPuerto=(pesoPuert/TotalContenedores);
		
	
		
		string NumeroString = Convert(promedioPuerto);
     

    	NumeroString =  ""+ NumeroString;
    	

		

		

		cout<<"\n";
		cout<<"el porcentaje de ocupacion actual del barco en el puerto "<<Nombre<<" es: "<<Porcentaje<<"%"<<endl;
		cout<<"\n";
		
		cout<<"el valor recaudado en el puerto "<<Nombre<<" es: $"<<RecaudoPuerto<<endl;
		
		for(int a=0;a<n;a++){
			puertosPeso[1][a]=NumeroString;
		}
	}
	cout<<"La cantidad de contenedores ingresados en todos los puertos es: "<<ContenedoresEnElUltimoPuerto<<endl; cout<<"\n";
	int f = (sizeof(MarcasZonaEco)/sizeof(MarcasZonaEco[0]));
		cout<<"\nLas Marcas en Zona Economica son: \n\n";
		for(int q=0;q<f;q++){
				cout<<"     "<<MarcasZonaEco[q] <<"\t";
			}
			cout<<"\n";
	int g = (sizeof(MarcasZonaPre)/sizeof(MarcasZonaPre[0]));
		cout<<"\nLas Marcas en Zona Premium son: \n\n";
		for(int o=0;o<f;o++){
				cout<<"     "<<MarcasZonaPre[o] <<"\t";
				
				int filas = (sizeof(celdas)/sizeof(celdas[0]));
   			 	int columnas = (sizeof(celdas[0])/sizeof(celdas[0][0]));
				cout<<"\nLas celdas disponibles en el barco se encuentran en ceros\n\n";
				for(int i=0;i<filas;i++){
					for(int j=0;j<columnas;j++){
					cout<<"     "<<celdas[i][j] <<"\t";
					}
					cout<<"\n";
				}
				int fi = (sizeof(marcas)/sizeof(marcas[0]));
    			int co = (sizeof(marcas[0])/sizeof(marcas[0][0]));
				cout<<"\nLas marcas ingresadas hasta ahora son:\n\n";
				for(int l=0;l<fi;l++){
					for(int m=0;m<co;m++){
						cout<<"           "<<marcas[l][m] <<"\t";
					}
					cout<<"\n";
				}
				int t = (sizeof(tipoArticulo)/sizeof(tipoArticulo[0]));
    			int w = (sizeof(tipoArticulo[0])/sizeof(tipoArticulo[0][0]));
				cout<<"\nLos articulos ingresados hasta ahora son:\n\n";
				for(int r=0;r<t;r++){
					for(int s=0;s<w;s++){
						cout<<"           "<<tipoArticulo[r][s] <<"\t";
					}
					cout<<"\n";
				}
				int c = (sizeof(pesos)/sizeof(pesos[0]));
    			int d = (sizeof(pesos[0])/sizeof(pesos[0][0]));
				cout<<"\nEl peso hasta ahora es:\n\n";
				for(int y=0;y<c;y++){
					for(int z=0;z<d;z++){
						cout<<"           "<<pesos[y][z] <<"\t";
					}
					cout<<"\n";
				}
				while(s==1)	{
				cout <<"seleccione una opcion"<<endl;
				cout <<"\n";
				cout <<"pres 1 contenedores por zonas y valor de los mismos"<<endl;
				cout <<"\n";
				cout <<"pres 2 promedio del peso de los contenedores"<<endl;
				cout <<"\n";
				cout <<"pres 3 cantidad de contenedores de cada clase"<<endl;
				cout <<"\n";
				cout <<"pres 4 puertos y promedio de peso"<<endl;
				cout <<"\n";
				cin >>menu;
				if(menu==1){
					string busqueda="";
								
					cout<<"contenedores en zona premium son:"<<u<<endl;
					cout<<"\n";
					cout<<"contenedores en zona Economica son:"<<v<<endl;
					cout<<"\n";
				}
				if(menu==2){
					Promedio=((sumaPeso/ContenedoresEnElUltimoPuerto));
					cout<<"El promedio de peso ingresado al barco es:"<<Promedio<<endl;
					cout<<"\n";
				}
				if(menu==3){
					cout<<"el numero de contenedores clase a es:"<<claseA<<endl;
					cout<<"\n";
					cout<<"el numero de contenedores clase 	b es:"<<claseB<<endl;
					cout<<"\n";
					cout<<"el numero de contenedores clase c es:"<<claseC<<endl;
					cout<<"\n";
				}
				if(menu==4){
					int x = (sizeof(puertosPeso)/sizeof(puertosPeso[0]));
    				int coa = (sizeof(puertosPeso[0])/sizeof(puertosPeso[0][0]));
					cout<<"\nLos puertos y los pesos son:\n\n";
					for(int l=0;l<x;l++){
						for(int m=0;m<coa;m++){
						cout<<"     "<<puertosPeso[l][m] <<"\t";
						}
					cout<<"\n";
				
					} 
				cout<<"pres 0 para salir o 1 para continuar"<<endl;
				cout<<"\n";
				cin>>s;
				}
			}
			cout<<"\n";
	} 
}
int main(){
	nombrespuertos();
	return 0;
}
