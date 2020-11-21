load ImpFTBS100t10.dat;
load ImpFTBS200t10.dat;
load ImpFTBS400t10.dat;
x100 = ImpFTBS100t10(:,1);
x200 = ImpFTBS200t10(:,1);
x400 = ImpFTBS400t10(:,1);

F100 = ImpFTBS100t10(:,3);
F200 = ImpFTBS200t10(:,3);
F400 = ImpFTBS400t10(:,3);
F400A = ImpFTBS400t10(:,4);


plot(x100,F100,'b',x200,F200,'g',x400,F400,'k',x400,F400A,'r');
title('Implicit FTBS SET1 & t=10')
xlabel('x')
ylabel('f(x,10)')
legend({'f N=100','f N=200','f N=400','f N=400 Analytic'},'Location','northwest')
axis([-50 50 0 1])
