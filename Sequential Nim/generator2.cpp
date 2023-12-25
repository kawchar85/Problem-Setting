#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	int min_n = atoi(argv[1]);
	int max_n = atoi(argv[2]);
	int max_num = atoi(argv[3]);
	int n = rnd.next(min_n, max_n);
	int q = rnd.next(min_n, max_n);
	cout<<n<<" "<<q<<endl;
	vector<int>a(n);
	for(int i = 0;i < n;i++){
		a[i] = rnd.next(1, 1);
		cout << a[i] << " \n"[i+1 == n];
	}
	for(int i = 1; i <= q; i++){
		int t, x, y;
		t = rnd.next(1, 100);
		t = (t == 1? 1 : 2);
		if(t == 1) {
			x = rnd.next(max(n - 10, 1), n);
			y = rnd.next(1, max_num);
		}
		else {
			x = rnd.next(1, min(10, n));
			y = rnd.next(max(n - 10, 1), n);
			if(x > y) swap(x, y);
		}
		cout << t << " " << x << " " << y << endl;
	}
	return 0;
}
