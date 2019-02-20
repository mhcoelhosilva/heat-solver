#ifndef HEAT_HPP
#define HEAT_HPP

#include "cg.hpp"
#include <math.h>

const double pi = 3.14159265359;

//n can be 1, 2, 3, etc. for 1-D, 2-D, 3-D cases respectively (not starting at zero)
template <int n, typename T>
class Heat 
{
public:
	////constructor
	Heat(T alpha, int m, T dt)
		: M((int)pow(m, n), (int)pow(m, n)) //construct (m^n)x(m^n) matrix. m^n unknowns (interior nodes).
	{	
		this->alpha = alpha; //storing the arguments for use in member functions
		this->m = m;
		this->dt = dt;
		for (int i = 0; i < pow(m, n); ++i) //equations (rows)
		{
			for (int j = 0; j < pow(m, n); ++j) //unknowns (columns)
			{
				//diagonal:
				if (i == j) {
					M[{i, j}] = 1.0 + 2 * n*dt*alpha * (pow(m + 1, 2));
				}
				//neighbors in n dimensions:
				for (int k = 0; k < n; ++k) {
					if ((i + pow(m, k)) == j && (j / (int)pow(m, k)) % m != 0) {
						M[{i, j}] = -dt * alpha * (pow(m + 1, 2));
					}
					else if ((i - pow(m, k)) == j && (j / (int)pow(m, k) + 1) % m != 0) {
						M[{i, j}] = -dt * alpha * (pow(m + 1, 2));
					}
				}
				
			}
		}
	}

	////methods
	//returns exact solution at time t at all internal nodes
	Vector<T> exact(T t) const
	{
		Vector<T> x(pow(m, n));

		for (int i = 0; i < pow(m, n); ++i) {
			x.data[i] = exp(-n * pi*pi*alpha*t);
			for (int k = 0; k < n; ++k) {
				x.data[i] *= sin(pi*(1.0 / ((double)m + 1.0))*(i / (int)pow(m, k) % m));
			}
		}
		return x;
	}

	Vector<T> solve(T t) const 
	{
		Vector<T> x(pow(m, n));
		
		//Initial condition (x_0):
		for (int i = 0; i < pow(m, n); ++i) {
			x.data[i] = 1.0;
			for (int k = 0; k < n; ++k) {
				x.data[i] *= sin(pi*(1.0 / ((double)m + 1.0))*(i / (int)pow(m, k) % m));
			}
		}

		//Solve:
		int numIter = 0;
		int tempIter;
		Vector<T> x_previous;
		for (int l = 1; l < t / dt; ++l) 
		{
			x_previous = x;
			tempIter = cg<T>(M, x_previous, x, 1.0e-6, 100); //x is changed here, x_previous isn't
			if (tempIter < 0) {
				std::cout << "CG Reached Max Iter" << std::endl;
				numIter += 100;
			} else {
				numIter += tempIter;
			}
		}	
		
		std::cout << "Number of iterations: " << numIter << std::endl;
		
		return x;
	}

	std::string getMatrix() const {
		return M.getMatrix();
	}

	void clear() {
		M.matrixClear();
	}

private:
	////attributes
	Matrix<T> M;
	T alpha;
	int m;
	T dt;
};

#endif // HEAT_HPP