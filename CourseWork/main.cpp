#include <iostream>
#include <fstream>
#include"Flow.h"

using namespace std;

int main(int argc, char* argv[])
{
	try {
		ifstream input("input.txt");
		Flow flow(input);
		if(flow.max_flow() == 0)
			throw exception("There is no way from the source to the sink");
		else
		cout << "Max flow for the input graph is: " << flow.max_flow() << endl;
	}
	catch (exception& ex) {
		cout << ex.what();
	}
	system("pause");
}