#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "sparse_matrix.h"

#define MAX_RANDOM 10

void newMatrix();
void addMatrices();
void addRandom();
void subtractMatrices();
void multiplyMatrices();
void deleteMatrix();
void menu();
void displayAll();
void chooseMatrices(int &m, int &n);
bool choice();
void chooseMatrix(int &n);

std::vector<Sparse_matrix> matrices;

int main(){

	menu();
	std::cout << "exited" << std::endl;
	return 0;
}


/*Prosi uzytkownika o podanie współrzędnych i wartosci i zapisuje je w nowym obiekcie*/
void newMatrix(){
	bool exit = false;
	std::cout << "An empty matrix 1 000 000 x 1 000 000 will be created.\n" ;
	std::cout << "Add elements in format  1)row 2)column 3)value." << std::endl;
	Sparse_matrix matrix;
	while(!exit){
		std::cin >> matrix;
		std::cout << "Do you want to continue? (y/n) " << std::endl;
		if(!choice()){
			exit = true;
		}
	}

	std::cout << "Do you want to save matrix? (y/n)" << std::endl;
	if(choice()){
		matrices.push_back(matrix);
		std::cout << "The matrix had been successfully saved" << std::endl;
	}
	else{
		std::cout << "The matrix wasn't saved" << std::endl;
	}
}

/*Wyswietla wszystkie obiekty macierzy*/
void displayAll(){
	for(int i=0; i<matrices.size();i++){
		std::cout <<  "Matrix "<< i+1 << std::endl;
		std::cout << matrices[i] << std::endl;
	}
}


/*Dodaje dwie wybrane przez uzytkownika macierze
i pyta czy zapisac wynik jako nowa macierz*/
void addMatrices(){
	Sparse_matrix matrix;
	int n=0;
	int m=0;
	chooseMatrices(n,m);
	matrix = matrices[n-1] + matrices[m-1];
	std::cout << matrix;
	std::cout << "Do you want to save matrix? (y/n)" << std::endl;
	if(choice()){
		matrices.push_back(matrix);
		std::cout << "The matrix had been successfully saved" << std::endl;
	}
	else{
		std::cout << "The matrix wasn't saved" << std::endl;
	}
}


/*Mnozy dwie wybrane przez uzytkownika  macierze
i pyta czy zapisac jako nowa macierz*/
void multiplyMatrices(){
	Sparse_matrix matrix;
	int n=0;
	int m=0;

	chooseMatrices(n,m);
	matrix = matrices[n-1] * matrices[m-1];
	std::cout << matrix;
	std::cout << "Do you want to save matrix? (y/n)" << std::endl;
	if(choice()){
		matrices.push_back(matrix);
		std::cout << "The matrix had been successfully saved" << std::endl;
	}
	else{
		std::cout << "The matrix wasn't saved" << std::endl;
	}

}

/*Odejmuje dwie wybrane przez uzytkownika macierze
i pyta czy zapisac jako nowa macierz*/
void subtractMatrices(){
	Sparse_matrix matrix;
	int n=0;
	int m=0;
	chooseMatrices(n,m);
	matrix = matrices[n-1] - matrices[m-1];
	std::cout << matrix;
	std::cout << "Do you want to save matrix? (y/n)" << std::endl;
	if(choice()){
		matrices.push_back(matrix);
		std::cout << "The matrix had been successfully saved" << std::endl;
	}
	else{
		std::cout << "The matrix wasn't saved" << std::endl;
	}
}


/*Usuwa wybrana macierz z std::vector matrices*/
void deleteMatrix(){
	int n=0;
	chooseMatrix(n);
	std::cout << "You have chosen matrix:\n" << matrices[n-1];
	std::cout << "Do you really want to delete matrix? (y/n)" << std::endl;
	if(choice()){
		matrices.erase(matrices.begin() + (n-1));
	}
	else{
		std::cout << "The matrix wasn't deleted" << std::endl;
	}
}



/*Wyswietla menu i wywoluje odpowiednie wybrane przez uzytkownika funkcje*/
void menu(){
	int choice=0;
	bool exit = false;
	while(!exit){
		choice =0;
		std::cout << "What are you going to do\n1) Add new matrix\n2) Add the chosen matrixes\n3) Multiply the chosen matrixes\n";
		std::cout << "4) Substract the chosen matrixes\n5) Delete the chosen matrix\n6) Show matrixes\n7) Create random matrix\n8) Exit\n" << std::endl;
		std::cin >> choice;
		while(choice <= 0 || choice > 7){
		std::cout << "Choose once again" << std::endl;
		std::cin >> choice;

		}


	switch(choice){

		case 1:
		newMatrix();
		break;

		case 2:
		addMatrices();
		break;

		case 3:
		multiplyMatrices();
		break;

		case 4:
		subtractMatrices();
		break;

		case 5:
		deleteMatrix();
		break;

		case 6:
			displayAll();
		break;

		case 7:
			addRandom();
			break;

		case 8:
		exit=true;
		break;


		default:
		exit=true;

	}
	}
}


/*funkcja do wyboru macierzy na ktorej bedzie wykonana jakas operacja*/
void chooseMatrix(int &n){
	displayAll();
	std::cout << "Write the number of the matrix you want to delete" << std::endl;
	std::cin >> n;
	while(n<0 || n>matrices.size()){
		std::cout << "Try again" << std::endl;
		std::cin >> n;
	}

}

/*funckcja do wyboru macierzy na ktorych bedzie wykonana operacja*/
void chooseMatrices(int &n, int &m){
	displayAll();
	std::cout << "Write one by one the numbers of the matrixes you want to add" << std::endl;
	std::cin >> n >> m;
	while(n<0 || n>matrices.size() || m<0 || m>matrices.size()){
		std::cout << "Try again" << std::endl;
		std::cin >> n >> m;
	}

}

/*funkcja do wyborow (y/n)*/
bool choice(){
	char choice;
	std::cin >> choice;
	while(choice!='y' && choice !='n'){
		std::cout << "Try again" << std::endl;
		std::cin >> choice;
	}
	if(choice=='y'){
		return true;
	}
	else{
		return false;
	}

}




/*Dodaje do std::vector matrices losowa macierz do ustalonej przez MAX_RANDOM
ilosci elementow*/
void addRandom(){
	 srand(time(NULL));
	 int a,b,c;
	 Sparse_matrix matrix1;

	 for(int i=0; i< MAX_RANDOM; i++){
		 a = rand() % 1000000;
		 b = rand() % 1000000;
		 c = rand() % 2000000;
		 matrix1.changeValue(a,b,c);
	 }
	 std::cout << matrix1;
	 matrices.push_back(matrix1);
}
