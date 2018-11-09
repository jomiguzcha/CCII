#include <iostream>

using namespace std;

void imprimir(double arr[][4],int len) {
    int cont = 1;
    for (double *i = *arr; i < *arr + len; i++, cont++) {
	   cout << *i << "  ";
	   if (cont % 4 == 0) {
		  cout << endl;
	   }
    }
    cout << endl;
}

void operar_fila(double arr[][4], double a, int x, double b, int y) {
    //matriz, coeficiente fila en la que se resta, fila en la que se resta, coeficiente fila que se resta, fila que se resta
    int cont = 0;
    for (double *i = *arr + 4; i<(*arr + x) + 7; i++, cont++) {
	   *i = (a * (*i)) - (b * *((*arr + y) + cont));
    }
}

void to_one(double arr[][4], int i) {
    double *a = *(arr + i) + i;
    if (*a == 0) {
	   *a = *a;
    }
    else {
	   double aux;
	   aux = 1 / *(*(arr + i) + i);
	   for (int x = 0; x < 4; x++)
		  *(*(arr + i) + x) *= aux;
    }
}

void gauss(double arr[][4]) {
    int aux = 0;
    for (double (*i)[4] = arr; aux<3; aux++) {
	   for (int cont = 0; i < arr + 3; i++, cont++) {
          if (*(*i+aux) == *(*(arr + cont) + cont) && *(*i+aux) != 1) {
			 to_one(arr, cont);
			 imprimir(arr, 12);
			 continue;
		  }

		  else if ((*(*i+aux) == *(*(arr + cont) + cont) && *(*i+aux) == 1) || *(*i+aux) == 0) {
			 imprimir(arr, 12);
			 continue;
		  }

		  operar_fila(arr, 1, cont, *(*i+aux), 0);
		  imprimir(arr, 12);

	   }
	   i = arr;
    }
}

int main() {
    double x = 0, y = 0, z = 0;
    double matriz[3][4] = { {1,1,1,6},
						    {2,-1,1,5},
						    {3,1,-2,9} };

    imprimir(matriz,12);
    gauss(matriz);

    if(*(*matriz+11)== 0) {
	   cout << "La matriz no tiene solucion" << endl;
	   return 0;
    }

    z = *(*matriz + 11);
    y = *(*matriz + 7) - *(*matriz + 6)* z;
    x = *(*matriz + 3) - (*(*matriz + 1) * y + *(*matriz + 2) * z);

    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
    cout << "Z = " << z << endl;

    return 0;
}


/*
{
    int n = 2, m =3, k= 5;

    int ***Matriz = new int**[n];
    int MatB [n][m][k];

    for(int i = 0; i<n; i++)
    {
         *(Matriz+i) = new int*[m];
         for(int j=0;j<m;j++)
            *(*(Matriz+i)+j) = new int[k];

    }

    for(int i=0; i<n;i++)
    {
        for(int j=0; j <m; j++)
        {
         for(int h=0; h<k;h++)
           cout<<Matriz[i][j][h]<<" ";
          cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}*/







