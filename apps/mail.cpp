#include <iostream>
#include "heat.hpp"
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{	
	ofstream outfile;
	outfile.open("tryout.dat");

	int m = 9;

	Heat<2, float> Heat2d(0.3125, m, 0.01);
	Vector<float> solution = Heat2d.solve(0.1);
	Heat2d.clear();

	for (int i = 0; i < solution.length; ++i) {
		outfile << i % m << " " << i / m << " " << solution.data[i] << endl;
	}

	outfile.close();
	
	return 0;
}