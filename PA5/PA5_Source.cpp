//Amanda Kaufman
//CISS350
//Programming Assignment 5
//Towers of Hanoi
//This problem provides the user with a series of instructions for how to
//solve the Towers of Hanoi problem for a number of rings accepted as input.

#include <iostream>
#include <fstream>
using namespace std;

//Function prototype
void moveStack(int, int, int, int, ofstream &);

int main()
{
	//Variable to run the program again
	char again = 'n';

	//Open an output file for testing output.
	ofstream outFile;
	outFile.open("test.out");

	//Title
	cout << "Towers of Hanoi\n\n";
	outFile << "Towers of Hanoi\n\n";
	
	do {
		//Get the number of rings from the user.
		cout << "How many rings do you need to move? ";
		outFile << "How many rings do you need to move? ";
		int numRings;
		cin >> numRings;
		outFile << numRings << endl << endl;
		cout << endl;

		//Output a list of instructions for the user by calling the recursive function moveStack(),
		//and pass it the number of rings.
		cout << "Instructions\n--------------------------------\n";
		outFile << "Instructions\n--------------------------------\n";
		moveStack(numRings, 1, 2, 3, outFile);

		//Ask the user if they would like to repeat the program.
		cout << endl << "Would you like to play again? (y/n): ";
		cin >> again;
		cin.ignore();
		cout << endl;
		outFile << endl;

	} while (again == 'y' || again == 'Y');
	
	//Goodbye message.
	cout << "Thanks for using the program!\n";
	outFile << "Thanks for using the program!\n";

	//Close the testing output file.
	outFile.close();

	cout << endl;
	system("pause");
	return 0;
}

//Function: Moves a stack from one peg to another.
//Assumption: There are three pegs.
//Arguments: Number of rings in the stack to be moved, the starting peg, the destination peg,
//			 the temporary peg used in transit, and the name of the testing output file.
//Pre: Number of rings is not negative.  Output file exists and has already been opened.
//Post: The stack of rings with num as the base has been moved to the destination peg.
void moveStack(int ringNum, int origin, int holder, int destination, ofstream &outFile)
{
	//Base case: number of rings passed equals 0, in which case the following code does not execute
	//and the function simply returns.
	if (ringNum > 0)
	{
		//Move the stack on top of ringNum (starting with ringNum - 1) to the holder peg to
		//get these rings out of the way.  Destination is used temporarily to accomplish this.
		moveStack((ringNum - 1), origin, destination, holder, outFile);

		//Tell the user to ove the ring for which this function was called from the origin
		//to the destination peg.
		cout << "Move a ring from peg " << origin << " to peg " << destination << ".\n";
		outFile << "Move a ring from peg " << origin << " to peg " << destination << ".\n";

		//Move the rest of the stack that was on top of ringNum (starting with ringNum - 1) from
		//the temporary holder peg onto the destination peg.
		moveStack((ringNum - 1), holder, origin, destination, outFile);
	}
}