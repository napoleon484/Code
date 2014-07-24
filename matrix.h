#include <iostream>
#include <math.h>

using namespace std;

#ifndef DLLIMPORT
#define DLLIMPORT __declspec(dllexport)
#endif 

class Matrix;

class DLLIMPORT Matrix {

	public:
		
		// Parameters
		double **M;

		// Function
		Matrix(int row, int col);
		~Matrix();

		static Matrix*		Inv(Matrix *);
		static Matrix*		Multiply(Matrix *, Matrix *);
		static double		Det(Matrix *);
		static Matrix*		Minor(Matrix *, int, int);
		static Matrix*		Transpose(Matrix *);
		static int			ShowFile(char * , Matrix *);

		static void			Show(Matrix *);
		static int			GetNbRow(Matrix *);
		static int			GetNbCol(Matrix *);
	
	private:
		
		// Parameters
		int row;
		int col;
};
