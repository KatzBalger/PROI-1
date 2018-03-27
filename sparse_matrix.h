#include <iostream>
#include <vector>		//szablon odpowiadający za realizację dynamicznej pamięci(w tym przypadku wektora)
#include <algorithm>	//header zawierający funkcje dla wykonania algorytmicznych działań nad containerami i szablonami


/*klasa, przechowująca macierz za pomocą 3 wektorów, w których przechowuje się
 * wartość elementu i jego współrzędne*/
class Sparse_matrix{

	private:

		std::vector<int> values;
		std::vector<int> rows;
		std::vector<int> columns;


	public:


		friend std::istream& operator>>(std::istream &input, Sparse_matrix &M);
		friend std::ostream& operator<<(std::ostream &output, const Sparse_matrix &M);
		

		Sparse_matrix operator+(Sparse_matrix M);
		Sparse_matrix operator-(Sparse_matrix M);
		
		
		Sparse_matrix& operator+=(const Sparse_matrix &M);
		Sparse_matrix& operator-=(const Sparse_matrix &M);
		
		
		Sparse_matrix operator*(const Sparse_matrix &M);
		Sparse_matrix& operator*=(const Sparse_matrix &M);
		

		bool operator==(const Sparse_matrix &M);
		bool operator!=(const Sparse_matrix &M);
		
		
		int getValue(int row, int column);
		int changeValue(int row, int column, int value); 

		
};
