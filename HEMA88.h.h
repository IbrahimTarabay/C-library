/*I Hope You have Good Experience*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<stdarg.h>
#define TRUE 1
#define FALSE 0
#define PI 3.14159
#define EXPONENTIAL 2.7182818284590452353602874713527
#define CIRCLE_AREA(x)((PI)*(x)*(x))
#define CIRCLE_CIRCUMFERENCE(x)(2*PI*x)
#define SPHERICAL_SIZE(x)((4/3)*PI*(x^3))
#define SPHERICAL_AREA(x)(4*PI*(x^2))
#define SQUARE_CIRCUMFERENCE(x)(4*x)
#define SQUARE_AREA(x)((x)*(x))
#define RECTANGLE_AREA(x,y)((x)*(y))
#define RECTANGLE_CIRCUMFERENCE(x,y)(2*(x+y))
#define TRIANGLE_CIRCUMFERENCE(x,y,z)(x+y+z)


struct tr{

struct tr *le;/*pointer to left subtree*/
int da;
struct tr *ri;/*pointer to left subtree*/

};

typedef struct tr Tr;
typedef Tr *tree;

struct st{

int dataaa;
struct st *ne;

};

typedef struct st St;/*synonym for struct stacknode*/
typedef St *stack;

struct qu{

char datass;
struct qu *quy;/*queuenode pointer*/

};

typedef struct qu Qu;
typedef Qu *queue;

struct li {

char datasa ;/*each listnode contains a character */
struct li *ppp;/*pointer to next node*/

};

typedef struct li Li; /*synonym for struct list node**/
typedef Li *list ; /*synonym for Listnote */


struct card{

const char *face;
const char *suit;

};

typedef struct card Card;/*new type name for struct card*/
Card deck[52];

const char *face[]={"Ace","Deuce","three","four","five","six","seven","eight","nine","ten","jack","queen","king"};
const char *suit[]={"hearts","diamonds","clubs","spades"};



/*HEMA functions*/
int maximum( int x, int y, int z );
int isequal(int n1,int n2);
double ln(double x);
void bubblesort(int array[],const int size);
char Rcontext(const char *const sptr);
void shuffle(Card *const deck,const char *Face[],
const char *Suit[]);
void deal(const Card *const deck);
void insertnode(tree *treeptr,int value);
void inorder(tree treeptr);
void preorder(tree treeptr);
void postorder(tree treeptr);
int p_two_dim_Array(int row,int column,int a[][column]);
void minArray(int row,int column,const int a[][column]);
void maxArray(int row,int column,const int a[][column]);
float averageArray(int row,int column,const int a[][column]);
float totalArray(int row,int column,const int a[][column]);
void maxRow(int row,int column,const int a[][column]);
void minRow(int row,int column,const int a[][column]);
void maxColumn(int row,int column,const int a[][column]);
void minColumn(int row,int column,const int a[][column]);
int push(stack *topptr,int info);
int pop(stack *topptr);
void printstack(stack currentptr);
int isstackempty(stack topptr);
void swap(int *element1,int *element2);
long factorial(long number);
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void printArray(int arr[], int size);
void printqueue(queue currentptr);
int isqueueempty(queue headptr);
char dequeue(queue *headptr,queue *tailptr);
void enqueue(queue *headptr,queue *tailptr,char value);
void displaybits(unsigned value);
void insert( list *sptr,char value );
char Delete(list *sptr,char value  );
int islistempty(list sptr);
void printlist(list currentptr);
void mean(const int a[],int size);
void median(int a[],int size);
void mode(const int a[],int size,int k,int freq[]);
int linearSearch( const int array[], int key, int size );
long fiii( long n );
void fibonacci(const int hold);
void convertToUppercase1(void);
void convertToUppercase2(char sentence[],int size);
void printRow( const int b[], int low, int mid, int high );
int binarySearch( const int b[], int searchKey, int low, int high );
void rolldice(int a[],int size);
void histogramNumber(int number);
void histogram_two_dim(int row,int column,int *a[row][column]);
double printArguments( int i, ... );




/*maximum function*/
int maximum( int x, int y, int z )
{
 /* assume x is largest */
 int max;
if ( x>y&&x>z  ) { /* if y is larger than max, assign y to max */
max = x;
} /* end if */
if ( y > x&&y>z) { /* if z is larger than max, assign z to max */
max = y;
} /* end if */
else{
    max=z;
}
return max; /* max is largest value */
} /* end function maximum */

