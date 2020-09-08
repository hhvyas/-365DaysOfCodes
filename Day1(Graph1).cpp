int main(){
    ll n,m;
    cin>>n>>m;    
    while (m--){
        ll x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1);
    return 0;
}


// DFS  (Depth Order traversal)
ek baju ni depth
vector<ll>a[n+1];
ll vis[n]=0;

void dfs(ll s){
	vis[s]=1;
	for (auto child:a[s]){
	   if (vis[child]==0){
		dfs(a,vis,child);
		}
	}
}


//Connected components
for (int i=1;i<=n;i++){
  if (vis[i]==0){
	dfs(i);
	countx++;
    }
}	

// SSSP 
distance array --> 

void dfs(ll s,ll c){
	vis[s]=1;
	dis[s]=c;
	for (auto child:a[s]){
	   if (vis[child]==0){
		dfs(child,c+1); // at every step we increment the distance, only works in tree
	   }
	}
}
dfs(1,0) --> 0 is distance

// Bipartate graph -->  (2 coloring problem) - if a node is color 0 then all of its neighbour should be colored differetly, is also used to check id the graph is tree or graph(WITH ODD LENGTH CYCLE)
You can divide the vertex set into the two disjoint sets such that
1) Each vertex belongs to only one of the 2 sets
2) Each edge connects vertices of two different sets.

void dfs(ll s,ll p){
	vis[s]=1;
	color[s]=p;
	for (auto child:a[s]){
	   if (vis[child]==0){
		if (dfs(child,!p)==false){
			return false; // if in any case false is returned then the given a 
	      }
	    }else if (color[s]==color[child]) return false;// s and child will be neighbours of each other so it will basically check  if equal then it mus be a graph
	}
	return true;
}
}

// Cycle detection
void dfs(ll s,ll parent){
	vis[s]=1;
	for (auto child:a[s]){
	   if (vis[child]==0){
		if (dfs(child,s)==true){
			return true;
		}
	    }else if (child!=parent) return true;
	}
	return false;
}


// Intime Outtime 
ll timex=0;
void dfs(ll s){
	vis[s]=1;
	intime[s]=timex++;
	dis[s]=c;
	for (auto child:a[s]){
	   if (vis[child]==0){
		dfs(child);
	   }
	}
	outtime[s]=timex++;
}	


// Diameter of tree  --> Longest path from any node to another node


	dfs(1,a,vis,dist);
	dfs(doit,a,vis,dist);
	max distance; where doit is node with higest distance when source node is 1;
}
}

// BFS

void BFS(ll s){
    vis[s]=1;
    dis[s]=0;
    queue <ll>z;
    z.push(s);
    while (!z.empty()){
        ll curr=z.front();
        z.pop();
        for (auto child:a[curr]){
            if (vis[child]==0){
                z.push(child);
                vis[child]=1;
                dis[child]=dis[curr]+1;
            }
        }
    }
}

/*Problems: -
https://codeforces.com/contest/217/problem/A
https://ideone.com/eDSNPw

https://codeforces.com/contest/129/problem/B
https://ideone.com/5mwbVr



