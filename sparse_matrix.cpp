#include "sparse_matrix.h"


/*tutaj są zaimplementowane operacje dla macierzy*/


/*Funkcja, zwracająca wartosc elementu o podanych wspolrzednych*/
int Sparse_matrix::getValue(int row, int column){
    if(row>= 1000000 || column >= 1000000){
        return -1;
    }

    for(int i=0;i<rows.size();i++){
        if(row==rows[i] && column==columns[i]){
            return values[i];
        }
    }
    return 0;
}



/*Funkcja zmieniająca wartosc elementu o podanych wspolrzednych. Jeżeli wartość jest niezerowa - zamienia
  tę wartość. Dla wartośi zerovej poprostu dodaje nową*/
int Sparse_matrix::changeValue(int row, int column, int value){
    if(row>= 1000000 || column >= 1000000){
        return -1;
    }

    for(int i=0;i<rows.size();i++){
        if(row==rows[i] && column==columns[i]){
            rows[i]=row;
            columns[i]=column;
            values[i]=value;
            return 0;
        }
    }

    rows.push_back(row);
    columns.push_back(column);
    values.push_back(value);
    return 0;
}





/*Funckja wczytuje trzy wartosci
  i zapisuje je w macierzy jako row column value */
std::istream& operator>>(std::istream &input, Sparse_matrix &M){
    int a,b,c;
    input >> a >> b >> c;
    for(int i=0;i<M.rows.size();i++){
        if(a==M.rows[i] && b==M.columns[i])
            return input;
    }

    M.rows.push_back(a);
    M.columns.push_back(b);
    M.values.push_back(c);

    return input;
}





/*Funcja +, szuka elementow o tych samych wspolrzendch i dodaje te wartosci
  jesli jakis element nie zostanie znalezniony w drugiej macierzy zosaje on dodany
  metoda push_back*/
Sparse_matrix Sparse_matrix::operator+(Sparse_matrix M){

    bool matchFound;

    for(int i=0;i<this->rows.size();i++){
        matchFound = false;
        for(int j=0;j<M.rows.size();j++){
            if(M.rows[j]==this->rows[i] && M.columns[j] == this->columns[i]){
                M.values[j] = M.values[j] + this->values[i];
                matchFound=true;
                break;
            }
        }
        if(!matchFound){
            M.rows.push_back(this->rows[i]);
            M.columns.push_back(this->columns[i]);
            M.values.push_back(this->values[i]);
        }
    }
    return M;
}





/*Funckja  += */
Sparse_matrix& Sparse_matrix::operator+=(const Sparse_matrix &M){
    bool matchFound;

    for(int j=0;j<M.rows.size();j++){
        matchFound = false;
        for(int i=0;i<this->rows.size();i++){
            if(M.rows[j]==this->rows[i] && M.columns[j] == this->columns[i]){
                this->values[j] = M.values[j] + this->values[i];
                matchFound=true;
                break;
            }
        }
        if(!matchFound){
            this->rows.push_back(M.rows[j]);
            this->columns.push_back(M.columns[j]);
            this->values.push_back(M.values[j]);
        }
    }
    return *this;
}





/*Funkcja - , na poczatku zamiena elementy na ujemne*/
Sparse_matrix Sparse_matrix::operator-(Sparse_matrix M){

    bool matchFound;
    for(int k=0;k<M.rows.size();k++){
        M.values[k] *= -1;
    }

    for(int i=0;i<this->rows.size();i++){
        matchFound = false;
        for(int j=0;j<M.rows.size();j++){
            if(M.rows[j]==this->rows[i] && M.columns[j] == this->columns[i]){
                M.values[j] = M.values[j] + this->values[i];
                matchFound=true;
                break;
            }
        }
        if(!matchFound){
            M.rows.push_back(this->rows[i]);
            M.columns.push_back(this->columns[i]);
            M.values.push_back(this->values[i]);
        }
    }
    return M;
}





