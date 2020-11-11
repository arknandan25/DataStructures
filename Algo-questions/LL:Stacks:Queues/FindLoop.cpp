#include<vector>
#include<unordered_set>
#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
};

LinkedList *findLoop(LinkedList *head) {
	//TC-O(N),SC-O(N), where N is the no. of elements in the LL
  // ---------Code just for understanding purpose-----dosen't run on tis platform as it requires
	unordered_set<int> set = {};
	LinkedList *ptr =head;
	while(ptr != NULL){
		
		if(set.find(ptr->value) != set.end()){
			//element already exist in the set means this is the statring point of the loop
			cout<<"The origin point of the loop in the LL:"<<ptr->value;	
			return true;
		}
		//if elememt not found in set -means traversing not complete of the entire list
		//keep inserting into the set and moving on
		set.insert(ptr->value);
		ptr = ptr->next;
				
	}
	return false;
}
