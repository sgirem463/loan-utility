// A unility function to calculate month loan payment given principal, interest rate
// and number of months

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#define TRUE    1
#define FALSE   0

int main(int argc, char *argv[])
{
        double  i1, i2, pr, in, in2, pa, mon_in, mon_in2, periods, tmp, accu, accu_int;
        int     i, detailed = FALSE;
        char c;


        // usage check
        if (argc != 4 && argc != 5) {
                printf("\nUsage: loan [-d] <principal> <interest rate> [interest rate] <# periods(months)>\n\n");
                printf("  The interest rates should be in %%. The second rate in [ ] is optional,\n");
                printf("  which forms a range with the first rate argument for the calculation\n");
                printf("  of a payment table with different rates. See examples.\n\n");
                printf("  option 'd' means detailed mode, applies to single interest rate case\n");
                printf("  the interest and principal portions of the every month's payment\n");
                printf("  will be given along with the accmulated principal payment\n\n");
                printf("  example: loan 10000.00 9 60\n");
                printf("           $10,000.00 loan at 9.0%% for 60 months\n\n");
                printf("  example: loan -d 250000 7.25 360\n");
                printf("           detailed mode $250,000.00 loan at 7.25%% for 360 months(30 years)\n\n");
                printf("  example: loan 250000 6 10 360\n");
                printf("           print monthly payment comparison for a 30-year $250,000.00 loan\n");
                printf("           where the interest rate is between 6.00%% and 10.00%%\n\n");
                exit(1);
        }


        // try to get command option(s)
        while ((c = getopt(argc, argv, "d")) != -1) {
                switch (c) {
                case 'd':
                        detailed = TRUE;
                        break;
                default:
                        break;
                }
        }


        // Convert the command line arguments
        if (argc == 4) {

                // single interest rate non-detailed mode

                pr = atof(argv[1]);
                in = atof(argv[2]);
                periods = atof(argv[3]);
        } else if (detailed) {

                // detailed mode, always single interest rate

                pr = atof(argv[2]);
                in = atof(argv[3]);
                periods = atof(argv[4]);
        } else {

                // interest range will be truncated to integers

                pr = atof(argv[1]);
                in = (double) atoi(argv[2]);
                in2 = (double) atoi(argv[3]);
                periods = atof(argv[4]);
        }


        // Check for unreasonable arguments
        if (in < 0 || in > 100.00) {
                printf("interest rate should be between 0 and 100\n");
                exit(1);
        }
        if (periods <= 0) {
                printf("number of periods should be a positive integer\n");
                exit(1);
        }


        // Start processing
        printf("principal \t\t= %.2f\n", pr);
        printf("number of periods \t= %.f\n", periods);
        if (argc == 4 || detailed) {
                // case for a single interest rate
                mon_in = in / 1200.0;
                tmp = mon_in * 100.0;
                printf("interest rate \t\t= %.4f%%\n", in);
                printf("monthly interest rate \t= %.4f%%\n", tmp);
                pa = pr / ((1.0 - pow(1 + mon_in, 0 - periods)) / mon_in);
                printf("monthly payment \t= %.3f\n", pa);


                // monthly details
                if (detailed) {
                        printf("\ntotal payment \t\t= %11.3f\n", pa * periods);
                        printf("total interest payment \t= %11.3f\n", pa * periods - pr);
                        printf("\nmonth     interest part   principal part   accu. principal   accu. interest\n");
                        for (accu = 0, accu_int = 0, i = 1; i <= periods; i++) {
                                tmp = pow(1 + mon_in, (double)(i - 1))
                                        * (pa - mon_in * pr);
                                accu += tmp;
                                accu_int = accu_int + pa - tmp;
                                printf("%5d       %9.3f        %9.3f       %11.3f       %11.3f\n",
                                        i, pa - tmp, tmp, accu, accu_int);
                        }
                }

        } else {

                // case for a interest rate range, calculate monthly payments
                // at different rates at 0.125% interval
                printf("interest rate \t\t= %.4f%% - %.4f%%\n\n", in, in2);

                for (i1 = in; i1 <= in2; i1 += 0.125) {
                        mon_in = i1 / 1200.0;
                        pa = pr / ((1.0 - pow(1 + mon_in, 0 - periods)) / mon_in);
                        printf("interest rate = %.4f  \tmonthly payment = %.3f\n", i1, pa);

                }
        }
}
