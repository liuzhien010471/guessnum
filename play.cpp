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
		int nowLocation = 0; 
		
		int guess[10];//紀錄猜測順序的堆疊 
		int guessTime = 0;
		
		
		void guessUP(int n){ //guess堆疊 
			guess[guessTime] = n;
			guessTime++;
		}
		
		
};


Number guess[9]; //宣告九個數值物件 
char point[5];
int vacancy[4] = {0};//記錄猜出的數值 

void randomAll(){//四個全換 
	int n = 0;

	for(int i = 0 ; i<4 ; i++){
		if(vacancy[i] != 0){//舊的數字清空 
			guess[vacancy[i]-1].nowGuess = false;
			guess[vacancy[i]-1].nowLocation = 0;
		}
		
		
		int n = 0;
		do{
			n = rand()%9; //9個物件 
		} while(guess[n].Mistake == true || guess[n].nowGuess == true);//隨機抽出一個物件，如果已被選過則重新選取 
		
		guess[n].nowGuess = true; //紀錄物件已被選過 
		guess[n].nowLocation = i+1;//紀錄物件現在位置 
		guess[n].guessUP(n);//紀錄位置 
		
		
		vacancy[i] = guess[n].value;
	} 
	
	
}

int changeTimes = 0;
char newPoint[5];



void  chooseLoacat(){//四位數字都正確，尋找排列 
	int n=0;
	int newLocat[4] = {0};

	for(int i = 0; i<9 ; i ++){
		guess[i].nowGuess = false;
	}

	for(int i=0 ; i<4 ;i++){
		guess[vacancy[i]-1].nowGuess = true;
	}

	while(newPoint[0] != '4'){
		
		newLocat[0] = 0;
		newLocat[1] = 0;
		newLocat[2] = 0;
		newLocat[3] = 0;
		
		for(int i = 0 ; i<9 ; i++){//確認處於正確位置的數值 
			if(guess[i].nowGuess == true && guess[i].location != 0){
				vacancy[guess[i].location-1] = guess[i].value;
				newLocat[guess[i].location-1] = 1;//紀錄位置被占用 
			}
		}

		for(int i = 0 ; i<9 ; i++){//更換新位置，但不更動已經正確的數字 
			if(guess[i].nowGuess == true && guess[i].location == 0 ){
				do{
					n = rand()%4+1;
				} while(newLocat[n-1] != 0 );
				newLocat[n-1] = 1;
				vacancy[n-1] = guess[i].value;
				guess[i].nowLocation = n;
				//cout << "k " ;
			}
		}
		
		cout << "我猜：" ; 
		for(int i = 0 ; i < 4 ; i++){//輸出新排序 
			cout << vacancy[i] ;
		}cout << endl;
		
		cin >> newPoint;

	}
	
	cout << "我猜對了" << endl ;
		
}



