void rmq_init(){
    for(int j = 1; (1<<j) <= n; j++){
        for(int i = 1; i+(1<<j)-1 <= n; i++){
            dmin[i][j] = std::min(dmin[i][j-1], dmin[i+(1<<(j-1))][j-1]);
        }
    }
}

int rmq(int l, int r){
    int k = (int)(log((double)(r-l+1))/log(2.0));
    int mmin = std::min(dmin[l][k], dmin[r-(1<<k)+1][k]);
    return mmin;
}
