// 思路：深度优先搜索找回路
#include <malloc.h>
#include <cstddef>

int* visit;
int* size;
int** rely;
int already;
bool findCircle(int cur){
    if(!size[cur]) return false;
    visit[cur] = 1;
    for(int i = 0;i < size[cur];i++){
        if(rely[cur][i] > already && ((visit[rely[cur][i]]) || findCircle(rely[cur][i]) == true)) return true;
    }
    visit[cur] = 0;
    return false;
}
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    size = (int*) calloc (numCourses,sizeof(int));
    rely = (int**) malloc (numCourses * sizeof(int*));
    for(int i = 0;i < prerequisitesSize;i++){
        size[prerequisites[i][0]]++;
    }
    for(int i = 0;i < numCourses;i++){
        rely[i] = (int*) calloc (size[i],sizeof(int));
        size[i] = 0;
    }
    for(int i = 0;i < prerequisitesSize;i++){
        rely[prerequisites[i][0]][size[prerequisites[i][0]]++] = prerequisites[i][1];
    }
    visit = (int*) calloc (numCourses,sizeof(int));
    already = -1;
    for(int i = 0;i < numCourses;i++){       
        if(findCircle(i) == true) return false;
        already++;
    }
    return true;
}