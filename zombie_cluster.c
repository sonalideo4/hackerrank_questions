/* Zombie connectedness */

void DFS(j, bool *visited, int *zombies, numZombies)
{
    for(int k=0; k<numZombies; k++) {
        if(zombies[j][k] == 1 && visited[j][k] == false && visited[k][j] == false) {
            visited[j][k] = true;
            visited[k][j] = true;
            DFS(k, &visited, &zombies, numZombies);
        }
    }
}

int zombieCluster(int numZombies, char **zombies) 
{
    bool visited [numZombies][numZombies];
    int clusters = 0;
    int zombieMatrix [numZombies][numZombies];
    char currentZombie[numZombies];
    bool rowChecked = false;
    
    // parse zombie ids and make a square matrix
    for(int i=0,k=0; i<numZombies; i++) {
        memcpy(currentZombie, &zombies[k], numZombies);
        k += numZombies;
        for(int j=0; j<numZombies; j++) {
            visited[i][j] = false;
            zombieMatrix[i][j] = (int)strtoul(currentZombie[j], NULL, 2);
        }
    }
    
    for(int i=0; i<numZombies; i++) {
        rowChecked = false;
        for(int j=0; j<numZombies; j++) {
            if(zombieMatrix[i][j] == 1 && visited[i][j] == false && visited[j][i] == false) {
                visited[i][j] = true;
                visited[j][i] = true;
                DFS(j, &visited, &zombieMatrix, numZombies);
                if(!onceChecked) {
                    clusters += 1;
                    rowChecked = true;
                }
            }
        }
    }
    return clusters;
}

int main()
{
    const char *zombies[5] = ["10101", "11101", "01100", "00010", "10011"];
    int cluster = zombieCluster(5, &zombies);
    printf("Zombie clusters=%d", cluster);
    return 0;
}