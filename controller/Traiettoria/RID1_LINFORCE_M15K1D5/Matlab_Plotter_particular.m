close all;
clear all;

A = load('QFile.txt');
B = load('QdFile.txt');
C = load('ForceFile.txt');
D = load('ErrorFile.txt');
E = load('DesiredPosFile.txt');
F = load('DesiredVelFile.txt');
G = load('CompliancePosFile.txt');
H = load('ComplianceVelFile.txt');
I = load('ActualPoseFile.txt');

dimAB = size(A);
dimAB = dimAB(1);
cont = 1;
A1 = zeros(dimAB/7,1);
A2 = zeros(dimAB/7,1);
A3 = zeros(dimAB/7,1);
A4 = zeros(dimAB/7,1);
A5 = zeros(dimAB/7,1);
A6 = zeros(dimAB/7,1);
A7 = zeros(dimAB/7,1);
B1 = zeros(dimAB/7,1);
B2 = zeros(dimAB/7,1);
B3 = zeros(dimAB/7,1);
B4 = zeros(dimAB/7,1);
B5 = zeros(dimAB/7,1);
B6 = zeros(dimAB/7,1);
B7 = zeros(dimAB/7,1);

for i = 1: 7: dimAB
   A1(cont) = A(i); 
   A2(cont) = A(i+1); 
   A3(cont) = A(i+2); 
   A4(cont) = A(i+3); 
   A5(cont) = A(i+4); 
   A6(cont) = A(i+5); 
   A7(cont) = A(i+6);
   B1(cont) = B(i); 
   B2(cont) = B(i+1); 
   B3(cont) = B(i+2); 
   B4(cont) = B(i+3); 
   B5(cont) = B(i+4); 
   B6(cont) = B(i+5); 
   B7(cont) = B(i+6);
   cont = cont +1;
end

t = linspace(0,dimAB/700,dimAB/7);
figure(1);
subplot(4,2,1);
plot(t, A1);
hold on;
plot(t,B1);
title('q1');
grid on;
legend('Q1','Q1d');
subplot(4,2,2);
plot(t, A2);
hold on;
plot(t,B2);
title('q2');
grid on;
legend('Q2','Q2d');
subplot(4,2,3);
plot(t, A3);
hold on;
plot(t,B3);
title('q3');
grid on;
legend('Q3','Q3d');
subplot(4,2,4);
plot(t, A4);
hold on;
plot(t,B4);
title('q4');
grid on;
legend('Q4','Q4d');
subplot(4,2,5);
plot(t, A5);
hold on;
plot(t,B5);
title('q5');
grid on;
legend('Q5','Q5d');
subplot(4,2,6);
plot(t, A6);
hold on;
plot(t,B6);
title('q6');
grid on;
legend('Q6','Q6d');
subplot(4,2,7);
plot(t, A7);
hold on;
plot(t,B7);
title('q7');
grid on;
legend('Q7','Q7d');

figure(2);
subplot(4,2,1);
plot(t, A1-B1);
title('Error qd1');
grid on;
subplot(4,2,2);
plot(t, A2-B2);
title('Error qd2');
grid on;
subplot(4,2,3);
plot(t, A3-B3);
title('Error qd3');
grid on;
subplot(4,2,4);
plot(t, A4-B4);
title('Error qd4');
grid on;
subplot(4,2,5);
plot(t, A5-B5);
title('Error qd5');
grid on;
subplot(4,2,6);
plot(t, A6-B6);
title('Error qd6');
grid on;
subplot(4,2,7);
plot(t, A7-B7);
title('Error qd7');
grid on;

dimIG = size(I);
dimIG = dimIG(1);
cont = 1;
I1 = zeros(dimIG/6,1);
I2 = zeros(dimIG/6,1);
I3 = zeros(dimIG/6,1);
I4 = zeros(dimIG/6,1);
I5 = zeros(dimIG/6,1);
I6 = zeros(dimIG/6,1);

G1 = zeros(dimIG/6,1);
G2 = zeros(dimIG/6,1);
G3 = zeros(dimIG/6,1);
G4 = zeros(dimIG/6,1);
G5 = zeros(dimIG/6,1);
G6 = zeros(dimIG/6,1);


