%Range plotnya
x = -2:0.0001:2;

%Nilai a dan b pada fungsinya
a = 0.5;
b = 3;

%Inisialisasi vektor weival sebagai kontainer nilai dari fungsi weierstrass
weival(40001) = 0;

%Generate isi weival dengan evaluasi aproksimasi dari definisi deret Fourier fungsi Weierstrass
for i = 1:40001
  cnt = 0;
  %Offset index array ke nilai x-nya
  xval = (i-40001)/10000 + 2;
  for n = 0:1:120 %Fungsi aslinya sampai tak hingga jadi kita dekati aja
    cnt = cnt + a^n*cos(b^n*pi*xval);
  end
  weival(i) = cnt;
end

plot(x,weival);

%Bikin sumbu x-y
axh = gca; % use current axes
color = 'k'; % black, or [0 0 0]
linestyle = '-'; % solid
line(get(axh,'XLim'), [0 0], 'Color', color, 'LineStyle', linestyle);
line([0 0], get(axh,'YLim'), 'Color', color, 'LineStyle', linestyle);
