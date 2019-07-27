#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include <unistd.h>
#include<vector>

using namespace std; 

const int grid_size= 30; 
int update(int cgrid[grid_size + 1][grid_size + 1], int , int ) ;
int main(){
	// initial variables for the game and the board 
	int x, y, iters; 
	string fileName, int_x, int_y, curr; 
	int grid[grid_size+1][grid_size+1]={}; // grid 

	cout<< "The Game of life" <<endl; 
	cout <<endl; 
	//get the input text file from the user 
	while(1){
		cout<<"Input the file "<<endl; 
		cin>>fileName; 
		ifstream read_file(fileName); 
		if (read_file.is_open()){
			while(getline(read_file, curr)){
				stringstream read(curr);
				getline(read,int_x,',');
				getline(read,int_y,',');
				//convert the string values to int
				x =stoi(int_x); 
				y= stoi(int_y); 
				grid[x][y]=1; 
			}
			break; 
		}
			else{
				cout<<"File name is either incorrect or non existent"<<endl; 
			}
		}
	}
	while (1){
		cout << endl;
		for (int i = 0; i < grid_size; i++) {
        		for (int j = 0; j < grid_size; j++) {
          			if (grid[i][j] == 0) {
            		    		cout << " * ";
          	  		} else if (board[i][j] == 1) {
                			cout << " O ";
        	    		}
	            		if (j == grid_size-1) {
                			cout << endl;
            			}
			}
		int cgrid[size + 1][size + 1] = {};
		std::copy(&grid[0][0], &grid[0][0] + grid_size*grid_size, &cgrid[0][0]);
		for(int i = 0; i < grid_size; i++) {
			for(int j = 0; j < grid_size; j++) {
				int alive = getAlive(cBoard, i, j);
				// rules of game of life 
				// cell with less than 2 neighbours dies
				if(alive < 2) {
					grid[i][j] = 0;
				}
				// cell with 2 or 3 neighbours lives on to the next gen  
				else if(alive == 3) {
					grid[i][j] = 1;
				} 
                // cell with more than 3 neighbours die (overpopulation)
				else if(alive > 3) {
					grid[i][j] = 0;
				}
			}
		}
		usleep(600000);
	}
		}	
	}
}

int update(int cgrid[grid_size + 1][grid_size + 1], int x, int y) {
	int up= 0;
	for(int i = -1; i < 2; i++) {
		for(int j = -1; j < 2; j++) {
			if(!(i == 0 && j == 0) && cgrid[x+i][y+j] == 1) {
					up++;
			}
		}
	}
	return up;
}
