function b = LowPass(Fc,Fs,N)
flag = 'scale';  % Sampling Flag
Beta = 4;        % Window Parameter

% Create the window vector for the design algorithm.
win = kaiser(N+1, Beta);

% Calculate the coefficients using the FIR1 function.
b  = fir1(N, Fc/(Fs/2), 'low', win, flag);
