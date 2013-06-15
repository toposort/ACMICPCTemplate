
//Shortest path faster Algorithm

/************************************
对于Bellman ford 算法的一个浅显的改进，
利用队列保存待更新的节点。作为一个迭代算法，
同时可以用于求解方程的近似解，
或者阶段性不明显的最优化问题。
时间复杂度O(ke) k是一个比较小的常数
*************************************/

const int oo = 1<<30;
const int maxn = 2011;
const int maxm = 50011<<1;
int n, m;
int cnt;
int dis[maxn], head[maxn];
bool vis[maxn];

struct node{
    int u;
    int v;
    int w;
    int next;
}edge[maxm];

void init(){
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void add(int u, int v, int w){
    edge[cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].u = v;
    edge[cnt].v = u;
    edge[cnt].w = w;
    edge[cnt].next = head[v];
    head[v] = cnt++;
}

void spfa(int s){
    queue<int>qu;
    for(int i = 0; i < n; i++){
        dis[i] = oo;
        vis[i] = false;
    }
    dis[s] = 0;
    vis[s] = true;
    qu.push(s);
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        vis[u] = false;
        for(int i = head[u]; i != -1; i = edge[i].next){
            int v = edge[i].v;
            if(dis[u]+edge[i].w < dis[v]){
                dis[v] = dis[u]+edge[i].w;
                if(!vis[v]){
                    vis[v] = true;
                    qu.push(v);
                }
            }
        }
    }
}

//SLF优化后的spfa

/************************************
spfa在加上SLF优化后不能用
某个点的入队列次数>点数来判负环
************************************/

void spfa(int s){
    deque<int>qu;
    for(int i = 0; i < n; i++){
        dis[i] = oo;
        vis[i] = false;
    }
    dis[s] = 0;
    vis[s] = true;
    qu.push_back(s);
    while(!qu.empty()){
        int u = qu.front();
        qu.pop_front();
        vis[u] = false;
        for(int i = head[u]; i != -1; i = edge[i].next){
            int v = edge[i].v;
            if(max(dis[u],edge[i].w) < dis[v]){
                dis[v] = max(dis[u], edge[i].w);
                if(!vis[v]){
                    vis[v] = true;
                    if(!qu.empty()){
                        if(dis[v] > dis[qu.front()]) qu.push_back(v);
                        else qu.push_front(v);
                    }
                    else qu.push_back(v);
                }
            }
        }
    }
}
