x_max = 20;
Q0 = 0.01;
x = [0:0.1:20];
Q = Q0*(1+log(9*(x/x_max)+1));

plot(x,Q)