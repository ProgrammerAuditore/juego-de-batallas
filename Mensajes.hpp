void mIntro(){
	gotoxy(37,8); std::cout<<"Instrucciones:"<< std::endl;
	gotoxy(37,9); std::cout<<"0 = Sparck " << "|| 1 = Nova" << std::endl;
	gotoxy(37,10); std::cout<<"Elige a un jugador:"<< std::endl;
	gotoxy(37,11); std::cin>>iPlay;
	gotoxy(37,12); std::cout<<"Introduzca la cantidad de vida de los jugadores:"<< std::endl;
	gotoxy(37,13); std::cin>>iPlayS;
	
	if(iPlayS == 0){ iPlayS = 50;}
	
	iPlayS = int(iPlayS);
	iPlayP = int(iPlayS/2);
	iPlayD = int(iPlayP/2);
	
	system("cls");
	
	if( iPlay != 0 || iPlay != 1 ){  }
	switch(iPlay){
		case 1: iPlay = 1; gotoxy(37,2); printf("Tu eres Nova"); sPlayN = "Nova*"; Turno = 0; sPlayN2 = "Sparck"; //gotoxy(103,3);std::cout<<"*"<<std::endl;
			break;
		case 0: iPlay = 0; gotoxy(37,2); printf("Tu eres Sparck"); sPlayN = "Sparck*"; Turno = 1; sPlayN2 = "Nova"; //gotoxy(10,1);std::cout<<"*"<<std::endl;
			break;
		default:
			iPlay = 0; gotoxy(37,2); printf("Tu eres Sparck"); sPlayN = "Sparck*"; Turno = 0; sPlayN2 = "Nova"; //gotoxy(10,1);std::cout<<"*"<<std::endl;
	}
}

void mBorrador(){
	gotoxy(37,8); std::cout<<"                                                  "<< std::endl;
	gotoxy(37,9); std::cout<<"                                                  "<< std::endl;
	gotoxy(37,10); std::cout<<"                                                  "<< std::endl;
	gotoxy(37,11); std::cout<<"                                                  "<< std::endl;
	gotoxy(37,12); std::cout<<"                                                  "<< std::endl;
	gotoxy(37,13);  std::cout<<"                                                  "<< std::endl;
}
