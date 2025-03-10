#include<iostream>
using namespace std;

bool IsEqual3(int x, int y, int z){
    if(x == y && x == z && x != ' '){
        return true;
    }
    return false;
}

int GetStatus(char board[3][3]){
for(int i =0 ;i < 3; i++){
if(IsEqual3(board[i][0],board[i][1],board[i][2])){
    if(board[i][1] == 'X'){return 2;}else if(board[i][1] == 'O') {return -2;}
}
}
for(int i =0 ;i < 3; i++){
if(IsEqual3(board[0][i],board[1][i],board[2][i])){
    if(board[1][i] == 'X'){return 2;}else if(board[1][i] == 'O'){return -2;}
}
}

if(IsEqual3(board[0][0],board[1][1],board[2][2])){
    if(board[1][1] == 'X'){return 2;}else if(board[1][1] == 'O'){return -2;}
}
if(IsEqual3(board[2][0],board[1][1],board[0][2])){
    if(board[1][1] == 'X'){return 2;}else if(board[1][1] == 'O'){return -2;}
}
for(int i = 0; i<3;i++){
    for(int j=0;j<3;j++){
        if(board[i][j] == ' '){
            return 0;
        }
    }
    
}
return 1;
}
void drawboard(char board[3][3])
{
for(int i = 0; i<3;i++){
    for(int j=0;j<3;j++){
        cout<<'|'<< board[i][j]<<'|';
    }
    cout<<"\n---------\n";
}

}


int main(){
//I need to draw board -> 2d array
char board[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}};
drawboard(board);
//2 players X and O, user inserts the column and row then the turn for the other player
int row,column;
char player = 'X';
int status = 0;
while(status == 0){
    cout<<"please enter the row and column\n";
    cin>>row>>column;
    if (board[row][column] == ' ')
    {board[row][column] = player;}
    else{
        cout<<"this slot is filled please try another one";
        continue;
    }
    
    player = (player == 'X' ) ? 'O' : 'X';
    drawboard(board);
    status = GetStatus(board);
    //check the status of the game, winner -> 2, lose -> -1, tie -> 1, none -> 0 
}
if (status == 2){
    cout << "X wins"; 
}
else if( status == -2){
    cout << "Y wins"; 
}
else if( status == 1){
    cout << "Tie"; 
}



}