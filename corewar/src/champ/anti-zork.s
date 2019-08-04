.name "anti-zork"
.comment "ZORK! I KILL U!"

paste:	sti r1, %:live, %1

live:	live %1

fork:   fork %:live
