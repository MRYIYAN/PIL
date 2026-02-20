double mif( double *x ) 
{
    double y;
    *x *= 3;
    y = (*x)++;
    return y;


}