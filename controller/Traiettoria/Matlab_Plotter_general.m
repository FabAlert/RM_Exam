close all; clear all; clc;

%%plot of Posizione desiderata in 3D
A = load('NORID_NOFORCE_MKD/DesiredPosFile.txt');
[r,c] = size(A);
a1 = zeros(r/6,1); a2 = a1; a3 = a1; a4 = a1; a5 = a1; a6 = a1;
cont = 1;

for i=1:6:r
    a1(cont) = A(i);
    a2(cont) = A(i+1);
    a3(cont) = A(i+2);
    a4(cont) = A(i+3);
    a5(cont) = A(i+4);
    a6(cont) = A(i+5);
    cont = cont +1;
end

t = linspace(0,r/600,r/6);

figure(1);
plot3(a1,a2,a3);
grid on;
title('Posizione desiderata');

figure(2);
subplot(3,1,1);
plot(t,a4);
grid on; 
title('Desired pitch');
subplot(3,1,2);
plot(t,a5);
grid on; 
title('Desired yaw');
subplot(3,1,3);
plot(t,a6);
grid on; 
title('Desired roll');

pause(); close all; clear all;

%%plot of posizione desiderata vs actual and errore per NoRidNoForce
A = load('NORID_NOFORCE_MKD/DesiredPosFile.txt');
B = load('NORID_NOFORCE_MKD/ActualPoseFile.txt');

[r,c] = size(A);
a1 = zeros(r/6,1); a2 = a1; a3 = a1; a4 = a1; a5 = a1; a6 = a1;
b1 = zeros(r/6,1); b2 = b1; b3 = b1; b4 = b1; b5 = b1; b6 = b1;

cont = 1;

for i=1:6:r
    a1(cont) = A(i);   b1(cont) = B(i);
    a2(cont) = A(i+1); b2(cont) = B(i+1);
    a3(cont) = A(i+2); b3(cont) = B(i+2);
    a4(cont) = A(i+3); b4(cont) = B(i+3);
    a5(cont) = A(i+4); b5(cont) = B(i+4);
    a6(cont) = A(i+5); b6(cont) = B(i+5);
    cont = cont +1;
end

t = linspace(0,r/600,r/6);

figure(3);
subplot(3,2,1);
plot(t,a1,'--');
hold on;
plot(t,b1);
grid on; 
legend('Desired Pos', 'Actual Pos');
title('X');
subplot(3,2,3);
plot(t,a2,'--');
hold on;
plot(t,b2);
grid on; 
legend('Desired Pos', 'Actual Pos');
title('Y');
subplot(3,2,5);
plot(t,a3,'--');
hold on;
plot(t,b3);
grid on; 
legend('Desired Pos', 'Actual Pos');
title('Z');
subplot(3,2,2);
plot(t,a4,'--');
hold on;
plot(t,b4);
grid on; 
legend('Desired Pos', 'Actual Pos');
title('Pitch');
subplot(3,2,4);
plot(t,a5,'--');
hold on;
plot(t,b5);
grid on; 
legend('Desired Pos', 'Actual Pos');
title('Yaw');
subplot(3,2,6);
plot(t,a6,'--');
hold on;
plot(t,b6);
grid on; 
legend('Desired Pos', 'Actual Pos');
title('Roll');

pause(); close all; clear all;

%%Plot of giunti vs giunti con ridondanza 
A = load('NORID_NOFORCE_MKD/QFile.txt');
B = load('RID1_NOFORCE/QFile.txt');
C = load('RID2_NOFORCE/QFile.txt');

[r1,c] = size(A);
[r2,c] = size(B);
[r3,c] = size(C);
dim = min([r1 r2 r3]);
a1 = zeros(dim/7,1); a2 = a1; a3 = a1; a4 = a1; a5 = a1; a6 = a1; a7 = a1;
b1 = zeros(dim/7,1); b2 = b1; b3 = b1; b4 = b1; b5 = b1; b6 = b1; b7 = b1;
c1 = zeros(dim/7,1); c2 = c1; c3 = c1; c4 = c1; c5 = c1; c6 = c1; c7 = c1;

cont = 1;

