# PS1="\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\\$ "
# PS1='\e[35m[\e[92m\u\e[35m]\e[0m$ '
# PS1='\e[92m\u\e[0m@\e[94m\h\e[0m:\e[35m\w\e[0m$ '
PS1='\e[35m[\e[92m\u\e[35m]\e[0m:\e[34m\w\e[0m$ '
alias comp='c++ -Wall -Wextra -Werror -std=c++98 -g main.cpp'
alias run='c++ -Wall -Wextra -Werror -std=c++98 -g main.cpp && ./a.out'
alias rma='rm ./a.out'
alias rua='./a.out'
alias mf='make fclean'
alias ex='make re && ./RPN "7 7 * 7 -"'
alias val='make re && valgrind ./btc'

alias ra='./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"'
alias re='./RPN "7 7 * 7 -"'
alias ri='./RPN "1 2 * 2 / 2 * 2 4 - +"'
alias ro='./RPN "(1 + 1)"'