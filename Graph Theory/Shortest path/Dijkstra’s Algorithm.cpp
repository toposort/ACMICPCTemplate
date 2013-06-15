
//优先队列优化的Dijkstra

/************************************
适用于正权图，由于每次更新距离标号单调不减，
故最小标号不再更新。
时间复杂度O(V^2 + E) 或 O((V+E)logV)。
*************************************/

const int maxn = 101;
const int maxm = 1001;
int cnt;
int head[maxn];
int dist[maxn];
struct edges{
	int to;
	int next;
	int cost;
}edge[maxm];
class states{
public:
	int cost;
	int id;
};
class cmp{
public:
	bool operator ()(const states &i, const states &j){
		return i.cost > j.cost;
	}
};

void init(int n){
	cnt = 0;
	for(int i = 0; i < n; i++){
	    head[i] = -1;
	}
}

void addedge(int x, int y, int cost){
	edge[cnt].to = y;
	edge[cnt].cost = cost;
	edge[cnt].next = head[x];
	head[x] = cnt++;
}

int dijkstra(int s, int t){
	memset(dist, 63, sizeof(dist));
	states u;
	u.id = s;
	u.cost = 0;
	dist[s] = 0;
	priority_queue<states, vector<states>, cmp> q;
	q.push(u);
	while(!q.empty()){
		u = q.top();
		q.pop();
		if(u.id == t) return dist[t];
		if(u.cost != dist[u.id]) continue;
		for(int i = head[u.id]; i != -1; i = edge[i].next){
			states v = u;
			v.id = edge[i].to;
			if(dist[v.id] > dist[u.id]+edge[i].cost){
				v.cost = dist[v.id] = dist[u.id]+edge[i].cost;
				q.push(v);
			}
		}
	}
	return -1;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	init(n);
	for(int i = 0; i < m; i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		addedge(x, y, z);
		addedge(y, x, z);
	}
	int s, t;
	scanf("%d%d", &s, &t);
	printf("%d\n", dijkstra(s, t));
	return 0;
}