for i=1:7:dim
    a1(cont) = A(i);   b1(cont) = B(i);   c1(cont) = C(i); 
    a2(cont) = A(i+1); b2(cont) = B(i+1); c2(cont) = C(i+1);
    a3(cont) = A(i+2); b3(cont) = B(i+2); c3(cont) = C(i+2);
    a4(cont) = A(i+3); b4(cont) = B(i+3); c4(cont) = C(i+3);
    a5(cont) = A(i+4); b5(cont) = B(i+4); c5(cont) = C(i+4);
    a6(cont) = A(i+5); b6(cont) = B(i+5); c6(cont) = C(i+5);
    a7(cont) = A(i+6); b7(cont) = B(i+6); c7(cont) = C(i+6);
    cont = cont +1;
end

t = linspace(0,dim/700,dim/7);

figure(4);
subplot(4,2,1);
plot(t,a1,'--');
hold on;
plot(t,b1);
hold on;
plot(t,c1);
grid on; 
legend('No Rid', 'Manip' ,'Dist Giunti');
title('Q1');
subplot(4,2,2);
plot(t,a2,'--');
hold on;
plot(t,b2);
hold on;
plot(t,c2);
grid on; 
legend('No Rid', 'Manip' ,'Dist Giunti');
title('Q2');
subplot(4,2,3);
plot(t,a3,'--');
hold on;
plot(t,b3);
hold on;
plot(t,c3);
grid on; 
legend('No Rid', 'Manip' ,'Dist Giunti');
title('Q3');
subplot(4,2,4);
plot(t,a4,'--');
hold on;
plot(t,b4);
hold on;
plot(t,c4);
grid on; 
legend('No Rid', 'Manip' ,'Dist Giunti');
title('Q4');
subplot(4,2,5);
plot(t,a5,'--');
hold on;
plot(t,b5);
hold on;
plot(t,c5);
grid on; 
legend('No Rid', 'Manip' ,'Dist Giunti');
title('Q5');
subplot(4,2,6);
plot(t,a6,'--');
hold on;
plot(t,b6);
hold on;
plot(t,c6);
grid on; 
legend('No Rid', 'Manip' ,'Dist Giunti');
title('Q6');
subplot(4,2,7);
plot(t,a7,'--');
hold on;
plot(t,b7);
hold on;
plot(t,c7);
grid on; 
legend('No Rid', 'Manip' ,'Dist Giunti');
title('Q7');

pause(); close all; clear all;

%%Plot of Posizione Desiderata vs Actual Forza lienare Caso unitario caso MKD
A = load('RID1_NOFORCE/DesiredPosFile.txt');
B = load('RID1_LINFORCE_MKD/CompliancePosFile.txt');
D = load('RID1_LINFORCE_M15K1D5/CompliancePosFile.txt');
C = load('RID1_LINFORCE_M15K50D5/CompliancePosFile.txt');


[r1,c] = size(A);
[r2,c] = size(B);
[r3,c] = size(C);
[r4,c] = size(D);


dim = min([r1 r2 r3 r4]);
a1 = zeros(dim/6,1); a2 = a1; a3 = a1; a4 = a1; a5 = a1; a6 = a1;
b1 = zeros(dim/6,1); b2 = b1; b3 = b1; b4 = b1; b5 = b1; b6 = b1;
c1 = zeros(dim/6,1); c2 = c1; c3 = c1; c4 = c1; c5 = c1; c6 = c1;
d1 = zeros(dim/6,1); d2 = d1; d3 = d1; d4 = d1; d5 = d1; d6 = d1;


cont = 1;

for i=1:6:dim
    a1(cont) = A(i);   b1(cont) = B(i);   c1(cont) = C(i);   d1(cont) = D(i);   
    a2(cont) = A(i+1); b2(cont) = B(i+1); c2(cont) = C(i+1); d2(cont) = D(i+1); 
    a3(cont) = A(i+2); b3(cont) = B(i+2); c3(cont) = C(i+2); d3(cont) = D(i+2); 
    a4(cont) = A(i+3); b4(cont) = B(i+3); c4(cont) = C(i+3); d4(cont) = D(i+3); 
    a5(cont) = A(i+4); b5(cont) = B(i+4); c5(cont) = C(i+4); d5(cont) = D(i+4); 
    a6(cont) = A(i+5); b6(cont) = B(i+5); c6(cont) = C(i+5); d6(cont) = D(i+5); 
    cont = cont +1;
end

t = linspace(0,dim/600,dim/6);

