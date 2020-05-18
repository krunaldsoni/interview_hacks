//============================================================================
// Name        : stllib_demo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

void demo_vector()
{
	vector<int> v;
	printf("\ninserting to vector array\n");
	for(int i = 0; i < 9; i++)
	{
		v.push_back(i*2);
	}
	for(auto it = v.begin(); it != v.end(); it++)
	{

		printf("v[%d] = %d\n", (int)distance(v.begin(), it), *it);
	}
	if (v.at(4) == 8)
	{
		printf("value 8 is stored at index 4");

	}
}
void demo_unordered_map()
{
	unordered_map<string, int> umap;
	umap.insert(make_pair("krunal",456));
	umap.insert(make_pair("chintan",123));
	umap["sonamsoni"] = 111;

	for (auto it = umap.begin(); it != umap.end(); it++)
		cout << "key:[" << it->first << "] value:[" << it->second << "]" << endl;

	umap.erase("sonamsoni");
	umap.erase("kkk");
	if (umap.find("krunal") != umap.end())
	{
		auto it = umap.find("krunal"); //or umap["krunal"]
		cout << "key:[krunal] value[" << it->second <<"]" <<endl;
	}

	/*
	 * umap.empty() -> true/false
	 *
	 */
}

void demo_unordered_set()
{
	unordered_set<int> s;
	for (int i = 0; i < 9; i++)
		s.insert(i);
	for(auto i = s.begin(); i != s.end(); i++)
		printf("%d\n", *i);
	s.erase(5);
	s.erase(4);
	for(auto i = s.begin(); i != s.end(); i++)
		printf("--%d--", *i);
	if (s.find(3) != s.end())
		printf("\nnumber-3 present\n");
}


void demo_stack()
{
	stack<int> s;
	printf("\ninserting [0 to 8] to stack");
	for (int i = 0; i < 9; i++)
		s.push(i);
	printf("\ndumping stack\n");
	while(!s.empty()) {
		printf("--%d--", s.top());
		s.pop();
	}
	printf("\n");
}

void demo_queue()
{
	queue<int> q;
	printf("\ninserting [0 to 8] to queue");
	for (int i = 0; i < 9; i++)
		q.push(i);
	printf("\ndumping queue\n");
	while(!q.empty()) {
		printf("--%d--", q.front());
		q.pop();
	}
	printf("\n");
}

void demo_priority_queue()
{
	priority_queue<int, vector<int>, greater<int>> pq;
	printf("\n inserting {5,2,1,8,7,3,4,6,0}");
	pq.push(5);
	pq.push(2);
	pq.push(1);
	pq.push(8);
	pq.push(7);
	pq.push(3);
	pq.push(4);
	pq.push(5);
	pq.push(0);
	printf("\ndumping priority queue\n");
	while(!pq.empty()) {
		printf("--%d--", pq.top());
		pq.pop();
	}
	printf("\n");
}
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	printf("=== demo unordered map ===");
	demo_unordered_map();
	printf("==== demo unoredered set ===");
	demo_unordered_set();
	printf("==== demo stack ===");
	demo_stack();
	printf("==== demo queue ===");
	demo_queue();
	printf("==== demo priority queue ===");
	demo_priority_queue();
	printf("\n==== demo vector ===\n");
	demo_vector();
	return 0;
}
