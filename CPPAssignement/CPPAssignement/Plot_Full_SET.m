load Richt100t10.dat;
load Richt200t10.dat;
load Richt400t10.dat;
x100 = Richt100t10(:,1);
x200 = Richt200t10(:,1);
x400 = Richt400t10(:,1);

F100 = Richt100t10(:,5);
F200 = Richt200t10(:,5);
F400 = Richt400t10(:,5);
F400A = Richt400t10(:,6);


plot(x100,F100,'b',x200,F200,'g',x400,F400,'k',x400,F400A,'r');
title('Richtmyer SET2 & t=10')
xlabel('x')
ylabel('f(x,10)')
legend({'f N=100','f N=200','f N=400','f N=400 Analytic'},'Location','northwest')
axis([-50 50 -0.5 1.02])