figure(5);
subplot(3,1,1);
plot(t,a1,'--');
hold on;
plot(t,b1);
hold on;
plot(t,c1);
hold on;
plot(t,d1);
grid on; 
legend('No Force', 'M = 1, K = 1, D = 1' ,'M = 15, K = 50, D = 5', 'M = 15, K = 1, D = 5');
title('X');
subplot(3,1,2);
plot(t,a2,'--');
hold on;
plot(t,b2);
hold on;
plot(t,c2);
hold on;
plot(t,d2);
grid on; 
legend('No Force', 'M = 1, K = 1, D = 1' ,'M = 15, K = 50, D = 5', 'M = 15, K = 1, D = 5');
title('Y');
subplot(3,1,3);
plot(t,a3,'--');
hold on;
plot(t,b3);
hold on;
plot(t,c3);
hold on;
plot(t,d3);
grid on; 
legend('No Force', 'M = 1, K = 1, D = 1' ,'M = 15, K = 50, D = 5', 'M = 15, K = 1, D = 5');
title('Z');

figure(6);
subplot(3,3,1);
plot(t,a1-b1);
grid on; 
title('Xde');
subplot(3,3,4);
plot(t,a2-b2);
grid on; 
title('Yde');
subplot(3,3,7);
plot(t,a3-b3);
grid on;
title('Zde');
subplot(3,3,2);
plot(t,a1-c1);
grid on; 
title('Xde');
subplot(3,3,5);
plot(t,a2-c2);
grid on; 
title('Yde');
subplot(3,3,8);
plot(t,a3-c3);
grid on;
title('Zde');
subplot(3,3,3);
plot(t,a1-d1);
grid on; 
title('Xde');
subplot(3,3,6);
plot(t,a2-d2);
grid on; 
title('Yde');
subplot(3,3,9);
plot(t,a3-d3);
grid on;
title('Zde');

pause(); close all; clear all;

A = load('RID1_NOFORCE/DesiredPosFile.txt');
B = load('RID1_LINFORCE_MKD/CompliancePosFile.txt');
C = load('RID1_LINFORCE_M1K50D1/CompliancePosFile.txt');
D = load('RID1_LINFORCE_M15K50D5/CompliancePosFile.txt');
E = load('RID1_LINFORCE_M15K10D5/CompliancePosFile.txt');

[r1,c] = size(A);
[r2,c] = size(B);
[r3,c] = size(C);
[r4,c] = size(D);
[r5,c] = size(E);

dim = min([r1 r2 r3 r4 r5]);
a1 = zeros(dim/6,1); a2 = a1; a3 = a1; a4 = a1; a5 = a1; a6 = a1;
b1 = zeros(dim/6,1); b2 = b1; b3 = b1; b4 = b1; b5 = b1; b6 = b1;
c1 = zeros(dim/6,1); c2 = c1; c3 = c1; c4 = c1; c5 = c1; c6 = c1;
d1 = zeros(dim/6,1); d2 = d1; d3 = d1; d4 = d1; d5 = d1; d6 = d1;
e1 = zeros(dim/6,1); e2 = e1; e3 = e1; e4 = e1; e5 = e1; e6 = e1;

cont = 1;

for i=1:6:dim
    a1(cont) = A(i);   b1(cont) = B(i);   c1(cont) = C(i);   d1(cont) = D(i);   e1(cont) = E(i);
    a2(cont) = A(i+1); b2(cont) = B(i+1); c2(cont) = C(i+1); d2(cont) = D(i+1); e2(cont) = E(i+1);
    a3(cont) = A(i+2); b3(cont) = B(i+2); c3(cont) = C(i+2); d3(cont) = D(i+2); e3(cont) = E(i+2);
    a4(cont) = A(i+3); b4(cont) = B(i+3); c4(cont) = C(i+3); d4(cont) = D(i+3); e4(cont) = E(i+3);
    a5(cont) = A(i+4); b5(cont) = B(i+4); c5(cont) = C(i+4); d5(cont) = D(i+4); e5(cont) = E(i+4);
    a6(cont) = A(i+5); b6(cont) = B(i+5); c6(cont) = C(i+5); d6(cont) = D(i+5); e6(cont) = E(i+5);
    cont = cont +1;
end

t = linspace(0,dim/600,dim/6);

