// 	Proyecto de Matematica discreta II

#include <iostream>
#include <cmath>

class Dado {

	private:
		
		struct Node {
			int Random;
			Node *next;
		};

	public:

		void RandomSeed();
		void Store_Events(int);
		double Exp_Probability(int *, int, int, int);
		double Norm_Probability(char, int, int, int);

		int Execution, F_Events, Prob;
};

inline double Probabilidad_Clasica(int, int);


int main() {
	Dado Object;    
	int Lados, Veces, Dados;
	Lados = Veces = Dados = 0;
	char Option;

	do {
		std::cout << "MENU\n\n";
		std::cout << "a) Asignar numero de: dados, lados del dado, veces que se lanzara.\n";
		std::cout << "b) Probabilidad de que caiga una o varias combinaciones especifica\n";
		std::cout << "c) Probabilidad de que caiga un numero par al tirar el dado\n";
		std::cout << "d) Probabilidad de que caiga un numero impar al tirar el dado\n";
		std::cout << "e) Hallar la probabilidad de que caiga al menos un numero especifico\n";
		std::cout << "f) Hallar la probabilidad de que caiga al menos un numero par\n";
		std::cout << "g) Hallar la probabilidad de que caiga al menos un numero impar\n";
		std::cout << "i) Salir\n\n";
		std::cout << "Su opcion es: ";

		std::cin >> Option;
		std::cout << '\n';

		if(Option != 'i') 

			switch(Option)  {

				case 'a':

					std::cout << "Digitar la cantidad de dados que se utilizaran: "; // Indicara cuantos dados se lanzaran simultaneamente
					std::cin >> Dados;

					std::cout << "Digitar el numero de lados del dado que desea tener: ";
					std::cin >> Lados;

					std::cout << "Digitar cuantas veces se lanzara el dado: "; // Indicara cuantas veces se lanzaran los dados uno despues de otro
					std::cin >> Veces;
					break;
				
				case 'b':
				case 'c':
				case 'd':
				case 'e':
				case 'f':
				case 'g':
				std::cout << "\nLa probabilidad es: " << Object.Norm_Probability(Option, Dados, Lados, Veces);
					break;
					
			}   
			   

		std::cout << "\n\n";
		std::cin.clear();
		std::cin.ignore();

	} while(true);
}	


inline double Probabilidad_Clasica(int cFavorables, int cPosibles) {
	return (double) cFavorables/cPosibles;
}


double Dado::Norm_Probability(char Opcion, int nDado, int nLado, int nVeces) {

	int cFavorables = 0, eMuestral = 0;
	double resultado = 1;

	/* En los 'b' - 'd', como son interceptos de conjuntos simplemente se multiplican las probabilidades de los conjuntos para hallar la probabilidad */

	switch(Opcion) {
	
		case 'b': {
			std::cout << "Digite la cantidad de combinaciones que se desea conocer la probabilidad ";
			std::cin >> cFavorables;

			cFavorables = pow(cFavorables, nDado *nVeces);
			eMuestral = pow(nLado, nDado * nVeces);

			return Probabilidad_Clasica(cFavorables, eMuestral);
		}

		case 'c': {
			
			for(int i = 1; i <= nLado; i++)
				if(i % 2 == 0)
					cFavorables++;
			
			cFavorables = pow(cFavorables, nDado * nVeces);
			eMuestral = pow(nLado, nDado * nVeces);

			return Probabilidad_Clasica(cFavorables, eMuestral);
		}
		
		case 'd': {

			for(int i = 1; i <= nLado; i++)
				if(i % 2 != 0)
					cFavorables++;
			
			cFavorables = pow(cFavorables, nDado * nVeces);
			eMuestral = pow(nLado, nDado * nVeces);

			return Probabilidad_Clasica(cFavorables, eMuestral);
		}

		case 'e': {

			for(int i = 1; i <= nDado * nVeces; i++) 
				resultado *= (double) (1.0 - Probabilidad_Clasica(1, nLado));

			resultado = (double) 1.0 - resultado;
			return resultado;
		}

		case 'f': {

			for(int i = 1; i <= nLado; i++)
				if(i % 2 == 0)
					cFavorables++;

			for(int i = 1; i <= nDado * nVeces; i++) 
				resultado *= (double) (1.0 - Probabilidad_Clasica(cFavorables, nLado));

			resultado = (double) 1.0 - resultado;
			return resultado;
		}

		case 'g': {

			for(int i = 1; i <= nLado; i++)
				if(i % 2 != 0)
					cFavorables++;

			for(int i = 1; i <= nDado * nVeces; i++) 
				resultado *= (double) (1.0 - Probabilidad_Clasica(cFavorables, nLado));

			resultado = (double) 1.0 - resultado;
			return resultado;
		}
	}
}
