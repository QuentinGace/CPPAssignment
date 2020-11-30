load Richt100t5.dat;
load Richt200t5.dat;
load Richt400t5.dat;
x100 = Richt100t5(:,1);
x200 = Richt200t5(:,1);
x400 = Richt400t5(:,1);

F100 = Richt100t5(:,5);
F200 = Richt200t5(:,5);
F400 = Richt400t5(:,5);
F400A = Richt400t5(:,6);


plot(x100,F100,'b',x200,F200,'g',x400,F400,'k',x400,F400A,'r');
title('Richtmyer SET2 & t=5')
xlabel('x')
ylabel('f(x,5)')
legend({'f N=100','f N=200','f N=400','f N=400 Analytic'},'Location','northwest')
axis([-50 50 0 1])