void finedA(){ //尋找A 
	int breakTimes = 0;
	
	while(point[0] != 4){
		int k = 0;
		changeTimes ++;
		if(changeTimes > 4){
			//cout << "reset" << endl;
			changeTimes = 1;
		}
		int oldClass;
		int changeLocat = 0;
		int loopTimes=0;
		
		if(breakTimes > 5){
			cout << "偵測到潛在的運算錯誤，可能為程序異常或提供錯誤題示導致，建議觀察後依據情況重新啟動遊戲" << endl;  
		}
		
		if(changeTimes == 4){ //更動第四位數 
			for(int i = 0 ; i<9 ; i++){
				if(guess[i].nowGuess == true && guess[i].nowLocation == 4 && guess[i].value == vacancy[3]){
					if(guess[i].location != 0){
						changeTimes++;
						break;
					} 
					oldClass = guess[i].value;
					changeLocat = 4;
					do{
						k = rand()%9;
						loopTimes++;
					} while((guess[k].nowGuess == true || guess[k].Mistake == true || guess[k].location != 0)&& loopTimes<100);
					
					if(loopTimes >= 100){//無法正確時跳出 
						loopTimes = 0;
						changeTimes ++;
						breakTimes++;
						//cout << "break " ;
						break;
					}
					
					guess[i].nowGuess = false;
					guess[i].nowLocation = 0; 
				}
			}
			vacancy[3] = guess[k].value;
			guess[k].nowGuess = true;
			guess[k].nowLocation = 4; 
		
		} if(changeTimes == 3){ //更動第三位數 
			for(int i = 0 ; i<9 ; i++){
				if(guess[i].nowGuess == true && guess[i].nowLocation == 3 && guess[i].value == vacancy[2]){
					if(guess[i].location != 0){
						changeTimes++;
						break;
					} 
					oldClass = guess[i].value;
					changeLocat = 3;
					do{
						k = rand()%9;
						loopTimes++;
					} while((guess[k].nowGuess == true || guess[k].Mistake == true || guess[k].location != 0)&& loopTimes<100);
					
					if(loopTimes >= 100){//無法正確時跳出 
						loopTimes = 0;
						changeTimes ++;
						breakTimes++;
						//cout << "break " ;
						break;
					}
					
					guess[i].nowGuess = false;
					guess[i].nowLocation = 0; 
				}
			}
			vacancy[2] = guess[k].value;
			guess[k].nowGuess = true;
			guess[k].nowLocation = 3; 
			 
		} if(changeTimes == 2){ //更動第二位數 
			for(int i = 0 ; i<9 ; i++){
				if(guess[i].nowGuess == true && guess[i].nowLocation == 2 && guess[i].value == vacancy[1]){
					if(guess[i].location != 0){
						changeTimes++;
						break;
					} 
					oldClass = guess[i].value;
					changeLocat = 2; 
					do{
						k = rand()%9;
						loopTimes++;
					} while((guess[k].nowGuess == true || guess[k].Mistake == true || guess[k].location != 0)&& loopTimes<100);
					
					if(loopTimes >= 100){//無法正確時跳出 
						loopTimes = 0;
						changeTimes ++;
						breakTimes++;
						//cout << "break " ;
						break;
					}
					
					guess[i].nowGuess = false;
					guess[i].nowLocation = 0;
					
				}
			}
			vacancy[1] = guess[k].value;
			guess[k].nowGuess = true;
			guess[k].nowLocation = 2; 
			
		} if(changeTimes == 1){ //更動第一位數 
			for(int i = 0 ; i<9 ; i++){
				if(guess[i].nowGuess == true && guess[i].nowLocation == 1 && guess[i].value == vacancy[0] ){
					if(guess[i].location != 0){
						changeTimes++;
						break;
					} 
					oldClass = guess[i].value;
					changeLocat = 1;
					do{
						k = rand()%9;
						loopTimes++;
					} while((guess[k].nowGuess == true || guess[k].Mistake == true || guess[k].location != 0 )&& loopTimes<100);
					
					if(loopTimes >= 100){//無法正確時跳出 
						loopTimes = 0;
						changeTimes ++;
						breakTimes++;
						//cout << "break " ;
						break;
					}
					
					guess[i].nowGuess = false;
					guess[i].nowLocation = 0; 
					
				}
			}
			vacancy[0] = guess[k].value;
			guess[k].nowGuess = true;
			guess[k].nowLocation = 1; 
		}
		
		cout << "我猜：" << vacancy[0] << vacancy[1] << vacancy[2] << vacancy[3] <<endl;
		
		do{
			cin >> newPoint;//玩家輸入提示 
			if(point[5] != 0 || point[1] != 'A' &&point[1] != 'a' || point[3] != 'B' && point[3] != 'b' || (int)point[0]-48 + (int)point[2]-48 > 4){ 
			cout << "請勿輸入規範外格式，請重新輸入xAyB。" << endl; //玩家輸入錯誤資訊時不進行下一步驟 
			}
		}while(point[5] != 0 || point[1] != 'A' &&point[1] != 'a' || point[3] != 'B' && point[3] != 'b' || (int)point[0]-48 + (int)point[2]-48 > 4);
	
	
	
//-------------------------------------------------------------------------------判斷區 
		
			
		if(newPoint[0] < point[0]){//A變少，新的錯，原本的為A 
			guess[vacancy[changeLocat-1]].Mistake = true;//新物件為錯誤 
			vacancy[changeLocat-1] = oldClass;
			guess[oldClass-1].nowGuess = true;
			guess[oldClass-1].nowLocation = changeLocat; 
			guess[oldClass-1].location = changeLocat;
			guess[oldClass-1].correct = true;
		} else if(newPoint[0] == point[0]){//A不變，分為B變多、變少或不變
			if(newPoint[2] > point[2]){
				guess[oldClass-1].Mistake = true;//舊物件為錯誤 
				point[2] = newPoint[2];//儲存新的提示 
			} else if(newPoint[2] == point[2]){
				vacancy[changeLocat-1] = oldClass;//還原變更 
				guess[oldClass-1].nowGuess = true;
				guess[oldClass-1].nowLocation = changeLocat; 
			} else if(newPoint[2] < point[2]){
				guess[vacancy[changeLocat-1]-1].Mistake = true;//新物件為錯誤 
				vacancy[changeLocat-1] = oldClass;//還原變更
				guess[oldClass-1].nowGuess = true;
				guess[oldClass-1].nowLocation = changeLocat; 
			}
		} else if(newPoint[0] > point[0]){ //A變多，新的為正解，分為B變少與不變 
			if(newPoint[2] < point[2]){
				guess[oldClass-1].correct = true;
				guess[k].location = changeLocat;
				guess[k].correct = true; 
				point[0] = newPoint[0];//儲存新的提示 
				point[2] = newPoint[2];
			} else if(newPoint[2] == point[2]){
				guess[k].location = changeLocat;
				guess[k].correct = true; 
				point[0] = newPoint[0];//儲存新的提示 
			}
		}
		if((int)newPoint[0]-48 + (int)newPoint[2]-48 == 4){ 
			chooseLoacat();
			break;
		}
	}
	while(point[0] != '4'){
		chooseLoacat();
		cin >> newPoint;
	} 
	
	
}



