#include<iostream>
#include<vector>
#include<stdlib.h>
#include<cctype>
using namespace std;

void fillArray(vector<int>& v, int size) {
	int num = 0; //user number 
	int i = 0;
	cout << "Enter" << " " << size << " " << " Numbers " << endl;
	while (i < size) {
		cin >> num;
		v[i] = num;
		i++;
	}
}
void printVector(vector<int>& v, int size) {

	for (int i = 0; i < size; i++) {
		cout << v[i] << " ";
	}


}

bool is_Palindrome(const string& user_string) {
	int i = 0;
	int size = user_string.length() - 1;

	while (i <= size) {
		// Skip whitespaces from the beginning
		while (i <= size && user_string[i] == ' ') {
			i++;
		}

		// Skip whitespaces from the end
		while (i <= size && user_string[size] == ' ') {
			size--;
		}

		if (i <= size && user_string[i] != user_string[size]) {
			return false;
		}

		i++;
		size--;
	}
	return true;
}



void Common(vector<int>& v1, vector<int>& v2, int size1, int size2)
{

	cout << "\n\n----------------Common Elements------------------\n\n";


	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (v1[i] == v2[j])
			{
				cout << v1[i] << "\t";

			}
		}
	}
	cout << "\n--------------------------------------------------------------------------------------------------------\n";
}
void Merge(vector<int>& v, int size1, vector<int>& v1, int size2, vector<int>& v2) {
	int i = 0; // starts from 0 index for the first array 
	int j = 0; // same here for the 2nd array
	int k = 0; // same here for the 3rd array

	while (i < size1 && j < size2) {
		if (v[i] < v1[j]) {
			v2[k++] = v[i++];

		}
		else {
			v2[k++] = v1[j++];

		}
	}

	// Since it's sorted, now just copy the remaining elements using a loop
	while (i < size1) {
		v2[k++] = v[i++];

	}
	while (j < size2) {
		v2[k++] = v1[j++];

	}
}
void printVector(const vector<int>& v, int size) {
	for (int i = 0; i < size; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}


void sort(vector<int>& v, int size) {         //Selection Sort

	for (int i = 0; i < size; i++) {

		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (v[j] < v[minIndex]) {
				minIndex = j;

			}

		}
		swap(v[minIndex], v[i]);
	}

}

int main() {

	string input;
	cout << "Enter a string: ";
	getline(cin, input);

	if (is_Palindrome(input)) {
		cout << "The entered string is a palindrome." << endl;
	}
	else {
		cout << "The entered string is not a palindrome." << endl;
	}

	cout << endl;

	int size1;
	int size2;

	cout << "Enter the size of First Array" << endl;
	cin >> size1;

	vector<int>v1(size1);
	fillArray(v1, size1);
	system("CLS");
	cout << "Here is the Sorted version of it of Array 1  " << endl;
	sort(v1, size1);
	printVector(v1, size1);

	cout << endl;

	cout << "Now its time to Enter size of your Second Array" << endl;
	cin >> size2;


	vector<int>v2(size2);
	fillArray(v2, size2);
	sort(v2, size2);
	printVector(v2, size2);


	cout << endl;
	Common(v1, v2, size1, size2);
	cout << endl;
	int final_size = size1 + size2;
	cout << "Here is the Merged Version of it" << endl;
	vector<int>v3(final_size);

	Merge(v1, size1, v2, size2, v3);
	printVector(v3, final_size);






	return 0;
}
