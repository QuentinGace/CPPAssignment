load ImpFTBS400t10.dat;
x = ImpFTBS400t10(:,1);
F1 = ImpFTBS400t10(:,3);
F1A = ImpFTBS400t10(:,4);
F2 = ImpFTBS400t10(:,5);
F2A = ImpFTBS400t10(:,6);


plot(x,F1,'b',x,F1A,'r',x,F2,'c',x,F2A,'m');
title('Implicit FTBS with N=400 & t=10')
xlabel('x')
ylabel('f(x,10)')
legend({'f SET1','f SET1-Analytic','f SET2','f SET2-Analytic'},'Location','northwest')
axis([-50 50 0 1])
