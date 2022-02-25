#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;



class Number {
	public:
		bool correct = false ; //是否為正確數字 
		int location = 0; //紀錄正確位置，0為未知
		int value = 0;//紀錄物件數值
		bool nowGuess = false;
		bool Mistake = false;
		
		int guess[10];//紀錄猜測順序的堆疊 
		int guessTime = 0;
		
		
		void guessUP(int n){ //guess堆疊 
			guess[guessTime] = n;
			guessTime++;
		}
		
		
};


Number guess[9]; //宣告九個數值物件 
char point[5];

void randomAll(){//四個全換 
	int n = 0;
	
	for(int i = 0 ; i<4 ; i++){
		
		int n = 0;
		do{
			n = rand()%9; //9個物件 
		} while(guess[n].Mistake == true || guess[n].nowGuess == true);//隨機抽出一個物件，如果已被選過則重新選取 
		
		guess[n].nowGuess = true; //紀錄物件已被選過 
		guess[n].guessUP(n);//紀錄位置 
		cout << guess[n].value;//輸出結果 
		
	} cout << endl;
	
}

void finedA(){ //尋找A 

}


void  chooseLoacat(){//四位數字都正確，尋找排列 
	 	int vacancy[4] = {0,0,0,0};
 		int newLocat;
	
		for(int i = 0 ; i<9 ; i++){//確認處於正確位置的數值 
			if(guess[i].nowGuess == true){
				if(guess[i].correct == true){
					vacancy[guess[i].guess[guess[i].guessTime]]=guess[i].value;
				}
			}
		}

		for(int i = 0 ; i<9 ; i++){//更換新位置，但不更動已經正確的數字 
			if(guess[i].nowGuess == true && guess[i].correct != true){
				do{
					newLocat = rand()%4;
					//cout << newLocat << " - " <<vacancy[newLocat] << "|";
				} while(vacancy[newLocat] != 0);
				vacancy[newLocat] = guess[i].value;
			}

		}
		
		for(int i = 0 ; i < 4 ; i++){//輸出新排序 
			cout << vacancy[i] ;
		}cout << endl;
}




//----------------------------------------------------------入口函式 

int main(){
	
  cout<<"1093203"<<endl;
  cout<<"劉至恩"<<endl;
  //-----------------------
  cout<<"demo"<<endl;
  return 1;
  
	srand((unsigned) time(NULL));//亂數種子 
	
	for(int i = 0 ; i<9 ; i++){//輸入物件value 
		guess[i].value = i+1;
	}
	
	randomAll();
	
	
	do{
		cin >> point;//玩家輸入提示 
		if(point[5] != 0 || point[1] != 'A' &&point[1] != 'a' || point[3] != 'B' && point[3] != 'b' || (int)point[0]-48 + (int)point[2]-48 > 4){ 
			cout << "請勿輸入規範外格式，請重新輸入xAyB。" << endl; //玩家輸入錯誤資訊時不進行下一步驟 
		}
	}while(point[5] != 0 || point[1] != 'A' &&point[1] != 'a' || point[3] != 'B' && point[3] != 'b' || (int)point[0]-48 + (int)point[2]-48 > 4);
	
	
	cout << "輸入了：" ; //測試用 
	for(int i = 0 ; i<4 ; i++){
		cout << point[i] ;
	} cout << endl;
	
	if(point[0]== '0'&& point[2] == '0' ){//全錯 
		for(int i = 0 ; i<9 ; i++){
			if(guess[i].nowGuess == true){
				guess[i].nowGuess = false;
				guess[i].Mistake = true;
			}
		}
		randomAll();
	}else if( ((int)point[0]-48 + (int)point[2]-48) == 4){//交換順序 

 		chooseLoacat();
		
	} else if(point[0] == 0){
		
	} else if(point[0] == 1){

	} else if(point[0] == 2){
		
	} else if(point[0] == 3){
		
	} else if(point[0] == 4){
		cout << "我猜對了" << endl ;
	}

}