/*isequal function*/
int isequal(int n1,int n2){
if(n1==n2){

    return 1;
}
else{

   return 0;
}
}

/*ln function*/
double ln(double x){

double y;

y=log(x);
  return y;

}

/*bubblesort function*/
void bubblesort(int array[],const int size){


int pass;
int j;


for(pass=0;pass<size;pass++){

    for(j=0;j<size-1;j++){

        if(array[j]>array[j+1]){

         int hold = array[j];

         array[j] = array[j+1] ;

         array[j+1] = hold;


        }
    }
}

}

/*Rcontext function*//*to reverse context*/
char Rcontext(const char *const sptr){

/* if end of the string */
if(sptr[0]=='\0'){/* base case */

    return 0;/*ÇßÊÈ Çì ÑÞã åíØáÚ äÝÓ ÇáäÇÊÌ*/
}

else{/* if not end of the string */

    Rcontext(&sptr[1]); /* recursion step ããßä ÊÛíÑ ÇáÓÊÈ ÈÍíË ãÊÙåÑÔì ÍÇÌÇÊ */
    putchar(sptr[0]);/* use putchar to display character  ããßä ÊÛíÑ äåÇíÊå ÈÍíË ÈÑÏå ãíÙåÑÔì ÈÚÖ ÇáßáÇã*/

}

}


/*suffle function*/

void shuffle(Card *const deck,const char *Face[],
 const char *Suit[]){
srand(time(NULL));

int i;
int j;
Card temp;


for ( i = 0; i <= 51; i++ ) {
 /* end for */
deck[ i ].face = Face[ i % 13 ];
deck[ i ].suit = Suit[ i / 13 ];
}

for(i=0;i<=51;i++){

 j=rand()%52;

 temp=deck[i];
 deck[i]=deck[j];
 deck[j]=temp;


}

}


void deal(const Card *const deck){


int i;

for(i=0;i<=51;i++){

   printf( "%5s of %-8s%s",deck[ i ].face ,deck[ i ].suit ,
( i + 1 ) % 4 ? " " : "\n" );

}
}

/*tree function*/

void insertnode(tree *treeptr,int value){

if(*treeptr==NULL){

    *treeptr=malloc(sizeof(Tr));

/*if memory was allocated then assign data*/

if(*treeptr!=NULL){

    (*treeptr)->da=value;
    (*treeptr)->le=NULL;
    (*treeptr)->ri=NULL;

}
else{

    printf("%d not inserted.no memory available.\n",value);
}

}
else{/*tree is not empty*/

    if(value<(*treeptr)->da){

        insertnode(&((*treeptr)->le),value);

    }
    else if(value>(*treeptr)->da){

        insertnode(&((*treeptr)->ri),value);
    }
    else{/*duplicate data value ignored*/

        printf("dup");

    }
}
}

void inorder(tree treeptr){/*<subleft><root><subright>*/

if(treeptr!=NULL){
inorder(treeptr->le);
printf("%3d",treeptr->da);
inorder(treeptr->ri);
}
}

void preorder(tree treeptr){

if(treeptr!=NULL){
printf("%3d",treeptr->da);
preorder(treeptr->le);
preorder(treeptr->ri);
}
}


void postorder(tree treeptr){

if(treeptr!=NULL){
postorder(treeptr->le);
postorder(treeptr->ri);
printf("%3d",treeptr->da);
}
}


int p_two_dim_Array(int row,int column,int a[][column] )
{
int i; /* row counter */
int j; /* column counter */

/* loop through rows */
for ( i = 0; i <row; i++ ) {
/* output column values */
for ( j = 0; j <column; j++ ) {
printf( "%d ", a[ i ][ j ] );

} /* end inner for */
printf("\n");
} /* end outer for */
} /* end function printArray */

/*minARRay function*/
void minArray(int row,int column,const int a[][column]){

int i;
int j;
int min_of_all=2147483647;

for(i=0;i<row;i++){

    for(j=0;j<column;j++){

        if(min_of_all>=a[i][j]){

            min_of_all=a[i][j];

        }
}

}
printf("%d",min_of_all);
}

/*maxArray function*/
void maxArray(int row,int column,const int a[][column]){

int i;
int j;
int max_of_all=-2147483647;

for(i=0;i<row;i++){

    for(j=0;j<column;j++){

        if(max_of_all<=a[i][j]){

            max_of_all=a[i][j];

        }
}

}
printf("%d",max_of_all);
}

