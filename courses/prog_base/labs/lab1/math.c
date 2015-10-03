double calc(double x, double y, double z) {
   double a;
	a=pow(x,(y+1))/pow((x-y),(1/z))+(8*y-z/x)+pow(x,(1/abs(sin(y))));
   return a;
}