for i = 1: 6: dimIG
   I1(cont) = I(i); 
   I2(cont) = I(i+1); 
   I3(cont) = I(i+2); 
   I4(cont) = I(i+3); 
   I5(cont) = I(i+4); 
   I6(cont) = I(i+5); 
   G1(cont) = G(i); 
   G2(cont) = G(i+1); 
   G3(cont) = G(i+2); 
   G4(cont) = G(i+3); 
   G5(cont) = G(i+4); 
   G6(cont) = G(i+5);
   cont = cont +1;
end

figure(3);
plot3(I1,I2,I3);
grid on;
title ('Actual Position');
t = linspace(0,dimIG/600,dimIG/6);

figure(4);
subplot(3,2,1);
plot(t, I1);
hold on;
plot(t, G1);
title('X');
grid on;
legend('X','X_c');
subplot(3,2,2);
plot(t, I2);
hold on;
plot(t, G2);
title('Y');
grid on;
legend('Y','Y_c');
subplot(3,2,3);
plot(t, I3);
hold on;
plot(t, G3);
title('Z');
grid on;
legend('Z','Z_c');
subplot(3,2,4);
plot(t, I4);
hold on;
plot(t, G4);
title('Pitch');
grid on;
legend('Pitch','Pitch_c');
subplot(3,2,5);
plot(t, I5);
hold on;
plot(t, G5);
title('Yaw');
grid on;
legend('Yaw','Yaw_c');
subplot(3,2,6);
plot(t, I6);
hold on;
plot(t, G6);
title('Roll');
grid on;
legend('Roll','Roll_c');

dimC = size(C);
dimC = dimC(1);
cont = 1;
C1 = zeros(dimC/6,1);
C2 = zeros(dimC/6,1);
C3 = zeros(dimC/6,1);

for i = 1: 6: dimC
   C1(cont) = C(i); 
   C2(cont) = C(i+1); 
   C3(cont) = C(i+2); 
   cont = cont +1;
end

t = linspace(0,dimC/600,dimC/6);
figure(5);
subplot(3,1,1);
plot(t, C1);
title('F1');
grid on;
subplot(3,1,2);
plot(t, C2);
title('F2');
grid on;
subplot(3,1,3);
plot(t, C3);
title('F3');
grid on;

dimD = size(D);
dimD = dimD(1);
cont = 1;
D1 = zeros(dimD/6,1);
D2 = zeros(dimD/6,1);
D3 = zeros(dimD/6,1);
D4 = zeros(dimD/6,1);
D5 = zeros(dimD/6,1);
D6 = zeros(dimD/6,1);

for i = 1: 6: dimD
   D1(cont) = D(i); 
   D2(cont) = D(i+1); 
   D3(cont) = D(i+2); 
   D4(cont) = D(i+3); 
   D5(cont) = D(i+4); 
   D6(cont) = D(i+5); 
   cont = cont +1;
end

t = linspace(0,dimD/600,dimD/6);
figure(6);
subplot(3,2,1);
plot(t, D1);
title('X-Error');
grid on;
subplot(3,2,2);
plot(t, D2);
title('Y-Error');
grid on;
subplot(3,2,3);
plot(t, D3);
title('Z-Error');
grid on;
subplot(3,2,4);
plot(t, D4);
title('Q1-Error');
grid on;
subplot(3,2,5);
plot(t, D5);
title('Q2-Error');
grid on;
subplot(3,2,6);
plot(t, D6);
title('Q3-Error');
grid on;
 
dimE = size(E);
dimE = dimE(1);
cont = 1;
E1 = zeros(dimE/6,1);
E2 = zeros(dimE/6,1);
E3 = zeros(dimE/6,1);
E4 = zeros(dimE/6,1);
E5 = zeros(dimE/6,1);
E6 = zeros(dimE/6,1);

for i = 1: 6: dimE
   E1(cont) = E(i); 
   E2(cont) = E(i+1); 
   E3(cont) = E(i+2); 
   E4(cont) = E(i+3); 
   E5(cont) = E(i+4); 
   E6(cont) = E(i+5); 
   cont = cont +1;
end

figure(7);
plot3(E1,E2,E3);
title ('Desired Position');
grid on;

