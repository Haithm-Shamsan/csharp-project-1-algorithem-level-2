// Project 1,algorithem level 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum enChoises {paper=1,sesser=2,stone=3};
enum enWinner{player=1,cumpote=2,Drow=3};
struct stRoundInfo {

	short HowManyRounds=0;
	enChoises PlayerChoise;
	enChoises CumpoterChoise;
	enWinner Winner;
	string WinnerName;

};
struct strGameResulte {

	short hwoManyrounds=0;
	short PlayerWonTimes=0;
	short cumpoterWonTimes = 0;
	short DrowTimes = 0;
	enWinner Winner;
	string NameWinner="";


};
int RandomNumber(int From, int To) 
{ 
	int randNum = rand() % (To - From + 1) + From; return randNum; 
}
string WinnerName(enWinner Winner) {
	string arr[3] = { "Player","cumpoter","NoWinner" };
	return arr[Winner - 1];
}
enWinner WhoWonTheRound(stRoundInfo RoundInfo) {

	

	if (RoundInfo.CumpoterChoise == RoundInfo.PlayerChoise) {
		return enWinner::Drow;
	}

	switch (RoundInfo.PlayerChoise)
	{
	case enChoises::paper:
		if (RoundInfo.CumpoterChoise == enChoises::sesser) {
			;
			return enWinner::cumpote;
		}
		break;
	case enChoises::sesser:
		if (RoundInfo.CumpoterChoise == enChoises::stone) {
			;
			return enWinner::cumpote;
		}
		break;
	case enChoises::stone:
		if(RoundInfo.CumpoterChoise == enChoises::paper){
		return enWinner::cumpote;}
		break;
	}

	return enWinner::player;
}
string ChoisesName(enChoises Choises) {

	string arr[3] = { "paper","sesser","stone" };
	return arr[Choises - 1];

}
void SetColorScreen(enWinner Winner) {

	switch (Winner)
	{
	case enWinner::player:
		system("color 2F");
		break;
	case enWinner::cumpote:
		system("color 4F");
		cout << "\a";
		break;
	case enWinner:: Drow:
		system("color 6F");
		break;
	
	}

}
void PrintRoundReslute(stRoundInfo RoundInfo) {
	
	cout << "--------------------------------------[" << RoundInfo.HowManyRounds << "]------------------------------------" << endl;
	cout << "Player Choise :" << RoundInfo.PlayerChoise << endl;
	cout << "cumpoter Choise :" << RoundInfo.CumpoterChoise << endl;
	cout << "Winner :" << RoundInfo.Winner << endl;
	cout << "Winner Name :" << RoundInfo.WinnerName << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	SetColorScreen(RoundInfo.Winner);
}
enWinner WhoWonTheGame(short PlayerWinTimes, short CumpoterWinTimes) {

	if (PlayerWinTimes > CumpoterWinTimes)
		return enWinner::player;
	else if (CumpoterWinTimes > PlayerWinTimes)
		return enWinner::cumpote;
	else
		return enWinner::Drow;


}
strGameResulte FallGameResulte(int HowManyRounds, short PlayerWinTimes, short CumpoterWinTimes, short DrowTimes) {

	strGameResulte GameResulte;
	GameResulte.hwoManyrounds = HowManyRounds;
	GameResulte.PlayerWonTimes = PlayerWinTimes;
	GameResulte.cumpoterWonTimes = CumpoterWinTimes;
	GameResulte.DrowTimes = DrowTimes;
	GameResulte.Winner = WhoWonTheGame(PlayerWinTimes,CumpoterWinTimes);
	GameResulte.NameWinner = WinnerName(GameResulte.Winner);
	return GameResulte;

}
enChoises ReadPlayerChoise() {
	short choise = 1;
	do
	{
		cout << "what choise do you want?paper[1],sesser[2],stone[3]?" << endl;
		cin >> choise;
	} while (choise<1||choise>3);
	return(enChoises) choise;
}
enChoises GetCumpoterChoise() {
	return(enChoises)RandomNumber(1, 3);
}
strGameResulte PlayGame(int HowManyRounds) {

	stRoundInfo RoundInfo;
	short PlayerWinTimes=0, CumpoterWinTimes=0, DrowTimes=0;
	for (int GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "-----------Round [" << GameRound << "] begian-------------------" << endl;
		 RoundInfo.HowManyRounds = GameRound ;
		 RoundInfo.PlayerChoise =ReadPlayerChoise();
		  RoundInfo.CumpoterChoise =GetCumpoterChoise();
		RoundInfo.Winner= WhoWonTheRound(RoundInfo);
		 RoundInfo.WinnerName =WinnerName(RoundInfo.Winner);
	

		if (RoundInfo.Winner==enWinner::player)
			PlayerWinTimes++;
		else if (RoundInfo.Winner==enWinner::cumpote)
			CumpoterWinTimes++;
		else
			DrowTimes++;

		PrintRoundReslute(RoundInfo);
		cout << endl; cout << endl;

	}
	return FallGameResulte(HowManyRounds, PlayerWinTimes, CumpoterWinTimes, DrowTimes);
}
string Tabs(short Tabs) {
	string t = "";
	for (int i = 1; i < Tabs; i++)
	{
		t = t + "\t";
		cout << t;
	}
	return t;
}
void ShowGameOverScreen() {
	cout << endl << Tabs(2) << "------------------------------------------------------------------------------------------------------" << endl;
	cout << endl << Tabs(2) << "                                + + + G a m e O v e r + + + " << endl;
	cout << endl << Tabs(2) << "------------------------------------------------------------------------------------------------------" << endl;

}
void PrintGameResulte(strGameResulte GameResulte) {
	
	cout <<Tabs(2)<< "---------------------------------------------------------------------------------" << endl;
	cout  << Tabs(2) << "Number of Rounds :" << GameResulte.hwoManyrounds << endl;
	cout  << Tabs(2) << "Player Win :" << GameResulte.PlayerWonTimes << "Time(s)" << endl;
	cout  << Tabs(2) << "Cumpoter Win :" << GameResulte.cumpoterWonTimes << "Time(s)" << endl;
	cout  << Tabs(2) << "Drow :" << GameResulte.DrowTimes << "Time(s)" << endl;
	cout  << Tabs(2) << "The Winner :" << GameResulte.Winner << endl;
	cout  << Tabs(2) << "Winner Name :" << GameResulte.NameWinner << endl;
	cout << Tabs(2)<<"----------------------------------------------------------------------------------" << endl;
	SetColorScreen(GameResulte.Winner);
}
void ResetScreen() {
	system("cls");
	system("color 0F");
}
short NumberOfRounds() {
	short Number=1;
	do
	{
		cout << "how many Rounds do you want to play?1 - 10" << endl;
		cin >> Number;
	} while (Number<1||Number>10);
	return Number;
}
void PlayGame() {

	char PlayAgain = 'Y';
	do
	{
		ResetScreen();
		strGameResulte GameResulte = PlayGame(NumberOfRounds());
		ShowGameOverScreen();
		PrintGameResulte(GameResulte);


		cout << endl<<"do you wanto to play agien?Y/N" << endl;
		cin >> PlayAgain;

	} while (PlayAgain=='y'||PlayAgain=='Y');


}





int main()
{
	srand((unsigned)time(NULL));
	PlayGame();
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
