#include <iostream>

using namespace std;

int n=3;int m=4;

void imprimir(double **arr) {
  for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
		  cout<<*(*(arr + i)+j)<<" ";
		  }
	   cout<<endl;
    }
    cout << endl << endl << endl;
}

void operar_fila(double **arr, double a, int x, double b, int y) {
    //matriz, coeficiente fila en la que se resta, fila en la que se resta, coeficiente fila que se resta, fila que se resta
    for (int i = 0;i<m;i++) {
	   *(*(arr + x) + i) = (*(*(arr + x) + i) * a) - (*(*(arr + y) + i) * b);
	   //Coeficiente fila en la que se resta,fila en la que se resta,coeficiente fila que se resta, fila que se resta
    }
}

void to_one(double **arr, int x) {
    double a = 0;
    if (*(*(arr + x) + x) == a) {
	   a=0;
    }
    else {
	   double aux;
	   aux = 1 / *(*(arr + x) + x);
	   for (int i = 0; i < m; i++)
		  *(*(arr + x) + i) *= aux;
    }
}

void gauss(double **arr) {
    for (int i = 0; i<(m-1); i++) {
	   for (int j = 0; j<n; j++) {
		  cout <<"J :"<< j <<"     I: "<< i << endl;
		  if (i==j && *(*(arr + j) + j) != 1) {
			 to_one(arr, j);
			 imprimir(arr);
			 continue;
		  }
		  else if ((i == j && *(*(arr + j) + j) == 1) || (*(*(arr + j) + i) ==0)) {
			 imprimir(arr);
			 continue;
		  }
		  operar_fila(arr, 1, j, *(*(arr + j) + i), i);
		  imprimir(arr);
	   }
    }
}

int main() {
    double x = 0, y = 0, z = 0;
    /*double matriz[3][4] = {{ 1,1,1,6 },
    							{ 2,-1,1,5 },
     							 {1,1,1,1}};*/

    double **matriz = new double*[n];
    for (int i = 0; i<n; i++) {
		  *(matriz + i) = new double[m];
    }
    
    for (int i = 0; i < n; i++) {
	   for (int j = 0; j < m; j++) {
		  if (i == 0) {
			 switch (j) {
			 case 0:*(*(matriz + i) + j) = 1; break;
			 case 1:*(*(matriz + i) + j) = 1; break;
			 case 2:*(*(matriz + i) + j) = 1; break;
			 case 3:*(*(matriz + i) + j) = 6; break;
			 }
		  }
		  else if (i == 1) {
			 switch (j) {
			 case 0:*(*(matriz + i) + j) = 2; break;
			 case 1:*(*(matriz + i) + j) = -1; break;
			 case 2:*(*(matriz + i) + j) = 1; break;
			 case 3:*(*(matriz + i) + j) = 5; break;
			 }
		  }
		  else if (i == 2) {
			 switch (j) {
			 case 0:*(*(matriz + i) + j) = 3; break;
			 case 1:*(*(matriz + i) + j) = 1; break;
			 case 2:*(*(matriz + i) + j) = -2; break;
			 case 3:*(*(matriz + i) + j) = 9; break;
			 }
		  }
	   }
    }

   /* for (int i = 0; i<n; i++) {
		  for (int j = 0; j<m; j++) {
			*(*(matriz + i)+j) = 2;
		  }
    }*/

    imprimir(matriz);
    gauss(matriz);
    
    if (*(*(matriz + (n-1)) + (m-1)) == 0) {
	   cout << "La matriz no tiene solucion" << endl;
	   system("pause");
	   return 0;
    }
    
    z = *(*(matriz + (n - 1)) + (m - 1));
    y = *(*(matriz + 1) + 3) - (*(*(matriz + 1) + 2) * z);
    x = *(*(matriz) + 3) - (*(*(matriz) + 2) * z ) - (*(*(matriz)+1) * y);

    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
    cout << "Z = " << z << endl;

    delete matriz;
    system("pause");
    return 0;
}

