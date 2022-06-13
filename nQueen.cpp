void addSolution(vector<vector<int>> &ans,vector<vector<int>> &board, int n){
    vector<int> v;
    for(int i=0 ;i<n;i++){
        for(int j=0 ;j<n;j++){
            v.push_back(board[i][j]);
        }
        
    }
    ans.push_back(v);
    
}

bool isSafe(int row, int col, vector<vector<int>> &board,int n){
    // row wala part same reh rha h and col wala part is decremnting 
    
    // checking for same row
    
    int x=row;
    int y=col;
    while(y>=0){
        if(board[x][y]==1){
            return false;
        }
        y--;
    }
    
    // NO NEED TO CHECK FOR COLOM
    // BCOZ HUM HAR BAAR , HAR EK COLM PAR EK QUEEN PLACE KRTE H , OR USKE BAAD HI AAGE BADHTE HAI
    
    // Lets check for diagonal
    
    x=row;
    y=col;
    
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
        
    }
    
    x=row;
    y=col;
    
    while(x<n && y>=0){
        if(board[x][y]==1){
            return false;
        }
        
        y--;
        x++;
    }
    
    return true;
    
}
void solve(int col,vector<vector<int>> &board, vector<vector<int>> &ans ,int n ){
    // base case
    if(col==n){
        addSolution(ans, board,n );
        return;
    }
    
    
    // solve 1 case and recursion will handle our other cases
    //  for first column we need to go to all the rows 
    for(int row=0 ;row<n ; row++){
        if(isSafe(row,col, board,n)){
            // if placing queen is safe 
            board[row][col]=1;
            solve (col+1, board,ans ,n);
            
            // backtracking 
            board[row][col]=0;
       }
    }
    
    
}
vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n, vector<int>(n,0));
    vector<vector<int>> ans;
    
    solve(0,board,ans,n);
    return ans;
}
