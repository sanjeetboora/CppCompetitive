import java.io.*; // for handling input/output
import java.util.*; // contains Collections framework

class Main {
    static class Edge implements Comparable<Edge>{
        int src;
        int dest;
        int wt;
        
        public int compareTo(Edge compareEdge)
        {
            return this.wt - compareEdge.wt;
        }
    };
    static Edge edgeList[];
    static int parent[];
    static int V;
    static int E;

    public static int superparent(int x){
        if(parent[x] == x){
            return x;
        }
        else{
            int superparentX = superparent(parent[x]);
			parent[x] = superparentX;
			return superparentX;
        }
    }

    public static void unite(int x, int y) {
		int parX = superparent(x);
		int parY = superparent(y);

		if (parX != parY) {
			parent[parX] = parY;
		}
	}

	public static void main (String[] args) {
        
        Scanner scn  = new Scanner(System.in);
        V = scn.nextInt(); 
        E = scn.nextInt();
        edgeList = new Edge[E];
        for(int i=0; i<E; i++){
            Edge e = new Edge();
            e.src = scn.nextInt(); 
            e.dest = scn.nextInt();
            e.wt = scn.nextInt();
            edgeList[i] = e;
        }
        parent = new int[V+1];
        for(int i=0; i<=V; i++){
            parent[i] =i;
        }
        Arrays.sort(edgeList);
        int totalWeight=0;
        
        for (int i = 0; i < E; ++i)
        {
            int wt = edgeList[i].wt;
            int x = edgeList[i].src;
            int y = edgeList[i].dest;

            if (superparent(x) != superparent(y)) {
                unite(x, y);
                totalWeight += wt;
            }
        }
        System.out.println(totalWeight);   
	}
}
