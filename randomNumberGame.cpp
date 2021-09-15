#include<iostream>
#include<random>
#include<cstdlib>
#include<ctime>

using namespace std;

int nf , nl , randomNumber , tries, answer;

int randomNumberGenerator(int nl, int nf)    
{
    mt19937 random;
    uniform_int_distribution<uint32_t> dice(nl,nf);
    random.seed(time(0));

    int randomN = dice(random);

    randomNumber = randomN;
    
    return randomNumber;
}

int numbers (){
    cout<<"number in: ";cin>>nl;
    cout<<"number to: ";cin>>nf;
    
    return nl, nf;
}

void game(int answer, int tries, int randomNumber){
    for (int i = 1; i < tries || randomNumber == answer; i++)
    {
        if (randomNumber > answer){
        cout<<"the number is higher, enter a number: ";cin>>answer;} 
        else if (randomNumber < answer){
        cout<<"the number is lower, enter a number:  ";cin>>answer;}
    }
    
    if (answer!=randomNumber){
        char answer;
        cout<<"you lost... but you can still try again!!"<<endl;
        cout<<"do you want to play again?"<<endl;
        cin>>answer;
        if (answer == 'y')
        {
            numbers();
        } else if (answer == 'n')
        {
            cout<<"bye"<<endl;
        }
         else
        {
            cout<<"missinput"<<endl;
        }
        
    }
    
    if (answer == randomNumber) {
        char answer;
        cout<<"You win!! Lest's play again"<<endl;
        cout<<"do you want to play again?"<<endl;
        cin>>answer;
        if (answer == 'y')
        {
            numbers();
        } else if (answer == 'n')
        {
            cout<<"bye"<<endl;
        }
         else
        {
            cout<<"missinput"<<endl;
        }
        
    }

}

int main()
{
    numbers();
    if (nl > nf)
    {
        cout<<"you can't do that... please insert other number"<<endl;
        numbers();
    } else
    {
       cout<<"number of tries: ";cin>>tries;
    randomNumberGenerator(nl,nf);
    cout<<randomNumber<<endl;
    cout<<"insert your number: ";cin>>answer;
    game(answer,tries, randomNumber); 
    }

    return 0;
}