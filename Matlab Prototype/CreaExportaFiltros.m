% -------------------------------------------------------------------------
% MINIPROYECTO TDS - ECUALIZADOR PARAMETRICO MULTIBANDA EN PARALELO
% -------------------------------------------------------------------------
% CURSO 2019-2020               TDS - GIET - ETSE
% -------------------------------------------------------------------------
% ALUMNOS: Carles Serra Vendrell y Jordi Ferrando Vila
% -------------------------------------------------------------------------
% Creamos el filtro parametric y exportamos los coeficientes a C 
% -------------------------------------------------------------------------
clear, close, clc

% -------------------------------------------------------------------------
% 1. GENERACIÓN DE LOS FILTROS
% -------------------------------------------------------------------------
% Variables diseño filtro.
F = [250 500 1000 2000 4000 8000 16000];
Ganancia = [0 0 0 0 0 0 0 0];
N = 128;
Fm = 48000;

% Convertimos de dB a lineal vector ganancia.
    G = db2mag(Ganancia);   
    
% LOW PASS FILTER (FIR)
    
    % Generamos  funcion de transferencia (coef. filtro) y la multiplicamos 
    % por la ganacia de esta banda.
    lp = LowPass(F(1),Fm,N)*G(1);
    
    % Representamos.
    figure('Name','ECUALIZADOR PARAMETRICO MULTIBANDA');
    freqz(lp);      % Representacion en frecuencia lowpass.
    
    hold on;       
    yline(-6);      % Creamos linea en -6dB, para visualizar cruce filtros. 
    ylim([-40 12]); % Limites eje y para mejor visualizacion.
    
% BAND PASS FILTER (FIR)
    
    bp_total = 0;   %Variable buffer
    % Generamos length(G)-2 funciones de transferencia .
    for i = 1:(length(G)-2)
        
        % Generamos  funciones de transferencia (coef. filtro) y la 
        % multiplicamos por la ganacia de esta banda.
        bp(i,:) = BandPass(F(i),F(i+1),Fm,N)*G(i+1);
        
        % Represetamos cada banda.
        freqz(bp(i,:));                 
        
        % Suma coefcientes de las diferentes bandas, obtenemos pasa banda
        % equivalente.
        bp_total = bp_total + bp(i,:);  
    end

% HIGH PASS FILTER (FIR)

    % Generamos  funcion de transferencia (coef. filtro) y la multiplicamos 
    % por la ganacia de esta banda.
    hp = HighPass(F(length(F)),Fm,N)*G(length(G));
    
    % Representamos respuesta en frecuencia del filtro.
    freqz(hp);
    
% ECUALIZADOR PARAMETRICO MULTIBANDA EN PARALELO

    % Suma de las diferentes bandas para obtener la funcion de trans. total
    parametric = lp + hp + bp_total;
    
    % Representamos.
    
    
    freqz(parametric);
    
% -------------------------------------------------------------------------
% 2. EXPORTAMOS COEFICIENTES FILTRO A C
% -------------------------------------------------------------------------
    coeffs = FIR_dump2cIHPDS_INT('Auriculares', 'Auriculares', parametric, length(parametric));
    
    