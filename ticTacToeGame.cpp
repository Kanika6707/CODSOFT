#include<iostream>
using namespace std;
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
char token ='X';
bool tie=false;
string n1;
string n2;


void functionone(){    
    
    
    cout<<"   |   |   \n";
    cout<<" "<<space[0][0]<<" |  "<<space[0][1]<<"|  "<<space[0][2]<<"\n";
    cout<<"___|___|___\n";
    cout<<"   |   |   \n";
    cout<<" "<<space[1][0]<<" |  "<<space[1][1]<<"|  "<<space[1][2]<<"\n";
    cout<<"___|___|___\n";
    cout<<"   |   |   \n";
    cout<<" "<<space[2][0]<<" |  "<<space[2][1]<<"|  "<<space[2][2]<<"\n";
    cout<<"   |   |   \n";
    
}



void functiontwo(){
    int digit;
    if(token=='X'){
        cout<<n1<<"please enter";
        cin>>digit; 
    }
    if(token=='O'){
        cout<<n2<<"please enter";
        cin>>digit;
    }
    if(digit==1){
        row=0;
        column=0;
    }
    if(digit==2){
        row=0;
        column=1;
    }
    if(digit==3){
        row=0;
        column=2;
    }
    if(digit==4){
        row=1;
        column=0;
    }
    if(digit==5){
        row=1;
        column=1;
    }
    if(digit==6){
        row=1;
        column=2;
    }
    if(digit==7){
        row=2;
        column=0;
    }
    if(digit==8){
        row=2;
        column=1;
    }
    if(digit==9){
        row=2;
        column=2;
    }
    else if(digit<1 || digit>9){
        cout<<"invalid !!! choice please enter number between 1 to 9 \n";
        functiontwo();
        return;
    }
    if(token=='X' && space[row][column]!='X' && space[row][column]!='O'){
        space[row][column]='x';
        token='O';
    }
    else if(token=='O' && space[row][column]!='X' && space[row][column]!='O'){
        space[row][column]='O';
        token='X';
    }
    else{
        cout<<"there is no empty space"<<endl;
        functiontwo();
    }
    functionone();

}



bool functionthree(){
    for(int i=0;i<3;i++){
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i]){
            return true;
        }
        else if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[0][2]==space[2][0]){
            return true;
        }
    }    
    for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
               if(space[i][j]!='X' && space[i][j]!='O'){
                return false;
            } 
        }
    }
    tie=true;
    return false;
    
    

}
    


int main() {
    char playAgain;

    do {
        
        char newSpace[3][3] = {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
        };

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                space[i][j] = newSpace[i][j];
            }
        }

        token = 'X';
        tie = false;

        cout << "\nEnter name of the first person: ";
        getline(cin >> ws, n1);

        cout << "Enter name of the second person: ";
        getline(cin, n2);

        cout << n1 << " will play first using X\n";
        cout << n2 << " will play second using O\n";

        functionone();   

        while (!functionthree()) {
            functiontwo();

            if (functionthree()) {
                break;   
            }


            if (tie) {
                break;
            }
        }

        if (tie == true) {
            cout << "Draw!!\n";
        }
        else if (token == 'X') {
            cout << n2 << " Wins!!\n";
        }
        else {
            cout << n1 << " Wins!!\n";
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";

    return 0;
}