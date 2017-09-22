#!/usr/bin/expect -f
# For colors
proc capability cap {expr {![catch {exec tput -S << $cap}]}}
proc colorterm {} {expr {[capability setaf] && [capability setab]}}
proc tput args {exec tput -S << $args >/dev/tty}
array set color {black 0 red 1 green 2 yellow 3 blue 4 magenta 5 cyan 6 white 7}
proc foreground x {exec tput -S << "setaf $::color($x)" > /dev/tty}
proc background x {exec tput -S << "setab $::color($x)" > /dev/tty}
proc reset {} {exec tput sgr0 > /dev/tty}

#Test the program
eval spawn [lrange $argv 0 end]

#Put your test case here

expect "What's the student's id? : " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "0202\r"
expect " name: Maria Lopez, semestre: 7" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
eval spawn [lrange $argv 0 end]

expect "What's the student's id? : " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "0220\r"
expect " Student 0220 not found." {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
eval spawn [lrange $argv 0 end]

expect "What's the student's id? : " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "0101\r"
expect " name: Pepe Perez, semestre: 6" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
