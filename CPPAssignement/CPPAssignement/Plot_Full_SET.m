load ExpFTBS100t5.dat;
load ExpFTBS200t5.dat;
load ExpFTBS400t5.dat;
x100 = ExpFTBS100t5(:,1);
x200 = ExpFTBS200t5(:,1);
x400 = ExpFTBS400t5(:,1);

F100 = ExpFTBS100t5(:,3);
F200 = ExpFTBS200t5(:,3);
F400 = ExpFTBS400t5(:,3);
F400A = ExpFTBS400t5(:,4);


plot(x100,F100,'b',x200,F200,'g',x400,F400,'k',x400,F400A,'r');
title('Explicit FTBS SET1 & t=5')
xlabel('x')
ylabel('f(x,5)')
legend({'f N=100','f N=200','f N=400','f N=400 Analytic'},'Location','northwest')
axis([-50 50 0 1])
