function coeffs = FIR_dump2cIHPDS_INT(filename, varname, coeffs, FIR_length)
%//////////////////////////////////////////////////////////////////////
%/ Modificado por M. Martinez para que N sea el n?mero de coeficientes no
%/ el orden
%
%/ Welch, Wright, & Morrow, 
%/ Real-time Digital Signal Processing, 2005
%/
%/ function FIR_dump2c(filename, varname, coeffs, FIR_length)
%/
%/ Dumps FIR filter coefficients to file in C language format in forward order.
%/ "cd" to the desired directory PRIOR to execution ... this will provide 
%/ for increased c code portability
%/
%/ e.g. FIR_dump2c('coeff', 'B', filt1.tf.num, length(filt1.tf.num))
%/
%/ Arguments: filename   - Filename to open for writing coefficients to, no extension
%/            varname    - Name to be assigned to coefficient array
%/            coeffs     - Vector containing FIR filter coefficients
%/            FIR_length - Number of FIR filter coefficients (padded with zeros if necessary)
%/
%//////////////////////////////////////////////////////////////////////

j = fopen([filename '.h'],'w');
fprintf(j, '/* %-35s */\n', [filename '.h']);
fprintf(j, '/* FIR filter coefficients              */\n');
fprintf(j, '/* exported by MATLAB using FIR_dump2c  */\n');
fprintf(j, '/* Michael G. Morrow - 2000, 2003, 2004 */\n\n\n');
%fprintf(j, '#define N %d\n\n', FIR_length - 1);
fprintf(j, '#define N %d\n\n', FIR_length);
fprintf(j, 'extern const int %s[];\n\n', varname);
      
fclose(j);

j = fopen([filename '.c'],'w');
fprintf(j, '/* %-35s */\n', [filename '.c']);
fprintf(j, '/* FIR filter coefficients              */\n');
fprintf(j, '/* exported by MATLAB using FIR_dump2c  */\n');
fprintf(j, '/* Michael G. Morrow - 2000, 2003       */\n\n\n');
fprintf(j, '#include "%s"\n\n', [filename '.h']);
%fprintf(j, 'float %s[N+1] = {\n', varname);

max(coeffs)
fprintf(j, 'const int %s[N] = {\n', varname);
Factor=2^(ceil(log(max(abs(coeffs))/2^15)/log(2))); %Potencia de 2 más proxima
coeffs=round(coeffs/Factor);
if (Factor>1)
     fprintf(1, 'Coeficientes escalados, FactorEscalado=%d\n',Factor);
end
for i=1:FIR_length
  
   if i <= length(coeffs)
      fprintf(j, '%d,	/* h[%d] */\n', coeffs(i), i-1);
   else
      fprintf(j, '%d,	/* ;h[%d] */\n', 0, i-1);
   end
end
fprintf(j, '};\n');
fclose(j);
