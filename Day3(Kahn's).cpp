/*
Link :- https://www.youtube.com/watch?v=7CTpoVNIc8o&t=26s&ab_channel=CodeNCode

Topological Sort :-

dependency is main priority..
if 1 --> 2 --> 3 graph is there, then to access 3 we must have 2 and before we have 2 we must have 1(visited)
So topological sort gives an order for a vertex.
like..
to visit 3 we must have 1,2 so.. topological sort will provide us that
https://ibb.co/QNFJwn1
Here, we can see that in topological sort.. every vertexes dependency comes before it in sorted order..
so if Topological order is like..

1,2,6,3,4,8,7,9 and we represent nodes in this order and connect them with former edges then all of the edges will go from left to right and so we can conclude that topological sort is correct.
If not then it's invaid sorting.
https://ibb.co/jTsDr99

Kahn's Algorithm :- O(V+E)
Indegree - Number of dependency or number of edges that are coming to that node.
Topsorting can be distinguished

So the intuition behind it is.. we will traverse and look for nodes whos indegree == 0 and remove that node and corresponding edges from graph.. and add that node to topological sort.. So it can be implemented through BFS.

Template : -
*/
vector<ll> a[1002]
vector<ll> ans;
ll indeg[1002];
void BFS(){
  queue<ll> q;
  for (int i=1;i<=n;i++){
	if (indeg[i] == 0){
	    q.push(i);
	}
  }
while(!q.empty()){
  ll curr = q.front();
  ans.push_back(curr); // Every element in this queue will be having indegree 1 so it will be pushed back, only thing matter is ordering
  q.pop();
  for (auto x: a[curr]){
	indeg[x]--;  // Node is deleting with corresponding edges, so indegree of all it's dependecy decreases.
        if (indeg[x] == 0)	q.push(x);
   }
}
}
int main(){
for (int i=1;i<=n;i++){
	int x,y;
	cin>>x>>y;
	a[x].push_back(y);
	indeg[y]++;   // because x -> y so y is dependent on x.
}
}
/*
(size of topological sort != number of nodes) --> Directed Graph contains Cyclic

 Priority Queue:-

priority_queue<int> q --> Max Heap(Top element in queue will be maximum)
priority_queue<int, vector<int>, greater<int> >q --> Min Heap(Top element in queue will be minimum)
q.front -> q.top() for priority queue.

Link - https://www.spoj.com/problems/TOPOSORT/
Sol - https://ideone.com/p4KNFN



Problems:-


Link - https://codeforces.com/problemset/problem/445/A
Sol - https://ideone.com/qGaQXp

Link - https://codeforces.com/problemset/problem/902/B
Sol - https://ideone.com/JXdRwz

Link - https://codeforces.com/contest/902/problem/A
Sol - https://ideone.com/PN9zzc

Link - https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/rhezo-and-hackerearth-3/
Sol - https://ideone.com/xMXA5L
*/
Thank You :)
