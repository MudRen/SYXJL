// color.c
// show colors define on /ansi.h by ken@XAJH

#include <ansi.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me)
{
if (wizardp(me)) write("\nThe color define on /include/ansi.h\n");
else write("\n��ɫ��ʾ��\n");
write("----------------------------------------------------------\n\n"
BLK"BLK\t"RED"RED\t"GRN"GRN\t"YEL"YEL\t"BLU"BLU\t"MAG"MAG\t"CYN"CYN\t"WHT"WHT"NOR".\n"
HIR"HIR\t"HIG"HIG\t"HIY"HIY\t"HIB"HIB\t"HIM"HIM\t"HIC"HIC\t"HIW"HIW"NOR".\n"
HBRED"HBRED\t"HBGRN"HBGRN\t"HBYEL"HBYEL\t"HBBLU"HBBLU\t"HBMAG"HBMAG\t"HBCYN"HBCYN\t"HBWHT"HBWHT"NOR".\n"
BBLK"BBLK\t"BRED"BRED\t"BGRN"BGRN\t"BYEL"BYEL\t"BBLU"BBLU\t"BMAG"BMAG\t"BCYN"BCYN"NOR".\n\n"
        );
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : color

���ָ������г�Ŀǰ����ʹ�õ���ɫ��

HELP);


return 1;
}

