int __max(int a, int b){
    if (a > b)
        return a;
    return b;
}
int largestAltitude(int* gain, int gainSize){
    int max = 0;
    int currentPlace = 0;
    int currentHeight = 0;
    while (currentPlace < gainSize){
        int depth = *(gain + currentPlace);
        currentPlace++;
        int tempHeight = currentHeight + depth;
        max = __max(tempHeight, max);
        currentHeight = tempHeight;
    }
    return max;
}