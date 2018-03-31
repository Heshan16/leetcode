class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty())
            return;
        vector<vector<int>> boardcp(board.size()+2,vector<int>(board[0].size()+2));
        int rows=board.size(),cols=board[0].size();
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++){
                if(boar[i][j]==1){
                    ++cpboard[i][j];
					++cpboard[i][j+1];
					++cpboard[i][j+2];
					++cpboard[i+1][j];
					++cpboard[i+1][j+2];
					++cpboard[i+2][j];
					++cpboard[i+2][j+1];
					++cpboard[i+2][j+2];
            	}
			
			}
		for(int i=0;i<rows;i++)
			for(int j=0;j<cos;j++) {
				if((cpboard[i][j]==3) || (board[i][j] && cpboard[i][j]==2))
					board[i][j]=1;
				else
					board[i][j]=0;
			}
    }
};
