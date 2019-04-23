#include <iostream>
#include <string>
#include "gotoxy.hpp"
#include "Objetos.hpp"
#include "Mensajes.hpp"

int main(){
	
	FnPintarEscenario();
	mIntro();
	mBorrador();
	FnPintarEscenario();
	
	
	int novaX = 40+rand()%96, novaY = 3+rand()%15;
	VEGETTA Nova(novaX,novaY);
	int sparckX = 3+rand()%40, sparckY = 3+rand()%15;
	PLAYER Sparck(sparckX,sparckY);
	
	OcultarCursor();
	
	while(!GAME_OVER){
		
		gotoxy(67,1); 	printf("Intentos:%d  ",iIntentos);
		Nova.vFnMover();
		Sparck.vFnMover();
		
		if( Sparck.FnIntObtS() <= 0 || Nova.FnIntObtS() <= 0){
			GAME_OVER = true;
		}
			
		if(Turno == 0 && iIntentos < 4){
			Sparck.vFnATQ(Nova);
		}
		
		if(Turno == 1 && iIntentos < 4){
			Nova.vFnATQ(Sparck);
		}
		
		Sleep(15);
	}
	
	system("cls");
	
	if( iPlay == 0 && Sparck.FnIntObtS() >= 0 || iPlay == 1 && Nova.FnIntObtS() >= 0 ){
		std::cout << "*****GAME OVER YOU WIN!!!*****"<< std::endl << "0> GANA: " << sPlayN << std::endl;
		std::cout <<iPlay<< " / 0> PIERDE:  " << sPlayN2 << std::endl;
	}else{
		std::cout << "****GAME OVER YOU LOSER!!!*****"<< std::endl << "0> GANA:  " << sPlayN2 << std::endl;
		std::cout <<iPlay<< " / 0> PIERDE:  " << sPlayN << std::endl;
	}
	
	
	
		
	
	getchar();
	getchar();
	return 0;
}
