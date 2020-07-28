#include <iostream>

using namespace std;

string defangIPaddr(string address) {

	qstring defanged;

	for(unsigned int i = 0 ; i < address.size(); i++) {

		if( address.at(i) == '.' ) {
			/* defang */
			defanged += "[.]";

		} else {
			/* add num */

			defanged += address.at(i);
		}

	}

	return defanged;

}


int main(int argc, char **argv) {

	string ipAddr = "250.100.50.0";

	cout << ipAddr << "\n" << defangIPaddr(ipAddr) << endl;

	return 0;
}