/*averageArray function*/
float averageArray(int row,int column,const int a[][column]){

int i;
int j;
int total=0;
float average;

for(i=0;i<row;i++){
for(j=0;j<column;j++){

        total+=a[i][j];/*ÊÚÇãá ßÇäåÇ ÚãæÏ áÇäåÇ ãä 0 Çáì 5*/

    }
}
average=(float)total/(float)(column*row);
printf("%f",average);
}

/*ããßä ÊÛíÑ ÇáÔßá æÊÎáì Çáì ÝæÞ åì Çáì ÊÊÚÇãá ßÇäåÇ ÚãæÏ æÇáÊÇäíå ÕÝ*/


/*totalArray function*/


float totalArray(int row,int column,const int a[][column]){

int i;
int j;
float total=0;


for(i=0;i<row;i++){
for(j=0;j<column;j++){

        total+=a[i][j];/*ÊÚÇãá ßÇäåÇ ÚãæÏ áÇäåÇ ãä 0 Çáì 5*/

    }
}
printf("%f",total);
}


/*maxRow function*/

void maxRow(int row,int column,const int a[][column]){

int i;
int j;

for(i=0;i<row;i++){

    int max_of_all=-2147483647;

    for(j=0;j<column;j++){

        if(max_of_all<=a[i][j]){

            max_of_all=a[i][j];

        }
}
printf("\n%d",max_of_all);
}
}

/*minRow function*/

void minRow(int row,int column,const int a[][column]){

int i;
int j;

for(i=0;i<row;i++){

int min_of_all=2147483647;

    for(j=0;j<column;j++){

        if(min_of_all>=a[i][j]){

            min_of_all=a[i][j];

        }
}
printf("\n%d",min_of_all);
}
}

/*maxColumn function*/

void maxColumn(int row,int column,const int a[][column]){

int i;
int j;

for(j=0;j<column;j++){

int max_of_all=-2147483647;

    for(i=0;i<row;i++){

        if(max_of_all<=a[i][j]){

            max_of_all=a[i][j];

        }
}

printf("\n%d",max_of_all);
}
}


/*minColumn function*/

void minColumn(int row,int column,const int a[][column]){

int i;
int j;

for(j=0;j<column;j++){

int min_of_all=2147483647;

    for(i=0;i<row;i++){

        if(min_of_all>=a[i][j]){

            min_of_all=a[i][j];

        }
}

printf("\n%d",min_of_all);
}
}

/*stack functions*/

/*insert anode at the stack top*/
int push(stack *topptr,int info){

stack newptr;

newptr=malloc(sizeof(St));

/*insert the node at stack top*/
if(newptr!=NULL){

    newptr->dataaa=info;
    newptr->ne=*topptr;
    *topptr=newptr;

}
else{/*no space available*/

    return 0;

}
}


/*remove anode form the stack top*/
int pop(stack *topptr){

stack tempptr;/*temporary node pointer*/
int popvalue;/*node value*/

tempptr=*topptr;
popvalue=(*topptr)->dataaa;
*topptr=(*topptr)->ne;

free(tempptr);
return popvalue;
}


void printstack(stack currentptr){

/*if stack is empty*/
if(currentptr==NULL){

    printf("the stack is empty.\n\n");
}
else{

    printf("the stack is:\n");

    while(currentptr!=NULL){

        printf("%d-->",currentptr->dataaa);

        currentptr=currentptr->ne;
    }
    printf("NULL\n\n");
}
}

int isstackempty(stack topptr){

return topptr==NULL;
}

/*swap function*/
void swap(int *element1,int *element2){

int hold = *element1;

*element1 = *element2;

*element2 = hold;

}

/*factorial function*/

long factorial(long number){

long result;

if(number==1||number==0){

return 1;

}

if(number<0||number>20){

    printf("sorry its not possible\n");

    return 0;
}
else{

    result=number*factorial(number-1);
}

return result;
}

/*quick sort function*/
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low-1);  // Index of smaller element

    for (int j = low;j<= high-1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
     int i;
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);


    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);

}

/*queue functions*/

