bool isSafe(int newx, int newy , vector < vector < int >> & arr, vector<vector<bool>> &vis, int n){
    if((newx>=0 && newx<n ) && (newy>=0 && newy<n) && vis[newx][newy]!=1 && arr[newx][newy]==1  ){
        return true;// it should not be previously visited 
    }else{
        return false;
    }
    
    
}
void solve(int x, int y ,vector < vector < int >> & arr,vector<string>& ans, int n, string path,vector<vector<bool>> &vis   ){
    
    //base case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return ;
    }
    
    vis[x][y]=1;
    // Down 
    if(isSafe(x+1,y, arr, vis,n )){
        solve(x+1,y, arr, ans, n, path+'D', vis);
    }
    
    // Left
    if(isSafe(x,y-1, arr, vis,n )){
        solve(x,y-1, arr, ans, n, path+"L", vis);
    }
    
    //Right
    if(isSafe(x,y+1, arr, vis,n )){
        solve(x,y+1, arr, ans, n, path+"R", vis);
    }
    
    // UP
    if(isSafe(x-1,y, arr, vis,n )){
        solve(x-1,y, arr, ans, n, path+"U", vis);
    }
    
    vis[x][y]=0;
    
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n,0));
    string path=" ";
    solve(0,0,arr, ans,n, path, visited);
    
    return ans;
}
