//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
   int Dfs(int n, vector<vector<int>> &adjNode, vector<bool>&visited, int &ans){
       visited[n] = true;
       int totalNode = 0;
       for(int node : adjNode[n]){
           if(!visited[node]){
               int take = Dfs(node, adjNode, visited, ans);
               if(take % 2 == 0) ans++;
               else totalNode += take;
           }
       }
       return totalNode + 1;
   }
   int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    // Code here
	    //if(n % 2 == 1) return 0;
	    vector<bool>visited(n + 2, false);
	    vector<vector<int>> adjNode(n + 1);
	    for(int i = 0; i<edges.size(); i++){
	        int u = edges[i][0];
	        int v = edges[i][1];
	        adjNode[u].push_back(v);
	        adjNode[v].push_back(u);
	    }
	    int ans = 0;
	    Dfs(1, adjNode, visited, ans);
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends