double calc(double x, double y, double z)
 {
   double a;
   if (x!=y&&z!=0&&x!=0&&sin(y)!=0&&x>0&&x-y>0)
    {
	a=pow(x,(y+1))/pow((x-y),(1/z))+(8*y-z/x)+pow(x,(1/fabs(sin(y))));
    return a;
    }
   else
    return NAN;
}