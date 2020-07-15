clear, clc

h = int16(randn(1,65) * 16384);
x = int16(randn(1,1000) * 10000);

for n = length(h)+1:1000
    y(n) = int32(0);
    for k = 1:65
        y(n) = y(n) + int32(h(k) * x(n-k));
    end
    
end
y = int16(y / 32);

clf
plot(x), hold on
plot(y), shg
legend('x','y')