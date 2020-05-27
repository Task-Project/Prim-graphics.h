#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#define n 3000
using namespace std;

int r=2,t=3;
DWORD fj=GetSystemMetrics(SM_CXSCREEN);
DWORD fi=GetSystemMetrics(SM_CYSCREEN);
vector<vector<pair<int,int> > > g(n);
vector<pair<int,int> > pos(n);
priority_queue<pair<int,pair<int,int> > > q;
bool visited[n]={0};

void draw_nodes(){
	for(int i=0;i<n;i++){
		circle(pos[i].second,pos[i].first,r);
	}
}

void load_edges(){
	double distace;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				distace=(pos[i].first-pos[j].first)*(pos[i].first-pos[j].first);
				distace+=(pos[i].second-pos[j].second)*(pos[i].second-pos[j].second);
				g[i].push_back({distace,j});
			}
		}
	}
}

main(){
	int dis,min,pos_min;
	initwindow(fj,fi);
	for(int i=0;i<n;i++)
		pos[i]={rand()%fi,rand()%fj};
	draw_nodes();
	load_edges();
	int pivot=n/2,guess;
	do{
		_sleep(t);
		visited[pivot]=1;
		for(int j=0;j<g[pivot].size();j++){
			guess=g[pivot][j].second;
			dis=g[pivot][j].first;
			q.push({-dis,{guess,pivot}});
		}
		while(visited[q.top().second.first]==1 && !q.empty()) q.pop();
		if(!q.empty()){
			pivot=q.top().second.first;
			line(pos[q.top().second.first].second,pos[q.top().second.first].first,pos[q.top().second.second].second,pos[q.top().second.second].first);
		}
	}while(!q.empty());
	getch();
	closegraph();
}
