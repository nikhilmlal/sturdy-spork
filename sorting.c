#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Selection_Sort(int[], int, FILE *);
void Bubble_Sort(int[], int, FILE *);

int counter=0;
double total_time;
clock_t start_time, end_time;

int *Sort_Array(int *a, int n){
  int temp;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(a[i]>a[j]){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
  return a;
}

int main(int argc, char const *argv[]) {

  int n;
  printf("Enter the range :\n");
  scanf("%d", &n);
  int ar[n], arr[n];

  for(int i=0; i<n; i++){
    ar[i]=rand()%100000;
  }
  *arr=*Sort_Array(ar, n);

  FILE *fp;
  fp=fopen("sort_results.txt", "a");

  Selection_Sort(ar, n, fp);
  Selection_Sort(arr, n, fp);

  Bubble_Sort(ar, n, fp);
  Bubble_Sort(arr, n, fp);

  return 0;
}

void Print_Results(double temp, FILE *fp, int n){
  if(counter==0){
    char s1[]="Sorting Algorithm", s2[]="Time for a sorted list", s3[]="Time for an unsorted list";
    fprintf(fp, "\n");
    fprintf(fp, "%s",s1);
    fprintf(fp, "\t%s",s2);
    fprintf(fp, "\t%s\n",s3);
    counter++;
  }
  if(counter==1){
    fprintf(fp, "\n");
    switch (n) {
      case 1:fprintf(fp,"%s","Selection_Sort :");
      break;
      case 2:fprintf(fp,"%s","Bubble_Sort    :" );
      break;
      default :fprintf(fp,"%s","Error !!" );
      break;
    }
  }
  fprintf(fp,"\t%f",temp);
  counter=((counter+1)%3)+((counter+1)/3);
}

void Selection_Sort(int ar[], int n, FILE *fp){
  start_time = clock();

  int temp;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(ar[i]>ar[j]){
        temp=ar[i];
        ar[i]=ar[j];
        ar[j]=temp;
      }
    }
  }

  end_time=clock();
  total_time = ((double)(end_time-start_time))/CLOCKS_PER_SEC;
  Print_Results(total_time, fp, 1);
}

void Bubble_Sort(int ar[], int n, FILE *fp){
  start_time=clock();

  int temp, flag;
  for(int x=0; x<n&&flag; x++){
    for(int i=0; i<n-1; i++){
      flag=0;
      for(int j=i+1; j<n;j=n){
        if(ar[i]>ar[j]){
          flag++;
          temp=ar[i];
          ar[i]=ar[j];
          ar[j]=temp;
        }
      }
    }
  }

  end_time=clock();
  total_time=((double)(end_time-start_time))/CLOCKS_PER_SEC;
  Print_Results(total_time, fp, 2);
}
