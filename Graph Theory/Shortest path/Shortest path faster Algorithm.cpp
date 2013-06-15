
//Shortest path faster Algorithm

/************************************
����Bellman ford �㷨��һ��ǳ�ԵĸĽ���
���ö��б�������µĽڵ㡣��Ϊһ�������㷨��
ͬʱ����������ⷽ�̵Ľ��ƽ⣬
���߽׶��Բ����Ե����Ż����⡣
ʱ�临�Ӷ�O(ke) k��һ���Ƚ�С�ĳ���
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

//SLF�Ż����spfa

/************************************
spfa�ڼ���SLF�Ż�������
ĳ���������д���>�������и���
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
