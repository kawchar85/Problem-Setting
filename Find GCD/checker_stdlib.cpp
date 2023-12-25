#include "testlib.h"

int main(int argc, char* argv[]) {

	registerTestlibCmd(argc, argv);

	bool correct = true;
	int T = inf.readInt();
	int wa = 0;

	for(int i = 1; i <= T; i++) {
		setTestCase(i);
		int pans = ouf.readInt();
		int jans = ans.readInt();

		if(pans != jans) {
			if(!wa) wa = i;
			correct = false;
		}
	}

	if(correct) {
		quitf(_ok, "passed all test cases");
	} 
	else {
		quitf(_wa, "wrong answer of test %d", wa);
	}

	return 0;
}
