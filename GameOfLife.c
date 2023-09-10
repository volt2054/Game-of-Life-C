#include <stdio.h>
#include <stdlib.h>
#include <time.h>


static const int M = 20;
static const int N = 20;
//#define M 10
//#define N 10
 
void print2d(int arr[M][N]) //bad function to print a 2d array
{
    for (i = 0; i < M; i++){ 
      for (j = 0; j < N; j++) {
        printf("%d ", arr[i][j]);
      }
    printf("\n");
    }
}
void print(int *arr, int size){ //bad function to print a 1d array
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
    }
}
void assignArray(int array1[M][N], int array2[M][N]){ //bad function to copy 1 array into another
    int i,j;
    for (i=0; i<M;++i){
        for (j=0; j<N;++j){
            array2[i][j] = array1[i][j];
        }
    }
}

void fill2darr(int (*array)[N], int m){ //bad function fill an array with 1s
    int i,j;
    int n;

    n = (int) (sizeof(array[0])/sizeof(array[0][0]));

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      array[i][j] = 1;
    }
  }

}
void readFileIntoArray(FILE* fp, int array[M][N]) { // bad function to read a file into a 2d array
    char c;
    int num;
    int temp, col = 0, row =1;
    int i, j;

    do {  
        c = getc (fp);
        if((temp != 2) && (c == ' ' || c == '\n'))
            col++;
        if(c == '\n'){
            temp =2;
            row++;
        }
    } while (c != EOF);

    rewind(fp);
    for(i=0; i < M; i++){
        for(j=0; j < N; j++){
            fscanf(fp, " %d", &num);
            array[i][j] = num;
        }
    }
}
void randomlyFillArray(int array[M][N]) { // bad function to randomly fill an array
    int i,j;
    srand(time(NULL));
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            array[i][j] = rand() % 2;
        }
    }
}

int findNeighbours(int arr[M][N], int x, int y) { // bad function to find neighbours of a point in a 2d array
    int neighbours = 0;

    if (arr[x-1][y-1] == 1 && (x-1 >= 0) && (y-1 >= 0)) {++neighbours;}
    if (arr[x-1][y] == 1 && (x-1 >= 0) && (y < N)) {++neighbours;}
    if (arr[x-1][y+1] == 1 && (x-1 >= 0) && (y+1 < N)) {++neighbours;}
    if (arr[x][y-1] == 1 && (x < M) && (y-1 >= 0)) {++neighbours;}
    if (arr[x][y+1] == 1 && (x < M) && (y+1 < N)) {++neighbours;}
    if (arr[x+1][y-1] == 1 && (x+1 < M) && (y-1 >= 0)) {++neighbours;}
    if (arr[x+1][y] == 1 && (x+1 < M) && (y < N)) {++neighbours;}
    if (arr[x+1][y+1] == 1 && (x+1 < M) && (y+1 < N)) {++neighbours;}

    return neighbours;
}
void nextTick(int arr[M][N], int (*nextArray)[N], int m) { // bad function to calculate next tick in life

    int i,j;
    int n;

    n = (int) (sizeof(nextArray[0])/sizeof(nextArray[0][0]));

    for (i = 0; i < m; i++){ 
      for (j = 0; j < n; j++) {
        if ((findNeighbours(arr, i, j) == 2 || findNeighbours(arr, i ,j) == 3) && arr[i][j] == 1) {nextArray[i][j] = 1;}
        else if (findNeighbours(arr,i,j) == 3 && arr[i][j] == 0) {nextArray[i][j] = 1;}
        else {nextArray[i][j] = 0;}
      }
    }
}

void make_pixel(FILE* fp, int true) { // bad functino to make a pixel (SHOULD NOT BE A FUNCTION)
    fprintf(fp, "%d ", true);
}
void make_ppm_header(FILE* fp,int width, int height) { // bad function to make the image
    fprintf(fp, "P1\n");
    fprintf(fp, "%d %d\n",width, height /*, 1*/); //dont need 1 since using p1
}
void write2dArrayToFile(FILE* fp, int array[M][N]) { // bad function to write2d array to image file
    
    int upscaleFactor;

    // int i,j,k,l;
    // for (i = 0; i < M*upscaleFactor; i+=upscaleFactor) {
    //     for (j = 0; j < N*upscaleFactor; j+=upscaleFactor) {

    //         for (k=i; k<i*upscaleFactor;++k) {
    //             for (l=j; l<j*upscaleFactor;++l){
    //                 make_pixel(fp, array[i/upscaleFactor][j/upscaleFactor]);
    //             }
    //         }
            
    //     }
    //     fprintf(fp, "\n");
    // }

    int i,j;
    for(i = 0; i < M; ++i) {
        for(j = 0; j < N; ++j) {
            make_pixel(fp, array[i][j]);
        }
        fprintf(fp, "\n");
    }
}


void animate(FILE* fp, int arr[M][N], int nextArray[M][N], int frames){ //bad function to make an animation

    for (int i = 0; i < frames; ++i){
        char filename[255];
        sprintf(filename, "./file/test%d.ppm", i);

        fp=fopen(("%s",filename),"w+");
        make_ppm_header(fp, M,N);

        nextTick(arr, nextArray, M);
        assignArray(nextArray,arr);

        write2dArrayToFile(fp, nextArray);
        fclose(fp);
    }
}


int main() // bad main function
{

    FILE *fp;

    int arr[M][N];
    int nextArray[M][N];

    //fp = fopen("game.txt","r"); // IF LOADING FROM FILE
    //readFileIntoArray(fp, arr); // IF LOADING FROM FILE

    randomlyFillArray(arr);
    print2d(arr);

    animate(fp, arr, nextArray, 20);

    return 0;
}