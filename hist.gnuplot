set terminal 'png'
set output 'out.png'
binwidth=0.01
set boxwidth binwidth
bin(x,width)=width*floor(x/width)+binwidth/2.0

plot 'out.dat' using (bin($1,binwidth)):(1.0) smooth freq with boxes
