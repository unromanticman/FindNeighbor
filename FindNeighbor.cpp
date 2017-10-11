#include <iostream>
#include <algorithm>
#include <deque>
#include <iomanip>
using namespace std;


//記錄點的類別
class Pos{
public:
	int x,y;
	Pos(int x,int y){
		this->x = x;
		this->y = y;
	}
};

//鄰居類別
class Neighbor{

private:
	deque<Pos> depthNeighbor;
	int max_X;//x邊界
	int max_Y;//y邊界
public:
	Neighbor(int max_x,int max_y){
		//設定邊界
		this->max_X = max_x;
		this->max_Y = max_y;
	}
	void travel(int x,int y,int ** map,int depth){

		if(depth == 0){
			deque<Pos> neighbor;
			for(int i=0;i<max_X;i++){
				for(int j=0;j<max_Y;j++){
					//判斷是否可以放置
					if(map[i][j] == 0){
						//判斷是否距離為1
						if(
							(i == x-1 && j== y) ||
							(i == x+1 && j== y) ||
							(i == x && j== y+1) ||
							(i == x && j== y-1) ||
							(i == x-1 && j== y-1) ||
							(i == x+1 && j== y+1) ||
							(i == x+1 && j== y-1) ||
							(i == x-1 && j== y+1)
						){	
							map[i][j] = 1;
							Pos pos(i,j);
							neighbor.push_back(pos);
						}
					}
				}
			}
			//將每次遞迴走到底的節點存進 depthNeighbor 陣列內
			depthNeighbor.insert (depthNeighbor.begin(),neighbor.begin(),neighbor.end());
			
		}else{
			deque<Pos> neighbor;
			for(int i=0;i<max_X;i++){
				for(int j=0;j<max_Y;j++){
					//判斷是否可以放置
					if(map[i][j] == 0){
						//判斷是否距離為1
						if(
							(i == x-1 && j== y) ||
							(i == x+1 && j== y) ||
							(i == x && j== y+1) ||
							(i == x && j== y-1) ||
							(i == x-1 && j== y-1) ||
							(i == x+1 && j== y+1) ||
							(i == x+1 && j== y-1) ||
							(i == x-1 && j== y+1) 
						){
							//新增節點
							map[i][j] = 1;
							Pos pos(i,j);
							neighbor.push_back(pos);
						}
					}
				}
			}
			//遍歷下個節點進行遞回
			for (std::deque<Pos>::iterator it = neighbor.begin(); it!=neighbor.end(); ++it){
				 Pos pos = *it;
				 travel(pos.x,pos.y,map,depth - 1);
			}
			
		}

	}

	//取得所有深度節點
	deque<Pos> findNeighborPos(int x,int y,int ** map,int depth){
		deque<Pos> result;
		for(int i=1;i<=depth;i++){
			deque<Pos> temp = findDepthPos(x,y,map,i);
			result.insert (result.begin(),temp.begin(),temp.end());
		}
		return result;
	}

	//取得每個深度的節點
	deque<Pos> findDepthPos(int x,int y,int ** map,int depth){
		//複製陣列防止參考
		int ** temp = new int*[max_X];;
		for(int i=0;i<max_X;i++){
			temp[i] = new int[max_Y];
			for(int j=0;j<max_Y;j++){
				temp[i][j] = map[i][j];
			}
		}
		//清空depthNeighbor
		depthNeighbor.clear(); 
		//如果為0則代表0層 所以直接回傳 主要修正傳入depth參數
		if(depth == 0){
			return depthNeighbor;
		}else{
			travel(x,y,temp,depth-1);
			return depthNeighbor;
		}
	}

};





int main(){
	
	//地圖X軸
	const int MAP_SIZE_X = 15;
	//地圖Y軸
	const int MAP_SIZE_Y = 15;

	//建立一個 15*15 地圖 
	int ** map = new int*[MAP_SIZE_X];
	
	//初始化每個點的值為0
	for(int i=0;i<MAP_SIZE_X;i++){
		map[i] = new int[MAP_SIZE_Y];
		for(int j=0;j<MAP_SIZE_Y;j++){
			map[i][j] = 0;
		}
	}

	//玩家位置
	int player_X = 10;
	int player_Y = 10;

	//設置玩家於地圖上
	map[player_X][player_Y] = 2;

	//建立搜尋器 並初始化陣列邊界
	Neighbor neighbor(MAP_SIZE_X,MAP_SIZE_Y); 
	
	//取得距離玩家2的所有座標點
	deque<Pos> pos = neighbor.findNeighborPos(player_X,player_Y,map,3);


	//印出所有點可行的點，並將點設定於地圖上
	int count = 0;
	for (std::deque<Pos>::iterator it = pos.begin(); it!=pos.end(); ++it){
		 Pos p = *it;
		 cout<<'('<<setw(2)<<p.x<<','<<setw(2)<<p.y<<')'<<' ';
		 map[p.x][p.y] = 1;
		 if(++count % 5 == 0){
		 	cout<<'\n';
		 }
	}

	cout<<'\n';

	//印出地圖
	for(int i=0;i<MAP_SIZE_X;i++){
		for(int j=0;j<MAP_SIZE_Y;j++){
			cout<< map[i][j] <<' ';
		}
		cout<<'\n';
	}


	cout<<'\n';
}