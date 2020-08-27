#include <stdio.h>
#include <assert.h>
#include <math.h>

const int inf = -1;

//----------------------------------------------
//! Solves a square equation ax2+bx+c=0
//! @param[in]  a  a-coefficient
//! @param[in]  b  b-coefficient
//! @param[in]  c  c-coefficient
//! @param[out] x1 Pointer to the 1st root
//! @param[out] x2 Pointer to the 2nd root
//----------------------------------------------

int SolveSquare(double a, double b, double c, double* x1, double* x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != 0);
    assert(x2 != 0);
    assert(x1 != x2);

    printf("\nSolving the equation:\n%lgx^2+%lgx+%lg=0\n\n", a, b, c);

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0) return inf;
            else /* if c != 0 */
            return 0;
        }
        else /* if b != 0 */
        {
            *x1 = -c/b;
            return 1;
        }
    }
    else /* if a != 0 */
    {
        double D = b*b - 4*a*c;

        if (D < 0)
        {
            return 0;
        }

        else if (D == 0)
        {
            *x1 = -b/(2*a);
            return 1;
        }

        else /* if D > 0 */
        {
            *x1 = (-b + sqrt(D))/(2*a);
            *x2 = (-b - sqrt(D))/(2*a);
            return 2;
        }
    }
}

int main()
{
    printf("Welcome! This is square equation solver!\n\nInput a, b and c coefficients of your equation.\n\n");

    double a=0, b=0, c=0;
    scanf("%lg %lg %lg", &a, &b, &c);

    double x1 = 0, x2 = 0;

    int k = SolveSquare(a, b, c, &x1, &x2);

    switch(k)
    {
        case 0: printf("This equation hasn't any roots.\n");
                break;

        case 1: printf("This equation has one root:\n%lg", x1);
                break;

        case 2: printf("This equation has two roots:\n%lg\n%lg", x1, x2);
                break;

        case inf: printf("This equation has infinite amount of roots.\n");
                break;

        default: printf("ERROR!\nThis equation has %lg roots.", k);
    }

    return 0;
}
