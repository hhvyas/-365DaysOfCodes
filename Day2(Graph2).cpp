/* Today I learnt about Bridges and Articulation point from https://www.youtube.com/watch?v=ECKTyseo2H8&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=23&ab_channel=CodeNCode
   CodeNCode Youtube channel, And solved couple of problems, count of which will grow eventually.

- If in DFS calling for a node, all of it's child nodes are visited then it's (not visited Edges) or Back-edges.
- And whichever edges are traversed during the DFS call, it will be forward edge or Tree edge.
https://ibb.co/bQ8fFKd is Example of it
- If any of the back-edges added to the tree, it will be graph.Will Contain Cycle.
- Every Back-edge connects descendant to one of it's parents ancestor.. because his parent will be the one with forward edge.
- So, Back-edges can't be bridges (Because there is always a path that exist (Grandfather - Grandson)

Low array is an array which stores min(low[node], intime[ancestor])
If we have a cycle like..
	1
         \
	  2
       /     \
      3 ----- 4	
then, (1-2) will be forward
      (2-3) will be forward
      (3-4) will be forward
but if we make dfs call to 4 (dfs(4)) then all of it's child nodes are visited and it's parent too, so we can conclude that 2-4 (as 3 is it's parent) will be a back-edge so for every back-edge we will calculate 
low-time which suggest the lowest ancestor of (parent) which connects that node(here 4).
like .. low[node] = min(low[node], intime[child(which isn't parent)]);
here child is refere to travarsal to that node(4) which is not its parent.
Why to take minimum ?
Ans --> If we will traverse back to 2 here.. then as all of its childs are visited so, it will assign low[2] = low[4] because 4 is child which isn;t parent of 2 and it has back-edge.

Now What if it's Forward edge..
if it's forward then we will traverse all the edges .. then when the program is traversing back to the actual (first call of DFS) if it's forward edge then we will check..

if (low[4] <= intime[2]) --> It's not a bridge. because there exist a path .. here low[4] = 2 so from 2-4 is possible 
So. if it's not a bridge.. the other end node's low time can be assigned to this one too .
Inshort.. If two point's path isn't bridge then low time of both the points will be equal and minimum among those two..
So if its forward edge then, while traversing back to original call of dfs..,
low[child] = min(low[child], low[node]);

So.. If(low[child] > intime[node]) --> It will be bridge.
- Edge which when removed number of connected components increases


*** Bridges::->
Template:-
ll vis[1002],low[1002],intime[1002];
vector<ll>a[1003];
ll timer;
void dfs(ll node,ll parent){
    vis[node]=1;
    intime[node]=timer;
    low[node] = timer;
    timer++;
    for (auto child:a[node]){
        if (child==parent)  continue;

        // Back- Edge

        if (vis[child] == 1){

            // Minimise low array for that given node

            low[node] = min (low[node] , intime[child]);
            // Child is visited and its already traversed that means it will be ancestor
        }
        else{
            // Forward Edge--

            dfs (child , node);
            low[node] = min(low[node] , low[child]);
            // Condition for Bridge -- Because Only forward edge can be Bridge

            if (low[child] > intime[node]){
                cout<<node<<" -- "<<child<<" is Bridge"<<endl;
            }
        }
    }
}
Problem: 
Link : https://codeforces.com/problemset/problem/118/E
Sol : https://ideone.com/sAj3wE
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Articulation Points:-
- An articulation point(Cut Vertex) is a vertex which  when removed makes graph disconnected or, number of Connected components grow.
- End points of bridges are articulation point */
- Only Non-leaf end points of bridges are articulation point. (Because then, the number of connected components are same).
- If Degree of nodes are 1 in bridge's end point then it can't be articulation point.
- It's not necessary for an articulation point to be end-point of a bridge.
- eg. if graph is like https://ibb.co/x6Q77Q7 then red node is articulation point because if we delete that node, number of connected components grows.
- So, Bridge theory doesn't work in articulation point.
- Let's say we are in the DFS, looking through the edges starting from vertex v≠root. If the current edge (v,to) is such that none of the vertices to or its descendants in the DFS traversal   tree has a back-edge to any of ancestors of v, then v is an articulation point. Otherwise, v is not an articulation point.

-Let's consider the remaining case of v=root
 This vertex will be the point of articulation if and only if this vertex has more than one child in the DFS tree.
- low is not assign to values of parents intime or lowtime at time of dfs'ing first time because only when backtracking we are using back-edges to connect child to ancestor of parent edge
*******************Time-Stamp - 09:00 https://www.youtube.com/watch?v=iGGolqb6gDE&t=241s&ab_channel=CodeNCode.*********************(IMP)
Now, it's low[child] >= intime[node] because if low(3) == low(4) == 2 so while backtracking, intime[2] will be 2 as well as lowtime of 3&4 are 2 so, from above graph we can say that it's an articulation point..
Now, we will not check any point's low time(update) with root node, because root node's ancestor won't be there.. so while checking if (low[child] >= intime[node] && p!=-1) is necessary.
now if root has only one subtree(Many back-edges are alowed, if its cyclic) so if (p==-1 and children>1) --> root will be articulation point
*/

(it's not articulation point if its one node is leaf node)
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]); // low[v] is while backtracking. 
            if (low[to] >= tin[v] && p!=-1)
                IS_CUTPOINT(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        IS_CUTPOINT(v);
}
https://ideone.com/9HDrzS
https://www.spoj.com/problems/SUBMERGE/

