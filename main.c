#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<conio.h>

double limitvalueY[100];
int num;
double h;

double equation(double x)
{
    //return 1/(1+x*x);
    //return sqrt(1+x*x);
    //return exp(pow(x,2));
    //return sqrt(1+x*x*x);
    //return x*x;
      return sqrt(x);
}

double TrapezoidalFormula()
{
 double sum=0;
 int loop;
 double middle=(limitvalueY[0]+limitvalueY[num]);
 for(loop=1;loop<=num-1;loop++)
 {
   sum+=limitvalueY[loop];
 }
 return h/2*(middle+2*sum);
}


double Simpson1and3Rule()
{
  int loop;
  double secondsum=0,thirdsum=0;
  double firstsum=(limitvalueY[0]+limitvalueY[num]);
  for(loop=1;loop<=num-1;loop++)
  {
    if(loop%2==0)
        secondsum+=limitvalueY[loop];
    else
        thirdsum+=limitvalueY[loop];
  }
  return h/3*(firstsum+4*thirdsum+2*secondsum);
}

double Simpson3and8Rule()
{
  int loop;
  double secondsum=0,thirdsum=0;
  double firstsum=(limitvalueY[0]+limitvalueY[num]);
  for(loop=1;loop<=num-1;loop++)
  {
    if(loop%3==0)
        secondsum+=limitvalueY[loop];
    else
        thirdsum+=limitvalueY[loop];
  }
  return 3*h/8*(firstsum+2*secondsum+3*thirdsum);
}

int main()
{
    int a,b,loop;
    double x;

    printf("Enter the Upper Limit\n");
    scanf("%d",&b);
    printf("Enter the Lower Limit\n");
    scanf("%d",&a);
    printf("How many number you want to enter\n");
    scanf("%d",&num);

    h=(double)(b-a)/num;
    double x0=(double)a;
    limitvalueY[0]=equation(x0);

    printf("\nX %lf \t\t\t\t",x0);
    printf("Y %lf\n",limitvalueY[0]);

    for(loop=1;loop<=num;loop++)
    {
      x=x0+h;
      printf("X %lf \t\t\t\t",x);
      limitvalueY[loop]=equation(x);
      printf("Y %lf\n",limitvalueY[loop]);
      x0=x;
    }

    double trapans=TrapezoidalFormula();
    printf("\n\nThe trapezoidal ans is %lf",trapans);
    double sim13ans=Simpson1and3Rule();
    printf("\nThe Simpson 1/3 Rule ans is %lf",sim13ans);
    double sim38ans=Simpson3and8Rule();
    printf("\nThe Simpson 3/8 Rule ans is %lf",sim38ans);

    return 0;
}
