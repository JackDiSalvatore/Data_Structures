/*
 * genSkipL.h
 *
 *  Created on: Jan 12, 2017
 *      Author: jack
 */

#ifndef GENSKIPL_H_
#define GENSKIPL_H_

#include <cstdlib>

const int maxLevel = 4;

template<class T>
class SkipListNode
{
public:
	SkipListNode()
	{
		T key;
		SkipListNode **next;
	}
};

template<class T>
class SkipList
{
public:
	SkipList();
	bool isEmpty() const;
	void choosePowers();
	int chooseLevel();
	T* skipListSearch(const T&);
	void skipListInsert(const T&);
private:
	typedef SkipListNode<T> *nodePtr;
	nodePtr root[maxLevel];
	int powers[maxLevel];
};

template<class T>
bool SkipList<T>::isEmpty() const
{
	return root[0] == 0;
}

template<class T>
void SkipList<T>::choosePowers()
{
	int i, j;

	powers[maxLevel-1] = (2 << (maxLevel-1)) - 1; // 2^maxLevel - 1
	for (i = maxLevel - 2, j = 0; i >= 0; i--, j++)
		powers[i] = powers[i+1] - (2 << j);		// 2^(j+1)
}

template<class T>
int SkipList<T>::chooseLevel()
{
	int i, r = rand() % powers[maxLevel-1] + 1;
	for( i = 1; i < maxLevel; i++)
		if( r < powers[i])
			return i - 1;	// return a level < the highest level
	return i-1;		// return the highest level
}

template<class T>
T* SkipList<T>::skipListSearch(const T& key)
{
	if (isEmpty()) return 0;

	nodePtr prev, curr;
	int lvl;

	/* Find the highest non-null level */
	for (lvl = maxLevel-1; lvl >= 0 && !root[lvl]; lvl--);
	prev = curr = root[lvl];
	while(true)
	{
		if(key == curr->key)		// success if equal
			return &curr->key;
		else if (key < curr->key)	// if smaller, go down, if possible
		{
			if (lvl == 0)
				return 0;
			else if ( curr == root[lvl])		// by one level
				curr == root[--lvl];			// starting from the
			else curr = *(prev->next + --lvl);	// predecessor which can be the root
		}
		else									// if greater, go to the next
		{										// non-null node on the same level
			prev = curr;						// or to a list on a
			if (*(curr->next + lvl) != 0)		// lower level
				curr = *(curr->next + lvl);
			else
			{

				for (lvl--; lvl >= 0 && *(curr->next + lvl) == 0; lvl);
				if (lvl >= 0)
					curr = *(curr->next + lvl);
				else return 0;
			}
		}
	}
}

template<class T>
void SkipList<T>::skipListInsert(const T& key)
{
	nodePtr curr[maxLevel], prev[maxLevel], newNode;
	int lvl, i;

	curr[maxLevel - 1] = root[maxLevel - 1];
	prev[maxLevel - 1] = 0;

	for (lvl = maxLevel - 1; lvl >= 0; lvl--)
	{
		while (curr[lvl] && curr[lvl]->key < key)		// go to the next
		{												// if smaller
			prev[lvl] = curr[lvl];
			curr[lvl] = *(curr[lvl]->next + key);
		}
		if (curr[lvl] && curr[lvl]->key == key)			// dont include
			return;										// duplicates
		if (lvl > 0)
			if (prev[lvl] == 0)				// go down one level
			{								// if not the lowest level, using a
				curr[lvl-1] = root[lvl-1];	// link either from the root
				prev[lvl-1] = 0;
			}
			else							// or from the predecessor
			{
				curr[lvl-1] = *(prev[lvl]->next + lvl-1);
				prev[lvl-1] = prev[lvl];
			}
	}
	lvl = chooseLevel();		// generates random level for newNode
	newNode = new SkipListNode<T>;
	newNode->next = new nodePtr[sizeof(nodePtr) * (lvl+1)];
	newNode->key = key;

	for (i = 0; i <=  lvl; i++)				// initialize next fields of newNode
	{										// and reset to newNode either fields
		*(newNode->next + i) = curr[i];		// or next fields of newNode's predecessors
		if (prev[i] == 0)
			root[i] = newNode;
		else *(prev[i]->next +i) = newNode;
	}
}

#endif /* GENSKIPL_H_ */
