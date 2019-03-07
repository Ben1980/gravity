set title "Calculation time of Euler-Method"
set auto x
set yrange [0:9850.59]
set style data histogram
set style histogram cluster gap 1
set style fill solid border -1
set boxwidth 0.9
set xtic rotate by -45 scale 0
set xlabel "Number of particles [N]"
set ylabel "Time [ms]"
#set bmargin 10 
set nokey
plot "eulerData.dat" using 2:xticlabels(1)
