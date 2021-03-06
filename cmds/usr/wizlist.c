// wizlist.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string *list;

        write("【"HIW + MUD_NAME + NOR"】" + "目前的巫师有：\n");
        write("────────────────────────────\n");
        list = sort_array(SECURITY_D->query_wizlist(), 1);
        write(HIW"【天界总管】 ："NOR);
        for(int i=0; i<sizeof(list); i++)
                printf("%s", (wiz_level(list[i])==7) ? "("HIW+list[i]+NOR") " : "");
        write("\n"HIR"【八部天神】 ："NOR);
        for(int i=0; i<sizeof(list); i++)
                printf("%s", (wiz_level(list[i])==6) ? "("HIR+list[i]+NOR") " : "");
	write("\n"HIM"【护法天尊】 ："NOR);
        for(int j=0; j<sizeof(list); j++)
                printf("%s", (wiz_level(list[j])==5) ? "("HIM+list[j]+NOR") " : "");
        write("\n"HIY"【天庭侍卫】 ："NOR);
        for(int i=0; i<sizeof(list); i++)
                printf("%s", (wiz_level(list[i])==4) ? "("HIY+list[i]+NOR") " : "");
        write("\n"HIG"【逍遥神仙】 ："NOR);
        for(int k=0; k<sizeof(list); k++)
                printf("%s", (wiz_level(list[k])==3) ? "("HIG+list[k]+NOR") " : "");
        write("\n"HIC"【金童玉女】 ："NOR);
        for(int l=0; l<sizeof(list); l++)
                printf("%s", (wiz_level(list[l])==2) ? "("HIC+list[l]+NOR") " : "");
       
        write("\n────────────────────────────\n");
        write("合计共有： "HIR + sizeof(list) + NOR" 位巫师工作中。\n");
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : wizlist

用途 : 列出目前所有的巫师名单。
HELP
     );
     return 1;
}




