#include <iostream>
#include <time.h>
#include <string>
using namespace std;

int correct_guess = 0;
const int MAX_LIVES = 3;
int wrong_guess = 0;


string guess(string word, int size, char letter, string answer)
{
	string temp = answer;
	for (int i = 0; i < size;i++)
	{
		if (word[i] == letter)
		{
			cout << letter << " ";
			answer[i] = letter;
			correct_guess++;
		}
		else {
			if (answer[i] == ' ')
			{
				cout << "_" << " ";
			}
			else {
				cout << answer[i] << " ";
			}
		}
	}
	cout << endl;
	if (temp == answer)
	{
		cout << "Wrong Guess, Try Again.\n";
		wrong_guess++;
		cout << "No. of Lives left = " << MAX_LIVES - wrong_guess<<endl;
	}
	return answer;
}

int main()
{
	string WORD_LIST[10] = { "paris", "moscow", "islamabad", "delhi", "madrid", "london", "washington", "berlin", "zurich", "sydney" };
	string guess_word = "                          ";
	cout << "\n\tHANGMAN\n\n";
	

	/*
	int random = offset + (rand() % range);
	In the above equation :
	offset - The starting point for the range of random numbers
	range - The number of values between first and the last possible random number including the limits.
	*/

	// The time() function is used to set the initial point for the srand() function.
	// Here we've used the time() function because it is the thing that is continuously changing its value.
	srand(time(0));
	int random = (rand() % 10);
	string selected_word = WORD_LIST[random];
	//cout << selected_word << endl;
	int size = selected_word.length();
	for (int i = 0;i < size;i++)
	{
		cout << "_" << " ";
	}
	cout << endl;
	char letter;
	while (true)
	{
		cout << "Enter a guess (letter) : ";
		cin >> letter;
		guess_word = guess(selected_word, size, letter, guess_word);
		if (correct_guess == size)
		{
			cout << "Correct.";
			break;
		}
		if (wrong_guess == MAX_LIVES)
		{
			cout << "Game Over!";
			break;
		}
	}
	return 0;
}