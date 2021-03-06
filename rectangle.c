/****************************************************************************
*                                                                           *
* Author            : Julian Proko                                          *
* Purpose           : C Programming Challenge                               *
* Version           : 1.0                                                   *
* Description       : Calculate and display rectangle perimeter and area    *
* Date Created      : 17/04/2021                                            *
* Last Modification : 17/04/2021                                            *
*                                                                           *
*****************************************************************************/
#include <stdio.h>

int main()
{
    //we hardcore the width and height of the rectangle
    double width = 84.13;
    double height = 52.15;

    //we calculate the perimeter and the area of the rectangle
    double perimeter = 2*(width+height);
    double area = width * height;

    //we print the calculated results
    printf("Rectangle width : %.2lf \n", width); 
    printf("Rectangle height : %.2lf \n", height);
    printf("Rectangle perimeter: %.2lf \n", perimeter);
    printf("Rectangle area: %.2lf \n", area);

    return 0;
}
