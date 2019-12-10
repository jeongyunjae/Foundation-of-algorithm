package circuits;

import java.util.Scanner;

public class TestGraph {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int vert;
		int m;
		int a,b,t;
		System.out.println("������ ���� �Է��ϼ���.");
		vert = sc.nextInt();
		Graph g = new Graph(vert);
		System.out.println("�Է��� �� edge���� �Է��ϼ���");
		t = sc.nextInt();
		System.out.println("edge��ǥ" + t+ "�� �Է�(ex 1 2) (��, edge�� 0���� ����)");
		for(int i = 0;i<t*2;i++) {
			a = sc.nextInt();
			b = sc.nextInt();
			g.addEdge(a, b);
		}
		System.out.println("Graph:");
		g.printGraph();
		System.out.println("result");
		hamCircuit(g);
	}
	
	static void hamCircuit(Graph g){
		int V = g.getvCount();
		
		int path[] = new int[V];
		for(int i=0; i<V; i++){
			path[i] = -1;
		}
		path[0] = 0;
		
		if(solveHamCircuit(V, g, path, 1) == false){
			System.out.println("��ΰ� �������� �ʽ��ϴ�.");
		}
		else{
			for(int i=0; i<V; i++){
				System.out.print(" " + path[i] + " ");
			}
			System.out.print(" " + path[0]);
		}
		
	}
	
	static boolean canBeAdded(int v, Graph g, int path[], int pos){
		if(g.getAdj()[pos - 1][v] == 0){
			return false;
		}
		
		for (int i = 0; i < pos; i++){
			if (path[i] == v) return false;
		}
		
	    return true;
	}
	
	static boolean solveHamCircuit(int V, Graph g, int path[], int pos){
		if(pos == V){
			if( g.getAdj()[path[pos - 1]][path[0]] == 1){
				return true;
			}
			else{
				return false;
			}
		}
		
		for (int v = 1; v < V; v++)
        {
            if (canBeAdded(v, g, path, pos))
            {
                path[pos] = v;
 
                if (solveHamCircuit(V, g, path, pos + 1) == true){
                    return true;
                }
                
                path[pos] = -1;
            }
        }
		
		return false;
	}
}