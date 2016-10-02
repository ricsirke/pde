reset

set datafile sep "\t"
stats "test.dat" nooutput

set xrange [0:1]
set yrange [0:10]

do for [i=0:(int(STATS_blocks)-1)] {
    plot "test.dat" index (i) w linespoint ls 1
    pause 0.5
}

pause -1

