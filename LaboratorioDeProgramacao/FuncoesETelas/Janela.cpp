#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <conio.h>
#include <windows.h>

using namespace std;                                      
void gotoxy(int x, int y);  
void LinhaHorizontal     // Desenha linha horizontal
	(int Col, int Lin, int Colunas, char Char);  
void LinhaVertical		 // Desenha linha Vertical
	(int Col, int Lin, int Colunas, int Linhas, char Char); 
void Janela				 // Desenha as linha da janela
	(int Col, int Lin, int Colunas, int Linhas, char Char);
void TextoJanela(); 	// Escreve os textos da janela
main()
   { 
    int Opcao, Col, Lin, Colunas, Linhas;
	char  Char;
    setlocale(LC_ALL,"");
    system("color F0");
    system("MODE con cols=90 lines=25");
    
    // Início do programa
  	do
		{
		system("cls");
		Janela(Col, Lin, Colunas, Linhas, Char);
		
	//	
	// Corpo do programa	
	//	
		
		gotoxy(10,23);
		cin  >> Opcao;
		
	// Leitura e validação da Opção
		while (Opcao < 1 || Opcao > 2)
			{
			gotoxy(10,21);
		 	cout << "Opção inválida. Tecle enter";
		 	system("pause>null");
			gotoxy(10,23); 
		 	cout << " ";
		 	gotoxy(10,21);
		 	for (int i=1; i<=27; i++)
			   	cout << " ";
		 	gotoxy(10,23);
		 	cin  >> Opcao;
		 	}
		}
		while (Opcao == 1); // Fim do Laço de repetição
	system("cls");
	system("pause>null");
	} // Fim da main()
		
		
void Janela(int Col, int Lin, int Colunas, int Linhas, char Char)
	{	
	Col 	= 1;
	Lin 	= 1;
	Char    = '=';
	Colunas = 90;
	LinhaHorizontal(Col, Lin, Colunas, Char);
	Lin = 3;
	LinhaHorizontal(Col, Lin, Colunas, Char);
	Lin = 5;
	LinhaHorizontal(Col, Lin, Colunas, Char);
	Lin = 12;
	LinhaHorizontal(Col, Lin, Colunas, Char);
	Lin = 20;
	LinhaHorizontal(Col, Lin, Colunas, Char);
	Lin = 22;
	LinhaHorizontal(Col, Lin, Colunas, Char);
	Lin = 24;
	LinhaHorizontal(Col, Lin, Colunas, Char);
	Lin      = 1;
	Linhas  = 24;
	Colunas = 90;
	Char = '*';
	LinhaVertical(Col, Lin, Colunas, Linhas, Char);
	TextoJanela();
	
	}
	
void TextoJanela()
	{
	gotoxy(35,2);
	cout << "CMP1046";
	gotoxy(33,4);
	cout << "TÍTULO";
	gotoxy(33,10);
	cout << "ENTRADA";
	gotoxy(33,17);
	cout << "SAÍDA";
	gotoxy(4,21);
	cout << "Mens [";
	gotoxy(88,21);
	cout << "]";
	gotoxy(3,23);
	cout << "Opção [  ]  1 - Repetir  2 - Encerrar";
	}
void gotoxy(int x, int y)  
	{
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
	}   
	
void LinhaHorizontal(int Col, int Lin, int Colunas, char Char)  
   { gotoxy(Col,Lin);
    for (int i=0; i < Colunas; i++)
		cout << Char;
   }
  
void LinhaVertical(int Col, int Lin, int Colunas, int Linhas, char Char)   
   {
   for (int i = 1; i < Linhas; i++)
	   {
		gotoxy(Col,Lin+i);  
		cout << Char;  
		gotoxy(Colunas,Lin+i); 
		cout << Char; 
		}
	}
		
   