void enqueue(queue *headptr,queue *tailptr,char value){

queue newptr;/*pointer to new node*/

newptr=malloc(sizeof(Qu));

if(newptr!=NULL){
    newptr->datass=value;
    newptr->quy=NULL;

    /*if empty,insert node at head*/
    if(isqueueempty(*headptr)){

        *headptr=newptr;

    }
    else{

        (*tailptr)->quy=newptr;
    }

    *tailptr=newptr;

}

else{

    printf("%c not inserted.no memory available.\n",value);

}
}

char dequeue(queue *headptr,queue *tailptr){

char value;
queue tempptr;

value=(*headptr)->datass;
tempptr=*headptr;
*headptr=(*headptr)->quy;

if(*headptr==NULL){

    *tailptr=NULL;
}
free(tempptr);
return value;
}

int isqueueempty(queue headptr){/*return 1 if the list is empty,0 otherwise*/

return headptr==NULL;
}

void printqueue(queue currentptr){

if(currentptr==NULL){

    printf("Queue is empty .\n\n");

}
else{

    printf("the queue is:\n");

    while(currentptr!=NULL){
        printf("%c-->",(currentptr)->datass);
        currentptr=(currentptr)->quy;
    }
 printf("NULL\n\n");
}
}

/*displaybits function*/

void displaybits(unsigned value){

unsigned c;
unsigned mask =1<<31;/*ÛíÑ ÝíåÇ ÚÔÇä ÊÝåã ÇßÊÑ*/

printf("%10u= ",value);

for(c=1;c<=32;c++){

putchar(value&mask?'1':'0');/*ÌÑÈåÇ ãä ÛíÑ ãÇÓß putchar(value?'1':'0');*/

value=value<<1;

    if(c%8==0){

        putchar(' ');
    }
}
putchar( '\n' );
}

/*linked list function*/

void insert( list *sptr,char value){

list newptr;/*pointer to new node*/
list previousptr;/*pointer to previous*/
list currentptr;/*pointer to current node in list*/

newptr=malloc(sizeof(Li));

if(newptr!=NULL){/*is space available*/

    newptr->datasa=value;/*place value in node*/
    newptr->ppp=NULL;/*node does not link to another node*/

previousptr =NULL;
currentptr =*sptr;

/*loop to find correct location in the list */
while(currentptr!=NULL&&value>currentptr->datasa){

    previousptr=currentptr;
    currentptr=currentptr->ppp;

}
/*insert new node at beginning of list*/

if(previousptr==NULL){

    newptr->ppp=*sptr;
    *sptr = newptr;

}

else{/*insert new node between previousptr and currentptr*/

    previousptr->ppp=newptr;
    newptr->ppp=currentptr;

}
}

else{
    printf("%c not inserted no memory available.\n",value);

}
}

char Delete(list *sptr,char value){

list previousptr;/*pointer to previous node in list*/
list currentptr;/*pointer to current node in list*/
list tempptr;/*temporary node pointer*/

/*delete first node*/
if(value==(*sptr)->datasa){

    tempptr=*sptr;/*hold onto node being removed*/
    *sptr=(*sptr)->ppp;/*de-thread the node*/
    free(tempptr);/*free the de-thread node*/

    return value;
}
else{
    previousptr=*sptr;
    currentptr=(*sptr)->ppp;


    /*loop to find the correct location in the list*/

    while(currentptr!=NULL&&currentptr->datasa!=value){

        previousptr=currentptr;/*walk to .....*/

        currentptr=currentptr->ppp;/*.....next node*/
    }
        /*delete node at currentptr*/
        if(currentptr!=NULL){

            tempptr=currentptr;
            previousptr->ppp=currentptr->ppp;

            free(tempptr);
            return value;

        }
    }

    return '\0';

}/*end function delete*/

/*return 1 if the list is empty , 0 otherwise*/

int islistempty(list sptr){

return sptr==NULL;
}

void printlist(list currentptr){

/*if list isempty*/
if(currentptr==NULL){

    printf("list is empty.\n\n");
}
else{

    printf("the list is:\n");

    while(currentptr!=NULL){

        printf("%c-->",currentptr->datasa);
        currentptr=currentptr->ppp;

    }

    printf("NULL\n\n");
}
}

/*mean,median,mode functions*/

void mean(const int a[],int size){

int i;
float total=0;
float mean;

for(i=0;i<size;i++){

    total+=a[i];

}

mean=(float)total/size;

printf("%f",mean);


}

void median(int a[],int size){

quickSort(a,0,size-1);

if(size%2==0){
printf("%f",((float)a[size/2]+(float)a[(size-2)/2])/(float)2);
}
else{

    printf("%f",(float)a[(size-1)/2]);
}
}

