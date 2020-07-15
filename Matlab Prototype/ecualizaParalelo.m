% -------------------------------------------------------------------------
% MINIPROYECTO TDS - ECUALIZADOR PARAMETRICO MULTIBANDA EN PARALELO
% -------------------------------------------------------------------------
% CURSO 2019-2020               TDS - GIET - ETSE
% -------------------------------------------------------------------------
% ALUMNOS: Carles Serra Vendrell y Jordi Ferrando Vila
% -------------------------------------------------------------------------
% Esta funcion filtra una señal x usando ecualizador parametrico multibanda 
% en paralelo definido por las variables de entrada.
% Primer filtro sera siempre pasa baja. Y el ultimo filtro sera pasa alta.
% Los demas filtros seran pasa banda y se generan tantos como bandas
% restantes hasta completar el numero de ganancias. Logitud del vector
% ganancias -2,
% -------------------------------------------------------------------------
% y = ecualizaParalelo(F,Ganancia,N,Fm,x)
% 
% Entradas
%     F          : Vector con fecuencias de los limites de las bandas.
%     Ganancia   : Vector gancacias de las bandas en dB.
%     N          : Orden de los filtros.
%     Fm         : Frecuencia de muestreo.
%     x          : Señal de entrada que filtraremos.
%
% Salidas
%     y          : Señal de salida una vez aplicado el filtro a la señal x.
%     
% -------------------------------------------------------------------------

function y = ecualizaParalelo(F,Ganancia,N,Fm,x)
% -------------------------------------------------------------------------
% 1. GENERACIÓN DE LOS FILTROS
% -------------------------------------------------------------------------

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
    ylim([-40 15]); % Limites eje y para mejor visualizacion.
    
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
% 2. FILTRAMOS LA SEÑAL DE ENTRADA
% -------------------------------------------------------------------------
    %y = filter(parametric,1,x);
    
    for n = length(parametric)+1:length(x)
        y(n) = 0;
        for k = 1:length(parametric)
            y(n) = y(n) + parametric(k) * x(n-k);
        end
    end