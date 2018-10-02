#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class dijkstra{
	int m,n,q;
	vector<vector<pair<int, int> > > gph;
	vector<int> qry;

	public : 
		struct myComp{
			bool operator()(pair<int, int>& a, pair<int,int>& b){
				return a.second > b.second; 
			}
		};

		dijkstra(){
			int _n,_m,_q;
			cin>>_n>>_m>>_q;
			vector<vector<pair<int, int> > > graph(_n, vector<pair<int, int> >());
			
			for(int i=0;i<_m;i++){
				int a,b,w;
				cin>>a>>b>>w;
				graph[a].push_back(make_pair(b,w));
				graph[b].push_back(make_pair(a,w));
			}

			vector<int> queries;
			for(int i=0;i<_q;i++){
				int node;
				cin>>node;
				queries.push_back(node);
			}
			this->m = _m;
			this->n = _n;
			this->q= _q;
			this->gph = graph;
			this->qry = queries;
		}

		pair<int, int> s_dis(int start_node){
			priority_queue<pair<int,int>, vector<pair<int, int> >, myComp> pq;
			vector<int> dis(this->n, 1e9);
			vector<bool> vis(this->n, false);

			dis[start_node]=0;
			
			pq.push(make_pair(start_node, 0));
			
			while(!pq.empty()){
				pair<int, int> _top = pq.top();
				pq.pop();

				if(vis[_top.first])
					continue;

				vis[_top.first] = true;
				
				for(auto node : this->gph[_top.first]){
					if(dis[node.first] > dis[_top.first] + node.second){
						dis[node.first] = dis[_top.first] + node.second;
						pq.push(make_pair(node.first, dis[node.first]));	
					}
					
				}
			}
			int max_ele = -1, cnt=0;
			for(int i=0;i<this->n;i++){
				if(dis[i]==1e9)
					continue;
				if(dis[i]>max_ele){
					cnt = 1;
					max_ele = dis[i];
				}
				else if(dis[i]==max_ele)
					cnt++;
			}
			return make_pair(max_ele, cnt);
		};

		void print_results(){
			for(int i=0;i<this->q;i++){
				pair<int, int> res = s_dis(qry[i]);
				cout<<res.first<<" "<<res.second<<endl;
			}
		}
};

int main()
{
	ios_base:: sync_with_stdio(false); cin.tie(0);
	dijkstra testcase;
	testcase.print_results();
	return 0;
}