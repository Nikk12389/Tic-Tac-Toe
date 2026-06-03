#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;
bool check_win(vector<vector<char>> &board);

void system_choice(vector<vector<char>> &board,bool &c){
    int i=rand()%3;
    int j=rand()%3;
    while(board[i][j]=='x' || board[i][j]=='o'){
        i=rand()%3;
        j=rand()%3;
    }
        board[i][j]='x';
         c=check_win(board);
         cout<<"BOARD:"<<endl;
        for(int i=0;i<3;i++){
          for(int j=0;j<3;j++)
          {
            cout<<board[i][j]<<" ";      
          }
          cout<<endl;
        } 

}
void user(vector<vector<char>> &board,bool &c){
    int index,i,j;
    cout<<"enter index number from (1 to 9) you want to place o"<<endl;
    cin>>index;
    while(cin.fail()){
        cin.clear();
        cin.ignore(100000,'\n');
        cout<<"INVALID index"<<endl<<"enter again"<<endl;
        cin>>index;
    }

    while(index<1 || index>9){
        cout<<"invalid index"<<endl<<"enter index again from 1 to 9"<<endl;
        cin>>index;
    }
    switch(index){
        case 1: i=0,j=0;
        break;
        case 2: i=0,j=1;
        break;
        case 3: i=0,j=2;
        break;
        case 4: i=1,j=0;
        break;
        case 5: i=1,j=1;
        break;
        case 6: i=1,j=2;
        break;
        case 7: i=2,j=0;
        break;
        case 8: i=2,j=1;
        break;
        case 9: i=2,j=2;
        break;

    }
    if(board[i][j]!='x' && board[i][j]!='o'){
        board[i][j]='o';
        c=check_win(board); 
        cout<<"BOARD:"<<endl;
        
         for(int i=0;i<3;i++){
          for(int j=0;j<3;j++)
          {
            cout<<board[i][j]<<" ";      
          }
          cout<<endl;
        }     
    }
    else
    {
        cout<<"index already filled"<<endl;
        return user(board,c);
    } 
    
    

}
bool check(char a,char b,char c){
    if(a==b&&a==c){
        if(a=='x'){
            cout<<"lose"<<endl;
            return true;
        }
        if(a=='o'){
            cout<<"win"<<endl;
            return true;
        }
    }
    return false;
    

}
bool check_win(vector<vector<char>> &board){
    if(check(board[0][0],board[1][1],board[2][2])) return true; 
    if(check(board[0][2],board[1][1],board[2][0])) return true;  
    if(check(board[0][0],board[0][1],board[0][2])) return true;  
    if(check(board[1][0],board[1][1],board[1][2])) return true;  
    if(check(board[2][0],board[2][1],board[2][2])) return true;  
    if(check(board[0][0],board[1][0],board[2][0])) return true;  
    if(check(board[0][1],board[1][1],board[2][1])) return true;  
    if(check(board[0][2],board[1][2],board[2][2])) return true;   
    return false;        
}




int main(){
    
    srand(time(0));
    int play=1;

   while(play==1){
    int moves=0;
     bool c=false;

    vector<vector<char>> board(3,vector<char>(3,'.'));
    
       
            while(moves<9){
                system_choice(board,c);
                moves++;
             
                 if(c==true || moves>=9){
                   break;
                 }
 
                user(board,c);
                moves++;
                if(c==true || moves>=9){
                   break;
                 }
                
            }
            if(c==false){
                cout<<"draw"<<endl;
            }
            
          
  
       cout<<"type enter key to continue....."<<endl;
       cin.ignore();
       cin.get();
       
       
       cout<<"enter 1 to play again and 0 for exit"<<endl;
       cin>>play;
   }

   cout<<"THANKYOU FOR PLAYING"<<endl;
    
    
   
    
}





/*
play again is printing too quicly after win/lose/draw  soo; cin.get() and system("pause") can be used 
cin.get()---> it continues the execution only after we press ENTER key;but in this we use endl after every cout that's why there is a chane that
endl will be in buffer and if it is in buffer then cin.get() automatically take it so we use cin.ignore() and cin.get();cin.ignore() clears the cin.

system("pause")---> it continues after pressing ANY KEY.pause is a string which s a command which prints press any key to contnue automatically
if we pass something like jnvndk as a string in system() then it shows error becoz it is not a command ,

we use cin.get() becoz system() works on windows only.
cin.get() is fast;system() is slower becoz it launches a new process just to pause.
*/