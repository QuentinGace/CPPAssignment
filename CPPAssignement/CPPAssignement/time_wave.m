load ExpFTBS400t5.dat;
x5 = ExpFTBS400t5(:,1);
A5 = ExpFTBS400t5(:,6);
R5 = ExpFTBS400t5(:,5);

load ExpFTBS400t10.dat;
x10 = ExpFTBS400t10(:,1);
A10 = ExpFTBS400t10(:,6);
R10 = ExpFTBS400t10(:,5);

plot(x5,A5,'k',x5,R5,'r',x10,A10,'b',x10,R10,'m');
title('Wave propagation SET2 & N=400')
xlabel('x')
ylabel('f(x,t)')
legend({'t5 Analytical','t5 Explicit FTBS','t10 Analytical','t10 Explicit FTBS'},'Location','northwest')
axis([-10 30 -0.02 0.55])