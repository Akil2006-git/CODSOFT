#include <iostream>
#include <random>
using namespace std;
int main(){

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> distr(1, 100);
int Secretnum = distr(gen);
int PLAYERGUESS;
int attempt=0;
string ans;

cout<<"Welcome to the game"<<endl;
cout<<"I have a secreat number. Can you guess it?"<<endl;
cin>>ans;
 if(ans == "YES"|| ans == "yes"){
    cout<<"Let's start"<<endl;

do {
    cout<<"Guess the number:";
    cin>>PLAYERGUESS;
    attempt++;

    if(Secretnum > PLAYERGUESS){
        cout<<"Too Low from the Secretnum"<<endl;
    }
    else if(Secretnum < PLAYERGUESS){
        cout<<"Too High from the Secretnum"<<endl;
    }
}
while(Secretnum != PLAYERGUESS);

 cout<<"Congratulations!! You have guessed the correct number in "<<attempt<< " attempts."<<endl;
 }
    else{
    cout<<"EXIT"<<endl;

}









}
