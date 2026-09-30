#include <iostream>
#include <windows.h>

using namespace std;

int NumberFromTo(int From, int To) {
	int Number = rand() % (To - From + 1) + From;
	return Number;
}

enum choices { rock, paper, scissor };
void Header() {
	cout << "Hello User Welcome To Rock-Paper-Scissor Game " << endl;
	cout << "How Many Rounds Do You Want This Game Played Between You And AI-Computer?";

}

string LetterOrNumberEntry() {
	string Choice;
	cin >> Choice;
	return Choice;
}

choices Questioning() {
	cout << "Pick, By Entering Number Or First Letter :  1:Rock  2:Paper  3:Scissor ";
	choices::paper;
	choices::rock;
	choices::scissor;

	string Userchoice = LetterOrNumberEntry();

	if (Userchoice == "1" || Userchoice == "r" || Userchoice == "R") {

		return choices::rock;
	}
	else if (Userchoice == "2" || Userchoice == "p" || Userchoice == "P") {
		return choices::paper;
	}
	else if (Userchoice == "3" || Userchoice == "s" || Userchoice == "S") {
		return choices::scissor;
	}
}

choices ComputerChoiceConversion(int Number) {
	if (Number == 1) {
		return choices::rock;
	}
	else if (Number == 2) {
		return choices::paper;
	}
	else return choices::scissor;
}

string ResultCalculation(choices ComputerChoice, choices UserChoice) {

	if (UserChoice == choices::rock && ComputerChoice == choices::scissor || UserChoice == choices::paper &&
		ComputerChoice == choices::rock || UserChoice == choices::scissor && ComputerChoice == choices::paper) {
		return "Winner";
	}
	else if (UserChoice == choices::scissor && ComputerChoice == choices::rock || UserChoice == choices::rock &&
		ComputerChoice == choices::paper || UserChoice == choices::paper && ComputerChoice == choices::scissor) {
		return "Loser";
	}
	else return "Draw";


}


void RoundPrint(choices& AiChoice, choices& UserChoice, string& result, int rounds, int& drawsCounter, int& winsCounter, int& lossesCounter) {


	for (int counter = 1;counter <= rounds;counter++) {
		AiChoice = ComputerChoiceConversion(NumberFromTo(1, 3));
		UserChoice = Questioning();
		cout << endl;

		result = ResultCalculation(AiChoice, UserChoice);
		if (result == "Draw") {
			system("color 80");
			Beep(300, 700);
			Beep(300, 700);
			system("color 0f");
			drawsCounter++;
			cout << result << endl << endl;
		}
		else if (result == "Winner") {
			system("color A0");
			Beep(400, 400);
			Beep(500, 600);
			system("color 0f");
			winsCounter++;
			cout << result << endl << endl;
		}
		else {
			system("color CF");
			Beep(500, 600);
			Beep(400, 400);
			system("color 0f");
			lossesCounter++;
			cout << result << endl << endl;

		}
	}
	cout << "Wins : " << winsCounter << endl;
	cout << "Losses : " << lossesCounter << endl;
	cout << "Draws : " << drawsCounter << endl;

}


int main() {
	int rounds;
	int winsCounter = 0;
	int lossesCounter = 0;
	int drawsCounter = 0;
	srand((unsigned)time(NULL));

	Header();
	cin >> rounds;

	choices AIchoice;
	choices UserChoice;
	string result;
	RoundPrint(AIchoice, UserChoice, result, rounds, drawsCounter, winsCounter, lossesCounter);
	cout << endl << endl;

	cout << "Do You Want To Play Again ? Yes = (1) or (Yes) or (yes)   No = (0) or (No) or (no) ";

	string ChoiceForAnotherTime;

	cin >> ChoiceForAnotherTime;

	int gamescounter = 1;

	if (ChoiceForAnotherTime == "yes" || ChoiceForAnotherTime == "Yes" || ChoiceForAnotherTime == "1") {
		gamescounter++;
		while (gamescounter > 1) {
			winsCounter = 0;
			lossesCounter = 0;
			drawsCounter = 0;
			RoundPrint(AIchoice, UserChoice, result, rounds, drawsCounter, winsCounter, lossesCounter);
	
			cout << "Do You Want To Play Again ? Yes = (1) or (Yes) or (yes)   No = type anything ";
			cin >> ChoiceForAnotherTime;
			if (ChoiceForAnotherTime == "no" || ChoiceForAnotherTime == "No" || ChoiceForAnotherTime == "0") {
				exit(0);
			}

		}

	}
	

}




