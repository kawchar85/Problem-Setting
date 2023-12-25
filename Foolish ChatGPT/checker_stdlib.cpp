#include "testlib.h"

int main(int argc, char* argv[]) {

    registerTestlibCmd(argc, argv);

    int pans = ouf.readInt(0, 1000000000, "Number to fool ChatGPT");
    int jans = ans.readInt();

    int A = inf.readInt();
    int B = inf.readInt();

    bool correct = true;
    
	if(pans == (A + B)) correct = false;

    if(correct) {
        quitf(_ok, "Successfully fooled.");
    } 
    else {
        quitf(_wa, "Failed to fooled ChatGPT");
    }

    return 0;
}
