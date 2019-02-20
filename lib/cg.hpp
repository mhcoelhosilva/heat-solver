#ifndef CG_HPP
#define CG_HPP

#include "matrix.hpp"

template<typename T>
int cg(const Matrix<T> &A, const Vector<T> &b, Vector<T> &x, T tol, int maxiter)
{
	Vector<T> p = b - A * x;
	Vector<T> r = p;
	Vector<T> r_nxt = r;

	T alpha, beta;
	int k;
	for (k = 0; k < maxiter; ++k)
	{
		r = r_nxt;
		alpha = dot(r, r) / dot(A * p, p);
		x = x + alpha * p; /* Vector x is actually changed here (not passed as const)*/
		r_nxt = r - alpha * (A * p);
			
		if (dot(r_nxt, r_nxt) < tol*tol)
			break;

		beta = dot(r_nxt, r_nxt) / dot(r, r);
		p = r_nxt + beta * p;
	}
	if (k < maxiter) {
		return k;
	}
	else {
		return -1;
	}
}
#endif // CG_HPP