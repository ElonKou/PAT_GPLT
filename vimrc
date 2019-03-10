"" 显示行号 语法高亮
set encoding=utf-8
set nu              
syntax on
set foldenable
set foldmethod=manual
set completeopt=preview,menu 
set clipboard+=unnamed
set nobackup
" 自动缩进
set autoindent
set cindent
" Tab键的宽度
set tabstop=4
" 统一缩进为4
set softtabstop=4
set shiftwidth=4
set expandtab
set mouse=a
set selection=exclusive
set selectmode=mouse,key


autocmd BufNewFile *.cpp,*.[ch],*.sh,*.java exec ":call SetTitle()" 
""定义函数SetTitle，自动插入文件头 
func SetTitle() 
    if &filetype == 'cpp'
        call setline(1,"//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++") 
        call append(line("."), "// File Name: ".expand("%")) 
        call append(line(".")+1, "// Author   : ElonKou")
        call append(line(".")+2, "// Email    : elonkou@ktime.cc")
        call append(line(".")+3, "// Date     : ".strftime("%c"))
        call append(line(".")+4,"//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++") 
        call append(line(".")+5, "")
        call append(line(".")+6, "#include <iostream>")
        call append(line(".")+7, "using namespace std;")
        call append(line(".")+8, "")
        call append(line(".")+9, "int main(int argc, char *argv[])")
        call append(line(".")+10, "{")
        call append(line(".")+11, "    cout << \"Hello,world!\";")
        call append(line(".")+12, "    return 0;")
        call append(line(".")+13, "}")
    endif
    if &filetype == 'c'
        call append(line(".")+6, "#include<stdio.h>")
        call append(line(".")+7, "")
    endif
    autocmd BufNewFile * normal G
endfunc 


"C，C++ 按F5编译运行
map <F5> :call CompileRunGcc()<CR>
func! CompileRunGcc()
    exec "w"
    if &filetype == 'c'
        exec "!g++ % -o %<"
        exec "! ./%<"
    elseif &filetype == 'cpp'
        exec "!g++ % -o %<"
        exec "! ./%<"
    elseif &filetype == 'sh'
        :!./%
    endif
endfunc
