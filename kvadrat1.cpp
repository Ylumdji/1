#include <stdio.h>
#include <math.h>

int solve(double  a,double b ,double c,double * x1,double *x2);
int solve(double  a,double b ,double c,double * x1,double *x2){
      if (a==(double)0){
           if (b==(double)0){
               if (c==(double)0){
                   return -1;
               }else{
                   return 0 ;
               }
           }else{
              *x1=(-c)/b;
              return 1;
           }
      }else{
            if (b==(double)0){
                    if (c < 0){
                       *x1=sqrt((-c)/a);
                       *x2=-sqrt((-c)/a);
                       return 2;
                    }
                    if (c==(double)0){
                        *x1=0;
                        return 1;
                    }
                    if (c>0){
                        return 0;
                    }
            }else{
                double discriminant=0;
                discriminant = b*b-4*a*c;
                if (discriminant > 0){
                       *x1 = (-b+sqrt(discriminant))/(2*a);
                       *x2 = (-b-sqrt(discriminant))/(2*a);
                       return 2;
                }
                if (discriminant==(double)0){
                       *x1 = (-b)/(2*a);
                       return 1;
                }
                if (discriminant < 0){
                       return 0;
                }
            }

      }
}
int main(){


    printf("           SOLUTION OF QUADRATIC EQUATION: a(x^2)+b(x)+c=0\n");
    printf("ENTER COEFFICIENT VALUES a , b , c\n");


    double a=0.0, b=0.0 , c = 0.0 , x1=0.0, x2=0.0 ;



    if(scanf("%lf %lf %lf",&a,&b,&c)!=3){
            printf("!!!WRONG FORMAT!!!\nPLEASE,TRY AGAIN");
            return 0;
    }



    int korni;
    korni = solve(a,b,c,&x1,&x2);



    switch (korni){
       case -1 : printf("Infinite number of roots");break;
       case  0 : printf("no roots");break;
       case  1 : printf("x = %lf",x1);break;
       case  2 : printf("x_1 = %lf\nx_2 = %lf",x1,x2);break;
       default : printf("CHETO NE TAK");
    }
    return 0 ;
}
