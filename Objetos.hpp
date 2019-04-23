#include <time.h>
#include <cstdlib>
#include <conio.h>

class PLAYER;
class VEGETTA;

// Variables globales
int Turno;
int iIntentos=0;
bool GAME_OVER=false;
// Reglas del juego
int iPlayS, iPlayP, iPlayD, iPlay;
std::string sPlayN, sPlayN2;



class VEGETTA{
	bool FULL;
	int x,y; int s,p,d; std::string n;
	
public:
	//Constructor
	VEGETTA(int _xX,int _yY);
	~VEGETTA(){}
	
	//Funciones para acceder a miembro privada
	int FnIntObtX(){ return x; }
	int FnIntObtY(){ return y; }
	int FnIntObtS(){ return s; }
	int FnIntObtP(){ return p; }
	int FnIntObtD(){ return d; }
	void RestarSalud(int RS){ s = (s-RS)+d; }
	std::string getNombre(){ return n; }
	
		// Funciones
		void vFnPintar(); // Dibujar Vegetta
		void vFnBorrar(); // Borrar Vegetta
		void vFnMover();  // Mover Vegetta
		void vFnHeart();  // Dibuja y Borra resultados
		
		friend class PLAYER;
		void vFnATQ(PLAYER &Sparck);
	 
	
};

class PLAYER{	
	bool FULL;
	int x,y; int s,p,d; std::string n;
	//NOVA
	int Nova_X , Nova_Y, Nova_S, Nova_P, Nova_D;
	
public:
	//Constructor
	PLAYER(int _xX,int _yY);
	~PLAYER(){}
		
	//Funciones para acceder a miembro privada
	int FnIntObtX(){ return x; }
	int FnIntObtY(){ return y; }
	int FnIntObtS(){ return s; }
	int FnIntObtP(){ return p; }
	int FnIntObtD(){ return d; }
	void RestarSalud(int RS){ s = (s-RS)+d; }
	std::string getNombre(){ return n; }
	
		// Funciones
		void vFnPintar(); // Dibujar Player
		void vFnBorrar(); // Borrar Player
		void vFnMover();  // Mover Player
		void vFnHeart();  // Dibuja y Borra resultados

		friend class VEGETTA;
		void vFnATQ(VEGETTA &Nova);	 
	
};




/*****************************************************************************************************
							CLASE VEGETTA
*****************************************************************************************************/

VEGETTA::VEGETTA(int _xX,int _yY){
	x = _xX;
	y = _yY;
	if(iPlay == 1){ n = sPlayN; }else{ n = sPlayN2; }
	s = iPlayS;
	p = 1+rand()%iPlayP;
	d = 2+rand()%iPlayD;
	vFnPintar();
	FULL = true;
}

void VEGETTA::vFnHeart(){
	gotoxy(99,4); std::cout << "Salud:     ";
	gotoxy(99,5); std::cout << "Power:     ";
	gotoxy(99,6); std::cout << "Defensa:     ";
	gotoxy(99,4); std::cout << "Salud: "   << s << std::endl;
	gotoxy(99,5); std::cout << "Power: "   << p << std::endl;
	gotoxy(99,6); std::cout << "Defensa: " << d << std::endl;
}

void VEGETTA::vFnPintar(){
	gotoxy(99,3); std::cout << n << std::endl;
	gotoxy(99,4); std::cout << "Salud: "   << s << std::endl;
	gotoxy(99,5); std::cout << "Power: "   << p << std::endl;
	gotoxy(99,6); std::cout << "Defensa: " << d << std::endl;
	gotoxy(x,y); printf("<Q");
}

void VEGETTA::vFnBorrar(){
	gotoxy(x,y); printf("  ");
}

void VEGETTA::vFnMover(){
	gotoxy(22,24); printf("                              ");
	gotoxy(22,24); printf("Nova :: X=%d y Y=%d",x,y);
	
	if(  y >= 4 && FULL == false){
		vFnBorrar(); y--; vFnPintar();
		if( y == 4){ FULL=true; }		
	}
	
	if(  y <= 18 && FULL == true){
		vFnBorrar(); y++; vFnPintar();
		if( y == 18 ){ FULL=false; }
	}
	
}



/*****************************************************************************************************
							CLASE PLAYER
*****************************************************************************************************/


PLAYER::PLAYER(int _xX,int _yY){
	x = _xX;
	y = _yY;
	if(iPlay == 0){ n = sPlayN; }else{ n = sPlayN2; }
	s = iPlayS;
	p = 1+rand()%iPlayP;
	d = 2+rand()%iPlayD;
	vFnPintar();
	FULL = true;
}

void PLAYER::vFnHeart(){
	gotoxy(3,2); 	printf("Salud:     ");
	gotoxy(14,2);	printf("Power:     ");
	gotoxy(24,2); 	printf("Defensa:     ");
	gotoxy(3,2); 	printf("Salud:%d",s);
	gotoxy(14,2);	printf("Power:%d",p);
	gotoxy(24,2); 	printf("Defensa:%d",d);
}

void PLAYER::vFnPintar(){
	gotoxy(3,1); 	std::cout << n << std::endl;
	/*
	gotoxy(3,2); 	printf("Salud:    ");
	gotoxy(14,2);	printf("Power:    ");
	gotoxy(24,2); 	printf("Defensa:    ");
	*/
	gotoxy(3,2); 	printf("Salud:%d",s);
	gotoxy(14,2);	printf("Power:%d",p);
	gotoxy(24,2); 	printf("Defensa:%d",d);
	gotoxy(x,y); printf("Q>");
}

