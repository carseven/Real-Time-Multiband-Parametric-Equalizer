    % GUARDA ESTE FICHERO CON EL NOMBRE: principal.m
clear, close, clc

% Cargamos Audio
[x,Fm] = audioread('Fisher - Losing It.wav'); 

%Orden filtros
N = 128; 
%Limites de las bandas
Frecuencias = [1000,3000,5000,8000,16000]; 
%Modos de ecualización
Llano = [0 0 0 0 0 0];
Rock =[6 -8 -3 2 4 8];
Dance = [2 4 -1 0 -1 0];
Eq0 = [12 -12 -12 -12 12 12];

y = ecualizaParalelo(Frecuencias, Rock, N, Fm,x(:,1));


% Escuchamos
%sound(x(:,1), Fm) % Original
sound(y,Fm) % Filtrada

figure,
subplot(211),plot(x),title('x')
subplot(212),plot(y), title('y'),shg
