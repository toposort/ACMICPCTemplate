struct node
{
    int u��
    int v;
    double w;
}edge[maxn * maxn];
int pre[maxn], id[maxn], vis[maxn];
int n, m;
double in[maxn];
double dirmst(int root, int V, int E)
{
    double ret = 0;
    while(true){
        for(int i = 0; i < V; i++){
            in[i] = oo;
        }
//����С���
        for(int i = 0; i < E; i++){
            int u = edge[i].u;
            int v = edge[i].v;
            if(edge[i].w < in[v] && u != v){
                pre[v] = u;
                in[v] = edge[i].w;
            }
        }
        for(int i = 0; i < V; i++){
            if(i == root) continue;
////���˸������е�û�����,����޷�������
            if(in[i] == oo) return -1;
        }
        int cnt = 0;
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        in[root] = 0;
//�һ�
        for(int i = 0; i < V; i++)
        {
//���ÿ����
            ret += in[i];
            int v = i;
            while(vis[v] != i && id[v] == -1 && v != root){
//ÿ����Ѱ����ǰ��㣬Ҫô����Ѱ����������Ҫô�ҵ�һ����
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && id[v] == -1){//����
                for(int u = pre[v]; u != v; u = pre[u]){
                    id[u] = cnt;
                }
                id[v] = cnt++;
            }
        }
        if(cnt == 0) break;//�޻�
        for(int i = 0; i < V; i++){
            if(id[i] == -1) id[i] = cnt++;
        }
//������ͼ
        for(int i = 0; i < E; i++){
            int u = edge[i].u;
            int v = edge[i].v;
            edge[i].u = id[u];
            edge[i].v = id[v];
            if(id[u] != id[v]) edge[i].w -= in[v];
        }
        V = cnt;
        root = id[root];
    }
    return ret;
}