figure(7);
subplot(3,1,1);
plot(t,a1,'--');
hold on;
plot(t,b1);
hold on;
plot(t,c1);
hold on;
plot(t,d1);
grid on; 
plot(t,e1);
grid on; 
legend('No Force', 'M = 1, K = 1, D = 1' ,'M = 15, K = 50, D = 5', 'M = 1, K = 50, D = 1', 'M = 15, K = 10, D = 5');
title('X');
subplot(3,1,2);
plot(t,a2,'--');
hold on;
plot(t,b2);
hold on;
plot(t,c2);
hold on;
plot(t,d2);
grid on; 
plot(t,e2);
grid on; 
legend('No Force', 'M = 1, K = 1, D = 1' ,'M = 15, K = 50, D = 5', 'M = 1, K = 50, D = 1','M = 15, K = 10, D = 5');
title('Y');
subplot(3,1,3);
plot(t,a3,'--');
hold on;
plot(t,b3);
hold on;
plot(t,c3);
hold on;
plot(t,d3);
grid on; 
plot(t,e3);
grid on;
legend('No Force', 'M = 1, K = 1, D = 1' ,'M = 15, K = 50, D = 5', 'M = 1, K = 50, D = 1', 'M = 15, K = 10, D = 5');
title('Z');


pause(); close all; clear all;

A = load('RID1_LINFORCE_MKD/ActualPoseFile.txt');
[r,c] = size(A);
a1 = zeros(r/6,1); a2 = a1; a3 = a1; a4 = a1; a5 = a1; a6 = a1;
cont = 1;

for i=1:6:r
    a1(cont) = A(i);
    a2(cont) = A(i+1);
    a3(cont) = A(i+2);
    a4(cont) = A(i+3);
    a5(cont) = A(i+4);
    a6(cont) = A(i+5);
    cont = cont +1; 
end

figure(12);
plot3(a1,a2,a3);
hold on
A = load('RID1_LINFORCE_M15K1D5/ActualPoseFile.txt');
[r,c] = size(A);
a1 = zeros(r/6,1); a2 = a1; a3 = a1; a4 = a1; a5 = a1; a6 = a1;
cont = 1;
 
for i=1:6:r
    a1(cont) = A(i);
    a2(cont) = A(i+1);
    a3(cont) = A(i+2);
    a4(cont) = A(i+3);
    a5(cont) = A(i+4);
    a6(cont) = A(i+5);
    cont = cont +1;
end
plot3(a1,a2,a3);
hold on
A = load('RID1_LINFORCE_M15K50D5/ActualPoseFile.txt');
[r,c] = size(A);
a1 = zeros(r/6,1); a2 = a1; a3 = a1; a4 = a1; a5 = a1; a6 = a1;
cont = 1;
 
for i=1:6:r
    a1(cont) = A(i);
    a2(cont) = A(i+1);
    a3(cont) = A(i+2);
    a4(cont) = A(i+3);
    a5(cont) = A(i+4);
    a6(cont) = A(i+5);
    cont = cont +1;
end
plot3(a1,a2,a3);
A = load('RID1_LINFORCE_M15K10D5/ActualPoseFile.txt');
[r,c] = size(A);
a1 = zeros(r/6,1); a2 = a1; a3 = a1; a4 = a1; a5 = a1; a6 = a1;
cont = 1;
 
for i=1:6:r
    a1(cont) = A(i);
    a2(cont) = A(i+1);
    a3(cont) = A(i+2);
    a4(cont) = A(i+3);
    a5(cont) = A(i+4);
    a6(cont) = A(i+5);
    cont = cont +1;
end
plot3(a1,a2,a3);
grid on;
title('Posizione attuale');
legend('M = 1, K = 1, D = 1' ,'M = 15, K =  1, D = 50','M = 15, K = 50, D = 5','M = 15, K = 10, D = 5');


pause(); close all; clear all; 

%%Plot of up con forza sinusoidale caso untiario caso MKD
A = load('RID1_NOFORCE/DesiredPosFile.txt');
B = load('RID1_SINFORCE_MKD/CompliancePosFile.txt');
C = load('RID1_SINFORCE_M15K50D5/CompliancePosFile.txt');
D = load('RID1_SINFORCE_M15K50D5/ForceFile.txt');

[r1,c] = size(A); 
[r2,c] = size(B);
[r3,c] = size(C);
[r4,c] = size(C);

