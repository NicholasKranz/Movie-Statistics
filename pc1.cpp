#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

char contInue;
int moviesWatched;
int studentAmount = 0;
int* ptrStudamt = &studentAmount;
vector<int> studentArray = {};
int commonAmt;

void calculateAvg();
void sort();
void calculateMedian();
void findmode();


int base = 1;

int main() {


	cout << "Enter total amount of students: " << endl;

	cin >> *ptrStudamt;//

	cout << "total students: " << *ptrStudamt << endl;//
	cout << endl;
	cout << endl;

	cout << "Enter amount of movies seen for each student as follows." << endl 
		 << "PRESS 'a' to continue: " << endl;

	cin >> contInue;

	cout << endl;

		
						if (contInue == 'a'); {

							for (int i = 0; i < *ptrStudamt; i++) {//

								cout << "Student" << "[" << base++ << "]:";
								cin >> moviesWatched;

								studentArray.push_back(moviesWatched);

							}
							
							//puts the list in numerical-ascending order
							sort();

							//calculates the average
							calculateAvg();

							//gets median
							calculateMedian();

							//gets mode
							findmode();
		
						}

							return 0;

}


void sort() {

	sort(studentArray.begin(), studentArray.end()); //array gets sorted for median-finding.

}

void calculateAvg() {

	int sum = accumulate(studentArray.begin(), studentArray.end(), 0);

	int average = (sum / *ptrStudamt);//

	cout << "Average: " << average << endl;

}

void calculateMedian() {

	int divNum = *ptrStudamt / 2;//divides the student amount by two, getting index. 

	int median = studentArray[divNum]; //here's our inde, which will print the middle value. 

	cout << "Median: " << median << endl;

}

void findmode() {
	int number = studentArray[0];
	int mode = number;
	int count = 1;
	int countmode = 1;

	for (int m = 1; m < *ptrStudamt; m++) {

		if (studentArray[m] == number) {
			++count;
		}

		else {

			if (count > countmode) {
				countmode = count; //leads to the largest occurance
				mode = number;
			}

			count = 1;
			number = studentArray[m];

		}	

	}

	cout << "Mode: " << mode << endl;
}


