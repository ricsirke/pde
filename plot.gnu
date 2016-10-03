reset

set datafile separator ","
set xrange [0:1]
set yrange [-200:1000]

n=0

do for [ii=1:99] {
    n=n+1
    plot 'results.dat' every ii
    pause 0.1
}