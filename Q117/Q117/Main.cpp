#include <iostream>
using namespace std;
enum Result{
	OSUCC, XSUCC, DOGFALL, PLAYING
};
enum Chess{
	X, O, N
};
class Board{
public:
	int n, m;
	int count = 0;
	Chess* chessBoard;
	Chess lastChess = Chess::N;

	void initBoard(){
		cin >> n >> m;
		chessBoard = new Chess[n*n];
		for (int i = 0; i < n*n; i++){
			chessBoard[i] = Chess::N;
		}
	}

	Chess getChess(int i, int j){
		return chessBoard[i*n + j];
	}

	void setChess(int i, int j,Chess chess){
		chessBoard[i*n + j] = chess;
	}

	bool isFull(){
		return count == n*n;
	}

	Result play(){
		int x, y;
		cin >> x >> y;
		count++;
		if (lastChess == Chess::X || lastChess == Chess::N){
			lastChess = Chess::O;
		}
		else{
			lastChess = Chess::X;
		}
		setChess(x, y, lastChess);
		//print();
		return judge();
	}
	void print(){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cout << getChess(i, j);
			}
			cout << endl;
		}
	}
	Result judge(){

		//ÅÐ¶ÏÁÐ
		for (int i = 0; i <= n - m; i++){
			for (int j = 0; j < n; j++){
				Chess chessNow = getChess(i, j);
				if (chessNow == Chess::N)
					continue;
				bool isSame = true;
				for (int k = i + 1; k < i + m; k++){
					if (getChess(k, j) != chessNow){
						isSame = false;
						break;
					}
				}
				if (isSame){
					return chessNow == Chess::O ? Result::OSUCC : Result::XSUCC;
				}
			}
		}
		//ÅÐ¶ÏÐÐ
		for (int i = 0; i < n; i++){
			for (int j = 0; j <= n - m; j++){
				Chess chessNow = getChess(i, j);
				if (chessNow == Chess::N)
					continue;
				bool isSame = true;
				for (int k = j + 1; k < j + m; k++){
					if (getChess(i, k) != chessNow){
						isSame = false;
						break;
					}
				}
				if (isSame){
					return chessNow == Chess::O ? Result::OSUCC : Result::XSUCC;
				}
			}
		}
		//ÅÐ¶ÏË³¶Ô½Ç
		for (int i = 0; i <= n - m; i++){
			for (int j = 0; j <= n - m; j++){
				Chess chessNow = getChess(i, j);
				if (chessNow == Chess::N)
					continue;
				bool isSame = true;
				for (int k = 1; k < m; k++){
					if (getChess(i+k, j+k) != chessNow){
						isSame = false;
						break;
					}
				}
				if (isSame){
					return chessNow == Chess::O ? Result::OSUCC : Result::XSUCC;
				}
			}
		}

		//ÅÐ¶ÏÄæ¶Ô½Ç
		for (int i = 0; i <= n - m; i++){
			for (int j = 0; j <= n - m; j++){
				Chess chessNow = getChess(n - i,j);
				if (chessNow == Chess::N)
					continue;
				bool isSame = true;
				for (int k = 1; k < m; k++){
					if (getChess(n - (i+k),n - (j+k)) != chessNow){
						isSame = false;
						break;
					}
				}
				if (isSame){
					return chessNow == Chess::O ? Result::OSUCC : Result::XSUCC;
				}
			}
		}

		if (isFull())
			return Result::DOGFALL;
		else
			return Result::PLAYING;
	}
};
int main(){
	Board board;
	board.initBoard();

	Result result = Result::PLAYING;
	while (result == Result::PLAYING){
		result = board.play();
	}
	if (result == Result::DOGFALL){
		cout << "Dogfall";
	}
	else if (result == Result::OSUCC){
		cout << "O Success";
	}
	else{
		cout << "X Success";
	}

}