#include<iostream>
#include<time.h>

using namespace std;

string choices [3] = {"r", "p", "s"};

int you_score {0}; //ints to hold the scores
int pc_score {0};

string you_choice {}; //char vars to hold the choices
string pc_choice {};
void intro_art(){
    cout<<endl;
    cout<<"               __"<<endl;
    cout<<"             _|  |_"<<endl;
    cout<<"           _|      |_"<<endl;
    cout<<"          |  _    _  |"<<endl;
    cout<<"          | |_|  |_| |"<<endl;
    cout<<"       _  |  _    _  |  _"<<endl;
    cout<<"      |_|_|_| |__| |_|_|_|"<<endl;
    cout<<"        |_|_        _|_|"<<endl;
    cout<<"          |_|      |_|"<<endl;
    cout<<endl;
    cout << "We will play a game of Rock Paper Scissors"<<endl<<"Best to three wins. Can you beat your PC?"<<endl;
    cout<<endl;
}
void pc_num_pick (){ //function to choose a thing
    int Randindex =rand() % 3;
    pc_choice = choices[Randindex];
}
void state_you_choice (){
    if (you_choice=="r") cout<<"\x1B[32mYou have chosen Rock!\033[0m\t\t"<<endl;
    else if (you_choice == "p") cout<<"\x1B[32mYou have chosen Paper!\033[0m\t\t"<<endl;
    else cout<<"\x1B[32mYou have chosen Scissors!\033[0m\t\t"<<endl;
}
void state_pc_choice (){
    if (pc_choice=="r") cout<<"\x1B[31mYour PC has chosen Rock!\033[0m\t\t"<<endl;
    else if (pc_choice == "p") cout<<"\x1B[31mYour PC has chosen Paper!\033[0m\t\t"<<endl;
    else cout<<"\x1B[31mYour PC has chosen Scissors!\033[0m\t\t"<<endl;
}
void who_won(){
    if (you_choice == "r" && pc_choice == "s"){
        you_score = you_score+1;
        cout <<"\x1B[32mRock blunts Scissors, you win this round\033[0m\t\t"<<endl;
    }
    else if (you_choice == "p" && pc_choice == "r"){
        you_score = you_score+1;
        cout <<"\x1B[32mPaper wraps Rock, you win this round\033[0m\t\t"<<endl;
    }
    else if (you_choice == "s" && pc_choice == "p"){
        you_score = you_score+1;
        cout <<"\x1B[32mScissors cut Paper, you win this round\033[0m\t\t"<<endl;
    }
    else if (you_choice == "p" && pc_choice == "s"){
        pc_score = pc_score+1;
        cout <<"\x1B[31mScissors cut Paper, you loose this round\033[0m\t\t"<<endl;
    }
    else if (you_choice == "s" && pc_choice == "r"){
        pc_score = pc_score+1;
        cout <<"\x1B[31mRock blunts Scissors, you loose this round\033[0m\t\t"<<endl;
    }
    else if (you_choice == "r" && pc_choice == "p"){
        pc_score = pc_score+1;
        cout <<"\x1B[31mPaper wraps Rock, you loose this round\033[0m\t\t"<<endl;
    }
    else    
        cout<<"A draw! Urgg, the suspense"<<endl;
}
void current_scores (){
    cout<<"**************************"<<endl;
    cout<<"\x1B[32mYOU\033[0m\t\t \x1B[31mPC\033[0m\t\t "<<endl;
    cout<<" "<<you_score<<"                "<<pc_score<<endl;
    cout<<"**************************"<<endl;
    cout<<endl;
    if (you_score == 1 && pc_score == 1) cout <<"OOO a tie, who ever wins the next round, takes teh title"<<endl;
    else if (you_score == 1 && pc_score == 0) cout <<"an early lead, can you kep it up?"<<endl;
    else if (you_score == 0 && pc_score == 1) cout <<"Haha! you are loosing, what a noob"<<endl;

}
// void play_again(){
//     cout<<"Would you like a rematch? Y?N :";
//     string answer {};
//     cin >> answer;
//     if (answer == "Y")
//         game_logic();
//     else
//         break;
// }

int main (){
    srand(time(NULL)); //initialise the random seed
    intro_art();
    while (you_score + pc_score < 3){
        cout << "please choose r/p/s: ";
        cin >> you_choice;
        state_you_choice();
        pc_num_pick();
        cout<<endl;
        state_pc_choice();
        cout<<endl;
        who_won();
        cout<<endl;
        current_scores();
        cout<<endl;
    }
    cout << ((you_score > pc_score) ? "Huzaar, you beat your PC" : "Oh Dear, how embarrasing for you, you lost to this?!") <<endl;
    return 0;
}