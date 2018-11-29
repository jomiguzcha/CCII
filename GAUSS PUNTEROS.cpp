#include <iostream>
#include <string>

using namespace std;

int n = 4; int m = 5;

void imprimir(double **arr) {
    for (int i = 0; i<n; i++) {
	   for (int j = 0; j<m; j++) {
		  cout << *(*(arr + i) + j) << " ";
	   }
	   cout << endl;
    }
    cout << endl << endl << endl;
}

void operar_fila(double **arr, double a, int x, double b, int y) {
    //matriz, coeficiente fila en la que se resta, fila en la que se resta, coeficiente fila que se resta, fila que se resta
    for (int i = 0; i<m; i++) {
	   *(*(arr + x) + i) = (*(*(arr + x) + i) * a) - (*(*(arr + y) + i) * b);
	   //Coeficiente fila en la que se resta,fila en la que se resta,coeficiente fila que se resta, fila que se resta
    }
}

void to_one(double **arr, int x) {
    double a = 0;
    if (*(*(arr + x) + x) == a) {
	   a = 0;
    }
    else {
	   double aux;
	   aux = 1 / *(*(arr + x) + x);
	   for (int i = 0; i < m; i++)
		  *(*(arr + x) + i) *= aux;
    }
}

void gauss(double **arr) {
    for (int i = 0; i<(m - 1); i++) {
	   for (int j = 0; j<n; j++) {
		  if (i == j && *(*(arr + j) + j) != 1) {
			 to_one(arr, j);
			 imprimir(arr);
			 continue;
		  }
		  else if ((i == j && *(*(arr + j) + j) == 1) || (*(*(arr + j) + i) == 0)) {
			 imprimir(arr);
			 continue;
		  }
		  operar_fila(arr, 1, j, *(*(arr + j) + i), i);
		  imprimir(arr);
	   }
    }
}

int main() {
    double x = 0, y = 0, z = 0, sum=0; int aux = 0;
    string arr[] = {"Z:","X:","Y:","W:","V:","U:","T:","S:","R:","Q:" };
   
    double **matriz = new double*[n];
    for (int i = 0; i<n; i++) {
	   *(matriz + i) = new double[m];
    }

    double *variables = new double[m - 1];


    for (int i = 0; i < n; i++) {
	   for (int j = 0; j < m; j++) {
		  cout << "Numero[" << i << "][" << j << "]: ";
		  cin >> *(*(matriz + i) + j);
	   }
    }

    /* for (int i = 0; i<n; i++) {
    for (int j = 0; j<m; j++) {
    *(*(matriz + i)+j) = 2;
    }
    }*/

    imprimir(matriz);
    gauss(matriz);

    if (*(*(matriz + (n - 1)) + (m - 2)) == 0) {
	   cout << "La matriz no tiene solucion" << endl;
	   system("pause");
	   return 0;
    }
    
    for (int i = 0; i < (m - 1); i++) {
	   double *var = variables;
	   if (i == 0) {
		  *(var + i) = *(*(matriz + (n - 1)) + (m - 1));
		  continue;
	   }

	   sum = *(*(matriz + (n - (i + 1))) + (m - 1)) - (*(*(matriz + (n - (i + 1))) + (m - 2)) * *(var + aux));

	   if (i > 1) {
		  for (int a = 0; a < (i - 1); a++) {
			 sum -= (*(*(matriz + (n - (i + 1))) + (m - (a+3))) *  *(var +(a+1)));}
	   }
	   *(var + i) = sum;
	   sum = 0;
    }

    for (int i = 0; i < (m - 1); i++) {
	   double *var = variables; string *ar = arr;
	   cout << *(ar+i);
	   cout << *(var + i) <<"\t";
    }
    cout << endl;

    delete matriz;
    system("pause");
    return 0;
}

