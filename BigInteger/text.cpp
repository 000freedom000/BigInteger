#include"BigInteger.h"
using namespace std;
int main(void) {
	string t = "0006000000";
	float a= 100;
	BigInteger text("1000000001");
	BigInteger text2(text);
	text <= text2;
	if (text <= text2) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	cout << text << endl;
	cout << text2 << endl;
	cout << "dff" << endl;
	return 0;
}