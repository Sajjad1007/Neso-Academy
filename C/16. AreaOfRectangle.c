#include <stdio.h>

struct point{
    int x, y;
};

struct rectangle{
    struct point upper_left;
    struct point lower_right;
};

int area(struct rectangle r)
{
    int length = r.lower_right.x - r.upper_left.x;
    int breadth = r.upper_left.y - r.lower_right.y;
    return length * breadth;
}

int main(void)
{
    struct rectangle r;
    printf("Enter upper  left coordinate of the rectangle : ");
    scanf("%d %d", &r.upper_left.x, &r.upper_left.y);
    printf("Enter lower right coordinate of the rectangle : ");
    scanf("%d %d", &r.lower_right.x, &r.lower_right.y);
    printf("\nArea of the rectangle = %d\n", area(r));
    return 0;
}

/*
Enter upper  left coordinate of the rectangle : 3 8
Enter lower right coordinate of the rectangle : 14 2

Area of the rectangle = 66
*/
