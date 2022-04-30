#include<iostream>
using namespace std;

bool allZs(string const& str)
{	
	int length = str.length();
	for (int i = 0; i <  length; i++)
	{
		if (str[i] != 'Z')
			return false;
	}

	return true;
}

void resetAllAndAppendA(string& str)
{
	int length = str.length();
	for (int i = 0; i<length ; i++)
	{
		str[i] = 'A';
	}
	str += "A";
}

void reset(string& str)
{
	int i = str.length()-1;
	bool flag = false;
	while (str[i] == 'Z')
	{
		str[i] = 'A';
		i--;
		flag = true;
	}

	if (flag == true)
		str[i]++;
}

int main()
{
	int n;
	cout << "Please enter positive integer number: ";
	cin >> n;
	if (n < 1)
		return 0;

	string currColName = "A";

	for (int i = 1; i <= n; i++)
	{
		int length = currColName.length();
		cout << i << ": " << currColName << endl;

		/*when all characters have become Z, we will reset them
		  all to A, and append another A.*/
		if (allZs(currColName) == true)
			resetAllAndAppendA(currColName);

		/*if the last few characters or even just the last character
		  is not Z, then we increment the last character.*/
		else if (currColName[length - 1] != 'Z')
			currColName[length - 1]++;

		/*when some character from the end (length-1 to i) have
		  have become Z, we will reset them to A and increment the (i-1)th character.*/
		else reset(currColName);
	}
}