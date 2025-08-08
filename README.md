# loan-utility
This is a Linux command line utility for calculating loan payment given principl, interest rate and number of months. It can compare payments in for a range of interest rates, it can also give details about principal and interest payments of each month.

### Usage:
Usage: loan [-d] <principal> <interest rate> [interest rate] <# periods(months)>

  The interest rates should be in %. The second rate in [ ] is optional,
  which forms a range with the first rate argument for the calculation
  of a payment table with different rates. See examples.

  option 'd' means detailed mode, applies to single interest rate case
  the interest and principal portions of the every month's payment
  will be given along with the accmulated principal payment

  example: loan 20000.00 5 48
           $20,000.00 loan at 5.0% for 60 months

      principal 		= 20000.00
      number of periods 	= 48
      interest rate 		= 5.0000%
      monthly interest rate 	= 0.4167%
      monthly payment 	= 460.586

  example: loan -d 500000 5.25 360
           detailed mode $500,000.00 loan at 5.25% for 360 months(30 years)

      principal 		= 500000.00
      number of periods 	= 360
      interest rate 		= 5.2500%
      monthly interest rate 	= 0.4375%
      monthly payment 	= 2761.019
      
      total payment 		=  993966.664
      total interest payment 	=  493966.664
      
      month     interest part   principal part   accu. principal   accu. interest
          1        2187.500          573.519           573.519          2187.500
          2        2184.991          576.028          1149.546          4372.491
          3        2182.471          578.548          1728.094          6554.962
          4        2179.940          581.079          2309.173          8734.901
          5        2177.397          583.621          2892.794         10912.299
          6        2174.844          586.174          3478.968         13087.143
          7        2172.280          588.739          4067.707         15259.422
          8        2169.704          591.315          4659.022         17429.126
          ....


  example: loan 500000 4 6 360
           print monthly payment comparison for a 30-year $500,000.00 loan
           where the interest rate is between 4.00% and 6.00%

      principal 		= 500000.00
      number of periods 	= 360
      interest rate 		= 4.0000% - 6.0000%
      
      interest rate = 4.0000  	monthly payment = 2387.076
      interest rate = 4.1250  	monthly payment = 2423.249
      interest rate = 4.2500  	monthly payment = 2459.699
      interest rate = 4.3750  	monthly payment = 2496.426
      interest rate = 4.5000  	monthly payment = 2533.427
      interest rate = 4.6250  	monthly payment = 2570.698
      interest rate = 4.7500  	monthly payment = 2608.237
      interest rate = 4.8750  	monthly payment = 2646.041
      interest rate = 5.0000  	monthly payment = 2684.108
      interest rate = 5.1250  	monthly payment = 2722.435
      interest rate = 5.2500  	monthly payment = 2761.019
      interest rate = 5.3750  	monthly payment = 2799.856
      interest rate = 5.5000  	monthly payment = 2838.945
      interest rate = 5.6250  	monthly payment = 2878.282
      interest rate = 5.7500  	monthly payment = 2917.864
      interest rate = 5.8750  	monthly payment = 2957.689
      interest rate = 6.0000  	monthly payment = 2997.753

