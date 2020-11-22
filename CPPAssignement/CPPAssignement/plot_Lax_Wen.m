load LaxWen400t5.dat;
x = LaxWen400t5(:,1);
F1 = LaxWen400t5(:,3);
F1A = LaxWen400t5(:,4);
F2 = LaxWen400t5(:,5);
F2A = LaxWen400t5(:,6);


plot(x,F1,'b',x,F1A,'r',x,F2,'c',x,F2A,'m');
title('Lax-Wendroff with N=400 & t=5')
xlabel('x')
ylabel('f(x,5)')
legend({'f SET1','f SET1-Analytic','f SET2','f SET2-Analytic'},'Location','northwest')
axis([-50 50 -0.2 1])
