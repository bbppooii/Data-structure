#include <iostream>
using namespace std;
#define MVNum 100							
typedef char VerTexType;
typedef struct ArcNode {
	int adjvex;                          
	struct ArcNode* nextarc;          
}ArcNode;
typedef struct VNode {
	VerTexType data;
	ArcNode* firstarc;                	
}VNode, AdjList[MVNum];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;              		
}ALGraph;
bool visited[MVNum];
int LocateVex(ALGraph G, VerTexType v) {
	for (int i = 0; i < G.vexnum; ++i)
		if (G.vertices[i].data == v)
			return i;
	return -1;
}
void CreateUDG(ALGraph& G) {
	int i, j, k;
	cout << "�������ܶ��������ܱ���:";
	cin >> G.vexnum >> G.arcnum;
	cout << "�����붥�������:";
	for (i = 0; i < G.vexnum; ++i) {          	
		cin >> G.vertices[i].data;           	
		G.vertices[i].firstarc = NULL;
	}
	for (k = 0; k < G.arcnum; ++k) {        		
		VerTexType v1, v2;
		cout << "�������" << (k + 1) << "���������Ķ���:";
		cin >> v1 >> v2;                 	
		i = LocateVex(G, v1);  j = LocateVex(G, v2);
		ArcNode* p1 = new ArcNode;
		p1->adjvex = j;
		p1->nextarc = G.vertices[i].firstarc;  G.vertices[i].firstarc = p1;
		ArcNode* p2 = new ArcNode;
		p2->adjvex = i;
		p2->nextarc = G.vertices[j].firstarc;  G.vertices[j].firstarc = p2;
	}
}
void DFS(ALGraph G, int v) {
	cout << G.vertices[v].data << "   ";
	visited[v] = true;
	ArcNode* p = G.vertices[v].firstarc;
	while (p != NULL) {              			
		int w = p->adjvex;
		if (!visited[w])  DFS(G, w);   			
		p = p->nextarc;
	}
}
int main() {
	ALGraph G;
	CreateUDG(G);
	cout << "�����������ͨͼ����ʼ�㣺";
	VerTexType c;
	cin >> c;
	int i;
	for (i = 0; i < G.vexnum; ++i) {
		if (c == G.vertices[i].data)
			break;
	}
	cout << endl;
	while (i >= G.vexnum) {
		cout << "�õ㲻���ڣ����������룡" << endl;
		cout << "�����������ͨͼ����ʼ�㣺";
		cin >> c;
		for (i = 0; i < G.vexnum; ++i) {
			if (c == G.vertices[i].data)
				break;
		}
	}
	cout << "���������������ͼ�����" << endl;
	DFS(G, i);
	cout << endl;
	return 0;
}