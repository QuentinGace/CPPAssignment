load ExpFTBS100t10.dat;
load ExpFTBS200t10.dat;
load ExpFTBS400t10.dat;
x100 = ExpFTBS100t10(:,1);
x200 = ExpFTBS200t10(:,1);
x400 = ExpFTBS400t10(:,1);

F100 = ExpFTBS100t10(:,5);
F200 = ExpFTBS200t10(:,5);
F400 = ExpFTBS400t10(:,5);
F400A = ExpFTBS400t10(:,6);


plot(x100,F100,'b',x200,F200,'g',x400,F400,'k',x400,F400A,'r');
title('Explicit FTBS SET2 & t=10')
xlabel('x')
ylabel('f(x,10)')
legend({'f N=100','f N=200','f N=400','f N=400 Analytic'},'Location','northwest')
axis([0 30 0 1.02])
