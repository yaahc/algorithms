#include <iostream>
#include <vector>

using namespace std;

int main() {

	int length, i, curr;
	vector<int> elements;
	bool inOrder;

	do {
		cin >> length;
		elements.clear();
		inOrder = true;
		for(i = 0; i < length; i++) {
			cin >> curr;

			if(elements.size() > 0 && curr < elements.back())
				inOrder = false;
			else
				elements.push_back(curr);
		}
	
		if(inOrder) {
			for(i = length - 1; i >= 0; i--) {
				cout << elements[i] << endl;
			}
		} else {
			cout << "INCORRECT SEQUENCE" << endl;
		}
	} while (length != 0);
	
	return 0;
}