/*Funkcja -= */
Sparse_matrix& Sparse_matrix::operator-=(const Sparse_matrix &M){
    bool matchFound;

    for(int j=0;j<M.rows.size();j++){
        matchFound = false;
        for(int i=0;i<this->rows.size();i++){
            if(M.rows[j]==this->rows[i] && M.columns[j] == this->columns[i]){
                this->values[j] = this->values[i] - M.values[j];
                matchFound=true;
                break;
            }
        }
        if(!matchFound){
            this->rows.push_back(M.rows[j]);
            this->columns.push_back(M.columns[j]);
            this->values.push_back(-M.values[j]);
        }
    }
    return *this;
}





/*funkcja * -  szuka elementow z macierzy 1 ktore
  maja taki sam nr kolumny co wiersz w macierzy 2 i mnozy te elementy */
Sparse_matrix Sparse_matrix::operator*(const Sparse_matrix &M){
    Sparse_matrix temp;
    int x;
    bool exists;
    for(int i=0;i<this->rows.size();i++){
        for(int j=0; j<this->rows.size();j++){
            exists = false;
            if(this->columns[i] == M.rows[j]){
                x = this->values[i] * M.values[j];
                for(int k=0;k<temp.rows.size();k++){
                    if(this->rows[i]==temp.rows[k] && M.columns[j] == temp.columns[k]){
                        temp.values[k] += x;
                        exists=true;
                        break;
                    }
                }
                if(!exists){
                    temp.rows.push_back(this->rows[i]);
                    temp.columns.push_back(M.columns[j]);
                    temp.values.push_back(x);
                }
            }
        }
    }
    return temp;
}





/*Funkcja *= */
Sparse_matrix& Sparse_matrix::operator*=(const Sparse_matrix &M){
    Sparse_matrix temp;
    int x;
    bool exists;
    for(int i=0;i<this->rows.size();i++){
        for(int j=0; j<this->rows.size();j++){
            exists = false;
            if(this->columns[i] == M.rows[j]){
                x = this->values[i] * M.values[j];
                for(int k=0;k<temp.rows.size();k++){
                    if(this->rows[i]==temp.rows[k] && M.columns[j] == temp.columns[k]){
                        temp.values[k] += x;
                        exists=true;
                        break;
                    }
                }
                if(!exists){
                    temp.rows.push_back(this->rows[i]);
                    temp.columns.push_back(M.columns[j]);
                    temp.values.push_back(x);
                }
            }
        }
    }
    this->rows = temp.rows;
    this->columns = temp.columns;
    this->values = temp.values;
    return *this;
}





/*Funkcja porownujaca dwie macierze, jesli ilosc elementow niezerowych jest rozna,
  jesli elementy o takich samych wspolrzednych sa rozne lub nie znaleziono elementu
  o takich samych wspolrzednych funckcja zwraca false, inaczej true*/
bool Sparse_matrix::operator==(const Sparse_matrix &M){
	
	if(this->rows.size()!=M.rows.size()){
		return false;
	}
	
	int checksMade=0;
	bool matchFound=false;
	
	for(int i=0;i<this->rows.size();i++){
		matchFound=false;
		for(int j =0;j<this->rows.size();j++){
			if(this->rows[i] == M.rows[j] && this->columns[i] == M.columns[j]){
		
				if(this->values[i]!=M.values[j]){
			
					return false;
				}
				checksMade++;
				
				matchFound=true;
			}
		}
		if(matchFound==false){
				return false;
			}
	}

	if(checksMade!=this->rows.size()){
		return false;
	}
	else{
		return true;
	}
}





/* != */
bool Sparse_matrix::operator!=(const Sparse_matrix &M){
	return !(*this==M);
}





/*Funkcja która wypisuje  niezerowe elementy macierzy  w postaci tabeli*/
std::ostream& operator<<(std::ostream &output, const Sparse_matrix &M){
	output << "Row: Column: Value:" << std::endl;

	for(int i=0;i<M.rows.size();i++){
		output << M.rows[i] << " " << M.columns[i] << " " << M.values[i] << std::endl;
	}

	return output;
}



