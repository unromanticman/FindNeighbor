# FindNeighbor
依照點的鄰居進行擴展，用途為可以取得鄰近的座標點。    
舉例:  
第1層有10個點  
第2層則由這10個點延伸出100個點  
第3層則由這100個點延伸出1000個點  

...依此類推。


<pre>
findNeighborPos(int x,int y,int ** map,int depth)
x:目前所在位置x
y:目前所在位置y
map:一個二維陣列的地圖
depth:進行深度搜尋
</pre>

# DEMO

### 深度1
目前在(10,10)，列出深度為1的點  
<img width="500" src="https://github.com/unromanticman/FindNeighbor/blob/master/demo1.png?raw=true">

### 深度2  
目前在(10,10)，列出深度為2的點  
<img width="500" src="https://github.com/unromanticman/FindNeighbor/blob/master/demo2.png?raw=true">

### 深度3
目前在(10,10)，列出深度為3的點  
<img width="500" src="https://github.com/unromanticman/FindNeighbor/blob/master/demo3.png?raw=true">