//----------------------------------------------------------入口函式 

int main(){
	cout<<"1093203"<<endl;
	cout<<"劉至恩"<<endl;
	//-----------------------
	cout<<"demo"<<endl;
	
	
	cout << "請先決定好四位數，並輸入任意字元開始猜題" <<endl;
	cin >> point; 
	srand((unsigned) time(NULL));//亂數種子 
	
	for(int i = 0 ; i<9 ; i++){//輸入物件value 
		guess[i].value = i+1;
	}
	
	randomAll();
	cout << "我猜：" << vacancy[0] << vacancy[1] << vacancy[2] << vacancy[3] <<endl;
	
	
	do{
		cin >> point;//玩家輸入提示 
		if(point[5] != 0 || point[1] != 'A' &&point[1] != 'a' || point[3] != 'B' && point[3] != 'b' || (int)point[0]-48 + (int)point[2]-48 > 4){ 
			cout << "請勿輸入規範外格式，請重新輸入xAyB。" << endl; //玩家輸入錯誤資訊時不進行下一步驟 
		}
	}while(point[5] != 0 || point[1] != 'A' &&point[1] != 'a' || point[3] != 'B' && point[3] != 'b' || (int)point[0]-48 + (int)point[2]-48 > 4);
	
	
	
	if(point[0]== '0'&& point[2] == '0' ){//全錯 
		for(int i = 0 ; i<9 ; i++){
			if(guess[i].nowGuess == true){
				guess[i].nowGuess = false;
				guess[i].Mistake = true;
			}
		}
		randomAll();
		finedA();
	}else if( ((int)point[0]-48 + (int)point[2]-48) == 4){//交換順序
 		chooseLoacat();
		
	} else if(point[0] == '0'){
		if((int)point[2]-48 <=2){//如為0a2b或以下，同樣全部重置  
			randomAll();
			finedA();
		} else {
			finedA();
		}
	} else if(point[0] == '1'){
		finedA();
	} else if(point[0] == '2'){
		finedA();
	} else if(point[0] == '3'){
		finedA();
	} else if(point[0] == '4'){
		cout << "我猜對了" << endl ;
	}

	return 1;
}
