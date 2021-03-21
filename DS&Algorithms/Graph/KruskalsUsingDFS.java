import java.io.*; // for handling input/output
import java.util.*; // contains Collections framework

// don't change the name of this class
// you can add inner classes if needed
class Main {
  static int visited[] = new int[100001];
  static ArrayList<Integer> arr[] = new ArrayList[100001];
  static int flag =0;
    
  static void dfs(int node, int parent){
      visited[node] = 1;
      for(int i=0; i<arr[node].size(); i++){
          int nbr = arr[node].get(i);
          if( nbr == parent){
              continue;
          }
          if(visited[nbr] == 1){
              flag = 1;
              return;
          }
          if(visited[nbr] == 0){
              dfs(nbr, node);
          }      
      }
      visited[node] = 2;
    }
	
  public static void main (String[] args) {
                   
      Scanner scn = new Scanner(System.in);
      int V = scn.nextInt();
      int E = scn.nextInt();
      //adjacency List
      for(int i=0; i<=V; i++){
          arr[i] = new ArrayList<Integer>();
      }
      for(int i=1; i<=E; i++){
          int a = scn.nextInt();
          int b = scn.nextInt();
          arr[a].add(b);
          arr[b].add(a);
      }

      for(int i=0; i<=V; i++){
          if(visited[i] == 0){
              dfs(i, -1);
          }
      }
      if(flag == 1){
          System.out.println("Yes");
      }
      else{
          System.out.println("No");
      }
	}
}
