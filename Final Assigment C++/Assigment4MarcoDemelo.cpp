#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;
//Name: Marco De Melo
//Assigment 2 Accepts products For butcher shop and calculates price for customer 
int main()
{
	//housekeeping
	 char meat;
	string customer;
	double weight, cost;
	cost = 0;
	//add the code to open a file for output and set output rules
	ofstream fout("receipts.txt");
	fout << fixed << setprecision(2);
	if (!fout.is_open())
	{
		cout << "receipts.txt did not open closing software" << endl;
		system("pause");
		exit(1);
	}
	//input
	cout << "Hello, enter your name: ";
	getline(cin, customer);
	cin.ignore(80, '\n');
	while (!cin.eof())
	{
		cout << "Hello " << customer << " Please put the chracter of the meat here: " << endl;
		cout << "Put C or c for chicken P or p For pork and B or b for beef" << endl;
		cin >> meat;
		while (meat != 'C' && meat != 'c' && meat != 'P' && meat != 'p' && meat != 'B' && meat != 'b' || cin.fail())
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "Invalid Data Please input Correct Data: " << endl;
			cout << "Put C or c for chicken P or p For pork and B or b for beef" << endl;
			cin >> meat;
		}



		cin.ignore(80, '\n');
		cout << "Great! Please Put the weight of the meat(in kg) here (Please input meat that weighs more then 0kg and less then 100kg: ";
		cin >> weight;
		while (weight > 100 || weight < 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "HaHa very funny please input valid data: ";
			cin >> weight;
		}

		//processing
		if (meat == 'C' || meat == 'c')
		{
			cost = weight * 5.49;
		}
		else if (meat == 'P' || meat == 'p')
		{
			cost = weight * 6.80;
		}
		else if (meat == 'B' || meat == 'b')
		{
			cost = weight * 8.80;
		}

		//output


		fout << setprecision(2) << "Customer:" << setw(20) << "Meat:" << setw(30) << "Weight in kg:" << setw(20) << "Cost$:" << endl;
		fout << setprecision(2) << left << setw(20) << customer << right << setw(5) << meat << right << setw(23) << weight << "kg" << right << setw(25) << cost << "$" << endl;
		cout<< <<setw(10)"Marco's Meats" << endl;
		cout << "Customer: " << customer;
		cout << "Meats Purchased";
		if (meat == 'C' && 'c')
			cout << "Chicken@ $" << weight << "/kg" << setw(10) << cost;
		cout << "Enter next customers name or hit ^Z to terminate the program: " << endl;
		
		cin.ignore(80, '\n');
		getline(cin, customer);
	}
			
				cout << "Register closed Thank you for shopping at Marco's Meats... Have a good day!" << endl;

	

	
	
	//Run the program, did the balance appear on the output file
	cout << endl << "Printout of receipts.txt" << endl << endl;
	// copy the output file to the I/O dialogue
	system("type receipts.txt");
	system("pause");
}