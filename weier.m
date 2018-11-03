x = -2:0.0001:2;
a = 0.5;
b = 3;
weival(40001) = 0;
for i = 1:40001
  cnt = 0;
  xval = (i-40001)/10000 + 2;
  for n = 0:1:120
    cnt = cnt + a^n*cos(b^n*pi*xval);
  end
  weival(i) = cnt;
end
plot(x,weival);
axh = gca; % use current axes
color = 'k'; % black, or [0 0 0]
linestyle = '-'; % solid
line(get(axh,'XLim'), [0 0], 'Color', color, 'LineStyle', linestyle);
line([0 0], get(axh,'YLim'), 'Color', color, 'LineStyle', linestyle);