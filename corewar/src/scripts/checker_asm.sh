#!/bin/bash
if [[ -z $1 ]]
then
    echo -e "\033[31mOut of map's name.\033[0m"
    exit
else
    ./asm $1.s > asm_our
    hexdump -vC $1.cor > asm.cor
    ./vm_champs/asm $1.s > asm_ex
    hexdump -vC $1.cor > asm_ex.cor
    diff asm.cor asm_ex.cor > asm_res
    diff asm_ex asm_our > res
    if [[ -s asm_res ]]
    then
        echo -e "\033[31mError on diff $1\033[0m"
        cat asm_res
    fi
    if [[ -s res ]]
    then
        echo -e "\033[31mDiff on output $1\033[0m"
        cat res
    fi
    # rm asm_res
    # rm asm.cor
    # rm asm_ex.cor
    # rm res
    # rm asm_ex
    # rm asm_our
fi