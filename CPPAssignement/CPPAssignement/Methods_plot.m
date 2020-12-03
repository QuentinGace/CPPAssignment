load ExpFTBS400t5.dat;
load ImpFTBS400t5.dat;
load LaxWen400t5.dat;
load Richt400t5.dat;

x = Richt400t5(:,1);
A = Richt400t5(:,4);

E = ExpFTBS400t5(:,3);
I = ImpFTBS400t5(:,3);
L = LaxWen400t5(:,3);
W = Richt400t5(:,3);

plot(x,E,x,I,x,L,x,W,x,A,'k');
title('All Methods SET1 & t=5 & N=400')
xlabel('x')
ylabel('f(x,5)')
legend({'Explicit FTBS','Implicit FTBS','Lax-Wendroff','Richtmyer ','Analytic'},'Location','northwest')
axis([-50 50 -0.2 1])