void PLAYER::vFnBorrar(){
	gotoxy(x,y); printf("  ");
}

void PLAYER::vFnMover(){
		gotoxy(22,22); printf("					                    ");
		gotoxy(22,22); printf("Sparck :: X=%d y Y=%d",x,y);
		
		if(  y >= 4 && FULL == false){
			vFnBorrar(); y--; vFnPintar();
			if( y == 4){ FULL=true; }		
		}
		
		if(  y <= 18 && FULL == true){
			vFnBorrar(); y++; vFnPintar();
			if( y == 18 ){ FULL=false; }
		}
		
}

void PLAYER::vFnATQ(VEGETTA &Nova){
	
	p = 10+rand()%10;
	d = 3+rand()%7;
	
	int Nova_X = Nova.x;
	int Nova_Y = Nova.y;
	
	if(iIntentos == 3){
		gotoxy(37,2); 	printf("                                                             ");
		if(s > Nova.FnIntObtS()){
			gotoxy(37,2); 	printf("Va ganando Sparck por %d de ventaja", (s - Nova.FnIntObtS()));
		}else if(s == Nova.FnIntObtS()){
			gotoxy(37,2); 	printf("Esto es un empate!!!");
		}
		
		Turno++;
		iIntentos =0;
	}
	
	if( x < Nova_X+3 ){ 
		vFnBorrar(); x++; vFnPintar();
	}
	
	if( x == Nova_X+3 && y != Nova_Y ){
		vFnBorrar();
		srand(time(NULL));
		x = 4+rand()%40;
		y = 4+rand()%16;
		
		if( x <= 4 || x > 40){
			x = 29;
		}
		
		if( y > 17 || y < 5 || y == 18 || y == 3 || y == 4 ){
			y = 13;
		}

		//getch();
		vFnBorrar();
		iIntentos++;
		Sleep(60);
		vFnPintar(); 
	}
	
			// || (x+1 == Nova_X-1 && y == Nova_Y)
	if( (x == Nova_X && y == Nova_Y) || (x+1 == Nova_X && y == Nova_Y) || (x+1 == Nova_X-1 && y == Nova_Y)){
		vFnBorrar();
		srand(time(NULL));
		x = 3+rand()%40;
		y = 3+rand()%15;
		
		if( x <= 4 || x > 40){
			x = 29;
		}
		
		if( y > 17 || y < 5 || y == 18 || y == 3 || y == 4 ){
			y = 13;
		}
		
		gotoxy(3,2); 	printf("Salud:    ");
		gotoxy(99,4); std::cout << "Salud:     ";
		gotoxy(37,2); 	printf("                                                             ");
		int CalSalud = (Nova.FnIntObtS() - p)+Nova.FnIntObtD();
		gotoxy(37,2); 	printf("Sparck a Nova: (%d-%d)+%d = %d ",Nova.FnIntObtS(), p, Nova.FnIntObtD(), CalSalud);
		//getch();
		iIntentos++;
		Nova.RestarSalud(p);
		vFnBorrar(); //Turno++;
		vFnPintar();
	}
	
}


/****************************************************************************************************
						FUNCIONES
****************************************************************************************************/

void VEGETTA::vFnATQ(PLAYER &Sparck){
	
	p = 10+rand()%10;
	d = 3+rand()%7;
	
	int _SxX = Sparck.x;
	int _SyY = Sparck.y;
	
	if(iIntentos == 3){
		gotoxy(37,2); 	printf("                                                             ");
		if(s > Sparck.FnIntObtS()){
			gotoxy(37,2); 	printf("Va ganando Nova por %d de ventaja", (s - Sparck.FnIntObtS()));
		}else if(s == Sparck.FnIntObtS()){
			gotoxy(37,2); 	printf("Esto es un empate!!!");
		}
		Turno--;
		iIntentos =0;
	}
	
	if( _SxX-3 <	x ){ 
		vFnBorrar(); x--; vFnPintar();
	}
	
	if( x == _SxX-3 && y != _SyY ){
		vFnBorrar();
		srand(time(NULL));
		x = 40+rand()%94;
		y = 4+rand()%16;
		
		if( x > 90 ){
			x = 79;
		}
		
		if( y > 17 || y < 5 || y == 18 || y == 3 || y == 4 ){
			y=14;
		}
		
		//getch();
		iIntentos++;
		vFnBorrar();
		Sleep(60);
		vFnPintar(); 
	}
	
		// || (x-1 == _SxX+1 && y == _SyY)
	if( (x == _SxX && y == _SyY) || (x-1 == _SxX && y == _SyY) || (x-1 == _SxX+1 && y == _SyY)){
		vFnBorrar();
		srand(time(NULL));
		x = 40+rand()%96;
		y = 3+rand()%15;
		
		if( x > 90){
			x = 79;
		}
		
		if( y > 17 || y < 5 || y == 18 || y == 3 || y == 4 ){
			y=14;
		}
		
		gotoxy(3,2); 	printf("Salud:    ");
		gotoxy(99,4); std::cout << "Salud:     ";
		gotoxy(37,2); 	printf("                                                             ");
		int CalSalud = (Sparck.FnIntObtS() - p)+Sparck.FnIntObtD();
		gotoxy(37,2); 	printf("Nova a Sparck: (%d-%d)+%d = %d",Sparck.FnIntObtS(), p, Sparck.FnIntObtD(), CalSalud);
		//getch();
		iIntentos++;
		Sparck.RestarSalud(p);
		vFnBorrar(); //Turno--;
		vFnPintar(); 
	}
	
}