t = linspace(0,dimE/600,dimE/6);
figure(8);
subplot(3,2,1);
plot(t, E4);
title('Desired X');
grid on;
subplot(3,2,2);
plot(t, E5);
title('Desired Y');
grid on;
subplot(3,2,3);
plot(t, E6);
title('Desired Z');
grid on;
subplot(3,2,4);
plot(t, E4);
title('Desired pitch');
grid on;
subplot(3,2,5);
plot(t, E5);
title('Desired yaw');
grid on;
subplot(3,2,6);
plot(t, E6);
title('Desired roll');
grid on;


dimF = size(F);
dimF = dimF(1);
cont = 1;
F1 = zeros(dimF/6,1);
F2 = zeros(dimF/6,1);
F3 = zeros(dimF/6,1);
F4 = zeros(dimF/6,1);
F5 = zeros(dimF/6,1);
F6 = zeros(dimF/6,1);

for i = 1: 6: dimF
   F1(cont) = F(i); 
   F2(cont) = F(i+1); 
   F3(cont) = F(i+2); 
   F4(cont) = F(i+3); 
   F5(cont) = F(i+4); 
   F6(cont) = F(i+5); 
   cont = cont +1;
end

figure(9);
subplot(3,2,1);
plot(t, F4);
title('Desired X Vel');
grid on;
subplot(3,2,2);
plot(t, F5);
title('Desired Y Vel');
grid on;
subplot(3,2,3);
plot(t, F6);
title('Desired Z Vel');
grid on;
subplot(3,2,4);
plot(t, F4);
title('Desired pitch Vel');
grid on;
subplot(3,2,5);
plot(t, F5);
title('Desired yaw Vel');
grid on;
subplot(3,2,6);
plot(t, F6);
title('Desired roll Vel');
grid on;


dimG = size(G);
dimG = dimG(1);
cont = 1;
G1 = zeros(dimG/6,1);
G2 = zeros(dimG/6,1);
G3 = zeros(dimG/6,1);
G4 = zeros(dimG/6,1);
G5 = zeros(dimG/6,1);
G6 = zeros(dimG/6,1);

for i = 1: 6: dimG
   G1(cont) = G(i); 
   G2(cont) = G(i+1); 
   G3(cont) = G(i+2); 
   G4(cont) = G(i+3); 
   G5(cont) = G(i+4); 
   G6(cont) = G(i+5); 
   cont = cont +1;
end

figure(10);
plot3(G1,G2,G3);
title ('Compliance Position');
grid on;

figure(11);
subplot(3,2,1);
plot(t, G4);
title('Compliance X');
grid on;
subplot(3,2,2);
plot(t, G5);
title('Compliance Y');
grid on;
subplot(3,2,3);
plot(t, G6);
title('Compliance Z');
grid on;
subplot(3,2,4);
plot(t, G4);
title('Compliance pitch');
grid on;
subplot(3,2,5);
plot(t, G5);
title('Compliance yaw');
grid on;
subplot(3,2,6);
plot(t, G6);
title('Compliance roll');
grid on;

dimH = size(H);
dimH = dimH(1);
cont = 1;
H1 = zeros(dimH/6,1);
H2 = zeros(dimH/6,1);
H3 = zeros(dimH/6,1);
H4 = zeros(dimH/6,1);
H5 = zeros(dimH/6,1);
H6 = zeros(dimH/6,1);

for i = 1: 6: dimH
   H1(cont) = H(i); 
   H2(cont) = H(i+1); 
   H3(cont) = H(i+2); 
   H4(cont) = H(i+3); 
   H5(cont) = H(i+4); 
   H6(cont) = H(i+5); 
   cont = cont +1;
end

figure(12);
subplot(3,2,1);
plot(t, H4);
title('Compliance X Vel');
grid on;
subplot(3,2,2);
plot(t, H5);
title('Compliance Y Vel');
grid on;
subplot(3,2,3);
plot(t, H6);
title('Compliance Z Vel');
grid on;
subplot(3,2,4);
plot(t, H4);
title('Compliance pitch Vel');
grid on;
subplot(3,2,5);
plot(t, H5);
title('Compliance yaw Vel');
grid on;
subplot(3,2,6);
plot(t, H6);
title('Compliance roll Vel');
grid on;

