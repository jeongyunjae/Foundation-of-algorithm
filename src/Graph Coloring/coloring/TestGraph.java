package coloring;

import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;

public class TestGraph {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int vert;
		int m;
		int a,b,t;
		System.out.println("정점의 수를 입력하세요.");
		vert = sc.nextInt();
		System.out.println("m값을 입력하세요");
		m = sc.nextInt();
		Graph g2 = new Graph(vert);
		System.out.println("입력할 총 edge수를 입력하세요");
		t = sc.nextInt();
		System.out.println("edge좌표" + t+ "개 입력(ex 1 2) (단, edge는 0부터 시작)");
		for(int i = 0;i<t;i++) {
			a = sc.nextInt();
			b = sc.nextInt();
			g2.addEdge(a, b);
		}
		System.out.println("Graph:");
		g2.printGraph();

		backTrackingColoring(g2, m);
	}

	public static boolean isSafe(int v, Graph g, int colors[], int cr) {
		for (int i = 0; i < g.getvCount(); i++) {
			if (g.hasEdge(v, i) && cr == colors[i]) {
				return false;
			}
		}
		return true;

	}

	public static boolean graphColoringUtil(Graph g, int m, int colors[], int v) {
		if (v == g.getvCount())
			return true;

		for (int cr = 1; cr <= m; cr++) {
			if (isSafe(v, g, colors, cr)) {
				colors[v] = cr;
				if (graphColoringUtil(g, m, colors, v + 1))
					return true;

				colors[v] = 0;
			}
		}

		return false;
	}

	public static void backTrackingColoring(Graph g, int m) {
		int V = g.getvCount();

		int colors[] = new int[V];

		Arrays.fill(colors, 0);

		if (!graphColoringUtil(g, m, colors, 0)) {
			System.out.println("Solution does not exist");
		}

		printColors(colors);
	}

	public static void printColors(int[] colors) {
		for (int i = 0; i < colors.length; i++)
			System.out.println("Vertex " + i + " --->  Color " + colors[i]);
	}
}