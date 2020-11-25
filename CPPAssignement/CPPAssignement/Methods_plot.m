load ExpFTBS400t10.dat;
load ImpFTBS400t10.dat;
load LaxWen400t10.dat;
load Richt400t10.dat;

x = Richt400t10(:,1);
A = Richt400t10(:,4);

E = ExpFTBS400t10(:,3);
I = ImpFTBS400t10(:,3);
L = LaxWen400t10(:,3);
W = Richt400t10(:,3);

plot(x,E,x,I,x,L,x,W,x,A,'k');
title('All Methods SET1 & t=10 & N=400')
xlabel('x')
ylabel('f(x,10)')
legend({'Explicit FTBS','Implicit FTBS','Lax-Wendroff','Richtmyer ','Analytic'},'Location','northwest')
axis([-50 50 -0.2 1])



