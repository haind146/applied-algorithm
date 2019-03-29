void genData(char* fn, int n) {
    FILE* f= fopen(fn,"w");
    fprintf(f, "%d\n", n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int x = rand()%20 +1;
            if(i==j) x = 0;
            fprintf(f, "%d ",x);
        }
        fprintf(f,"\n");

    }
    fclose(f);
}