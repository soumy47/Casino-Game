
#include<iostream>
#include<string>
#include<cstdlib>  // Needed to use random numbers
#include<ctime>
using namespace std;
void rules();

int main(){
    string playerName;
    int balance;  // stores player's balance
    int bettingAmt;
    int guess; 
    int dice;     //stores the random no.
    char choice;

    srand(time(0)); // sets seed for random generator
    cout<<"\n\t\t=======WELCOME TO CASINO WORLD======\n\n";
    cout<<"\n What's your name :  ";
    getline(cin, playerName);
    cout<<"\n\n Enter the initial balance to play game :  $";
    cin >> balance;
    do{
        system("cls");
        rules(); // rules to be followed

        cout<<"\n\n Your curent balance is $ "<<balance<<"\n";

        // Get the player's bettingAmount
        do{
                cout<<"Hey, "<<playerName<<", enter the to be bet : $";
                cin>>bettingAmt;
                if(bettingAmt > balance){
                    cout<<"Betting balance can't be more than the current balance! \n";
                    cout<<"Re-enter  balance\n";
                }
        }while(bettingAmt > balance);

        // get the player's number
        do{
                cout<<"Guess any betting number between 1 and 10 : ";
                cin>>guess;
                if((guess <=0) ||  (guess > 10)){
                    cout<<"\nNumber should be between 1 and 10\n "<<"Re-enter number :\n";
                }
        }while((guess <=0) ||  (guess > 10));

        dice = rand()%11;  // gives no between 1 to 10
        if(dice == guess){
            cout<<"\n\n Bravo! You're  in luck! You have won"<<bettingAmt*10;
            balance  += bettingAmt*10;
        }
        else{
            cout<<"Oops!, better luck next time !! You lost $"<<bettingAmt<<"\n";\
            balance -= bettingAmt;
        }
        cout<<"\nThe winning number was : "<<dice<<"\n";
        cout<<"\n"<<playerName<<", you've balance of "<<balance<<"\n";
        if(balance == 0){
            cout<<"\nYou've no money to play\n";
            break;
        }
        cout<<"\n\n -->Do you want to play again(y/n)";
        cin>>choice;
    }while(choice=='Y' || choice =='y');
    cout<<"\n\n Thanks for playing the game. Your balance is $"<<balance<<"\n\n";
    
    return 0;
}

void rules()
{
    system("cls");
    cout<<"\t\t======CASINO NUMBER GUESSING GAME!======\n";
    cout<<"\t1. Choose a number between 1 and 10. \n";
    cout<<"\t2. Winner gets 10 times of the money bet.\n";
    cout<<"\t3. Wrong bet, and you lose the amount you bet.\n\n";
}
