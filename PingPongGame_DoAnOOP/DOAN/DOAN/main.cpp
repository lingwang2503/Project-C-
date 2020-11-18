#include "Paddle.h"
#include "OMG.h"

int main()
{

	hideCursor();
	OMG omg(right, bottom);
	int choice;
	omg.printMenu(choice);
	do
	{
		omg.run(choice); // chơi game
		omg.printGameOver();
		omg.printMenu(choice);
	} while (choice != 3);

	return 0;
}