void mode(const int a[],int size,int k,int freq[k]){

int hold;
int j;
int i;

for(i=0;i<size;i++){


    ++freq[a[i]];

}

for(j=0;j<k;j++){

if(freq[j]<freq[j+1]){

hold=j+1;

}
}
 printf("%d",hold);

}

/*linear search function*/

int linearSearch( const int array[], int key, int size )
{
int n;
int hold=88888888;
 /* counter */
/* loop through array */
for ( n = 0; n < size; ++n ) {
if ( array[ n ] == key ) {
        hold=key;
printf("%d",n);
 /* return location of key*/
} /* end if */
}
if(hold!=key){

    printf("error");
}

}


/*fabinocci function*/
long fiii( long n )
{
   long result;

/* base case */
if ( n == 0 || n == 1 ) {
return n;
} /* end if */
if(n<0||n>20){

   printf("error");
   return 0;
}
else { /* recursive step */

return result=(fiii( n - 1 ) + fiii( n - 2 ));

}
} /* end else */

/* end function fibonacci */
void fibonacci(const int hold){

printf( "%ld\n",fiii(hold) );

}

/*convert to uppercase function*/

void convertToUppercase1(void){


char sentence[ 80 ]; /* create char array */
int i = 0; /* initialize counter i */

puts( "Enter a line of text:" );
fgets(sentence,80,stdin);/* use fgets to read line of text */

for(i=0;sentence[i]!='\0';i++){

if (islower(sentence[i]) ) {
  sentence[i] = toupper(sentence[i]);
}
printf("%c",sentence[i]);
}
}

/*convertToUppercase2 function*/
void convertToUppercase2(char sentence[],int size){

int i = 0; /* initialize counter i */

for(i=0;sentence[i]!='\0';i++){

if (islower(sentence[i]) ) {
  sentence[i] = toupper(sentence[i]);
}
printf("%c",sentence[i]);
}
}

/*binary search function*/

void printRow( const int b[], int low, int mid, int high )
{
int i;

for ( i = 0; i <= high; i++ ) {

if ( i < low || i > high ) {
printf( " " );
}

else if ( i == mid ) {
printf( "%3d*", b[ i ] );
}

else {
printf( "%3d ", b[ i ] );
}
}
printf( "\n" );
}


int binarySearch(const int b[],int searchKey,int low,int high)
{
int i;
int middle;
printf( "\nSubscripts:\n" );

for ( i = 0; i <= high; i++ ) {
printf( "%3d ", i );
}
printf( "\n" );

for ( i = 1; i <= 5 * high; i++ ) {
printf( "-" );
}
printf( "\n" );

while ( low <= high ) {

middle = ( low + high ) / 2;

printRow( b, low, middle, high );

if ( searchKey == b[ middle ] ) {
        printf("keynumber at elemen:%d",middle);
return middle;
}

else if ( searchKey < b[ middle ] ) {
high = middle - 1;
}

else {
low = middle + 1;
}
}
if(searchKey!=b[middle]){

    printf("not found");
}
}

/*roll dice function*/
void rolldice(int a[],int size){

int i;
int j;
int b[7]={0};

srand( time( NULL ) );

for(i=0;i<size;i++){

    a[i]=1+rand()%6;


    b[a[i]]++;

}
for(j=1;j<=6;++j){

   printf("frequncy of %d is %d\n",j,b[j]);

}
printf("total is %d",b[1]+b[2]+b[3]+b[4]+b[5]+b[6]);
}

/*histograms function*/

void histogramNumber(int number){

int j;

for(j=1;j<=number;j++){

      printf( "%c", '*' );
}
}


void histogramArray(int a[],int size){

int i;
int j;

printf("%9s%10s%13s\n","order","value","histogram");

for(i=0;i<size;i++){

printf("%7d%10d         ",i,a[i]);

for(j=1;j<=a[i];j++){

      printf( "%c", '*' );
}
printf( "\n" );
}
}

/*argument list function*/
double printArguments( int i, ... ){

double value = 0; /* initialize total */
int j;

va_list ap; /* stores information needed by va_start and va_end */
va_start( ap, i );
/* process variable length argument list */

for(j=1;j<=i;j++){

value += va_arg( ap, double );
 va_end( ap );

printf("%0.3f\n",value);
if(value!=0){
    value=0;
}
}
} /* end for */









