#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int,list<pair<int,int>>>adj;

    void edge(int u,int v,int wt,int dir){
        if(dir==1){
            adj[u].push_back({v,wt});
        }
        else{
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<":"<<"{";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<"),";
            }
            cout<<"}"<<endl;
        }
    }

void dijkstraShortestDistance(int n,int src,int des){
        vector<int>dist(n+1,INT_MAX);
        set<pair<int,int>>st;

        dist[src]=0;
        st.insert({0,src});

        while(!st.empty()){
            auto topNodeRef=st.begin();
            st.erase(st.begin());

            auto topPair=*topNodeRef;
            int currDist=topPair.first;
            int currNode=topPair.second;

            for(auto it:adj[currNode]){
                int childNode=it.first;
                int TochildDist=it.second;

                if(currDist+TochildDist<dist[childNode]){
                    auto prev=st.find({dist[childNode],childNode});
                    if(prev!=st.end()){
                        st.erase(prev);
                    }

                    st.insert({currDist+TochildDist,childNode});
                    dist[childNode]=currDist+TochildDist;
                }
            }
        }


        cout<<"Shortest Distance Between "<<src<<" And "<<des<<" : "<<dist[des]<<endl;
    }
};
// void dijkstraShortestDistance(int n, int src, int dest) {
	// 	vector<int> dist(n+1, INT_MAX);
	// 	set<pair<int,int> > st;

	// 	//INTIAL STATE -> (0,src)
	// 	st.insert({0,src});
	// 	dist[src] = 0;

	// 	//distance updation logic 
	// 	while(!st.empty()) {
	// 		auto topElement = st.begin();
	// 		pair<int, int> topPair = *topElement;
	// 		int topDist = topPair.first;
	// 		int topNode = topPair.second;
	// 		//remove the topNode
	// 		st.erase(st.begin());

	// 		//update distance of nbr
	// 		for(pair<int,int> nbrPair: adj[topNode]) {
	// 			int nbrNode = nbrPair.first;
	// 			int nbrDist = nbrPair.second;
	// 			if(topDist + nbrDist < dist[nbrNode]) {
	// 				//found a new shorter distnace
	// 				//now update: 
					
	// 				// -> set ki entry
	// 				//find previousEntry and delete it
	// 				auto previousEntry = st.find({dist[nbrNode], nbrNode});
	// 				if(previousEntry != st.end()) {
	// 					// entry present in set
	// 					st.erase(previousEntry);
	// 				}
	// 				// -> dist ka array
	// 				dist[nbrNode] = topDist + nbrDist;
	// 				//create a new entry in the set for new distance
	// 				st.insert({dist[nbrNode], nbrNode});
	// 			}
	// 		}
	// 	}
	// 	cout << "Shortest Distance from " << src << " Node to " << dest << " Node: " << dist[dest] << endl;


	// }

//};

int main(){
    graph g;
    // g.edge(0,1,5,1);
    // g.edge(0,2,2,1);
    // g.edge(2,1,2,1);
    // g.edge(1,3,3,1);
    // g.edge(2,4,11,1);
    // g.edge(4,3,14,1);
    //  g.edge(1,4,5,1);

    // int n=5;

    // g.print();
    // stack<int>st;
    // unordered_map<int,bool>visited;

    // g.toposortDfs(0,st,visited);

    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    // g.shortestPathDfs(st,n);
    g.edge(1,6,14,0);
	g.edge(1,3,9,0);
	g.edge(1,2,7,0);
	g.edge(2,3,10,0);
	g.edge(2,4,15,0);
	g.edge(3,4,11,0);
	g.edge(6,3,2,0);
	g.edge(6,5,9,0);
	g.edge(5,4,6,0);

    int n = 6;
	int src = 6;
	int dest = 6;
	g.dijkstraShortestDistance(n, src, dest);

}