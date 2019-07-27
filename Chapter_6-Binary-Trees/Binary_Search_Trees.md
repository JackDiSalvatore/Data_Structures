# Binary Search Trees
The left child < parent, right child > parent


* Breadth First Search: Traverse tree level by level.  Utilizes a queue.  Ex: find the nearset node

* Depth First Search: Traverse tree by searching arcs.  Utilizes a stack.
  * Preorder Traversal: Visit Left Right
  * Inorder Traversal: Left Visit Right
  * Postorder Traversal: Left Right Visit

Binary search uses log(n) time


### Breadth First Traversal
ex:

            13 
         /     \
        10      25
       / \     / \
      2   12  20  31
                 /
               29

1. visit 13       queue: ->[]->
1. add children   queue: ->[25,10]->

2. pop 10         queue: ->[25]->
2. visit 10       queue: ->[12,2,25]->
2. add children   queue: ->[12,2,25]->

3. pop 25         queue: ->[12,2]->
3. visit 25       queue: ->[12,2]->
3. add children   queue: ->[31,20,12,2]->

4. pop 2          queue: ->[31,20,12]->
4. visit 2        queue: ->[31,20,12]->
4. add children   queue: ->[31,20,12]->   (no children)

5. pop 12         queue: ->[31,20]->
5. visit 12       queue: ->[31,20]->
5. add children   queue: ->[31,20]->   (no children)

6. pop 20         queue: ->[31]->
6. visit 20       queue: ->[31]->
6. add children   queue: ->[31]->   (no children)

7. pop 31         queue: ->[]->
7. visit 31       queue: ->[]->
7. add children   queue: ->[29]->   (no children)

8. pop 29         queue: ->[]->
8. visit 29       queue: ->[]->
8. add children   queue: ->[]->   (no children)

9. DONE

Output: 13, 10, 25, 2, 12, 20, 31, 29


### Depth First Traversal

##### Preorder: VLR
ex:

            13 
         /     \
        10      25
       / \     / \
      2   12  20  31
                 /
               29

1.  **visit 13**
2.  at 13, go left
3.  **visit 10**
4.  at 10, go left
5.  **visit 2**
6.  at 2, go left, nothing there
7.  at 2, go right, nothing there
8.  *return 10*
9.  at 10, go right
10. **visit 12**
11. at 12, go left, nothing there
12. at 12, go right, nothing there
13. *return 10*
14. *return 13*
15. at 13 go right
16. **visit 25**
17. at 25, go left
18. **visit 20**
19. at 20, go left, nothing there
20. at 20, go right, nothing there
21. *return 25*
22. at 25, go right
23. **visit 31**
24. at 31, go left
25. **visit 29**
26. at 29, go left, nothing there
27. at 29, go right, nothing there
28. *return 31*
29. at 31, go right, nothing there
30. *return 25*
31. *return 13*
32. DONE

Output: 13, 10, 2, 12, 25, 20, 31, 29


##### Inorder: LVR
ex:

            13 
         /     \
        10      25
       / \     / \
      2   12  20  31
                 /
               29

1.  starting at 13, go left
2.  at 10, go left
3.  at 2, go left, stop nothing there
4.  **visit 2**
5.  at 2, go right, stop nothing there
6.  *return to 10*
7.  **visit 10**
8.  at 10, go right
9.  at 12, go left, stop nothing there
10.  **visit 12**
11. at 12, go right, stop nothing there
12. *return to 10*
13. *return to 13*
14.  **visit 13**
15. at 13, go right
16. at 25, go left
17. at 20, go left, stop nothing there
18. **visit 20**
19. at 20, go right, stop nothing there
20. *return to 25*
21. **visit 25**
22. at 25, go right
23. at 31, go left
24. at 29, go left, stop nothing there
25. **visit 29**
26. at 29, go right, stop nothing there
27. *return to 31*
28. **visit 31**
29. at 31, go right, stop nothing there
30. *return 25*
31. *return 13*
32. DONE

Output: 2, 10, 12, 13, 20, 25, 29, 31


##### Postorder: LRV
ex:

            13 
         /     \
        10      25
       / \     / \
      2   12  20  31
                 /
               29

1.  at 13, go left
2.  at 10, go left
3.  at 2, go left, nothing there
4.  at 2, go right, nothing there
5.  **visit 2**
6.  *return 10*
7.  at 10, go right
8.  at 12, go left, nothing there
9.  at 12, go right, nothing there
10. **visit 12**
11. *return 10*
12. **visit 10**
13. *return 13*
14. at 13, go right
15. at 25, go left
16. at 20, go left, nothing there
17. at 20, go right, nothing there
18. **visit 20**
19. *return to 25*
20. at 25, go right
21. at 31, go left
22. at 29, go left, nothing there
23. at 29, go right, nothing there
24. **visit 29**
25. *return 31*
26. at 31, go right, nothing there
27. **visit 31**
28. *return 25*
29. **visit 25**
30. *return 13*
31. **visit 13**
32. DONE

Output: 2, 12, 10, 20, 29, 31, 25, 13
