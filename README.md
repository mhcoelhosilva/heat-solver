Heat Solver

A C++ library for numerically solving the heat partial differential
equation in an arbitrary number of spatial dimensions. A second-order
Finite Difference method is used for the spatial discretization, and
the Backward Euler method is used for time-stepping. The variable m
sets the number of internal nodes per axis, which are equally spaced
in n dimensions. Horizontal numbering is used, meaning e.g. the single
index j = x + m y +m^2 z represents a single point in 3 dimensions.
The domain here is [0, 1]^n.
Initial and boundary conditions:

u(x, t) = 0                             for all x at boundary
u(x, 0) = \prod_{k=0}^{n-1} sin(pi x_k) for all x in domain

The numerical solution is found to converge with dx^(1.426 +- 0.213)
in space and dt^(1.337 +- 0.671) in time.