dim = min([r1 r2 r3 r4]);
a1 = zeros(dim/6,1); a2 = a1; a3 = a1; a4 = a1; a5 = a1; a6 = a1;
b1 = zeros(dim/6,1); b2 = b1; b3 = b1; b4 = b1; b5 = b1; b6 = b1;
c1 = zeros(dim/6,1); c2 = c1; c3 = c1; c4 = c1; c5 = c1; c6 = c1;
d1 = zeros(dim/6,1); d2 = d1; d3 = d1; d4 = d1; d5 = d1; d6 = d1;

cont = 1;

for i=1:6:dim
    a1(cont) = A(i);   b1(cont) = B(i);   c1(cont) = C(i);   d1(cont) = D(i);
    a2(cont) = A(i+1); b2(cont) = B(i+1); c2(cont) = C(i+1); d2(cont) = D(i+1);
    a3(cont) = A(i+2); b3(cont) = B(i+2); c3(cont) = C(i+2); d3(cont) = D(i+2);
    a4(cont) = A(i+3); b4(cont) = B(i+3); c4(cont) = C(i+3); d4(cont) = D(i+3);
    a5(cont) = A(i+4); b5(cont) = B(i+4); c5(cont) = C(i+4); d5(cont) = D(i+4);
    a6(cont) = A(i+5); b6(cont) = B(i+5); c6(cont) = C(i+5); d6(cont) = D(i+5);
    cont = cont +1;
end

t = linspace(0,dim/600,dim/6);

figure(8);
subplot(3,1,1);
plot(t,d1);
grid on; 
title('Force X');
subplot(3,1,2);
plot(t,d2);
grid on; 
title('Force Y');
subplot(3,1,3);
plot(t,d3);
grid on; 
title('Force Z');

figure(9);
subplot(3,1,1);
plot(t,a1,'--');
hold on;
plot(t,b1);
hold on;
plot(t,c1);
grid on; 
legend('No Force', 'M = 1, K = 1, D = 1' ,'M = 15, K = 50, D = 5');
title('X');
subplot(3,1,2);
plot(t,a2,'--');
hold on;
plot(t,b2);
hold on;
plot(t,c2);
grid on; 
legend('No Force', 'M = 1, K = 1, D = 1' ,'M = 15, K = 50, D = 5');
title('Y');
subplot(3,1,3);
plot(t,a3,'--');
hold on;
plot(t,b3);
hold on;
plot(t,c3);
grid on; 
legend('No Force', 'M = 1, K = 1, D = 1' ,'M = 15, K = 50, D = 5');
title('Z');

figure(10);
subplot(3,2,1);
plot(t,a1-b1);
grid on; 
title('Xde');
subplot(3,2,3);
plot(t,a2-b2);
grid on; 
title('Yde');
subplot(3,2,5);
plot(t,a3-b3);
grid on;
title('Zde');
subplot(3,2,2);
plot(t,a1-c1);
grid on; 
title('Xde');
subplot(3,2,4);
plot(t,a2-c2);
grid on; 
title('Yde');
subplot(3,2,6);
plot(t,a3-c3);
grid on;
title('Zde');

pause(); close all; clear all;

A = load('RID1_SINFORCE_MKD/ActualPoseFile.txt');
[r,c] = size(A);
a1 = zeros(r/6,1); a2 = a1; a3 = a1; a4 = a1; a5 = a1; a6 = a1;
cont = 1;

for i=1:6:r
    a1(cont) = A(i);
    a2(cont) = A(i+1);
    a3(cont) = A(i+2);
    a4(cont) = A(i+3);
    a5(cont) = A(i+4);
    a6(cont) = A(i+5);
    cont = cont +1; 
end

figure(11);
plot3(a1,a2,a3);
hold on
A = load('RID1_SINFORCE_M15K50D5/ActualPoseFile.txt');
[r,c] = size(A);
a1 = zeros(r/6,1); a2 = a1; a3 = a1; a4 = a1; a5 = a1; a6 = a1;
cont = 1;
 
for i=1:6:r
    a1(cont) = A(i);
    a2(cont) = A(i+1);
    a3(cont) = A(i+2);
    a4(cont) = A(i+3);
    a5(cont) = A(i+4);
    a6(cont) = A(i+5);
    cont = cont +1;
end
plot3(a1,a2,a3);
grid on;
title('Posizione attuale');
legend('M = 1, K = 1, D = 1' ,'M = 15, K = 50, D = 5');


pause(); close all; clear all;
